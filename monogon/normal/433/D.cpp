
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// for each pixel, store how far it extends in the four directions so that all are lit
// 2 * (n + m) * q + n * m complexity

const int N = 1005;
int n, m, q, a[N][N], dir[4][N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool inbounds(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void upd(int x, int y, int d) {
    if(a[x][y] == 0) {
        dir[d][x][y] = 0;
    }else {
        int xx = x + dx[d];
        int yy = y + dy[d];
        dir[d][x][y] = (inbounds(xx, yy) ? 1 + dir[d][xx][yy] : 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }
    rep(i, 0, n) rep(j, 0, m) {
        upd(i, j, 2);
        upd(i, j, 3);
    }
    for(int i = n - 1; i >= 0; i--) for(int j = m - 1; j >= 0; j--) {
        upd(i, j, 0);
        upd(i, j, 1);
    }
    while(q--) {
        int ty, x, y;
        cin >> ty >> x >> y;
        x--; y--;
        if(ty == 1) {
            a[x][y] = !a[x][y];
            rep(i, x, n) upd(i, y, 3);
            for(int i = x; i >= 0; i--) upd(i, y, 1);
            rep(j, y, m) upd(x, j, 2);
            for(int j = y; j >= 0; j--) upd(x, j, 0);
        }else {
            int best = 0;
            rep(d, 0, 4) {
                int dd = (d + 1) % 4;
                int xl = x, yl = y, xr = x, yr = y;
                for(int h = N; h > 0; h--) {
                    while(inbounds(xl, yl) && dir[d][xl][yl] >= h) {
                        xl -= dx[dd];
                        yl -= dy[dd];
                    }
                    while(inbounds(xr, yr) && dir[d][xr][yr] >= h) {
                        xr += dx[dd];
                        yr += dy[dd];
                    }
                    if(xl == xr && yl == yr) continue;
                    int w = max(abs(yr - yl) - 1, abs(xr - xl) - 1);
                    best = max(best, w * h);
                }
            }
            cout << best << '\n';
        }
    }
}