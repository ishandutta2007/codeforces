#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1e5 + 10;
vector<int> x[maxN];
vector<int> y[maxN];
ll solve(vector<int>& t) {
    sort(t.begin(), t.end());
    int cnt = t.size();
    ll f = 0;
    for (int i = 0; i + 1 < t.size(); i++) {
        f += (1LL * t[i + 1] - t[i]) * (1LL * i + 1) * (1LL * cnt - i - 1);
    }
    return f;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int c;
            cin >> c;
            x[c].emplace_back(i);
            y[c].emplace_back(j);
        }
    }
    ll ans = 0;
    for (int i = 1; i < maxN; i++) {
        if (!x[i].empty()) {
            ans += solve(x[i]);
        }
        if (!y[i].empty()) {
            ans += solve(y[i]);
        }
    }
    cout << ans << '\n';
    return 0;
}