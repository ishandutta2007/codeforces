#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,m,t,a,b,mini=1e9,quicksum;

int main()
{
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld",&n);
        quicksum=0;
        mini=1e15;
        vector<pair<long long,long long>> v;
        for(j=0;j<n;j++)
        {
            scanf("%lld%lld",&a,&b);
            v.push_back(pair<long long, long long>(a,b));
            if(j>=1)
            {
                quicksum+=a-min(a,v[j-1].second);
                if(min(a,v[j-1].second) < mini)
                {
                    mini=min(a,v[j-1].second);
                }
            }

        }
        quicksum+=v[0].first-min(v[0].first,v[n-1].second);
        if(min(v[0].first,v[n-1].second) < mini)
        {
            mini=min(v[0].first,v[n-1].second);
        }
        cout<<quicksum+mini<<"\n";
    }
}