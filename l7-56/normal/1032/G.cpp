#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef pair <int, int> pii;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (int i = 0; s[i]; ++i) putchar(s[i]); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

const int maxn = 1e5 + 10, T = 18;
int n, a[maxn], lg2[maxn];
pii f[T][T][maxn];
pii merge(pii p, pii q) {
    int l1 = p.fir, r1 = p.sec, l2 = q.fir, r2 = q.sec;
    if (l2 > r2) swap(l1, l2), swap(r1, r2);
    if (l2 > r2) return merge({0, max(r1, r2)}, {min(l1, l2), n - 1});
    if (l1 > r1) {
        if (l2 <= r1 + 1) return merge({0, max(r1, r2)}, {l1, n - 1});
        if (r2 >= l1 - 1) return merge({0, r1}, {min(l1, l2), n - 1});
        return {-1, -1};
    }
    if (l1 == 0 && r2 == n - 1) return r1 + 1 >= l2 ? pii(0, n - 1) : pii(l2, r1);
    return {min(l1, l2), max(r1, r2)};
}

pii F(int i, pii p) {
    int l = p.fir, r = p.sec;
    if (l > r) return merge(F(i, {0, r}), F(i, {l, n - 1}));
    int k = lg2[r - l + 1];
    return merge(f[i][k][l], f[i][k][r - (1 << k) + 1]);
}

int main() {
	// freopen("sn.in", "r", stdin), freopen("sn.out", "w", stdout);
    read(n);
    for (int i = 2; i <= n; ++i) lg2[i] = lg2[i >> 1] + 1;
    for (int i = 0; i < n; ++i) read(a[i]);
    for (int i = 0; i < n; ++i)
        f[0][0][i] = a[i] * 2 + 1 >= n ? pii(0, n - 1) : pii((i - a[i] + n) % n, (i + a[i]) % n);

    for (int i = 1; i < T; ++i)
        for (int j = 0; j + (1 << i) <= n; ++j)
            f[0][i][j] = merge(f[0][i - 1][j], f[0][i - 1][j + (1 << (i - 1))]);
    for (int i = 1; i < T; ++i)
        for (int j = 0; j < T; ++j)
            for (int k = 0; k + (1 << j) <= n; ++k)
                f[i][j][k] = F(i - 1, F(i - 1, pii(k, k + (1 << j) - 1)));
    for (int i = 0; i < n; ++i) {
        pii p = {i, i};
        int ans = 0;
        for (int j = T - 1; j >= 0; --j) {
            pii np = F(j, p);
            if (np != pii(0, n - 1)) p = np, ans += (1 << j);
        }
        if (p != pii(0, n - 1)) p = F(0, p), ans++;
        write(p == pii(0, n - 1) ? ans : -1, " \n"[i == n - 1]);
    }
	return 0;
}