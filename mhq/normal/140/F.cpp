#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, k;
const int maxN = 2 * (int)1e5 + 100;
int x[maxN], y[maxN];
bool ok[maxN];
bool ok2[maxN];
set < pair < int, int > > s;
void check(int a, int b) {
    memset(ok, 0, sizeof ok);
    int r = n;
    for (int i = 1; i <= n; i++) {
        if (make_pair(x[i] + x[r], y[i] + y[r]) < make_pair(a, b)) continue;
        if (i > r) break;
        while (r >= 1 && make_pair(x[i] + x[r], y[i] + y[r]) >= make_pair(a, b)) r--; r++;
    //    if (i > r) break;
      //  if (x[i] + x[r] > a) continue;
     //   cout << "now " << i << " " << r << '\n';
      //  while (r >= 1 && (x[i] + x[r] == a && y[i] + y[r] >= b)) r--; r++;
        if (y[i] + y[r] == b && x[i] + x[r] == a && r <= n) {
            ok[i] = true;
            ok[r] = true;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (ok[i]) sum++;
    }
    if (sum >= n - k) {
        s.insert(make_pair(a, b));
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(228);
   // freopen("input.txt", "r", stdin);
    cin >> n >> k;
    vector < pair < int, int > > all(n);
    for (auto& t : all) cin >> t.first >> t.second;
    sort(all.begin(), all.end());
    for (int i = 1; i <= n; i++) {
        x[i] = all[i - 1].first;
        y[i] = all[i - 1].second;
    }
    if (k >= n) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= min(n, k + 3); i++) {
        for (int j = max(i, n - k - 2); j <= n; j++) {
            check(x[i] + x[j], y[i] + y[j]);
        }
    }
    cout << s.size() << '\n';
    for (auto it : s) {
        cout << fixed << setprecision(10) << 1.0 * it.first / 2 << " " << 1.0 * it.second / 2 << '\n';
    }
    return 0;
}