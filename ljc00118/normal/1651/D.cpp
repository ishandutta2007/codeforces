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

const int N = 2e5 + 5;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

map <pii, int> mp;
queue <int> q;
int x[N], y[N], dis[N], ansx[N], ansy[N];
int n;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(x[i]), read(y[i]), mp[make_pair(x[i], y[i])] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            int _x = x[i] + dx[j], _y = y[i] + dy[j];
            if (!mp.count(make_pair(_x, _y))) {
                ansx[i] = _x;
                ansy[i] = _y;
                dis[i] = 1;
                q.push(i);
                break;
            }
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int _x = x[u] + dx[i], _y = y[u] + dy[i];
            if (mp.count(make_pair(_x, _y))) {
                int v = mp[make_pair(_x, _y)];
                if (!dis[v]) {
                    dis[v] = dis[u] + 1;
                    ansx[v] = ansx[u]; ansy[v] = ansy[u];
                    q.push(v);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) print(ansx[i], ' '), print(ansy[i], '\n');
    return 0;
}