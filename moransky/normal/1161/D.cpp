// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 4005, P = 998244353;

int n, m, f[N], ans;

char s[N];

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

int inline get1(int o, int x) {
    return o * n + x;
}

int inline get2(int o, int x) {
    return 2 * n + o * m + x;
}

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
    f[find(x)] = find(y);
} 

bool ban[N], vis[N];

int inline work() {
    memset(ban, 0, sizeof ban);
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= 2 * n + 2 * m; i++) f[i] = i;
    for (int i = 1; i <= n / 2; i++) {
        merge(get1(0, i), get1(0, n - i + 1));
        merge(get1(1, i), get1(1, n - i + 1));
    }
    for (int i = 1; i <= m / 2; i++) {
        merge(get2(0, i), get2(0, m - i + 1));
        merge(get2(1, i), get2(1, m - i + 1));
    }
    for (int i = 1; i <= m; i++) {
        if (s[i] == '?') continue;
        if (s[i] == '1') {
            merge(get1(0, i), get2(1, i));
            merge(get1(1, i), get2(0, i));
        } else {
            merge(get1(1, i), get2(1, i));
            merge(get1(0, i), get2(0, i));
        }
    }
    ban[find(get1(0, n))] = 1;
    ban[find(get2(0, m))] = 1;
    for (int i = m + 1; i <= n; i++) {
        if (s[i] == '?') continue;
        if (s[i] == '1') {
            ban[find(get1(0, i))] = 1;
        } else {
            ban[find(get1(1, i))] = 1;
        }
    }
    int res = 1;
    for (int i = 1; i <= n; i++) {
        int X = find(i), Y = find(i + n);
        if (X == Y) return 0;
        if (ban[X] && ban[Y]) return 0;
        if (!vis[X]) {
            vis[X] = vis[Y] = 1;
            if (!ban[X] && !ban[Y]) res = res * 2 % P;
        }
    }
    for (int i = 1; i <= m; i++) {
        int X = find(i + 2 * n), Y = find(i + m + 2 * n);
        if (X == Y) return 0;
        if (ban[X] && ban[Y]) return 0;
        if (!vis[X]) {
            vis[X] = vis[Y] = 1;
            if (!ban[X] && !ban[Y]) res = res * 2 % P;
        }
    }
    return res;
}

int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
    reverse(s + 1, s + 1 + n);
    for (int i = 1; i < n; i++)
        m = i, add(ans, work());
    print(ans);
	return 0;
}