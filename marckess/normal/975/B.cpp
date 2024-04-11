#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n;
vi a(15);

void shift () {
    int temp = a[0];
    for (int i = 0; i < n - 1; i++)
        a[i] = a[i+1];
    a[n-1] = temp;
}

ll techo (ll a, ll b) {
    return (a + b - 1) / b;
}

ll obtRes () {
    vi b = a;

    ll x = a[0], res = 0;

    if (x == 0)
        return 0;

    for (int i = 0; i < n - 1; i++) {
        if (x - i >= 0) {
            b[i+1] += techo(x - i, 14);
        }
    }

    if (x - 13 >= 0)
        b[0] = techo(x - 13, 14);

    for (int i = 0; i < 14; i++)
        if (b[i] % 2 == 0)
            res += b[i];

    return res;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    n = 14;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, obtRes());
        shift();
    }

    cout << res << endl;

    return 0;
}