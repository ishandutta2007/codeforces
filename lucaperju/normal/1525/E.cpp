#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int lgput (int x, int exp)
{
    int rz=1;
    while(exp)
    {
        if(exp&1)
        {
            exp^=1;
            rz=rz*1LL*x%mod;
        }
        else
        {
            exp>>=1;
            x=x*1LL*x%mod;
        }
    }
    return rz;
}
int fct[21];
vector<int>v[50003];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,i,j,k,m;
    cin>>n>>m;
    fct[0]=fct[1]=1;
    for(i=2;i<=n;++i)
        fct[i]=i*1LL*fct[i-1]%mod;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            int x;
            cin>>x;
            v[j].push_back(x);
        }
    long long rz=0;
    for(i=1;i<=m;++i)
    {
        long long sc=1;
        sort(v[i].begin(),v[i].end());
        for(j=0;j<v[i].size();++j)
            sc=sc*1LL*(v[i][j]-j-1)%mod;
        sc=(fct[n]-sc+mod)%mod;;
        rz=(rz+sc)%mod;
    }
    cout<<rz*1LL*lgput(fct[n],mod-2)%mod;
}