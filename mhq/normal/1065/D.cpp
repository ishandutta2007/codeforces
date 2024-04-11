#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 12;
struct state{
    int x, y, type;
    state(int _x, int _y, int _type) {
        x = _x;
        y = _y;
        type = _type;
    }
};
// i, i -> 1
int n;
int a[maxN][maxN];
pair < int, int > dist[maxN][maxN][maxN][maxN][3][3];
pair < int, int > id[maxN * maxN];
const int INF = (int)1e9;
pair < int, int > val[10];
pair < int, int > sum(pair < int, int > a, pair < int, int > b) {
    return {a.first + b.first, a.second + b.second};
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            id[a[i][j]] = make_pair(i, j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 3; k++) {
                for (int ii = 1; ii <= n; ii++) {
                    for (int jj = 1; jj <= n; jj++) {
                        for (int kk = 0; kk < 3; kk++) {
                            dist[i][j][ii][jj][k][kk] = make_pair(INF, INF);
                        }
                    }
                }
                dist[i][j][i][j][k][k] = make_pair(0, 0);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int t1 = 0; t1 < 3; t1++) {
                for (int t2 = 0; t2 < 3; t2++) {
                    if (t1 == t2) continue;
                    dist[i][j][i][j][t1][t2] = make_pair(1, 1);
                    //g[i][j][t1].emplace_back(make_pair(state(i, j, t2), 1));
                }
            }
            int x = i;
            int y = j;
            for (int sx = -3; sx <= 3; sx++) {
                for (int sy = -3; sy <= 3; sy++) {
                    if (abs(sx) == 0 || abs(sx) == 3) continue;
                    if (abs(sy) == 0 || abs(sy) == 3) continue;
                    int nx = x + sx;
                    int ny = y + sy;
                    if (nx  < 1 || nx > n || ny < 1 || ny > n) continue;
                    if (abs(sx) + abs(sy) != 3) continue;
                    dist[i][j][nx][ny][0][0] = make_pair(1, 0);
                   // g[i][j][0].emplace_back(make_pair(state(i, j, 0), 0));
                }
            }
            for (int p = -1; p <= 1; p += 2) {
                for (int q = -1; q <= 1; q += 2) {
                    for (int sh = 1; sh <= n; sh++) {
                        int nx = x + p * sh;
                        int ny = y + q * sh;
                        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                        dist[i][j][nx][ny][1][1] = make_pair(1, 0);
                        //g[i][j][1].emplace_back(make_pair(state(i, j, 1), 0));
                    }
                }
            }
            for (int to = 1; to <= n; to++) {
                if (to != i) {
                    dist[i][j][to][j][2][2] = make_pair(1, 0);
                    //g[i][j][2].emplace_back(make_pair(state(to, j, 2), 0));
                }
                if (to != y) {
                    dist[i][j][i][to][2][2] = make_pair(1, 0);
                    //g[i][j][2].emplace_back(make_pair(state(i, to, 2), 0));
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 3; k++) {
                for (int fromi = 1; fromi <= n; fromi++) {
                    for (int fromj = 1; fromj <= n; fromj++) {
                        for (int fromk = 0; fromk < 3; fromk++) {
                            for (int toi = 1; toi <= n; toi++) {
                                for (int toj = 1; toj <= n; toj++) {
                                    for (int tok = 0; tok < 3; tok++) {
                                        if (i == fromi && j == fromj && k == fromk) continue;
                                        if (toi == i && toj == j && tok == k) continue;
                                        if (fromi == toi && fromj == toj && fromk == k) continue;
                                        pair < int, int > &t1 = dist[fromi][fromj][toi][toj][fromk][tok];
                                        pair < int, int > &t2 = dist[fromi][fromj][i][j][fromk][k];
                                        pair < int, int > &t3 = dist[i][j][toi][toj][k][tok];
                                        t1 = min(t1, make_pair(t2.first + t3.first, t2.second + t3.second));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i + 1 <= n * n; i++) {
        int fromi = id[i].first;
        int fromj = id[i].second;
        int toi = id[i + 1].first;
        int toj = id[i + 1].second;
        pair < int, int > nval[3];
        for (int k = 0; k < 3; k++) nval[k] = make_pair(INF, INF);
        for (int fromk = 0; fromk < 3; fromk++) {
            for (int tok = 0; tok < 3; tok++) {
                nval[tok] = min(nval[tok], sum(val[fromk], dist[fromi][fromj][toi][toj][fromk][tok]));
            }
        }
        for (int k = 0; k < 3; k++) val[k] = nval[k];
    }
    pair < int, int > mn = {INF, INF};
    for (int k = 0; k < 3; k++) mn = min(mn, val[k]);
    cout << mn.first << " " << mn.second;
    return 0;
}