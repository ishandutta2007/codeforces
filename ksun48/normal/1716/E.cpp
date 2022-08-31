#include <bits/stdc++.h>
using namespace std;

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

using ll = int64_t;
struct info {
	ll sum, l, r, mid;
};
info combine(info a, info b){
	return {
		a.sum + b.sum,
		max(a.l, a.sum + b.l),
		max(b.r, b.sum + a.r),
		max({a.mid, b.mid, a.r + b.l})
	};
}

info get(ll x){
	return {
		x,
		max(x, ll(0)),
		max(x, ll(0)),
		max(x, ll(0)),
	};
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	int N = 1 << n;
	vector<ll> a(N);
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	vector<ll> ans(N);
	vector<info> st(N);
	for(int i = 0; i < N; i++) st[i] = get(a[i]);
	y_combinator(
		[&](auto self, vector<info> cur, int x) -> void {
			if(cur.size() == 1){
				ans[x] = cur[0].mid;
				return;
			}
			int l = (int)cur.size() / 2;
			int bit = N / cur.size();
			for(int b = 0; b < 2; b++){
				vector<info> ncur(l);
				for(int i = 0; i < l; i++){
					ncur[i] = combine(cur[2 * i + b], cur[2 * i + 1 - b]);
				}
				self(ncur, x + b * bit);
			}
		}
	)(st, 0);
	int Q;
	cin >> Q;
	int mask = 0;
	while(Q--){
		int k;
		cin >> k;
		mask ^= (1 << k);
		cout << ans[mask] << '\n';
	}
}