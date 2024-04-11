#include <bits/stdc++.h>
using namespace std;
using ld = long double;

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
	int n, d;
	cin >> n >> d;
	vector<vector<int> > c(10);
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		c[a%10].push_back(a);
	}
	vector<vector<pair<int, ld> > > cands(10);
	vector<vector<vector<int> > > used(10);
	for(int i = 0; i < 10; i++){
		sort(c[i].begin(), c[i].end());
		used[i].push_back({});
		cands[i].push_back({1, ld(0)});
		for(int r = 0; r < 4; r++){
			if(r > c[i].size()) continue;
			ld sum = 0;
			int prod = 1;
			for(int j = r; j < (int)c[i].size(); j++){
				sum += log(ld(c[i][j]));
				prod = (prod * i) % 10;
			}
			cands[i].push_back({prod, sum});
			used[i].push_back(vector<int>(c[i].begin() + r, c[i].end()));
		}
	}
	ld best = -1;
	vector<int> best_cur;
	vector<int> emp;
	y_combinator(
		[&](auto self, int k, vector<int> cur) -> void {
			if(k == 10){
				int prod = 1;
				for(int i = 0; i < 10; i++){
					prod = (prod * cands[i][cur[i]].first) % 10;
				}
				if(prod == d){
					ld res = 0;
					for(int i = 0; i < 10; i++){
						prod = (prod * cands[i][cur[i]].first) % 10;
						res += cands[i][cur[i]].second;
					}
					if(res > 0.0001){
						if(res > best){
							best = res;
							best_cur = cur;
						}						
					}
				}
			} else {
				for(int j = 0; j < cands[k].size(); j++){
					cur.push_back(j);
					self(k+1, cur);
					cur.pop_back();
				}
			}
		}
	)(0, emp);
	if(best < -0.5){
		cout << -1 << '\n';
	} else {
		vector<int> cards;
		for(int i = 0; i < 10; i++){
			cards.insert(cards.end(), used[i][best_cur[i]].begin(), used[i][best_cur[i]].end());
		}
		cout << cards.size() << '\n';
		for(int x : cards){
			cout << x << ' ';
		}
		cout << '\n';
	}

}