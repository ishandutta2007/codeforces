#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

int y, x, b, n;
float m;
ll res = 0;

ll obtCB (ll x, ll y) {
    ll a1 = x * (x + 1) / 2;
    ll an = a1 + (x + 1) * y;
    return (y + 1) * (a1 + an) / 2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> m >> b;
    
    n = m * b;
    for (x = 0; x <= n; x++) {
        y = - x / m + b;
        res = max (res, obtCB(x, y));
    }

    cout << res << endl;

    return 0;
}