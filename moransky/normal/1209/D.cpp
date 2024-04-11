#include <iostream>
#include <cstdio>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e5 + 5;

int n, m, f[N];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
    f[find(x)] = find(y);
}

int main() {
	read(n); read(m);
    for (int i = 1; i <= n; i++) f[i] = i;
    int ans = m;
    while (m--) {
        int a, b; read(a), read(b);
        if (find(a) != find(b)) ans--, merge(a, b);
    }
    printf("%d\n", ans);
}