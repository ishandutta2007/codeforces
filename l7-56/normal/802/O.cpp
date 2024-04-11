#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pll;
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

const ll maxn = 5e5 + 10, inf = 2e9;
ll n, k, a[maxn], b[maxn];

pll work(ll dlt) {
	pll res;
	priority_queue <pll, vector <pll>, greater <pll> > pq;
	for (ll i = 1; i <= n; ++i) {
		pq.push({a[i], 1});
		ll val = pq.top().fir + b[i] - dlt;
		if (val < 0)
			res.fir += val, res.sec += pq.top().sec, pq.pop(), pq.push({- b[i] + dlt, 0});
	}
	return res;
}

int main() {
	read(n, k);
	for (ll i = 1; i <= n; ++i) read(a[i]);
	for (ll i = 1; i <= n; ++i) read(b[i]);

	ll l = -inf, r = inf, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (work(mid).sec >= k) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	write(ans * k + work(ans).fir, '\n');
	return 0;
}