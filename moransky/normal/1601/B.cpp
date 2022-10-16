// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 3e5 + 5;

int n, a[N], b[N], q[N], d[N], pre[N], top;
 
set<int> s;

typedef set<int>::iterator SIT;

int inline bfs() {
    memset(d, 0x3f, sizeof d);
    int hh = 0, tt = 0;
    q[0] = n, d[n] = 0;
    for (int i = 1; i < n; i++) s.insert(i);
    while (hh <= tt) {
        int u = q[hh++];
        int x = u + b[u];
        if (x - a[x] == 0) {
            top = u;
            return d[u] + 1;
        }
        int L = x - a[x], R = x - 1;
        while (1) {
            SIT it = s.lower_bound(L);
            if (it == s.end() || *it > R) break;
            int v = *it;
            if (d[u] + 1 < d[v]) {
                d[v] = d[u] + 1, q[++tt] = v;
                pre[v] = u;
            }
            s.erase(it);
        }
    } 
    return -1;
}

void print(int u) {
    if (u == n)  return;
    print(pre[u]);
    printf("%d ", u);
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) read(b[i]);
    printf("%d\n", bfs());
    if (top) { print(top); printf("0\n"); }
    return 0;
}