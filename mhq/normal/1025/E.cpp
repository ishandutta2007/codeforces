#include <bits/stdc++.h>

using namespace std;
const int maxN = 55;
const int INF = (int)1e9;
int n, m;
int x[maxN], y[maxN];
int finX[maxN], finY[maxN];
bool empt[maxN][maxN];
vector < pair < int, int > > from, to;
int dist[maxN][maxN];
const int BUBEN = 228;
pair < int, int > prv[maxN][maxN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool valid(int x, int y) {
    return (x >= 1 && y >= 1 && x <= n && y <= n);
}
bool go(int i, int toX, int toY) {
    int stX = x[i];
    int stY = y[i];
    queue < pair < int, int > > q;
    memset(dist, -1, sizeof dist);
    dist[stX][stY] = 0;
    prv[stX][stY] = make_pair(-1, -1);
    q.push(make_pair(stX, stY));
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (!valid(nx, ny)) continue;
            if (!empt[nx][ny]) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            prv[nx][ny] = make_pair(x, y);
            q.push({nx, ny});
        }
    }
    if (dist[toX][toY] == -1) return false;
    vector < pair < int, int > > f1, to1;
    int curX = toX;
    int curY = toY;
    while (curX != x[i] || curY != y[i]) {
        pair < int, int > before = prv[curX][curY];
        f1.push_back(before);
        to1.push_back({curX, curY});
        curX = before.first;
        curY = before.second;
    }
    reverse(f1.begin(), f1.end());
    reverse(to1.begin(), to1.end());
    for (int i = 0; i < f1.size(); i++) from.push_back(f1[i]);
    for (int i = 0; i < to1.size(); i++) to.push_back(to1[i]);
    empt[x[i]][y[i]] = true;
    empt[toX][toY] = false;
    x[i] = toX;
    y[i] = toY;
    return true;
}
int can(int i, int tox, int toy) {
    memset(dist, -1, sizeof dist);
    queue < pair < int, int > > q;
    dist[x[i]][y[i]] = 0;
    q.push(make_pair(tox, toy));
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (!valid(nx, ny)) continue;
            if (!empt[nx][ny]) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    if (dist[tox][toy] == -1) return INF;
    else return dist[tox][toy];
}
bool cmp(int i, int j) {
    return finY[i] < finY[j];
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)  {
        for (int j = 1; j <= n; j++) {
            empt[i][j] = true;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
        empt[x[i]][y[i]] = false;
    }
    for (int i = 1; i <= m; i++) {
        cin >> finX[i] >> finY[i];
    }
    int row = (n + 1) / 2;
    while (1) {
        bool ok = true;
        for (int j = 1; j <= m; j++) {
            if (x[j] != row) ok = false;
        }
        if (ok) break;
        for (int i = 1; i <= n; i++) {
            if (!empt[row][i]) continue;
            memset(dist, -1, sizeof dist);
            queue < pair < int, int > > q;
            dist[row][i] = 0;
            int posX = -1;
            int posY = -1;
            q.push(make_pair(row, i));
            while (!q.empty()) {
                if (posX != -1) break;
                auto t = q.front();
                q.pop();
                int x = t.first;
                int y = t.second;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (!valid(nx, ny)) continue;
                    if (!empt[nx][ny] && (nx != row)) {
                        posX = nx;
                        posY = ny;
                        break;
                    }
                    if (!empt[nx][ny]) continue;
                    if (dist[nx][ny] == -1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
            for (int j = 1; j <= m; j++) {
                if (x[j] == posX && y[j] == posY) {
                    assert(go(j, row, i));
                    break;
                }
            }
            break;
        }
    }
    vector < int > all;
    for (int i = 1; i <= m; i++) all.push_back(i);
    sort(all.begin(), all.end(), cmp);
    for (int i = 0; i < m; i++) {
        int i1 = all[i];
        vector < pair < int, int > > px;
        for (int j = 1; j <= m; j++) {
            px.push_back(make_pair(y[j], j));
        }
        sort(px.begin(), px.end());
        int j1 = px[i].second;
        if (j1 == i1) continue;
        int prvY = y[i1];
        assert(go(i1, min(n, row + 2), min(n, y[i1] + 2)));
        int nY = y[j1];
        assert(go(j1, row, prvY));
        assert(go(i1, row, nY));
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (y[i] < y[j] && finY[i] > finY[j]) {
                assert(0);
            }
        }
    }
    for (int i = 1; i <= row - 2; i++) {
        for (int j = 1; j <= n; j++) {
            for (int ind = 1; ind <= m; ind++) {
                if (finX[ind] == i && finY[ind] == j) {
                    go(ind, i, j);
                }
            }
        }
    }
    for (int i = n; i >= row + 2; i--) {
        for (int j = 1; j <= n; j++) {
            for (int ind = 1; ind <= m; ind++) {
                if (finX[ind] == i && finY[ind] == j) {
                    go(ind, i, j);
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (x[i] != finX[i] || y[i] != finY[i]) {
            go(i, finX[i], y[i]);
        }
    }
    for (int iter = 1; iter <= m; iter++) {
        for (int i = 1; i <= m; i++) {
            if (x[i] != finX[i] || y[i] != finY[i]) {
                bool ok = true;
                for (int j = 1; j <= m; j++) {
                    if (j == i) continue;
                    if (x[j] == x[i]) {
                        if (y[j] >= min(y[i], finY[i]) && y[j] <= max(y[i], finY[i])) ok = false;
                    }
                }
                if (ok) go(i, finX[i], finY[i]);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (x[i] != finX[i] || y[i] != finY[i]) {
            for (int j = 1; j <= m; j++) {
                if (abs(finX[j] - row) <= 1) cout << x[j] << " " << y[j] << " " << finX[j] << " " << finY[j] << endl;
            }
        }
    }
    // assert(from.size() <= 10800);
    cout << from.size() << '\n';
    for (int i = 0; i < from.size(); i++) {
        cout << from[i].first << " " << from[i].second << " " << to[i].first << " " << to[i].second << '\n';
    }
    return 0;
}