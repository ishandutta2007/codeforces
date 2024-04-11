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
	int n;
	cin >> n;
	n *= 2;
	vector<vector<int> > card(n, vector<int>(2));
	vector<map<int,int> > idx(2);
	auto sgn = [&](int a) -> int {
		return a / abs(a);
	};
	for(int i = 0; i < n; i++){
		cin >> card[i][0] >> card[i][1];
		idx[0][card[i][0]] = i;
		idx[1][card[i][1]] = i;
	}
	vector<vector<int> > ocard = card;
	set<int> exists;
	for(int i = 0; i < n; i++) exists.insert(i);
	vector<vector<int> > ins(n);
	auto check = [&](int v) -> int {
		if(!exists.count(v)) return -1;
		int a = card[v][0];
		int b = card[v][1];
		assert(idx[0].count(-a));
		assert(idx[1].count(-b));
		if(sgn(a) != sgn(b)){
			int p, q;
			if(sgn(a) == -1){
				p = idx[0][-a];
				q = idx[1][-b];
			} else {
				p = idx[1][-b];
				q = idx[0][-a];
			}
			ins[p].push_back(v);
			ins[p].push_back(q);
			ins.push_back({p, v, q});
			for(int x : {p, v, q}){
				idx[0].erase(card[x][0]);
				idx[1].erase(card[x][1]);
			}
			exists.erase(v);
			exists.erase(q);
			if(sgn(a) == -1){
				card[p][0] = card[q][0];
			} else {
				card[p][1] = card[q][1];
			}
			idx[0][card[p][0]] = p;
			idx[1][card[p][1]] = p;
			return p;
		}
		return -1;
	};
	vector<int> b;
	for(int i = 0; i < n; i++) b.push_back(i);
	int s = 0;
	while(s < (int)b.size()){
		int v = b[s];
		s++;
		int k = check(v);
		if(k >= 0) b.push_back(k);
	}
	vector<int> ans;
	for(int i = 0; i < n; i++){
		if(exists.count(i)){
			assert(sgn(card[i][0]) == sgn(card[i][1]));
			if(sgn(card[i][0]) == -1) continue;
			int v = idx[0][-card[i][0]];
			int w = idx[1][-card[i][1]];
			if(v != w){
				cout << "NO" << '\n';
				exit(0);
			}
			exists.erase(i);
			exists.erase(v);
			auto add_vals = y_combinator(
				[&](auto self, int x) -> void {
					ans.push_back(x);
					for(int y : ins[x]){
						self(y);
					}
				}
			);
			add_vals(i);
			add_vals(v);
		}
	}
	vector<vector<int> > seq(2);
	for(int p : ans){
		for(int j = 0; j < 2; j++){
			if(!seq[j].empty() && seq[j].back() > 0 && seq[j].back() == -ocard[p][j]){
				seq[j].pop_back();
			} else {
				seq[j].push_back(ocard[p][j]);
			}
		}
	}
	if((int)ans.size() == n && seq[0].empty() && seq[1].empty()){
		cout << "YES" << '\n';
		for(int p : ans){
			cout << ocard[p][0] << ' ' << ocard[p][1] << '\n';
		}
	} else {
		cout << "NO" << '\n';
	}
}