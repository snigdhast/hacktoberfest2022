class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        int mIdx = (n1+n2) / 2 - 1;
        int i = -1, j = -1, last = 0, current = 0;
        while(i+j<mIdx)
        {
            last = current;
            if(i>=n1-1)
            {
                current = nums2[++j];
            }
            else if(j>=n2-1)
            {
                current = nums1[++i];
            }
            else if(nums1[i+1]>nums2[j+1])
            {
                current = nums2[++j];
            }
            else
            {
                current = nums1[++i];
            }
        }
        if((n1+n2) % 2)
            return current;
        else
            return (current + last) / 2.0;
    }
};
