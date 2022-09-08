#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = 2e5 + 10;
vector<int> bal[maxN];
int he[maxN];
int go(int l, int r) {
    if (l > r) return 0;
    assert(he[r] == he[l] - 1);
    int k = he[l] - 1;
    int pos = lower_bound(bal[k].begin(), bal[k].end(), l) - bal[k].begin();
    int cmp = 1;
    int cur = l;
    for (int q = pos; ; q++) {
        cmp += go(cur + 1, bal[k][q] - 1);
        if (bal[k][q] == r) break;
        cur = bal[k][q] + 1;
    }
    return cmp;
}
void solve() {
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i <= 2 * n; i++) {
        bal[i].clear();
    }
    int cur = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '(') cur++;
        else cur--;
        he[i + 1] = cur;
        bal[cur].emplace_back(i + 1);
    }
    cout << go(1, 2 * n) << '\n';

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