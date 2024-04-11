#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 605;

vector <int> b[N], c[N], vec[N];
int dis[N], used[N], qwq[N];
int n, m;

int main() {
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        int u, x, y;
        read(u); read(x); read(y);
        b[u].push_back(x);
        c[u].push_back(y);
    }
    for (int i = 0; i < n; i++) {
        memset(dis, 0x7f, sizeof(dis));
        memset(used, 0, sizeof(used));
        dis[i] = 0;
        for (int _ = 1; _ <= n; _++) {
            int minn = 2e9, u;
            for (int j = 0; j < n; j++) {
                if (!used[j] && dis[j] < minn) {
                    minn = dis[j];
                    u = j;
                }
            }
            memset(qwq, 0x7f, sizeof(qwq));
            used[u] = 1;
            for (int j = 0; j < (int)b[u].size(); j++) qwq[(b[u][j] + dis[u]) % n] = c[u][j];
            int now = 0x7f7f7f7f;
            for (int j = 0; j < n; j++) now = min(now + 1, qwq[j]);
            for (int j = 0; j < n; j++) {
                now = min(now + 1, qwq[j]);
                dis[j] = min(dis[j], dis[u] + now);
            }
        }
        for (int j = 0; j < n; j++) print(dis[j], j == n - 1 ? '\n' : ' ');
    }
    return 0;
}