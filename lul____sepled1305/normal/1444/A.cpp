/**Ogiso Setsuna**/
#include<bits/stdc++.h>
using namespace std;
using pii = pair<long long,long long>;
int T;

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
    {
        long long p,q,x = 1,i;
        cin>>p>>q;
        if(p%q != 0)
        {
            cout<<p<<endl;
            continue;
        }
        else
        {
            vector<pii> divisor;
            long long Q = q, P  = p;
            for(i=2;i*i <= Q; i++)
            {
                if(q%i == 0)
                {
                    long long cur = 0;
                    while(q%i==0)
                    {
                        cur++;
                        q/=i;
                    }
                    divisor.push_back({i,cur});
                }
            }
            if(q > 1)
                divisor.push_back({q,1});

            for(auto it: divisor)
            {
                long long prime = it.first;
                long long powe = it.second;
                p = P;
                long long cur = 0;
                while(p%prime == 0)
                {
                    cur++;
                    p/=prime;
                }
                long long left = cur-powe+1;
                long long here = 1;
                for(i=0;i<left;i++)
                    here*=prime;
                x = max(x,P/here);
            }
            cout<<x<<endl;
        }
    }
    return 0;
}