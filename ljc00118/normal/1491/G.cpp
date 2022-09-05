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

vector <pii> ans;
vector <int> cycs[N];
int a[N], pre[N], vis[N], used[N], vis2[N];
int n, len;

void doit(int x, int y) {
    ans.emplace_back(x, y);
    swap(a[x], a[y]); a[x] = -a[x]; a[y] = -a[y];
    pre[abs(a[x])] = x; pre[abs(a[y])] = y;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    vector <int> las_cyc;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vector <int> cyc;
        int now = i;
        while (!vis[now]) {
            cyc.push_back(now);
            vis[now] = 1;
            now = a[now];
        }
        if (cyc.size() > 1) {
            cycs[++len] = cyc;
        } else {
            vis2[cyc[0]] = 1;
        }
    }
    if (len == 1) {
        if (cycs[1].size() == 2) {
            vector <int> cyc = cycs[1];
            int pos = 0;
            for (int j = 0; j < (int)cyc.size(); j++) used[cyc[j]] = 1;
            for (int j = 1; j <= n; j++) {
                if (!used[j]) {
                    pos = j;
                    break;
                }
            }
            for (int j = 0; j < (int)cyc.size(); j++) used[cyc[j]] = 0;
            doit(pos, cyc[0]); doit(pos, cyc[1]); doit(pos, cyc[0]);
            vis2[cyc[0]] = vis2[cyc[1]] = 1;
        } else {
            doit(cycs[1][1], cycs[1][2]);
            doit(cycs[1][2], cycs[1][0]);
        }
    } else {
        int up = len;
        if (len % 2 == 1) {
            doit(cycs[len][0], cycs[len - 1][0]);
            doit(cycs[len][0], cycs[len - 2][0]);
            up = len - 3;
        }
        for (int i = 1; i <= up; i += 2) {
            doit(cycs[i][0], cycs[i + 1][0]);
        }
    }
    // for (int i = 1; i <= n; i++) print(a[i], i == n ? '\n' : ' ');
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (vis[i] || vis2[i]) continue;
        vector <int> cyc;
        int now = i;
        while (!vis[now]) {
            cyc.push_back(now);
            vis[now] = 1;
            now = abs(a[now]);
        }
        int pos = -1, val;
        for (int i = 0; i < (int)cyc.size(); i++) {
            if (a[cyc[i]] < 0) {
                pos = cyc[i];
                break;
            }
        }
        assert(pos != -1);
        val = a[pos];
        while (a[-val] > 0) {
            // fprintf(stderr, "pos = %d, val = %d, a[-val] = %d\n", pos, val, a[-val]);
            doit(pos, -val);
            val = a[pos];
        }
        int pos2 = -val, val2 = a[pos2];
        while (a[-val2] > 0) {
            // fprintf(stderr, "pos2 = %d, val2 = %d, a[-val2] = %d\n", pos2, val2, a[-val2]);
            doit(pos2, -val2);
            val2 = a[pos2];
        }
        doit(pos, pos2);
    }
    print(ans.size(), '\n');
    for (auto i : ans) print(i.first, ' '), print(i.second, '\n');
    // for (int i = 1; i <= n; i++) print(a[i], i == n ? '\n' : ' ');
    return 0;
}