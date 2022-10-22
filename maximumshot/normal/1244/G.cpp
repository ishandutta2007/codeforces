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

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll k;

    cin >> n >> k;

//    mt19937_64 rnd(time(NULL));
//
//    n = rnd() % 1000 + 1;
//    k = rnd() % (1ll * n * n);

    if (k < 1ll * n * (n + 1) / 2) {
        cout << "-1\n";
        return 0;
    }

    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        mx += max(i, n - i + 1);
    }

    k = min(k, mx);

    cout << k << "\n";

    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << "\n";

    vector<int> p(n + 1);
    vector<int> used(n + 1);

    ll cur = 0;
    int i = 0;

    while (i < n) {
        int x = i + 1;
        int y = n - i;
        if (cur + max(x, y) + (i + 1 < n ? 1ll * (i + 2 + n) * (n - i - 1) / 2 : 0ll) <= k) {
            p[x] = y;
            used[y] = 1;
            cur += max(x, y);
            i++;
            continue;
        }
        ll can = k - cur - (i + 1 < n ? 1ll * (i + 2 + n) * (n - i - 1) / 2 : 0ll);
        assert(can >= x);
        p[x] = can;
        used[can] = 1;
        i += 2;
        y = 1;
        for (int j = i; j <= n; j++) {
            while (used[y]) y++;
            p[j] = y;
            y++;
        }
        break;
    }

    ll cost = 0;

    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
        cost += max(i, p[i]);
    }
    cout << "\n";

    assert(cost == k);

    return 0;
}