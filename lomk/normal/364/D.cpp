/*input
6
6 2 3 4 5 6

*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {cout << "[" << #x << "] ="; _print(x);}
void _print() {cout << endl;}
template<typename T, typename... Ts> void _print(const T& value, const Ts&... values) {cout << ' ' << value; _print(values...);}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value; _print(values...);}
// change cout to cerr for debug in crash
// for struct, can write print operator to use print() (even with SegTree)
const int N = 1e6 + 5;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
using ll = long long;
int n;
ll a[N];

vector<ll> getDiv(ll X) {
	vector<ll> ret{1};
	for (int i = 2, lim = sqrt(X); i <= lim; i++) {
		ll base = 1; int sz = ret.size();
		while (X % i == 0) {
			base *= i; X /= i;
			loop(j, 0, sz - 1) ret.push_back(ret[j]*base);
		}
	}
	if (X > 1)
		for (int i = 0, sz = ret.size(); i < sz; i++) ret.push_back(ret[i]*X);
	return ret;
}

ll solve(ll X) {
	map<ll, int> mark;

	auto rec = getDiv(X);
	for (auto it : rec) mark[it] = 0;
	loop(i, 1, n) mark[gcd(X, a[i])]++;

	vector<pair<ll, int> > div(mark.begin(), mark.end());

	rloop(i, div.size() - 1, 0) {
		int sum = 0;
		for_each(div.begin() + i, div.end(), [&](auto it) {
			if (it.fi % div[i].fi == 0) sum += it.se;
		});
		if (sum * 2 >= n) return div[i].fi;
	}
	assert(false);
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	loop(i, 1, n) cin >> a[i];
	int RUN = 10;
	ll ans = 0;
	shuffle(a + 1, a + n + 1, rd);
	loop(i, 1, min(RUN, n)) {
		ans = max(ans, solve(a[i]));
	}
	cout << ans << endl;
}