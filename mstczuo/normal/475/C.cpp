# include <iostream>
# include <cstdio>
# include <vector>
# include <cstring>
# include <algorithm>

using namespace std;
const int INF = 0x7fffffff;
char a[3200][3200];
int c[3200][3200];
int tot, sx, sy, n, m;

int get_w() {
    int w = 1;
    while(a[sx][sy+w] == 'X') ++w;
    return w;
}

int get_h() {
    int h = 1;
    while(a[sx+h][sy] == 'X') ++h;
    return h;
}

inline bool fill(int x,int y,int w,int h) {
    int xx = x + h - 1;
    int yy = y + w - 1;
    if(xx > n || yy > m) return false;
    return c[xx][yy] - c[xx][y-1] - c[x-1][yy] + c[x-1][y-1] == w*h;
}

int check(int w,int h) {
    if(!fill(sx, sy, w, h)) return INF;
    vector< pair<int,int> > tmp;
    int x = sx, y = sy, cnt = w * h;
    while(true) {
        bool dx = false, dy = false;
        if(x < n && fill(x + 1, y, w, h)) dx = true;
        if(y < m && fill(x, y + 1, w, h)) dy = true;
        if(dx && dy) return INF;
        if(dx) cnt += w, x += 1; else
        if(dy) cnt += h, y += 1; else
            break;
    }
    return cnt == tot ? w * h : INF;
}

void solve() {
    int w, h, ans = INF;
    w = get_w();
    for(h = 1; sx + h - 1 <= n; ++h)
        if(w * h < ans) ans = min(ans, check(w, h));
    h = get_h();
    for(w = 1; sy + w - 1 <= m; ++w)
        if(w * h < ans) ans = min(ans, check(w, h));
    if(ans == INF) ans = -1;
    cout << ans << endl;
}

int main() {
    //freopen("in","r",stdin);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) 
        scanf("%s", a[i] + 1);
    bool flag = true;
    for(int i = 1; flag && i <= n; ++i)
        for(int j = 1; flag && j <= m; ++j) {
            if(a[i][j] == 'X') {
                sx = i;
                sy = j;
                flag = false;
            }
        }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            c[i][j] = c[i-1][j] + c[i][j-1] - c[i-1][j-1] + (a[i][j] == 'X');
        }
    }
    tot = c[n][m];
    if(tot == 0) {
        cout << -1 << endl;
        return 0;
    } else solve();
}