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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	auto solve = y_combinator(
		[&](auto self, vector<int> x) -> int {
			if(x.size() <= 1) return 0;
			int ml = 0;
			for(int a : x){
				if(a == 0) continue;
				ml = max(ml, 31 - __builtin_clz(a));
			}
			vector<int> l, r;
			for(int a : x){
				if((1 << ml) & a){
					l.push_back(a ^ (1 << ml));
				} else {
					r.push_back(a);
				}
			}
			return min(max((int)l.size()-1, 0) + self(r), max((int)r.size()-1, 0) + self(l));
		}
	);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	int ans = solve(a);
	cout << ans << '\n';
}