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

const ll maxn = 1 << 18, inf = 1e18;
ll n, q, a[maxn];
struct node {
    ll lmx, rmx, mx, sum;
    node() { lmx = rmx = mx = sum = 0; }
    node(ll x) { lmx = rmx = mx = max(x, 0ll), sum = x; }
    node(ll lmx, ll rmx, ll mx, ll sum) : lmx(lmx), rmx(rmx), mx(mx), sum(sum) {}
    friend node operator + (node L, node R) {
        return node(max(L.lmx, L.sum + R.lmx),
                    max(R.rmx, R.sum + L.rmx),
                    max(max(L.mx, R.mx), L.rmx + R.lmx),
                    L.sum + R.sum);
    }
};
typedef vector <node> vn;
vn solve(ll l, ll r) {
    if (l == r) return vn(1, a[l]);
    ll mid = (l + r) >> 1, len = mid - l + 1;
    vn L = solve(l, mid), R = solve(mid + 1, r), res;
    res.resize(r - l + 1);
    for (ll i = 0; i < len; ++i)
        res[i] = L[i] + R[i], res[i + len] = R[i] + L[i];
    return res;
}

int main() {
    read(n);
    for (ll i = 0; i < (1 << n); ++i) read(a[i]);
    vn ans = solve(0, (1 << n) - 1);
    read(q);
    ll x = 0;
    while (q--) {
        ll k; read(k);
        write(ans[x ^= (1 << k)].mx, '\n');
    }
	return 0;
}