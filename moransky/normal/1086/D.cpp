// Skyqwq
#include <iostream>
#include <cstdio>
#include <set>
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

const int N = 2e5 + 5;

int n, q, a[N];

char g[N];

set<int> s[3];
int c[3][N];

void inline add(int o, int x, int k) {
    for (; x <= n; x += x & -x) c[o][x] += k;
}

int inline ask(int o, int x) {
    int res = 0;
    for (; x; x -= x & -x) res += c[o][x];
    return res;
}

int inline get(char c) {
    if (c == 'R') return 0;
    else if (c == 'P') return 1;
    return 2;
}

void inline del(int o, int x) {
    add(o, x, -1);
    s[o].erase(x);
}

void inline insert(int o, int x) {
    add(o, x, 1);
    s[o].insert(x);
}

int inline getNum(int o, int l, int r) {
    if (l > r) return 0;
    return ask(o, r) - ask(o, l - 1);
}

int inline query() {
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        int fr = (i - 1 + 3) % 3, en = (i + 1) % 3;
        if (!s[en].size()) {
            ans += ask(i, n);
            continue;
        }
        if (s[fr].size())  {
            ans += ask(i, n);
            ans -= getNum(i, *s[en].begin(), *s[fr].begin() - 1);
            ans -= getNum(i, *s[fr].rbegin() + 1, *s[en].rbegin());
        }
    }
    return ans;
}
 
int main() {
    read(n); read(q);
    scanf("%s", g + 1);
    for (int i = 1; i <= n; i++) a[i] = get(g[i]), insert(a[i], i);
    printf("%d\n", query());
    while (q--) {
        int p; read(p); scanf("%s", g);
        del(a[p], p);
        a[p] = get(g[0]);
        insert(a[p], p);
        printf("%d\n", query());
    }
	return 0;
}