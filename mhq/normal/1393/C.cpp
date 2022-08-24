#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int n;
int cnt[maxN];
int val[maxN];
vector < int > add[maxN];
bool check(int l) {
    set < pair < int, int > > s;
    for (int i = 1; i <= n; i++) add[i].clear();
    for (int i = 1; i <= n; i++) {
        val[i] = cnt[i];
        if (val[i]) {
            s.insert(make_pair(val[i], i));
            add[1].emplace_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int v : add[i]) {
            s.insert(make_pair(val[v], v));
        }
        if (s.empty()) return false;
        auto it = *(--s.end());
        int who = it.second;
        s.erase(it);
        val[who]--;
        if (val[who]) {
            if (i + l + 1 <= n) add[i + l + 1].emplace_back(who);
        }
    }
    return true;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int l = 0;
    int r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << '\n';
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