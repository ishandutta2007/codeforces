#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 5e5 + 10;
int n;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n;
        int s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s += a[i];
        }
        if (s % 2 != 0) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> vals;
        for (int i = 1; i <= n; i++) {
            if (a[i] != 0) {
                vals.emplace_back(i);
            }
        }
        if (vals.empty()) {
            cout << 1 << "\n" << 1 << " " << n << '\n';
            continue;
        }
        assert(vals.size() % 2 == 0);
        vector<int> ps;
        if (vals[0] != 1) {
            ps.emplace_back(1);
        }
        for (int i = 0; i < vals.size(); i += 2) {
            ps.emplace_back(vals[i]);
            if (a[vals[i]] == a[vals[i + 1]]) {
                if (vals[i] + 1 != vals[i + 1]) {
                    ps.emplace_back(vals[i + 1] - 1);
                }
            }
            else {
                ps.emplace_back(vals[i + 1]);
            }
        }
        ps.emplace_back(n + 1);
        cout << ps.size() - 1 << '\n';
        for (int i = 0; i + 1 < ps.size(); i++) {
            cout << ps[i] << " " << ps[i + 1] - 1 << '\n';
        }

    }

    return 0;
}