#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, INF = 1e9 + 5;

int n, m;

int size[N];
vector<pair<int, int> > spojna[N];
int rep[N];

int find(int w) {
    return w == rep[w] ? w : rep[w] = find(rep[w]);
}

void Union(int a, int b) {
    size[b] += size[a];
    rep[a] = b;
}

int main() {

    scanf("%d %d", &n, &m);

    int tab[n + 1][m + 1];
    int nextInRow[n + 1][m + 1];
    int nextInCol[n + 1][m + 1];
    int id[n + 1][m + 1];
    int dist[n + 1][m + 1];
    int deg[n + 1][m + 1];
    queue<pair<int, int> > Q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &tab[i][j]);
            id[i][j] = (i - 1) * m + j - 1;
            rep[id[i][j]] = id[i][j];
            size[id[i][j]] = 1;
            deg[i][j] = 0;
        }
    }


    for (int i = 1; i <= n; i++) {
        vector<pair<int, int> > pom;
        for (int j = 1; j <= m; j++) {
            pom.push_back({tab[i][j], j});
        }
        sort(pom.begin(), pom.end());
        int last = -1;
        for (int j = pom.size() - 1; j >= 0; j--) {
            if (j == pom.size() - 1 || pom[j].first < pom[j+ 1].first) {
                last = (j == pom.size() - 1 ? -1 : pom[j + 1].second);
            } else {
                Union(find(rep[id[i][pom[j].second]]), find(rep[id[i][pom[j + 1].second]]));
            }
            nextInRow[i][pom[j].second] = last;
            if (last != -1) {

                deg[i][last]++;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        vector<pair<int, int> > pom;
        for (int j = 1; j <= n; j++) {
            pom.push_back({tab[j][i], j});
        }
        sort(pom.begin(), pom.end());
        int last = -1;
        for (int j = pom.size() - 1; j >= 0; j--) {
            if (j == pom.size() - 1 || pom[j].first < pom[j + 1].first) {
                last = (j == pom.size() - 1 ? -1 : pom[j + 1].second);
            } else {
                Union(find(rep[id[pom[j].second][i]]), find(rep[id[pom[j + 1].second][i]]));
            }
            nextInCol[pom[j].second][i] = last;
            if (last != -1) {

                deg[last][i]++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        size[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            spojna[find(id[i][j])].push_back({i, j});
            size[find(id[i][j])]++;
            dist[i][j] = 0;
            if (deg[i][j] == 0) {
                Q.push({i, j});
            }
        }
    }
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        int r = find(rep[id[x][y]]);
        size[r]--;
        if (size[r] == 0) {
            int xp = x;
            int yp = y;
            int mx = 0;

            for (int i = 0; i < spojna[r].size(); i++) {
                mx = max(mx, dist[spojna[r][i].first][spojna[r][i].second]);
            }
            for (int i = 0; i < spojna[r].size(); i++) {
                int x = spojna[r][i].first;
                int y = spojna[r][i].second;
                dist[x][y] = mx;
                if (nextInCol[x][y] != -1) {
                    deg[nextInCol[x][y]][y]--;
                    dist[nextInCol[x][y]][y] = max(dist[nextInCol[x][y]][y], dist[x][y] + 1);
                    if (deg[nextInCol[x][y]][y] == 0) {
                        Q.push({nextInCol[x][y], y});
                    }
                }
                if (nextInRow[x][y] != -1) {
                    deg[x][nextInRow[x][y]]--;
                    dist[x][nextInRow[x][y]] = max(dist[x][nextInRow[x][y]], dist[x][y] + 1);
                    if (deg[x][nextInRow[x][y]] == 0) {
                        Q.push({x, nextInRow[x][y]});
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", dist[i][j] + 1);
        }
        printf("\n");
    }

    return 0;
}