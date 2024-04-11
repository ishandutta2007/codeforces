#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long nextt[500005],nextequal[500005],nextnextt[500005],lastpz[500005],v[500005],cst[500005],dp[500005],b[500005],n,m,cstequal[500005],cstnextt[500005],sumneg[500005];
//map<int,long long>mp[500010];
vector <int> updequal[500005],updnext[500005];
long long aib[500005];
int prevv[500005];
long long lsb (int x)
{
    return x&-x;
}
void update (int x, long long val)
{
    int i,j;
    for(i=x;i<=500005;i+=lsb(i))
        aib[i]+=val;
}
long long query (int x)
{
    long long rz=0;
    int i,j;
    for(i=x;i>0;i-=lsb(i))
        rz+=aib[i];
    return rz;
}
long long dfs (int pz)
{
    if(pz==n+2)
        return 0;
    if(pz==n+1)
        return 10000000000000000LL;
    if(lastpz[pz]!=0)
        return dp[pz];
    lastpz[pz]=1;
    dp[pz]=min(cst[pz]+cstequal[pz]+dfs(nextequal[pz]),cstnextt[pz]+dfs(nextnextt[pz]));
    return dp[pz];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,mx=0,s=0,ok;
    long long k=0,t,d;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        lastpz[i]=n+1;
    }
    for(i=1;i<=n;++i)
    {
        cin>>cst[i];
        if(cst[i]<0)
            sumneg[i]+=cst[i];
        sumneg[i]+=sumneg[i-1];
    }
    for(i=n+1;i<=n+3;++i)
        sumneg[i]=sumneg[i-1];
    cin>>m;
    for(i=1;i<=m;++i)
    {
        cin>>b[i];
        nextt[b[i-1]]=b[i];
        prevv[b[i]]=b[i-1];
    }
    for(i=n;i>=1;--i)
    {
        nextequal[i]=lastpz[v[i]];
        nextnextt[i]=lastpz[nextt[v[i]]];
        if(nextnextt[i]==0)
            nextnextt[i]=n+1;
        if(nextequal[i]==0)
            nextequal[i]=n+1;
        if(nextt[v[i]]==0)
            nextnextt[i]=n+1;
        lastpz[v[i]]=i;
        if(v[i]==b[m])
            nextnextt[i]=n+2;
        cstequal[i]=sumneg[nextequal[i]-1]-sumneg[i]/**+query(nextequal[i],500000-v[i])-query(i-1,500000-v[i])*/;
        updequal[nextequal[i]-1].push_back(i);
        updequal[i].push_back(-i);
        cstnextt[i]=sumneg[nextnextt[i]-1]-sumneg[i]/**+query(nextnextt[i]-1,500000-v[i])-query(i-1,500000-v[i])*/;
        updnext[min(n,nextnextt[i]-1)].push_back(i);
        updnext[(i-1)].push_back(-i);
    }
    nextequal[0]=n+1;
    cstequal[0]=0;
    nextnextt[0]=lastpz[b[1]];
    if(nextnextt[i]==0)
        nextnextt[i]=n+1;
    cstnextt[0]=sumneg[nextnextt[0]-1];/**+query(nextnextt[0]-1,500000-v[i])*/;
    updnext[nextnextt[i]-1].push_back(i);
    for(i=1;i<=n;++i)
    {
        if(cst[i]>0)
        update(500001-v[i],cst[i]);
        for(j=0;j<updnext[i].size();++j)
        {
            int pz=updnext[i][j];
            if(pz<0)
            {
                cstnextt[-pz]-=query(500000-v[-pz]);
            }
            else
            {
                cstnextt[pz]+=query(500000-v[pz]);
            }
        }
        for(j=0;j<updequal[i].size();++j)
        {
            int pz=updequal[i][j];
            if(pz<0)
            {
                cstequal[-pz]-=query(500000-prevv[v[-pz]]);
            }
            else
            {
                cstequal[pz]+=query(500000-prevv[v[pz]]);
            }
        }
    }
    for(i=1;i<=n;++i)
        lastpz[i]=0;
    long long rz=dfs(0);
    if(rz>500000000000001LL)
        cout<<"NO";
    else
        cout<<"YES\n"<<rz;
    return 0;
}