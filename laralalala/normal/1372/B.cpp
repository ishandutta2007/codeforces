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
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
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
#define MAXN (ll)(2e3+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll>divs;
        for(ll i=1;i*i<=n;i++)
        {
            if(n%i)
                continue;
            if(i*i!=n)
                divs.push_back(n/i);
            divs.push_back(i);
        }
        vector<pip> pos;
        for(auto y : divs)
        {
            if(y==n)
                continue;
            ll a=y;
            ll b=n-y;
            pos.push_back(pip(n-y,pii(a,b)));
        }
        sort(all(pos));
        cout<< pos[0].s.f << ' ' << pos[0].s.s << '\n';
    }

    return 0;
}