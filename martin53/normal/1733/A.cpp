#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
        int n,k;
        vector<int> input;

    public:
        Solution()
        {
            scanf("%i%i",&n,&k);

            for(int i=1;i<=n;i++)
            {
                int cur;

                scanf("%i",&cur);

                input.push_back(cur);
            }
        }

        void solve()
        {
            vector<int> MX(k,0);

            for(int i=0;i<n;i++)
                MX[i%k]=max(MX[i%k],input[i]);

            long long outp=0;

            for(auto current:MX)
                outp+=current;

            printf("%lld\n",outp);
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