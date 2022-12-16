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

const ll maxn = 3e5 + 10;
ll n, m, a[maxn], b[maxn], s[maxn], sum, pos;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = exgcd(b, a % b, y, x); y -= a / b * x;
    return d;
}

ll updiv(ll x, ll y) {
    if (y < 0) x = -x, y = -y;
    if (x >= 0) return x / y + (x % y != 0);
    return x / y;
}

ll dwdiv(ll x, ll y) {
    if (y < 0) x = -x, y = -y;
    if (x >= 0) return x / y;
    return x / y - (x % y != 0);
}

ll query(ll p, ll q) {
    ll x, y, d = exgcd(p, q, x, y);
    if (n % d) return -1;
    ll L = updiv(-n * x, q), R = dwdiv(n * y, p), stp = q / d;
    x *= n / d;
    if (L > R) return -1;
    auto calc = [&] (ll k) {
        k = max(L, min(R, k));
        return sum + s[p * (x + k * stp)];
    };
    return max(calc(dwdiv(pos - x * p, stp * p)), calc(updiv(pos + 1 - x * p, stp * p)));
}

int main() {
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i], b[i]), s[i] = a[i] - b[i], sum += b[i];
    sort(s + 1, s + n + 1, greater <ll> ());
    for (int i = 1; i <= n; ++i) {
        if (s[i] >= 0) pos = i;
        s[i] += s[i - 1];
    }
    read(m);
    while (m--) {
        ll x, y; read(x, y);
        write(query(x, y), '\n');
    }
	return 0;
}