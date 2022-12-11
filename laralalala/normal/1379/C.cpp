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
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,m;
        cin >> n >> m;
        vector<pii> vp;
        vector<ll> xs;
        for(int i=0;i<m;i++)
        {
            ll x,y;
            cin >> x >> y;
            vp.push_back(pii(x,y));
            xs.push_back(x);
        }

        sort(allr(vp));
        sort(all(xs));

        vector<ll> ac(m+1);
        for(int i=0;i<m;i++)
            ac[i+1]=ac[i]+vp[i].f;
        ll res=ac[min(n,m)];
        for(int i=0;i<m;i++)
        {
            int p=lower_bound(all(xs),vp[i].s+1)-xs.begin();
            p=m-p;
            ll sum=ac[p];
            int cant=p;
            if(vp[i].f>vp[i].s)
            {
                sum-=vp[i].f;
                cant--;
            }
            sum+=vp[i].f;
            cant++;
//            cout << sum << ' ' << cant << '\n';
            if(cant>n)
                continue;
            sum+=(n-cant)*vp[i].s;
            res=max(res,sum);
        }
        db(res)
    }

    return 0;
}
/**
2
4 3
5 0
1 4
2 2

5 3
5 2
4 2
3 1
**/