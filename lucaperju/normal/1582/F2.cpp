#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
//*
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
}
/*/
//vector<int>active[5001];
int nrop1=0,nrop2=0;
int active[5001][8200];
int cat[5001];
int dp[8200];
void update (int pz, int val)
{
    ++nrop2;
    for(int i=val+1;i<=min(5000,dp[pz]);++i)
    {
        //active[i].push_back(pz);
        active[i][++cat[i]]=pz;
        ++nrop1;
    }
    dp[pz]=min(dp[pz],val); /// fk me
}
/// 8192
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,q,t,i,j,k,a;
    cin>>n;
    //n=1000000;
    for(i=0;i<8192;++i)
        dp[i]=10000;
    dp[0]=0;
    for(i=1;i<=5000;++i)
    {
        //active[i].push_back(0);
        active[i][++cat[i]]=0;
    }
    for(i=1;i<=n;++i)
    {
        cin>>a;
        //a=(rand()^rand())%5001;
        //for(j=0;j<active[a].size();++j)
        //    update(active[a][j]^a,a);
        //active[a].clear();
        for(j=1;j<=cat[a];++j)
            update(active[a][j]^a,a);
        cat[a]=0;
    }
    vector<int>rz;
    for(j=0;j<8192;++j)
        if(dp[j]!=10000)
            rz.push_back(j);
    cout<<rz.size()<<'\n';
    for(i=0;i<rz.size();++i)
        cout<<rz[i]<<' ';
   // cout<<'\n'<<nrop1<<' '<<nrop2<<'\n';
}