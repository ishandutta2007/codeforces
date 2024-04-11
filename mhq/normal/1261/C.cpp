#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
vector < vector < char > > a;
vector < vector < char > > bck;
const int maxN = (int)1e6 + 100;
int x[maxN], y[maxN];
vector < vector < int > > dist;
vector < vector < int > > ndist;
bool check(int mid) {
    //queue < pair < int, int > > q;
    int topQ = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bck[i][j] = '.';
            dist[i][j] = -1;
            ndist[i][j] = -1;
            if (a[i][j] == '.') {
                dist[i][j] = 0;
                x[topQ] = i;
                y[topQ] = j;
                topQ++;
            }
        }
    }
    for (int i = 0; i < topQ; i++) {
        int xx = x[i];
        int yy = y[i];
        for (int a = -1; a <= 1; a++) {
            for (int b = -1; b <= 1; b++) {
                int nx = xx + a;
                int ny = yy + b;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[xx][yy] + 1;
                    x[topQ] = nx;
                    y[topQ] = ny;
                    topQ++;
                }
            }
        }
    }
    topQ = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] > mid || dist[i][j] == -1) {
                if (i - mid < 0 || i + mid >= n || j - mid < 0 || j + mid >= m) continue;
                ndist[i][j] = 0;
                bck[i][j] = 'X';
                x[topQ] = i;
                y[topQ] = j;
                topQ++;
            }
        }
    }
    for (int i = 0; i < topQ; i++) {
        int xx = x[i];
        int yy = y[i];
        for (int a = -1; a <= 1; a++) {
            for (int b = -1; b <= 1; b++) {
                int nx = xx + a;
                int ny = yy + b;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (ndist[nx][ny] == -1) {
                    ndist[nx][ny] = ndist[xx][yy] + 1;
                    x[topQ] = nx;
                    y[topQ] = ny;
                    topQ++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'X' && (ndist[i][j] == -1 || ndist[i][j] > mid)) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    a = vector < vector < char > > (n, vector < char >(m));
    bck = vector < vector < char > > (n, vector < char >(m));
    dist = vector < vector < int > > (n, vector < int >(m, -1));
    ndist = vector < vector < int > > (n, vector < int >(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int l = 0;
    int r = max(n, m) + 2;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        }
        else r = mid;
    }
    check(l);
    cout << l << '\n';
    for (auto& it : bck) {
        for (auto& c : it) cout << c;
        cout << '\n';
    }
    return 0;
}