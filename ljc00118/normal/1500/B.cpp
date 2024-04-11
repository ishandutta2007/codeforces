#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 1e6 + 5;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

void exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return; }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

ll pos[N];
int a[N], b[N], pa[N], pb[N];
int n, m; ll k;

int main() {
    read(n); read(m); read(k); int d = gcd(n, m);
    ll lcm = 1ll * n * m / d;
    // nx - my = d
    ll x, y;
    exgcd(n, m, x, y);
    y = -y;
    for (int i = 1; i <= n; i++) read(a[i]), pa[a[i]] = i;
    for (int i = 1; i <= m; i++) read(b[i]), pb[b[i]] = i;
    int lim = max(n, m) * 2;
    for (int i = 1; i <= lim; i++) {
        if (pa[i] && pb[i]) {
            if ((pa[i] - pb[i]) % d) continue;
            ll _x = x * ((pb[i] - pa[i]) / d);
            // ll _y = y * ((pb[i] - pa[i]) / d);
            ll _pos = _x * n + pa[i];
            _pos = (_pos % lcm + lcm) % lcm;
            if (_pos == 0) _pos += lcm;
            pos[i] = _pos;
            // fprintf(stderr, "i = %d, pos = %lld\n", i, _pos);
        }
    }
    ll l = 1, r = 1e18, ans = 1e18;
    while (l <= r) {
        ll mid = (l + r) >> 1, now = mid;
        for (int i = 1; i <= lim; i++) {
            if (pos[i] && pos[i] <= mid) {
                now -= (mid - pos[i]) / lcm + 1;
            }
        }
        if (now >= k) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    print(ans, '\n');
    return 0;
}