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
	vector<vector<int> > lines = {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8},
		{2, 4, 6},
	};
	vector<int> masks;
	for (vector<int> x : lines){
		int a = 0;
		for (int y : x) a ^= (1 << y);
		masks.push_back(a);
	}
	map<pair<int,int>, int > ways;
	map<pair<int,int>, int> winX;
	map<pair<int,int>, int> winO;
	set<pair<int,int> > game_over;
	y_combinator(
		[&](auto self, vector<pair<int,int> > history) -> void {
			ways[history.back()]++;
			auto [x, y] = history.back();
			int turn = 1 & __builtin_popcount(x ^ y);
			int win = 0;
			for (int v : masks){
				if ((x & v) == v) win = 1;
				if ((y & v) == v) win = -1;
			}
			if (win != 0){
				for (pair<int,int> p : history){
					(win == 1 ? winX : winO)[p] += 1;
				}
				game_over.insert({x, y});
			} else {
				int nmoves = 0;
				for (int j = 0; j < 9; j++){
					if (x & (1 << j)) continue;
					if (y & (1 << j)) continue;
					nmoves++;
					if (turn == 0){
						vector<pair<int,int> > nhistory = history;
						nhistory.push_back({x ^ (1 << j), y});
						self(nhistory);
					} else {
						vector<pair<int,int> > nhistory = history;
						nhistory.push_back({x, y ^ (1 << j)});
						self(nhistory);
					}
				}
				if (!nmoves) game_over.insert({x, y});
			}
		}
	)(vector<pair<int,int> > {{0, 0}});
	string s;
	for (int i = 0; i < 3; i++){
		string t;
		cin >> t;
		s += t;
	}
	int x = 0, o = 0;
	for (int i = 0; i < 9; i++){
		if (s[i] == 'X') x ^= (1 << i);
		if (s[i] == '0') o ^= (1 << i);
	}
	if (!ways.count({x, o})){
		cout << "illegal" << '\n';
	} else if (game_over.count({x, o})){
		if (winX[{x, o}]){
			cout << "the first player won" << '\n';
		} else if (winO[{x, o}]){
			cout << "the second player won" << '\n';
		} else {
			cout << "draw" << '\n';
		}
	} else {
		int turn = __builtin_popcount(x) - __builtin_popcount(o);
		if (turn){
			cout << "second" << '\n';
		} else {
			cout << "first" << '\n';
		}
	}
}