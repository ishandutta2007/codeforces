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
	int n, m;
	cin >> n >> m;
	vector<vector<int> > color(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> color[i][j];
		}
	}
	vector<tuple<int,int,int> > ops;
	for(int si = 0; si < n-1; si++){
		for(int sj = 0; sj < m-1; sj++){
			y_combinator(
				[&](auto self, int i, int j) -> void {
					if(i < 0 || j < 0 || i >= n-1 || j >= m-1) return;
					int c = 0;
					for(int r : {i, i+1}){
						for(int s : {j, j+1}){
							c |= color[r][s];
						}
					}
					bool works = true;
					for(int r : {i, i+1}){
						for(int s : {j, j+1}){
							if(color[r][s] != 0 && color[r][s] != c){
								works = false;
							}
						}
					}
					if(c && works){
						ops.push_back({i, j, c});
						for(int r : {i, i+1}){
							for(int s : {j, j+1}){
								color[r][s] = 0;
							}
						}
						for(int r : {i-1, i, i+1}){
							for(int s : {j-1, j, j+1}){
								self(r, s);
							}
						}
					}
				}
			)(si, sj);
		}
	}
	if(color == vector<vector<int> > (n, vector<int>(m, 0))){
		reverse(ops.begin(), ops.end());
		cout << ops.size() << '\n';
		for(auto [x, y, c] : ops){
			cout << (x+1) << ' ' << (y+1) << ' ' << c << '\n';
		}
	} else {
		cout << -1 << '\n';
	}
}