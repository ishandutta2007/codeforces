#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return (a + b);
}
const int maxN = 3 * (int)1e5 + 100;
int n, m;
ll x[maxN], p[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    ll d = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        d = gcd(x[i] - x[1], d);
    }
    for (int i = 1; i <= m; i++) {
        ll p;
        cin >> p;
        if (d % p == 0) {
            cout << "YES" << '\n' << x[1] << " " << i;
            return 0;
        }
    }
    cout << "NO";
    return 0;
}