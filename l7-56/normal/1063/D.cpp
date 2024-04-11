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

ll n, l, r, k, x;
bool check(ll a, ll i) {
    return a >= 0 && a <= min(i, x) && i - a <= n - x + 1
        && (i - a <= n - x || a + 1 <= min(i, x));
}

int main() {
	// freopen("mk.in", "r", stdin), freopen("mk.out", "w", stdout);
    read(n, l, r, k);
    x = (r - l + 1 + n) % n;
    if (!x) x = n;
    if (k < x) return write("-1\n"), 0;
    if (n <= 300000) {
        for (ll i = n; i >= 0; --i) {
            ll a = (k - x) % (n + i);
            if (check(a, i)) return write(i, '\n'), 0;
        }
        write("-1\n");
    }
    else {
        ll ans = -1;
        for (ll c = 0; c * n <= k; ++c) {
            ll i = ((1 - c) * n + k + 1 - 2 * x) / (c + 1);
            ll a = k - x - c * (n + i);
            if (a < 0) {
                if (c == 0) continue;
                ll ned = (-a - 1) / c + 1;
                a += c * ned, i -= ned;
            }
            if (check(a, i)) ans = max(ans, i);
        }
        write(ans, '\n');
    }
	return 0;
}