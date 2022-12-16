#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 2e5 + 10, A = 2e5;
ll c3(ll n) { return n * (n - 1) * (n - 2) / 6; }
int n;
vi g[maxn];
ll ans[maxn];
vector <pll> t[maxn];

struct BIT {
	ll c[maxn];
	void add(ll x, ll y) { for (; x <= A; x += x & (-x)) c[x] += y; }
	void add(ll l, ll r, ll x) { add(l, x), add(r + 1, -x); }
	ll ask(ll x) {
		ll res = 0;
		for (; x > 0; x &= x - 1) res += c[x];
		return res;
	}
} tr;

void init() {
	for (int i = 1; i <= A; ++i)
		for (int j = i * 2; j <= A; j += i)
			g[j].push_back(i);
}

int main() {
	init();
	read(n);
	for (int i = 1; i <= n; ++i) {
		int l, r; read(l, r);
		t[r].push_back({l, i});
		ans[i] = c3(r - l + 1);
	}
	for (int r = 3; r <= A; ++r) {
		if (r % 6 == 0) tr.add(1, r / 2, 1);
		if (r % 15 == 0) tr.add(1, r / 5 * 2, 1);
		int len = g[r].size();
		for (int i = 0; i < len; ++i)
			tr.add(1, g[r][i], len - i - 1);
		for (pll p : t[r]) ans[p.sec] -= tr.ask(p.fir);
	}
	for (int i = 1; i <= n; ++i) write(ans[i], '\n');
	return 0;
}