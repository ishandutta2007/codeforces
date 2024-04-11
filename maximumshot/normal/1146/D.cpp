#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int X = 1e6 + 5;

int used[X];
int dp[X];

ll gcd(ll a, ll b) {
    return !a ? b : gcd(b % a, a);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, a, b;

    cin >> m >> a >> b;

    int cur = 0;

    set<int> q;
    q.insert(0);

    used[0] = 1;
    dp[0] = 0;

    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        cur = max(cur, v);
        if (v - b >= 0 && !used[v - b]) {
            used[v - b] = 1;
            dp[v - b] = cur;
            q.insert(v - b);
        }
        if (v + a < X && v + a <= m && !used[v + a]) {
            used[v + a] = 1;
            dp[v + a] = max(cur, v + a);
            q.insert(v + a);
        }
    }

    ll res = 0;

    for (int x = 0; x <= m && x < X; x++) {
        if (used[x] && dp[x] <= m) {
            res += m - dp[x] + 1;
//            cout << x << " : " << dp[x] << "\n";
        }
    }

    ll g = gcd(a, b);

    ll k1 = (X / g);

    while (k1 * g < X) k1++;

    ll k2 = m / g;

//    cout << g << " ?\n";

    if (k1 <= k2) {
        res += (m + 1) * (k2 - k1 + 1);
        res -= g * (k1 + k2) * (k2 - k1 + 1) / 2;
    }

    cout << res << "\n";

    return 0;
}