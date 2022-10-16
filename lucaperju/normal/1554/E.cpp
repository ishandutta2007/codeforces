#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
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
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(long long i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
const int mod = 998244353;
vector<int>v[100005];
long long dp[100005][2];
long long rzi[100005],n,rzf[100005];
void dfs (int pz, int t, int val)
{
    if(val==1)
    {
        dp[pz][0]=1;
        for(int i=0;i<v[pz].size();++i)
        {
            if(v[pz][i]==t)
                continue;
            dfs(v[pz][i],pz,val);
            dp[pz][0]=dp[pz][0]*2LL%mod*1LL*dp[v[pz][i]][0]%mod;
        }
    }
    else
    {
        int cnt=0;
        long long rzc=1;
        for(int i=0;i<v[pz].size();++i)
        {
            if(v[pz][i]==t)
                continue;
            dfs(v[pz][i],pz,val);
            if(dp[v[pz][i]][0] != 0)
                rzc=rzc*1LL*dp[v[pz][i]][0]%mod,++cnt;
            else if(dp[v[pz][i]][1] != 0)
                rzc=rzc*1LL*dp[v[pz][i]][1]%mod;
            else
                rzc=0;
        }
        dp[pz][0]=dp[pz][1]=0;
        if(cnt%val==0)
            dp[pz][0]=rzc;
        if((cnt+1)%val==0)
            dp[pz][1]=rzc;
    }
}
long long solve (int val)
{
    dfs(1,-1,val);
    return dp[1][0];
}
int parity[100005];
int eok[100005];
vector<int>divisors;
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,i,j,k,m;
    for(i=2;i*i<=100000;++i)
        for(int j=i*i;j<=100000;j+=i*i)
            eok[j]=1;
    for(i=2;i<=100000;++i)
    {
        if(parity[i]==0)
            for(j=i;j<=100000;j+=i)
                parity[j]++;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            rzi[i]=0;
            rzf[i]=0;
        }
        for(i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        divisors.clear();
        for(i=1;i<n;++i)
            if((n-1)%i==0)
            {
                divisors.push_back(i);
                rzi[i]=solve(i);
            }
        //for(i=1;i<=n;++i)
        //    cout<<rzi[i]<<' ';
        for(i=0;i<divisors.size();++i)
            for(j=i;j<divisors.size();++j)
            {
                if(divisors[j]%divisors[i] || eok[divisors[j]/divisors[i]])
                    continue;
                if(parity[divisors[j]/divisors[i]]%2==0)
                    rzf[divisors[i]]=(rzf[divisors[i]]+rzi[divisors[j]])%mod;
                else
                    rzf[divisors[i]]=(rzf[divisors[i]]-rzi[divisors[j]]+mod)%mod;
            }
        for(i=1;i<=n;++i)
            cout<<rzf[i]<<' ';
        cout<<'\n';
    }
    return 0;
}