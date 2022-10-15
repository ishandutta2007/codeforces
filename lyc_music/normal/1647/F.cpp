//~~
#define setI(x) freopen(x,"r",stdin)
#define setO(x) freopen(x,"w",stdout)
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 500005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,tp,tp1,sta[N],sta1[N],a[N];
int nowtr[N];
int dp[N],dp1[N];
int ans;
int vis[N];
int nxt[N];
int gtans()
{
    int ans=0;
    int mx=0,mxx=0;
    for (int i=1;i<=n;i++)
    {
        vis[i]=0;nowtr[i]=0;
        if (a[i]>mx) mx=a[i],mxx=i;
    }
    int sufmx=0;
    tp=0;
    for (int i=n;i>mxx;i--)
    {
        if (max(sufmx,a[i])!=a[i])
        {
            if (sta[tp]>a[i]) return 0;
            sta[++tp]=a[i];
        }
        sufmx=max(sufmx,a[i]);
    }
    memset(dp,0x3f,sizeof(dp));
    memset(dp1,-0x3f,sizeof(dp1));
    dp[mxx]=sta[tp];
    dp1[mxx]=-inf;
    for (int i=mxx-1;i>=1;i--)
    {
        if (a[i]<a[i+1])
        {
            dp[i]=min(dp[i+1],dp[i]);
        }
        {
            if (a[i]<dp1[i+1])
            {
                dp[i]=min(dp[i],a[i+1]);
            }
        }

        if (a[i]>a[i+1])
        {
            dp1[i]=max(dp1[i],dp1[i+1]);
        }
        {
            if (a[i]>dp[i+1])
            {
                dp1[i]=max(dp1[i],a[i+1]);
            }
        }
        // cout<<i<<","<<" "<<dp[i]<<" "<<dp1[i]<<" "<<sta[tp]<<endl;
    }
    tp1=0;
    int premx=0;
    for (int i=1;i<mxx;i++)
    {
        premx=max(premx,a[i]);
        if (premx!=a[i])
        {
            if (a[i]<sta1[tp1]) break;
            sta1[++tp1]=a[i];
            if (a[i]>a[i+1]&&premx<dp1[i+1]) ans++;
            else
            {
                if (premx<a[i+1]&&a[i]>dp[i+1]) ans++;
            }
        } else
        {
            if (a[i]>a[i+1]&&sta1[tp1]<=dp1[i+1]) ans++;
            else
            {
                if (sta1[tp1]<=a[i+1]&&a[i]>dp[i+1]) ans++;
            }
        }
        // cout<<"?"<<i<<" "<<ans<<" "<<a[i]<<" "<<dp[i+1]<<endl;
    }
    return ans;
}
void BellaKira()
{
    n=read();
    for (int i=1;i<=n;i++)
    {
        a[i]=read();
    }
    ans+=gtans();
    reverse(a+1,a+n+1);
    ans+=gtans();
    writeln(ans);
}
signed main()
{
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}
/*

*/