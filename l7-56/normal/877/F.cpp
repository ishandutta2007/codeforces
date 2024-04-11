#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

template <typename __Tp> void read(__Tp &x) {
	x = 0; char ch = getchar(); bool f = 0;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}

const ll maxn = 1e6 + 10;
ll n,k,m,d,s[maxn],sd[maxn],su[maxn];
vector <ll> S;
ll ask(ll x) { return lower_bound(S.begin(), S.end(), x) - S.begin(); }

ll len,bel[maxn];
struct node {
	ll l, r, id;
	friend bool operator < (node x, node y) {
		if (bel[x.l] != bel[y.l]) return bel[x.l] < bel[y.l];
		return bel[x.l] & 1 ? x.r < y.r : x.r > y.r;
	}
}a[maxn];
ll ans[maxn];

ll cnt[maxn], res;
void addl(ll i) {
	res += cnt[su[i]];
	cnt[s[i]]++;
}
void addr(ll i) {
	res += cnt[sd[i]];
	cnt[s[i]]++;
}
void dell(ll i) {
	cnt[s[i]]--;
	res -= cnt[su[i]];
}
void delr(ll i) {
	cnt[s[i]]--;
	res -= cnt[sd[i]];
}

int main() {
	read(n), read(k);
	len = sqrt(n);
	for (ll i = 0; i <= n; ++i) bel[i] = i / len + 1;
	for (ll i = 1; i <= n; ++i) read(s[i]);
	for (ll i = 1; i <= n; ++i) {
		ll t; read(t);
		if (s[i] == 1) s[i] = s[i - 1] + t;
		else s[i] = s[i - 1] - t;
	}
	S.push_back(-3e18);
	for (ll i = 0; i <= n; ++i) S.push_back(s[i] - k), S.push_back(s[i]), S.push_back(s[i] + k);
	stable_sort(S.begin(), S.end());
	S.erase(unique(S.begin(), S.end()), S.end());
	for (ll i = 0; i <= n; ++i) su[i] = ask(s[i] + k), sd[i] = ask(s[i] - k), s[i] = ask(s[i]);
	read(m);
	for (ll i = 1; i <= m; ++i) read(a[i].l), read(a[i].r), --a[i].l, a[i].id = i;
	sort(a + 1, a + m + 1);
	ll l = 0, r = 0; cnt[s[0]] = 1;
	for (ll i = 1; i <= m; ++i) {
		while (l > a[i].l) addl(--l);
		while (r < a[i].r) addr(++r);
		while (l < a[i].l) dell(l++);
		while (r > a[i].r) delr(r--);
		ans[a[i].id] = res;
	}
	for (ll i = 1; i <= m; ++i) printf("%lld\n", ans[i]);
	return 0;
}