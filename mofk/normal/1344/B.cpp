#include <bits/stdc++.h>

using namespace std;

int n, m;
string s[1005];
bool vis[1005][1005];
int r[1005], c[1005];

int nxt(int a, char c) {
    if (c == '.') return a + a % 2;
    return a + (1 - a % 2);
}

int checkrow(int i) {
    int state = 0;
    for (int j = 0; j < m; ++j) {
        state = nxt(state, s[i][j]);
    }
    return state;
}

int checkcol(int i) {
    int state = 0;
    for (int j = 0; j < n; ++j) {
        state = nxt(state, s[j][i]);
    }
    return state;
}

const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
pair <int, int> nxt(int x, int y, int dd) {
    return make_pair(x + dx[dd], y + dy[dd]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) r[i] = checkrow(i);
    for (int i = 0; i < m; ++i) c[i] = checkcol(i);
    for (int i = 0; i < n; ++i) if (r[i] >= 3) return cout << -1 << endl, 0;
    for (int i = 0; i < m; ++i) if (c[i] >= 3) return cout << -1 << endl, 0;
    bool fr = 0, fc = 0;
    for (int i = 0; i < n; ++i) if (r[i] == 0) fr = 1;
    for (int i = 0; i < m; ++i) if (c[i] == 0) fc = 1;
    if (fr != fc) return cout << -1 << endl, 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[i][j] == '#' && !vis[i][j]) {
        vis[i][j] = 1;
        ++ans;
        queue <pair <int, int> > q;
        q.push(make_pair(i, j));
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int t = 0; t < 4; ++t) {
                pair <int, int> v = nxt(x, y, t);
                if (!valid(v.first, v.second) || s[v.first][v.second] != '#' || vis[v.first][v.second]) continue;
                vis[v.first][v.second] = 1;
                q.push(v);
            }
        }
    }
    cout << ans << endl;
    return 0;
}