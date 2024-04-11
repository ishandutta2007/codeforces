#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, ii> iiii;

const int Maxn = 2005;

int T;
int n, m;
char B[Maxn][Maxn];
ii nxt[Maxn][Maxn];
vector <ii> tome[Maxn][Maxn];
int tk[Maxn][Maxn];
int res[Maxn][Maxn];
vector <ii> Q;

void Loop(ii v)
{
    vector <ii> seq;
    while (!tk[v.first][v.second]) {
        seq.push_back(v);
        tk[v.first][v.second] = seq.size();
        v = nxt[v.first][v.second];
    }
    int from = tk[v.first][v.second] - 1;
    for (int i = from; i < seq.size(); i++)
        res[seq[i].first][seq[i].second] = int(seq.size()) - from;
    for (int i = from; i < seq.size(); i++) {
        ii v = seq[i];
        for (int j = 0; j < tome[v.first][v.second].size(); j++) {
            ii u = tome[v.first][v.second][j];
            if (!res[u.first][u.second]) {
                res[u.first][u.second] = int(seq.size()) - from + 1;
                Q.push_back(u);
            }
        }
    }
    for (int i = 0; i < seq.size(); i++)
        tk[seq[i].first][seq[i].second] = 0;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tome[i][j].clear();
        Q.clear();
        for (int i = 0; i < n; i++) {
            scanf("%s", B[i]);
            fill(res[i], res[i] + m, 0);
            for (int j = 0; j < m; j++) {
                if (B[i][j] == 'L') nxt[i][j] = ii(i, j - 1);
                else if (B[i][j] == 'R') nxt[i][j] = ii(i, j + 1);
                else if (B[i][j] == 'U') nxt[i][j] = ii(i - 1, j);
                else nxt[i][j] = ii(i + 1, j);
                if (0 <= nxt[i][j].first && nxt[i][j].first < n && 0 <= nxt[i][j].second && nxt[i][j].second < m)
                    tome[nxt[i][j].first][nxt[i][j].second].push_back(ii(i, j));
                else {
                    res[i][j] = 1;
                    Q.push_back(ii(i, j));
                }
            }
        }
        int best = 0, br, bc;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                while (!Q.empty()) {
                    ii v = Q.back(); Q.pop_back();
                    for (int i = 0; i < tome[v.first][v.second].size(); i++) {
                        ii u = tome[v.first][v.second][i];
                        if (!res[u.first][u.second]) {
                            res[u.first][u.second] = res[v.first][v.second] + 1;
                            Q.push_back(u);
                        }
                    }
                }
                if (!res[i][j])
                    Loop(ii(i, j));
                while (!Q.empty()) {
                    ii v = Q.back(); Q.pop_back();
                    for (int i = 0; i < tome[v.first][v.second].size(); i++) {
                        ii u = tome[v.first][v.second][i];
                        if (!res[u.first][u.second]) {
                            res[u.first][u.second] = res[v.first][v.second] + 1;
                            Q.push_back(u);
                        }
                    }
                }             
                if (res[i][j] > best) {
                    best = res[i][j];
                    br = i + 1;
                    bc = j + 1;
                }
            }
        printf("%d %d %d\n", br, bc, best);
    }
    return 0;
}