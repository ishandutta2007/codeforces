#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = 5e5 + 10;
int b[maxN];
int p[maxN];
vector<int> ev[maxN];
int r[maxN];
void solve() {
    cin >> n;
    for (int i = 1; i <= n + 1; i++) {
        ev[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        int L = 1;
        int R = n;
        if (b[i] > 0) {
            R = min(R, i / b[i]);
        }
        L = max(L, (i + b[i] + 1) / (b[i] + 1));
        assert(L <= R);
        r[i] = R;

        ev[L].emplace_back(i);
    }
    set<pair<int,int>> s;
    for (int i = 1; i <= n; i++) {
        for (auto& it : ev[i]) {
            if (it > 0) {
                s.insert(make_pair(r[it], it));
            }
        }
        assert(!s.empty());
        p[(s.begin() -> second)] = i;
        s.erase(s.begin());
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}