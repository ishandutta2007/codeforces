#include<bits/stdc++.h>
#define ld long double
#define tset puts("qwq");
#define test puts("QAQ");
#define pb push_back
#define pii pair<ll,ll> 
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define int long long
#define R(i,a,b) for(int i=(a),i##E=(b);i<=i##E;i++)
#define L(i,a,b) for(int i=(b),i##E=(a);i>=i##E;i--)
#define clr(f,n) memset((f),0,sizeof((f)[0])*(n))
#define cpy(f,g,n) memcpy((f),(g),sizeof((g)[0])*(n))
template <typename T> bool ckmax(T &x, T y) { return x<y?x=y,true:false;}
template <typename T> bool ckmin(T &x, T y) { return x>y?x=y,true:false;}
using namespace std;
//const ll inf=0x7f7f7f7f7f7f7f3f;
const ll inf=1e18;

//const int inf=0x7f7f7f7f;
//const int mod=1e9+7;
const double Pi=acos(-1);
const int mod=998244353;
const double eps=1e-6;
inline int fpow(int a,int b=mod-2,int p=mod){a%=p;int res=1;while(b){if(b&1)res=1ll*res*a%p;a=1ll*a*a%p;b>>=1;}return res;}
inline ll read()
{
    char c=getchar();ll x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;
    return x;
}

inline void write(int x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(int x){write(x),putchar(' ');}
inline void writeln(int x){write(x);putchar('\n');}
int a[222222],dp[222222];
int n,m;
signed main()
{
    //ios_base::sync_with_stdio(0); 
    //cin.tie(0); 
    //cout.tie(0);
    int _;
    cin>>_;
    for(;_--;)
    {
        std::vector<pair<ll,ll> >v;
        cin>>n>>m;
        R(i,1,n) cin>>a[i];
        sort(a+1,a+n+1);
        a[0]=-inf,a[n+1]=inf;
        R(i,1,m)
        {
            int x,y;
            cin>>x>>y;
            v.pb({x,y});
        }
        sort(v.begin(),v.end());
        R(i,1,m) dp[i]=inf;

        R(i,1,n)
        {
            int pos=lower_bound(v.begin(),v.end(),pair<ll,ll>{a[i]+1,-inf})-v.begin();
            int t=0,tt=dp[pos],ttt=inf;
            L(j,1,pos) 
            {
                if(v[j-1].fi<a[i-1]) break;
                ckmax(t,a[i]-v[j-1].se);
                ckmin(dp[pos],dp[j-1]+t);
                ckmin(tt,dp[j-1]+2ll*t);
                ckmin(ttt,dp[j-1]+t);
             //   printf("1:t:%lld dp[pos]:%lld tt:%lld ttt:%lld\n",t,dp[pos],tt,ttt);
            }   
            R(j,pos+1,m) 
            {
                if(v[j-1].fi>a[i+1]) break;
                ll tw=(v[j-1].fi-a[i]);
                ckmin(dp[j],tw+tt);
                ckmin(dp[j],2ll*tw+ttt);    
               // printf("2:dp[j]:%lld\n",dp[j]);
            }
        }
        cout<<dp[m]<<'\n';
    }
}