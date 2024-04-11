#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

ll gcd(ll& x, ll y) {
    return !x ? y : gcd(y % x, x);
}

ll f(ll x) {
    return x >= 0 ? x : -x;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    ll g = 0;
    for (int i = 1; i < n; i++)
        g = gcd(g, f(a[i] - a[i - 1]));

    for (int i = 0; i < m; i++)
        cout << gcd(g, a[0] + b[i]) << '\n';

    return 0;
}