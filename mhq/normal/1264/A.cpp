#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 4 * (int)1e5 + 100;
int p[maxN];
void solve() {
    cin >> n;
    vector < int > cuts;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i + 1 <= n; i++) {
        if (p[i] > p[i + 1]) {
            cuts.push_back(i);
        }
    }
    for (int i = (int)cuts.size() - 1; i >= 0; i--) {
        if (2 * cuts[i] > n) continue;
        int g = cuts[0];
        if (2 * g >= cuts[i]) continue;
        auto it = lower_bound(cuts.begin(), cuts.end(), 2 * g + 1) - cuts.begin();
        int s = cuts[it] - cuts[0];
        if (i == it) continue;
        int b = cuts[i] - cuts[it];
        if (b <= g) continue;
        cout << g << " " << s << " " << b << '\n';
        return;
    }
    cout << 0 << " " << 0 << " " << 0 << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}