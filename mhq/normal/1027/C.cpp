#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = (int)1e4 + 10;
int tst;
int cnt[maxN];
void solve() {
    int n;
    cin >> n;
    vector < int > g;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        g.push_back(x);
    }
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    vector < int > ng;
    ll opta = 1e9;
    ll optb = 1;
    for (int i : g) {
        if (cnt[i] >= 2) {
            ng.push_back(i);
        }
        if (cnt[i] >= 4) {
            opta = i;
            optb = i;
        }
    }
    for (int i = 0; i + 1 < ng.size(); i++) {
        int na = ng[i + 1];
        int nb = ng[i];
        if (cnt[ng[i]] >= 4) {
            opta = ng[i];
            optb = ng[i];
        }
        if (na * optb < nb * opta) {
            opta = na;
            optb = nb;
        }
    }
    for (int i = 0; i < 2; i++) cout << opta << " " << optb << " ";
    cout << '\n';
    for (int i : g) cnt[i] = 0;
}
int main() {
    ios_base::sync_with_stdio(false);
   //freopen("input.txt", "r", stdin);
   cin >> tst;
   while (tst--) solve();
    return 0;
}