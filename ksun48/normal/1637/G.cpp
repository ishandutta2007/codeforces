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

void solve(){
	int n;
	cin >> n;
	if(n == 2){
		cout << -1 << '\n';
		return;
	}
	int G = 1;
	while(G < n) G <<= 1;
	multiset<int> cnum;
	vector<pair<int,int> > ops;
	y_combinator(
		[&](auto self, int k, int mult) -> void {
			if(!k) return;
			int r = 31 - __builtin_clz(k);
			if(k == (1 << r)){
				cnum.insert(k * mult);
				self(k-1, mult);
				return;
			}
			for(int v = k; v > (1 << r); v--){
				ops.push_back({v * mult, ((2 << r) - v) * mult});
				cnum.insert((2 << r) * mult);
			}
			cnum.insert(mult << r);
			self((2 << r) - k - 1, mult);
			self(k - (1 << r), mult << 1);
		}
	)(n, 1);
	for(int v = 1; v < G; v *= 2){
		if(cnum.count(v) >= 2){
			cnum.erase(cnum.find(v));
			cnum.erase(cnum.find(v));
			ops.push_back({v, v});
			cnum.insert(0);
			cnum.insert(2 * v);
			break;
		}
	}
	assert(cnum.count(0));
	cnum.erase(cnum.find(0));
	while(!cnum.empty()){
		int x = *cnum.begin();
		cnum.erase(cnum.begin());
		while(x < G){
			ops.push_back({x, 0});
			ops.push_back({x, x});
			x *= 2;
		}
	}
	ops.push_back({0, G});
	cout << ops.size() << '\n';
	for(auto [x, y] : ops){
		cout << x << ' ' << y << '\n';
	}
	multiset<int> r;
	for(int i = 1; i <= n; i++){
		r.insert(i);
	}
	for(auto [x, y] : ops){
		r.erase(r.find(x));
		r.erase(r.find(y));
		r.insert(x + y);
		r.insert(abs(x - y));
	}
	assert(ops.size() <= 20 * n);
	assert(r.count(G) == n);
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}