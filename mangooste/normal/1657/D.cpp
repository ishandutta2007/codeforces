#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, max_c;
    cin >> n >> max_c;
    vector<ll> best(max_c + 1, -1);
    for (int i = 0; i < n; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        best[x] = max(best[x], y * z);
    }

    for (int i = 1; i <= max_c; i++) {
        if (best[i] == -1) continue;
        for (int j = i + i; j <= max_c; j += i) {
            best[j] = max(best[j], best[i] * (j / i));
        }
    }
    for (int i = 1; i <= max_c; i++) {
        best[i] = max(best[i], best[i - 1]);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        x *= y;
        int pos = upper_bound(all(best), x) - best.begin();
        if (pos == max_c + 1) pos = -1;
        cout << pos << " \n"[i == m - 1];
    }
}