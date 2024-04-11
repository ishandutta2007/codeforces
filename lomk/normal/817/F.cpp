/*input
20
2 3 3
1 3 10
3 5 7
1 9 10
3 8 9
2 6 6
3 4 7
3 10 10
2 4 8
1 10 10
3 7 10
1 4 4
1 8 9
1 5 9
3 9 9
2 1 1
1 7 10
1 8 10
3 8 9
1 1 6
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
const int N = 4e5 + 10;

const int INF = 1e18;
class ITrangeMaxMin {
private:
#define mid ((l+r)/2)
	int n, lazy[4 * N];
	pair<int, int> f[4 * N]; // min,max

	int merge(int now, int in) {
		if (now == 0) return in;
		if (now == 1) return (in == now ? 1 : 2);
		if (now == 2) return (in != now ? 1 : 2);
		// if (now == 3) {
		if (in == 1 || in == 2) return in;
		return 0;
		// }
	}
	void dolazy(int k, int l, int r) {
		if (lazy[k] == 0) return;
		if (lazy[k] == 1) f[k].fi = f[k].se = 1;
		else if (lazy[k] == 2) f[k].fi = f[k].se = 0;
		else {
			f[k].fi ^= 1, f[k].se ^= 1;
			if (f[k].fi > f[k].se) swap(f[k].fi, f[k].se);
		}
		if (l != r) {
			lazy[k * 2] = merge(lazy[k * 2], lazy[k]);
			lazy[k * 2 + 1] = merge(lazy[k * 2 + 1], lazy[k]);
		}
		lazy[k] = 0;
	}
	void init(int k, int l, int r) {
		f[k].fi = f[k].se = lazy[k] = 0; if (l == r) return;
		init(k * 2, l, mid); init(k * 2 + 1, mid + 1, r);
	}
	void update(int k, int l, int r, int L, int R, int val) {
		dolazy(k, l, r);
		if (r < L || R < l) return;
		if (L <= l && r <= R) {
			lazy[k] = merge(lazy[k], val); dolazy(k, l, r);
			return;
		}
		update(k * 2, l, mid, L, R, val); update(k * 2 + 1, mid + 1, r, L, R, val);
		f[k].fi = min(f[k * 2].fi, f[k * 2 + 1].fi);
		f[k].se = max(f[k * 2].se, f[k * 2 + 1].se);
	}
	int get(int k, int l, int r, int pos) {
		dolazy(k, l, r);
		if (r < pos || pos < l) return -1; // flip
		if (pos <= l && r <= pos) return f[k].fi;
		return max(get(k * 2, l, mid, pos), get(k * 2 + 1, mid + 1, r, pos)); // flip;
	}
	int find(int k, int l, int r) {
		dolazy(k, l, r);
		if (f[k].fi == 1) return -1;
		if (l == r) return l;
		auto rec = find(k * 2, l, mid);
		if (rec != -1) return rec;
		return find(k * 2 + 1, mid + 1, r);
	}
public:
	void init(int _n) {n = _n; init(1, 0, n + 1);}
	int find() {return find(1, 0, n + 1);}
	int get(int pos) {return get(1, 0, n + 1, pos);};
	void update(int l, int r, int val) {update(1, 0, n + 1, l, r, val);};
#undef mid
} IT;

int q;
vector<int> all;
vector<tuple<int, int, int>  > query;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> q;
	loop(i, 1, q) {
		int type, l, r; cin >> type >> l >> r;
		loop(j, 0, 1) all.push_back(l + j), all.push_back(r + j);
		query.push_back({type, l, r});
	}
	all.push_back(1); all.push_back(INF + 10);
	sort(all.begin(), all.end()); all.resize(distance(all.begin(), unique(all.begin(), all.end())));
	// print(all);
	IT.init(all.size());
	for (auto &[type, l, r] : query) {
		l = lower_bound(all.begin(), all.end(), l) - all.begin();
		r = lower_bound(all.begin(), all.end(), r) - all.begin();
		IT.update(l, r, type);
		auto rec = IT.find();
		// print(type, l, r);
		int ans = all[rec];
		cout << ans << endl;
	}
	// print(all);
	// loop(i, 0, all.size() - 1) cout << IT.get(i) << sp;
	// cout << endl;
}