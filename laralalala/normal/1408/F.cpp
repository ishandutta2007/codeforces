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
#define MAXN (ll)(2e5+5)

void solve(int p,int l,vector<pii>& r)
{
    int po=2;
    while(po<=l)
    {
        for(int i=p;i<p+l;i+=po)
            for(int j=0;j<po/2;j++)
                r.push_back(pii(i+j,i+po/2+j));
        po*=2;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> res;
    vector<int> bs;
    for(int i=14;i>=0;i--)
        if(n&(1<<i))
            bs.push_back((1<<i));

    int ac=1;
    for(auto y : bs)
    {
        solve(ac,y,res);
        ac+=y;
    }
    if(bs.size()>2)
    {
        vector<int> pos;
        for(int i=0;i<bs.back();i++)
            pos.push_back(n-i);
        int ap=1;
        int last=n-bs.back();
        for(int i=bs.size()-2;i>=1;i--)
        {
            while(pos.size()<bs[i])
            {
                int ini=ap;
                for(int i=0;i<pos.size();i++)
                {
                    res.push_back(pii(ap,pos[i]));
                    ap++;
                }
                for(int i=ini;i<ap;i++)
                    pos.push_back(i);
            }
            int ini=last;
            for(auto y : pos)
            {
                res.push_back(pii(y,last));
                last--;
            }

            for(int i=last+1;i<=ini;i++)
                pos.push_back(i);
        }
    }

    db(res.size())
    for(auto y : res)
        cout << y.f << ' ' << y.s << '\n';

    return 0;
}