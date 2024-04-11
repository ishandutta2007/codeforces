#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, m, q;
const int maxN = 305;
int a[maxN][maxN];
const int maxQ = 2 * (int)1e6 + 100;
int x[maxQ], y[maxQ], c[maxQ];

struct query{
    int x, y, id;
    query(int _x, int _y, int _id) : x(_x), y(_y), id(_id) {}
};

vector < query > add[maxQ];
vector < query > del[maxQ];
int p[maxN * maxN];
int TOT_SZ = 0;
mt19937 rnd(228);
int get(int a) {
    if (a == p[a]) return a;
    return p[a] = get(p[a]);
}
void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (rnd() & 1) swap(a, b);
    TOT_SZ--;
    p[a] = b;
}
int id[maxN][maxN];
int delta[maxQ];
int last[maxN][maxN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> q;
    //n = 1; m = 1; q = 2e6;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            id[i][j] = (i - 1) * m + j;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            add[0].emplace_back(query(i, j, 0));
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> x[i] >> y[i] >> c[i];
        //x[i] = 1;
        //y[i] = 1;
        //c[i] = i;
        if (a[x[i]][y[i]] == c[i]) continue;
        add[c[i]].emplace_back(query(x[i], y[i], i));
        del[a[x[i]][y[i]]].emplace_back(query(x[i], y[i], i));
        a[x[i]][y[i]] = c[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            last[i][j] = a[i][j];
        }
    }
    memset(a, -1, sizeof a);
    for (int i = 0; i < maxQ; i++) {
        if (add[i].empty() && del[i].empty()) continue;
        vector < pair < int, int  > > verts;
        for (auto& it : add[i]) {
            verts.emplace_back(it.x, it.y);
        }
        for (auto& it : del[i]) {
            verts.emplace_back(it.x, it.y);
        }
        sort(verts.begin(), verts.end());
        verts.erase(unique(verts.begin(), verts.end()), verts.end());
        for (auto it : verts) {
            a[it.first][it.second] = -1;
        }
        TOT_SZ = 0;
        for (int pp = 0; pp < add[i].size(); pp++) {
            TOT_SZ++;
            int x = add[i][pp].x;
            int y = add[i][pp].y;
            p[id[x][y]] = id[x][y];
            a[x][y] = 0;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (a[nx][ny] != -1) unite(id[x][y], id[nx][ny]);
            }
            if (pp != add[i].size() - 1) {
                delta[add[i][pp].id] += TOT_SZ;
                delta[add[i][pp + 1].id] -= TOT_SZ;
            }
            else {
                delta[add[i][pp].id] += TOT_SZ;
                if (!del[i].empty()) {
                    delta[del[i][0].id] -= TOT_SZ;
                }
            }
        }
        TOT_SZ = 0;
        for (auto it : verts) {
            a[it.first][it.second] = -1;
            p[id[it.first][it.second]] = id[it.first][it.second];
            if (last[it.first][it.second] == i) {
                TOT_SZ++;
                a[it.first][it.second] = 0;
            }
        }
        for (auto it : verts) {
            int x = it.first;
            int y = it.second;
            if (last[x][y] == i) {
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                    if (a[nx][ny] != -1) unite(id[x][y], id[nx][ny]);
                }
            }
        }
        if (!del[i].empty()) {
            delta[del[i].back().id] += TOT_SZ;
        }
        for (int it = (int)del[i].size() - 1; it >= 0; it--) {
            int x = del[i][it].x;
            int y = del[i][it].y;
            a[x][y] = 0;
            p[id[x][y]] = id[x][y];
            TOT_SZ++;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (a[nx][ny] != -1) unite(id[x][y], id[nx][ny]);
            }
            if (it != 0) {
                delta[del[i][it - 1].id] += TOT_SZ;
                delta[del[i][it].id] -= TOT_SZ;
            }
        }
        for (auto it : verts) a[it.first][it.second] = -1;
    }
    int cur = 0;
    for (int i = 0; i <= q; i++) {
        cur += delta[i];
        if (i) cout << cur << '\n';
    }
    return 0;
}