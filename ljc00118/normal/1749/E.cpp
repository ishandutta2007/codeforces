#include <bits/stdc++.h>
#include <Windows.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

char c[N];
int T, n, m;

int main() {
    read(T);
    while (T--) {
        read(n); read(m);
        vector < vector <int> > a(n + 1, vector <int> (m + 1, 0)), ban = a, dis = a;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dis[i][j] = 1e9;
            }
        }
        vector < vector <pii> > fr(n + 1, vector <pii> (m + 1));
        for (int i = 1; i <= n; i++) {
            scanf("%s", c + 1);
            for (int j = 1; j <= m; j++) {
                a[i][j] = (c[j] == '#');
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j]) {
                    for (int d = 0; d < 4; d++) {
                        int x = i + dx[d], y = j + dy[d];
                        if (x >= 1 && y >= 1 && x <= n && y <= m) ban[x][y] = 1;
                    }
                }
            }
        }
        deque <pii> q;
        for (int i = 1; i <= n; i++) {
            if (!ban[i][1]) {
                q.push_front(make_pair(i, 1));
                dis[i][1] = 1 - a[i][1];
            }
        }
        while (!q.empty()) {
            pii u = q.front(); q.pop_front();
            for (int i = -1; i <= 1; i++) for (int j = -1; j <= 1; j++) {
                if (!i || !j) continue;
                int x = u.first + i, y = u.second + j;
                if (x >= 1 && y >= 1 && x <= n && y <= m && !ban[x][y] && dis[x][y] > dis[u.first][u.second] + 1 - a[x][y]) {
                    fr[x][y] = u; dis[x][y] = dis[u.first][u.second] + 1 - a[x][y];
                    if (1 - a[x][y]) q.push_back(make_pair(x, y));
                    else q.push_front(make_pair(x, y));
                }
            }
        }
        int ans = 1e9;
        for (int i = 1; i <= n; i++) {
            if (dis[i][m] < 1e9) {
                if (ans == 1e9) ans = i;
                else if (dis[i][m] < dis[ans][m]) ans = i;
            }
        }
        if (ans <= n) {
            int x = ans, y = m;
            while (y != 1) {
                a[x][y] = 1;
                pii t = fr[x][y];
                x = t.first; y = t.second;
            }
            a[x][y] = 1;
            printf("YES\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    putchar(a[i][j] ? '#' : '.');
                }
                putchar('\n');
            }
        } else {
            printf("NO\n");
        }
    }
    return 0;
}