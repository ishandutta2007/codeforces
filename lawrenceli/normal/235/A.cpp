#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) { return a*b/gcd(a, b); }

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    int n; cin >> n;
    ll ans = 0;
    if (n <= 10) {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                for (int k=1; k<=n; k++)
                    ans = max(ans, lcm(lcm(i, j), k));
        cout << ans << endl;
    } else {
        if (n%2) cout << lcm(lcm(n, n-1), n-2) << endl;
        else {
            ans = lcm(lcm(n-1, n-2), n-3);
            ans = max(ans, lcm(lcm(n, n-1), n-3));
            ans = max(ans, lcm(lcm(n, n-1), n-4));
            cout << ans << endl;
        }
    }
}