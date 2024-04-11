#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

int dp[MAXN];
int xy[MAXN][2];
int t[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r,n;
    cin >> r >> n;
    for(int i=1;i<=n;i++)
        cin >> t[i] >> xy[i][0] >> xy[i][1];

    xy[0][0]=1;
    xy[0][1]=1;
    int ma_prev=-1;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        int x=xy[i][0];
        int y=xy[i][1];
        for(int j=1;j<=min(i,1000);j++)
            if((j==i || dp[i-j]) && t[i]-t[i-j]>=abs(x-xy[i-j][0])+abs(y-xy[i-j][1]))
                dp[i]=max(dp[i-j]+1,dp[i]);
        dp[i]=max(ma_prev+1,dp[i]);
        if(i>=1000)
            ma_prev=max(ma_prev,dp[i-1000]);
        res=max(res,dp[i]);
//        cout << i << ' ' << dp[i] << '\n';
    }
    db(res)

    return 0;
}