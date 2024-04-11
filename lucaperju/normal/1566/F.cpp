#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
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
*/
long long v[200005];
struct ura
{
    long long a,b;
};
vector<ura>segs;
bool cmp (ura a, ura b)
{
    if(a.a==b.a)
        return a.b>b.b;
    return a.a<b.a;
}
vector<ura> v1[200005];
bool isbetter (ura a, ura b)
{
    if(b.a<=a.a && a.b<=b.b)
        return true;
    return false;
}
long long dp[200005][2]; /// 0 = i+1-th point is doubling left, 1 = i+1-th point is doubling right
/// min cost to solve all segs < i including the ones between i and i+1
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,n,m,j,k,q;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        segs.clear();
        for(i=1;i<=m;++i)
        {
            int a,b;
            cin>>a>>b;
            int k=0;
            int pas=(1<<19);
            while(pas)
            {
                if(k+pas<=n && v[k+pas]<=b)
                    k+=pas;
                pas>>=1;
            }
            if(k==0 || v[k]<a)
                segs.push_back({a,b});
        }
        sort(segs.begin(),segs.end(),cmp);
        for(i=0;i<=n;++i)
        {
            v1[i].clear();
            dp[i][0]=dp[i][1]=0;
        }
        int pzc=0;
        for(i=0;i<segs.size();++i)
        {
          //  cout<<"!"<<segs[i].a<<'\n';
            while(pzc<n && segs[i].a>v[pzc+1])
                ++pzc;
            while(v1[pzc].size() && isbetter(segs[i],v1[pzc].back()))
                v1[pzc].pop_back();
            v1[pzc].push_back(segs[i]);
        }
        v[0]=-10000000000LL;
        v[n+1]=10000000000LL;
        if(v1[0].size()==0)
        {
            dp[0][0]=dp[0][1]=0;
        }
        else
        {
            dp[0][0]=2LL*(v[1]-v1[0][0].b);
            dp[0][1]=(v[1]-v1[0][0].b);
        }
        for(i=1;i<=n;++i)
        {
            if(v1[i].size()==0)
            {
                dp[i][0]=dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
                continue;
            }
            /// left -> right
            /// 0 -> 1
            long long sc=(v[i+1]-v1[i][0].b)*1LL;
            for(j=0;j<v1[i].size();++j)
            {
                long long vlc=(v1[i][j].a-v[i])*1LL;
                if(j<v1[i].size()-1)
                    vlc=vlc+(v[i+1]-v1[i][j+1].b)*1LL;
                sc=min(sc,vlc);
            }
            dp[i][1]=dp[i-1][0]+sc;
            /// 1 -> 1
            sc=(v[i+1]-v1[i][0].b)*1LL;
            for(j=0;j<v1[i].size();++j)
            {
                long long vlc=(v1[i][j].a-v[i])*2LL;
                if(j<v1[i].size()-1)
                    vlc=vlc+(v[i+1]-v1[i][j+1].b)*1LL;
                sc=min(sc,vlc);
            }
            dp[i][1]=min(dp[i][1],dp[i-1][1]+sc);
            ///------
            sc=(v[i+1]-v1[i][0].b)*2LL;
            for(j=0;j<v1[i].size();++j)
            {
                long long vlc=(v1[i][j].a-v[i])*1LL;
                if(j<v1[i].size()-1)
                    vlc=vlc+(v[i+1]-v1[i][j+1].b)*2LL;
                sc=min(sc,vlc);
            }
            dp[i][0]=dp[i-1][0]+sc;
            /// 1 -> 0
            sc=(v[i+1]-v1[i][0].b)*2LL;
            for(j=0;j<v1[i].size();++j)
            {
                long long vlc=(v1[i][j].a-v[i])*2LL;
                if(j<v1[i].size()-1)
                    vlc=vlc+(v[i+1]-v1[i][j+1].b)*2LL;
                sc=min(sc,vlc);
            }
            dp[i][0]=min(dp[i][0],dp[i-1][1]+sc);
        }
        cout<<min(dp[n][0],dp[n][1])<<'\n';
    }
    return 0;
}