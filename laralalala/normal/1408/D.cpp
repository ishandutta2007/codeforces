#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

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
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

int xyn[MAXN][2];
int xym[MAXN][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> add(1e6+5);
    for(int i=0;i<n;i++)
        cin >> xyn[i][0] >> xyn[i][1];
    for(int i=0;i<m;i++)
        cin >> xym[i][0] >> xym[i][1];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int x1=xyn[i][0];
            int y1=xyn[i][1];
            int x2=xym[j][0];
            int y2=xym[j][1];
            if(x1>x2 || y1>y2)
                continue;
            int dx=x2-x1;
            add[dx]=max(add[dx],y2-y1+1);
        }

    for(int i=1e6+3;i>=0;i--)
        add[i]=max(add[i],add[i+1]);

    int res=1e6+5;
    for(int i=0;i<1e6+5;i++)
    {
//        if(i<=10)
//            cout << i << ' ' << add[i] << '\n';
        res=min(res,i+add[i]);
    }
    db(res)

    return 0;
}