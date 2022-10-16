#include <bits/stdc++.h>
using namespace std;
vector<int>v[100005];
long long val[100005],n;
long long dfsinit (int pz, int t)
{
    long long sz=1;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        sz+=dfsinit(v[pz][i],pz);
    }
    if(pz!=1)
        val[pz-1]=sz*1LL*(n-sz);
    return sz;
}
long long v2[60004];
bool cmp (long long a, long long b)
{
    return a>b;
}
const int mod=1000000007;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int i,j;
        cin>>n;
        for(i=1;i<=n;++i)
            v[i].clear();
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfsinit(1,-1);
        --n;
        sort(val+1,val+n+1,cmp);
        int m;
        cin>>m;
        for(i=1;i<=m;++i)
            cin>>v2[i];
        sort(v2+1,v2+m+1,cmp);
        long long rz=0;
        int pz=1;
        if(m>=n)
        {
            rz=1;
            while(m-pz+1>=n)
            {
                rz=(rz*1LL*v2[pz])%mod;
                ++pz;
            }
            rz=(rz*1LL*(val[1]%mod))%mod;
            for(i=2;pz<=m;++i,++pz)
            {
                rz=(rz+val[i]%mod*1LL*v2[pz]%mod)%mod;
            }
        }
        else
        {
            for(i=1;pz<=m;++i,++pz)
            {
                rz=(rz+val[i]%mod*1LL*v2[pz]%mod)%mod;
            }
        }
        for(;i<=n;++i)
            rz=(rz+val[i])%mod;
        cout<<rz<<'\n';
    }
}