#include <bits/stdc++.h>

using namespace std;


const long long mod = 1000000007;
/*
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}*/
vector<int>v[200005];
int dst[200005];
int dp[2][200005];
int ord[200005];
bool cmp (int a, int b)
{
    return dst[a]<dst[b];
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,k,m,j=0,n,tt,s=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int x,y;
        cin>>x>>y;
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            dp[0][i]=dp[1][i]=0;
            dst[i]=0;
        }
        for(i=1;i<=m;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        queue<int>q;
        q.push(x);
        dst[x]=1;
        while(!q.empty())
        {
            int pz=q.front();
            q.pop();
            for(int i=0;i<v[pz].size();++i)
            {
                if(!dst[v[pz][i]])
                {
                    dst[v[pz][i]]=1+dst[pz];
                    q.push(v[pz][i]);
                }
            }
        }
        for(i=1;i<=n;++i)
            ord[i]=i;
        sort(ord+1,ord+n+1,cmp);
        dp[0][x]=1;
        dp[1][x]=0;
        for(i=1;i<=n;++i)
        {
            int ci=i;
            i=ord[i];
            for(j=0;j<v[i].size();++j)
            {
                if(dst[v[i][j]]<dst[i])
                    dp[0][i]=(dp[0][i]+dp[0][v[i][j]])%mod;
            }
            i=ci;
        }
        for(i=1;i<=n;++i)
        {
            int ci=i;
            i=ord[i];
            for(j=0;j<v[i].size();++j)
            {
                if(dst[v[i][j]]<dst[i])
                    dp[1][i]=(dp[1][i]+dp[1][v[i][j]])%mod;
                if(dst[v[i][j]]==dst[i])
                    dp[1][i]=(dp[1][i]+dp[0][v[i][j]])%mod;
            }
            i=ci;
        }
        cout<<(dp[1][y]+dp[0][y])%mod<<'\n';
    }
    return 0;
}