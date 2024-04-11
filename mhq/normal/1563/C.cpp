#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2028;
int p[maxN];
int n;
int OP = 0;
vector<int> ans;
int pos[maxN];
int orig_n;
void do_rev(int pref) {
    ans.emplace_back(pref);
    assert(pref % 2 == 1);
    reverse(p + 1, p + pref + 1);
    for (int i = 1; i <= orig_n; i++) {
        pos[p[i]] = i;
    }
}
void solve() {
    ans.clear();
    cin >> n;
    orig_n = n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2 != p[i] % 2) {
            cout << -1 << '\n';
            return;
        }
    }
    while (n > 1) {
        int where = pos[n];
        if (where != 1) do_rev(where);
        if (pos[n - 1] != 2) {
            int c = pos[n - 1];
            do_rev(c - 1);
            assert(pos[n] == c - 1);
            do_rev(c + 1);
            assert(pos[n] == 3 && pos[n - 1] == 2);
            do_rev(3);
        }
        assert(pos[n] == 1 && pos[n - 1] == 2);
        do_rev(n);
        n -= 2;
    }
    assert((int)ans.size() * 2 <= 5 * orig_n);
    for (int i = 1; i <= orig_n; i++) {
        assert(p[i] == i);
    }
    cout << ans.size() << '\n';
    for (int u : ans) {
        cout << u << " ";
    }
    cout << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}