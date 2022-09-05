#include <bits/stdc++.h>
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

int mx[1 << 18][2], id[1 << 18][2];
int f[N], a[N], maxn[N], go[N];
int n, blocks;
ll ans;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void add(int x, int y, int z) {
    if (y > mx[x][0]) {
        if (z != id[x][0]) {
            mx[x][1] = mx[x][0];
            id[x][1] = id[x][0];
        }
        mx[x][0] = y;
        id[x][0] = z;
    } else if (y > mx[x][1] && z != id[x][0]) {
        mx[x][1] = y;
        id[x][1] = z;
    }
}

int main() {
    read(n); blocks = n + 1;
    for (int i = 1; i <= n; i++) read(a[i]), f[i] = i, ans -= a[i];
    a[++n] = 0; f[n + 1] = n + 1;
    while (blocks > 1) {
        for (int i = 0; i < (1 << 18); i++) mx[i][0] = mx[i][1] = -1;
        for (int i = 1; i <= n; i++) add(a[i], a[i], find(i));
        for (int mid = 1; mid < (1 << 18); mid <<= 1) {
            for (int i = 0; i < (1 << 18); i += (mid << 1)) {
                for (int j = 0; j < mid; j++) {
                    if (mx[i + j][0] != -1) add(i + j + mid, mx[i + j][0], id[i + j][0]);
                    if (mx[i + j][1] != -1) add(i + j + mid, mx[i + j][1], id[i + j][1]);
                }
            }
        }
        memset(maxn, -1, sizeof(maxn));
        for (int i = 1; i <= n; i++) {
            int cat = ((1 << 18) - 1) ^ a[i];
            if (mx[cat][0] != -1 && id[cat][0] != find(i)) {
                if (mx[cat][0] + a[i] > maxn[find(i)]) {
                    maxn[find(i)] = mx[cat][0] + a[i];
                    go[find(i)] = id[cat][0];
                }
            }
            if (mx[cat][1] != -1 && id[cat][1] != find(i)) {
                if (mx[cat][1] + a[i] > maxn[find(i)]) {
                    maxn[find(i)] = mx[cat][1] + a[i];
                    go[find(i)] = id[cat][1];
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (find(i) == i) {
                if (find(i) != find(go[i])) {
                    // fprintf(stderr, "i = %d, go = %d, maxn[i] = %d\n", i, go[i], maxn[i]);
                    f[i] = go[i];
                    ans += maxn[i];
                    --blocks;
                }
            }
        }
    }
    print(ans, '\n');
    return 0;
}