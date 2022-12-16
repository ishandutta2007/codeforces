// LUOGU_RID: 95082990
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
#define fir first
#define sec second
typedef vector <int> vi;
typedef vector <ll> vl;

const int maxn = 1e5 + 10;
const ll inf = 1e17;
ll n, s, e, h[maxn], a[maxn], b[maxn], c[maxn], d[maxn];
#define chkmn(x, y) ((x) = (x) < (y) ? (x) : (y))
ll dlt[maxn], lim[maxn], w[maxn][3];
multiset <ll> st;

int main() {
	// freopen("furry.in", "r", stdin), freopen("furry.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &s, &e);
	for (int i = 1; i <= n; ++i) scanf("%lld", &h[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &b[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &c[i]);
	for (int i = 1; i <= n; ++i) scanf("%lld", &d[i]);
	
	for (int i = 1; i <= n; ++i) {
		int H = h[i], A = a[i], B = b[i], C = c[i], D = d[i];
		a[i] = D - H, b[i] = A + H;
		c[i] = C + H, d[i] = B - H;
		
		if (i == s) w[i][1] = c[i], w[i][2] = a[i], w[i][0] = inf;
		else if (i == e) w[i][0] = b[i], w[i][1] = d[i], w[i][2] = inf;
		else w[i][1] = min(a[i] + b[i], c[i] + d[i]), w[i][2] = a[i] + d[i], w[i][0] = b[i] + c[i];
		dlt[i] = (i >= e) - (i >= s);
		lim[i] = 1;
		if (e <= i && i < s) lim[i] = 0;
	}
	lim[n] = 0;
	
	ll x = 0, y = 0;
	for (int i = 1; i <= n; ++i) {
		if (!st.size()) st.insert(inf);
		ll tx = x, ty = y, ny;
		++x, y += *st.begin(), st.erase(st.begin());
		if (i != s && i != e) {
			ny = y + w[i][0];
			if (tx >= 1) ny = min(ny, ty + a[i] + b[i]);
			if (tx + dlt[i] >= 1) ny = min(ny, ty + c[i] + d[i]);
		}
		else ny = min(y + w[i][0], ty + w[i][1]);
		
		x += -1, y += w[i][0];
		st.insert(w[i][1] - w[i][0]);
		st.insert(w[i][2] - w[i][1]);
		while (x < lim[i] || x <= tx) x += 1, y += *st.begin(), st.erase(st.begin());
		
		auto chg = [&] (ll oy) {
			if (y <= oy) return;
			if (st.size()) {
				y += *st.begin();
				st.erase(st.begin());
				st.insert(y - oy);
			}
			y = oy;
		};
		if (x == tx + 1) chg(ty + w[i][2]);
		if (tx >= lim[i] && x == tx + 1) x = tx, st.insert(y - ny), y = ny;
		if (tx - 1 >= lim[i]) st.insert(y - (ty + w[i][0])), x--, y = ty + w[i][0];
		// printf("(%lld, %lld)\n", x, y);
	}
	printf("%lld\n", y);
	return 0;
}