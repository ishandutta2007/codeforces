#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int LIM = (int)1e9 + 1;
const int maxN = 75 * 1000 + 10;
int from[3][maxN], to[3][maxN], k[3][maxN], b[3][maxN];
vector < pair < int, pair < ll, ll > > > all[4 * maxN];
void build(int v, int tl, int tr) {
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        build(v + v, tl, tm);
        build(v + v + 1, tm + 1, tr);
    }
    vector < int > all_cords;
    for (int j = tl; j <= tr; j++) {
        for (int k = 0; k < 3; k++) {
            all_cords.push_back(from[k][j]);
        }
    }
    all_cords.push_back(LIM);
    sort(all_cords.begin(), all_cords.end());
    all_cords.erase(unique(all_cords.begin(), all_cords.end()), all_cords.end());
    int k = all_cords.size();
    all[v].resize(k - 1);
    for (int i = 0; i < (k - 1); i++) {
        all[v][i].first = all_cords[i + 1];
    }
    for (int j = tl; j <= tr; j++) {
        for (int it = 0; it < 3; it++) {
            int l = from[it][j];
            int r = to[it][j];
            int idL = lower_bound(all_cords.begin(), all_cords.end(), l) - all_cords.begin();
            int idR = lower_bound(all_cords.begin(), all_cords.end(), r) - all_cords.begin();
            all[v][idL].second.first += ::k[it][j];
            if (idR < all[v].size()) {
                all[v][idR].second.first -= ::k[it][j];
            }
            all[v][idL].second.second += ::b[it][j];
            if (idR < all[v].size()) {
                all[v][idR].second.second -= ::b[it][j];
            }
        }
    }
    for (int i = 1; i < all[v].size(); i++) {
        all[v][i].second.first += all[v][i - 1].second.first;
        all[v][i].second.second += all[v][i - 1].second.second;
    }
}
const ll INF = (ll)1e18;
ll get(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        auto it = lower_bound(all[v].begin(), all[v].end(), make_pair(x, make_pair(-INF, -INF))) - all[v].begin();
        return (all[v][it].second.second + (1LL * x * all[v][it].second.first));
    }
    int tm = (tl + tr) / 2;
    return get(v + v, tl, tm, l, min(tm, r), x) + get(v + v + 1, tm + 1, tr, max(tm + 1, l), r, x);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        from[0][i] = -1;
        cin >> to[0][i];
        from[1][i] = to[0][i];
        k[0][i] = 0;
        cin >> to[1][i];
        from[2][i] = to[1][i];
        to[2][i] = LIM;
        cin >> b[0][i];
        cin >> k[1][i] >> b[1][i];
        cin >> b[2][i];
        k[2][i] = 0;
    }
    build(1, 1, n);
    ll last = 0;
    int mod = 1000 * 1000 * 1000;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        x = (int)((x + last) % mod);
        last = get(1, 1, n, l, r, x);
        cout << last << '\n';
    }
    return 0;
}