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
typedef bitset<maxN> bs;
int a[maxN][5];
int w[maxN];
int b[maxN][5];
int new_w[maxN];
vector<int> who[5 * maxN];
int cnt[5 * maxN];
int mt[5 * maxN];
const int BUBEN = 1000;
bs hl[BUBEN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    const int INF = 2e9 + 228;
    vector<pair<int,int>> t;
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            vals.emplace_back(a[i][j]);
        }
        cin >> w[i];
        t.emplace_back(w[i], i);
    }
    sort(t.begin(), t.end());
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int sz = 0;

    for (auto& it : t) {
        new_w[sz] = it.first;
        for (int j = 0; j < m; j++) {
            b[sz][j] = lower_bound(vals.begin(), vals.end(), a[it.second][j]) - vals.begin();
            cnt[b[sz][j]]++;
            who[b[sz][j]].emplace_back(sz);
        }
        sz++;
    }
    assert(sz == n);
    vector<pair<int,int>> best;
    for (int i = 0; i < vals.size(); i++) {
        best.emplace_back(cnt[i], i);
    }
    sort(best.begin(), best.end());
    reverse(best.begin(), best.end());
    if (best.size() > BUBEN) best.resize(BUBEN);
    memset(mt, -1, sizeof mt);
    int c = 0;
    for (auto& it : best) {
        mt[it.second] = c;
        hl[c] = 0;
        for (auto& id : who[it.second]) {
            hl[c][id] = true;
        }
        c++;
    }
    assert(c <= BUBEN);
    bs prep;
    for (int i = 0; i < n; i++) {
        prep[i] = 1;
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        bs cur = 0;
        for (int j = 0; j < m; j++) {
            if (mt[b[i][j]] == -1) {
                for (int z : who[b[i][j]]) cur[z] = 1;
            }
            else {
                cur |= hl[mt[b[i][j]]];
//                if (hl[mt[j]][0] == 1) cout << " ? " << endl;
            }
        }
        int bit = (prep ^ cur)._Find_first();
//        cout << i << " " << bit << endl;
        if (bit < n) ans = min(ans, new_w[bit] + new_w[i]);
    }
    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}