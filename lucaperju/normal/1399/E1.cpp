#include <bits/stdc++.h>
using namespace std;
vector<long long>v[200005];
vector<long long>cst[200005];
vector<long long>all;
long long sall;
long long dfs (long long pz, long long t)
{
    long long sc=0;
    if(v[pz].size()==1)
        ++sc;
    for(long long i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        long long vlc=dfs(v[pz][i],pz);
        long long cstc=cst[pz][i];
        sall+=cstc*1LL*vlc;
        while(cstc>0)
        {
            all.push_back(vlc*1LL*(cstc-cstc/2));
            cstc>>=1;
        }
        sc+=vlc;
    }
    return sc;
}
bool cmp (long long a, long long b)
{
    return a>b;
}
int main()
{
    long long t,n,s,m,i,j,x,y,k,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        sall=0;
        all.clear();
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            cst[i].clear();
        }
        for(i=1;i<n;++i)
        {
            long long a,b,c;
            cin>>a>>b>>c;
            v[a].push_back(b);
            v[b].push_back(a);
            cst[a].push_back(c);
            cst[b].push_back(c);
        }
        dfs(1,-1);
        sort(all.begin(),all.end(),cmp);
        int pz=0;
        while(sall>s)
            sall-=all[pz++];
        cout<<pz<<'\n';
    }
    return 0;
}