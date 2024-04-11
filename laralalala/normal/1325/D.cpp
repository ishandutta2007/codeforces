#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll u,v;
    cin >> u >> v;
    if(u>v)
        db("-1")
    else
    {
        ll r=v-u;
        if(r&1)
            db(-1)
        else
        {
            ll x=r/2;
            if(!x && !u)
            {
                db(0)
            }
            else if(!x)
            {
                db(1)
                db(u)
            }
            else if(u&x)
            {
                db(3)
                cout << u << ' ' << x << ' ' << x << '\n';
            }
            else
            {
                db(2)
                cout << x+u << ' ' << x << '\n';
            }
        }
    }

    return 0;
}