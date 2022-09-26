#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int tt; cin >> tt;
	while (tt--) {
		set<int> s;
		vector<double> vec;
		int n; cin >> n;
		while (n--) {
			int x; cin >> x;
			if (s.find(x) != s.end()) {
				vec.push_back((double)x);
				s.erase(x);
			}
			else s.insert(x);
		}
		sort(vec.begin(), vec.end());
		pair<double,int> opt = make_pair(double(1e9), -1);
		for (int i = 1; i < vec.size(); ++i) {
			opt = min(opt, make_pair(vec[i] / vec[i - 1] + vec[i - 1] / vec[i], i));
		}
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				cout << vec[opt.second - i] << ' ';
			}
		}
		cout << '\n';
	} 	
}