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

            for(int i=0;i<n;i++)
            {
                int cur;

                scanf("%i",&cur);

                inp.push_back(cur);
            }
        }

        void solve()
        {
            sort(inp.begin(),inp.end());

            int outp=inp[2]-inp[0];

            for(int i=2;i<inp.size();i++)
                outp=min(outp,inp[i]-inp[i-1]+inp[i-1]-inp[i-2]);

            printf("%i\n",outp);
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