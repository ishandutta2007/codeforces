// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 100005;

int m, n, d[N], c[N], L[N], R[N];

void inline add(int x, int k) {
    for (; x <= m + 1; x += x & -x) chkMax(c[x], k);
}

int inline ask(int x) {
    int ret = 0;
    for (; x; x -= x & -x) chkMax(ret, c[x]);
    return ret;
}

int main() {
    read(m), read(n);
    for (int i = 1; i <= m; i++) {
        int x, y; read(x), read(y);
        d[x]++, d[y + 1]--;
    }
    for (int i = 2; i <= n; i++) d[i] += d[i - 1];
    for (int i = 1; i <= n; i++) d[i]++;
    for (int i = 1; i <= n; i++) {
        L[i] = ask(d[i]) + 1;
        add(d[i], L[i]);
    }
    for (int i = 1; i <= m + 1; i++) c[i] = 0;
    int ans = 0;
    for (int i = n; i; i--) {
        R[i] = ask(d[i]) + 1;
        add(d[i], R[i]);
        chkMax(ans, L[i] + R[i] - 1);
    }
    printf("%d\n", ans);
    return 0;
}