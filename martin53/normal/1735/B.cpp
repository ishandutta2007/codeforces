#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
        int n;
        vector<int> inp;

    public:
        Solution()
        {
            scanf("%i",&n);

            for(int i=1;i<=n;i++)
            {
                int cur;

                scanf("%i",&cur);

                inp.push_back(cur);
            }
        }

        void solve()
        {
            sort(inp.begin(),inp.end());

            long long output=0;

            for(auto current:inp)
                output+=(current+2*inp[0]-1-1)/(2*inp[0]-1)-1;

            printf("%lld\n",output);
        }
};

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        Solution current;

        current.solve();
    }

    return 0;
}