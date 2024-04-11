#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
        int n;
        vector<bool> inp;
        vector<bool> taken;

    public:
        Solution()
        {
            inp.push_back(0);
            taken.push_back(0);

            scanf("%i",&n);

            for(int i=1;i<=n;i++)
            {
                taken.push_back(0);

                char c='-';

                while(c!='0'&&c!='1')c=getchar();

                inp.push_back(c-'0');
            }
        }

        void solve()
        {
            long long output=0;

            for(int k=1;k<=n;k++)
            {
                for(int cur=k;cur<=n;cur+=k)
                    if(taken[cur]==0)
                    {
                        if(inp[cur])break;
                        else
                        {
                            taken[cur]=1;

                            output+=k;
                        }
                    }
            }

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