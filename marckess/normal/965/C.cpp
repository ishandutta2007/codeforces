#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll n, k, m, d, lim = 1e18;

ll vuel (ll x) {
    if (x > lim / k)
        return 1;
    return n / (k * x) + bool(n % (k * x) >= x);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k >> m >> d;
    
    ll res = 0, mx = m;
    while (1) {
        ll act = vuel(mx);
        if (act > d) break;
        
        ll i = 1, j = mx, rep = 64;
        res = max(res, mx * act);
        
        while (rep--) {
            ll m = (i+j)/2;
            if (vuel(m) == act) j = m;
            else i = m;
        }
        
        mx = j-1;
        if (mx < 1) break;
    }
    
    cout << res << endl;

    return 0;
}