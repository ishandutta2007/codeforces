#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int n, m;
const int maxN = 1005;
int a[maxN];
vector < pair < int, int > > all[maxN];
const int SZ = 64;
int state_now[SZ];
int f[4][4];
int trans[4][SZ][SZ];
int trans_all[SZ][SZ];
vector < int > who[SZ];
int new_state[SZ];
int moves[40][SZ][SZ];
vector < int > hs[4][SZ];
vector < int > solve(int x) {
    int len = a[x];
    all[x].emplace_back(len + 1, -1);
    vector < pair < int, int > > need;
    vector < int > clrs(4, -1);
    for (auto it : all[x]) {
        if (it.first <= 3) {
            clrs[it.first] = it.second;
        }
        else {
            need.emplace_back(it);
        }
    }
    sort(need.begin(), need.end());
    memset(state_now, 0, sizeof state_now);
    state_now[0] = 1;
    for (int it = 0; it <= min(a[x] - 1, 2); it++) {
        memset(new_state, 0, sizeof new_state);
        for (int clr = 1; clr <= 3; clr++) {
            if (clrs[it + 1] != -1 && clrs[it + 1] != clr) continue;
            for (int i = 0; i < SZ; i++) {
                int c[3];
                c[0] = i & 3;
                c[1] = (i >> 2) & 3;
                c[2] = (i >> 4) & 3;
                set < int > s;
                for (int move = 1; move <= 3; move++) {
                    if (f[clr][move] == 0 || it + 1 - move <= 0) continue;
                    s.insert(c[3 - move]);
                }
                int gr = 0;
                while (s.find(gr) != s.end()) gr++;
                int ni = (i >> 2) + gr * 16;
                new_state[ni] = sum(new_state[ni], state_now[i]);
            }
        }
        for (int j = 0; j < 64; j++) state_now[j] = new_state[j];
    }
    int cur_pos = min(a[x], 3);
    for (int j = 0; j < need.size(); j++) {
        assert(cur_pos < need[j].first);
        int t = need[j].first - cur_pos - 1;
        for (int p = 0; (1 << p) <= t; p++) {
            if (t & (1 << p)) {
                memset(new_state, 0, sizeof new_state);
                for (int k = 0; k < SZ; k++) {
                    for (int r = 0; r < SZ; r++) {
                        new_state[k] = sum(new_state[k], mult(moves[p][k][r], state_now[r]));
                    }
                }
                for (int k = 0; k < SZ; k++) state_now[k] = new_state[k];
            }
        }
        cur_pos = need[j].first - 1;
        if (need[j].first <= len) {
            cur_pos++;
            for (int clr = 1; clr <= 3; clr++) {
                if (clr != need[j].second) {
                    continue;
                }
                memset(new_state, 0, sizeof new_state);
                for (int ni = 0; ni < SZ; ni++) {
                    for (int v : hs[clr][ni]) {
                        new_state[ni] = sum(new_state[ni],  state_now[v]);
                    }
                }
                for (int ni = 0; ni < SZ; ni++) state_now[ni] = new_state[ni];
            }
        }
    }
    vector < int > total(4, 0);
    for (int i = 0; i < SZ; i++) {
        int who = (i >> 4) & 3;
        total[who] = sum(total[who], state_now[i]);
    }
    return total;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        all[x].emplace_back(y, z);
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> f[i][j];
        }
    }

    for (int clr = 1; clr <= 3; clr++) {
        for (int i = 0; i < SZ; i++) {
            int c[3];
            c[0] = i & 3;
            c[1] = (i >> 2) & 3;
            c[2] = (i >> 4) & 3;
            set < int > s;
            for (int move = 1; move <= 3; move++) {
                if (f[clr][move] == 0) continue;
                s.insert(c[3 - move]);
            }
            int gr = 0;
            while (s.find(gr) != s.end()) gr++;
            int ni = (i >> 2) + gr * 16;
            trans[clr][ni][i] = sum(trans[clr][ni][i], 1);
            trans_all[ni][i] = sum(trans_all[ni][i], 1);
            hs[clr][ni].push_back(i);
            who[ni].push_back(i);
        }
    }
    for (int j = 0; j < SZ; j++) {
        for (int k = 0; k < SZ; k++) {
            moves[0][j][k] = trans_all[j][k];
        }
    }
    for (int i = 0; i + 1 < 35; i++) {
        for (int j = 0; j < SZ; j++) {
            for (int k = 0; k < SZ; k++) {
                for (int p = 0; p < SZ; p++) {
                    moves[i + 1][j][p] = sum(moves[i + 1][j][p], mult(moves[i][j][k], moves[i][k][p]));
                }
            }
        }
    }


    vector < int > cur(4);
    cur[0] = 1;
    for (int i = 1; i <= n; i++) {
        auto now = solve(i);
        vector < int > ncur(4, 0);
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                ncur[j ^ k] = sum(ncur[j ^ k], mult(cur[j], now[k]));
            }
        }
        cur = ncur;
    }
    cout << cur[0];
    return 0;
}