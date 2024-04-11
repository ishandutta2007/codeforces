#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e5 + 100;
const int maxM = 41;
const int HALF = 20;
string f[maxN];
bool upd[maxN];
int n, m;
bool bad[maxM][maxM];
bool can[maxM][maxM];
void find_clique() {
    int half1 = (m / 2);
    int half2 = (m - (m / 2));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            can[i][j] = (!bad[i][j]);
            if (i == j) can[i][j] = true;
        }
    }
    vector < bool > good(1 << half2);
    vector < int > cover(1 << half2);
    good[0] = true;
    vector < int > calc(half2);
    for (int j = 0; j < half2; j++) {
        int bad_mask = 0;
        for (int i = 0; i < half1; i++) {
            if (!can[i][j + half1]) {
                calc[j] |= (1 << i);
            }
        }
    }
    int all = (1 << half1) - 1;
    vector < int > dp(1 << half1);
    vector < bool > is_good(1 << half1);
    is_good[0] = true;
    dp[0] = 0;
    for (int i = 1; i < (1 << half1); i++) {
        int lst = -1;
        int other_mask = -1;
        for (int j = 0; j < half1; j++) {
            if (i & (1 << j)) {
                other_mask = i ^ (1 << j);
                lst = j;
                break;
            }
        }
        if (!is_good[other_mask]) {
            is_good[i] = false;
            dp[i] = 0;
            continue;
        }
        int bt = 1;
        is_good[i] = true;
        for (int bit = 0; bit < half1; bit++) {
            if (other_mask & (1 << bit)) {
                bt++;
                if (!can[lst][bit]) {
                    is_good[i] = false;
                }
            }
        }
        if (is_good[i]) {
            dp[i] = bt;
        }
    }
    for (int bit = 0; bit < half1; bit++) {
        for (int mask = 0; mask < (1 << half1); mask++) {
            if (mask & (1 << bit)) continue;
            dp[mask ^ (1 << bit)] = max(dp[mask], dp[mask ^ (1 << bit)]);
        }
    }
    int ans = 0;
    for (int i = 1; i < (1 << half2); i++) {
        vector < int > bits;
        int other_mask = 0;
        for (int j = 0; j < half2; j++) {
            if (i & (1 << j)) {
                other_mask = (i ^ (1 << j));
                bits.push_back(j);
            }
        }
        if (!good[other_mask]) {
            good[i] = false;
            continue;
        }
        int lst = bits.back();
        good[i] = true;
        cover[i] = (cover[other_mask] | calc[lst]);
        for (int j = 0; j + 1 < bits.size(); j++) {
            if (!can[lst + half1][bits[j] + half1]) {
                good[i] = false;
                break;
            }
        }
        if (good[i]) {
            int inside = all ^ (cover[i]);
            ans = max(ans, dp[inside] + (int)bits.size());
        }
    }
    cout << ans << '\n';
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    vector < string > all;
    for (int i = 1; i <= n; i++) {
        char s;
        cin >> s;
        if (s == '1') {
            upd[i] = true;
        }
        else {
            cin >> f[i];
            all.push_back(f[i]);
        }
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    ll mask = 0;
    for (int i = 1; i <= n; i++) {
        if (upd[i]) {
            mask = 0;
        }
        else {
            int id = lower_bound(all.begin(), all.end(), f[i]) - all.begin();
            mask |= (1LL << id);
            for (int bit = 0; bit < m; bit++) {
                if (mask & (1LL << bit)) {
                    if (bit != id) {
                        bad[bit][id] = true;
                        bad[id][bit] = true;
                    }
                }
            }
        }
    }
    find_clique();
    return 0;
}