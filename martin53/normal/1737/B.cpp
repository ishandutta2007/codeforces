#include<bits/stdc++.h>
using namespace std;

const int INF=0;

class Solution
{
    public:
        long long l,r;

        Solution()
        {
            scanf("%lld%lld",&l,&r);
        }

        long long up_to(long long val)
        {
            long long sq=sqrt(val);

            while((sq+1)*(sq+1)<=val)sq++;

            long long ret=3*(sq-1);

            if(sq*sq<=val)ret++;

            if(sq*sq+sq<=val)ret++;

            if(sq*sq+2*sq<=val)ret++;

            return ret;
        }

        void solve()
        {
            printf("%lld\n",up_to(r)-up_to(l-1));
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