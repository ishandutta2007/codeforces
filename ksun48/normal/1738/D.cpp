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
	int N;
	cin >> N;
	vector<int> b(N+2);
	for(int i = 1; i <= N; i++){
		cin >> b[i];
	}
	vector<vector<int> > ch(N+2);
	for(int i = 1; i <= N; i++){
		ch[b[i]].push_back(i);
	}
	int root = 0;
	if(ch[root].empty()) root = N+1;
	assert(!ch[root].empty());
	vector<int> val(N+2);
	y_combinator(
		[&](auto self, int v) -> void {
			val[v] = 1;
			for(int w : ch[v]){
				self(w);
				val[v] = max(val[v], val[w] + 1);
			}
		}
	)(root);
	vector<int> side(N+2);
	vector<int> ord;
	y_combinator(
		[&](auto self, int v, int s) -> void {
			side[v] = s;
			sort(ch[v].begin(), ch[v].end(), [&](int x, int y) { return val[x] < val[y]; });
			ord.push_back(v);
			for(int w : ch[v]){
				self(w, 1 ^ s);
			}
		}
	)(root, 0);
	side[N+1-root] = 1;
	int x = 0;
	while(side[x] == side[x+1]) x++;
	cout << x << '\n';
	for(int i = 1; i <= N; i++){
		cout << ord[i] << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}