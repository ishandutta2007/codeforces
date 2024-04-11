#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll l, r, x, y, res = 0;
set<ll> dv;

ll gcd (ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> l >> r >> x >> y;

    for (ll i = 1; i * i <= y; i++) {
        if (y % i == 0) {
            if (l <= i && i <= r)
                dv.insert(i);
            if (l <= y / i && y / i <= r)
                dv.insert(y/i);
        }
    }

    for (ll a : dv) {
        for (ll b : dv) {
            ll d = gcd(a, b);
            if (d == x && a * b / d == y)
                res++;
        }
    }

    cout << res << endl;

    return 0;
}