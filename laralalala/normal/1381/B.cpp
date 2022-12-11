#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(4e3+5)

int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,a;
        cin >> n;
        vector<int> ps;
        int ini=0;
        int ma=0;
        for(int i=0;i<2*n;i++)
        {
            cin >> a;
            if(a>ma)
            {
                ma=a;
                ps.push_back(i);
            }
        }
        ps.push_back(2*n);
        dp[0]=1;
        for(int i=1;i<ps.size();i++)
        {
            int w=ps[i]-ps[i-1];
            for(int j=MAXN-1;j>=w;j--)
                dp[j]|=dp[j-w];
        }
        if(dp[n])
            db("YES")
        else
            db("NO")
        for(int i=0;i<MAXN;i++)
            dp[i]=0;
    }

    return 0;
}
/**
6
2
2 3 1 4
2
3 1 2 4
4
3 2 6 1 5 7 8 4
3
1 2 3 4 5 6
4
6 1 3 7 4 5 8 2
6
4 3 2 5 1 11 9 12 8 6 10 7
**/