#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
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

const int maxn = 4e6 + 10;
ll n, m, x[maxn], d[maxn][2], tx, a[maxn];
pii b[maxn];

void work() {
    read(n, m);
    tx = 0;
    auto add = [&] (ll p) { x[++tx] = p, x[++tx] = p - 1, x[++tx] = p + 1; };
    for (ll i = 1; i <= n; ++i) {
        read(b[i].fir, b[i].sec);
        add(b[i].fir), add(b[i].fir - b[i].sec + 1), add(b[i].fir + b[i].sec - 1);
    }
    sort(x + 1, x + tx + 1);
    tx = unique(x + 1, x + tx + 1) - x - 1;
    auto ask = [&] (ll p) { return lower_bound(x + 1, x + tx + 1, p) - x; };
    for (ll i = 1; i <= tx; ++i) d[i][0] = d[i][1] = 0;
    auto upd = [&] (ll l, ll r, ll v0, ll v1) {
        d[l][0] += v0, d[r][0] -= v0;
        d[l][1] += v1, d[r][1] -= v1;
    };
    for (ll i = 1; i <= n; ++i) {
        ll l = ask(b[i].fir - b[i].sec + 1), mid = ask(b[i].fir), r = ask(b[i].fir + b[i].sec);
        upd(l, mid, b[i].sec - b[i].fir, 1);
        upd(mid, r, b[i].sec + b[i].fir, -1);
    }
    for (ll i = 1; i <= tx; ++i)
        d[i][0] += d[i - 1][0], d[i][1] += d[i - 1][1],
        a[i] = d[i][0] + (ll) d[i][1] * x[i];

    ll v1 = LLONG_MIN, v2 = LLONG_MIN;
    for (ll i = 1; i <= tx; ++i)
        if (a[i] > m) v1 = max(v1, a[i] - x[i]), v2 = max(v2, a[i] + x[i]);
    for (ll i = 1; i <= n; ++i)
        write(int(b[i].sec - b[i].fir + m >= v1 && b[i].sec + b[i].fir + m >= v2));
    write('\n');
}

int main() {
    int T; read(T);
    while (T--) work();
	return 0;
}