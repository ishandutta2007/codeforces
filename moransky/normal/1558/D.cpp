// Skyqwq
#include <bits/stdc++.h>

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

const int N = 4e5 + 5, P = 998244353, S = 19;

int L = 2e5, n, m, x[N], y[N], fact[N], infact[N], c[N];

void inline Add(int x, int k) {
    for (; x <= L; x += x & -x) c[x] += k;
}

int inline query(int k) {
    int p = 0;
    for (int i = S - 1; ~i; i--) {
        if (p + (1 << i) <= L && c[p + (1 << i)] < k) p += 1 << i, k -= c[p];
    }
    return p + 1;
}

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}

void inline factPrework(int n) {
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (LL)fact[i - 1] * i % P;
    infact[n] = power(fact[n], P - 2);
    for (int i = n - 1; i; i--) infact[i] = infact[i + 1] * (i + 1ll) % P;
}
int inline C(int a, int b) {
    if (a < b || a < 0 || b < 0) return 0;
    return (LL)fact[a] * infact[b] % P * infact[a - b] % P;
}
 
void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

bool st[N];

int d[N];

int inline get() {
    int cnt = 1;
    for (int i = m; i; i--) {
        int v = query(y[i]);
        d[i] = v;
        if (!st[v + 1]) {
            cnt++;
        }
        st[v] = 1;
        Add(v, -1);
    }
    for (int i = 1; i <= m; i++) Add(d[i], 1), st[d[i]] = 0;
    return cnt;
}

int main() {
    int T; read(T); factPrework(400000);
    for (int i = 1; i <= L; i++) Add(i, 1);
    while (T--) {
        read(n), read(m);
        for (int i = 1; i <= m; i++) {
            read(x[i]), read(y[i]);
        }
        int k = get();
        int ans = C(2 * n - k, n - k);
        printf("%d\n", ans);
    }
    return 0;   
}