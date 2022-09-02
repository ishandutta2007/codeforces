#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 4 * (ll)1e18;

const int C = 26;
vector<int> conns[C];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		string str;
		cin >> str;
		int n = str.size();

		for (int i = 0; i+1 < n; ++i) {
			int a = str[i] - 'a';
			int b = str[i+1] - 'a';
			
			bool ex = 0;
			for (auto x : conns[a]) {
				if (x == b) ex = 1;
			}
			if (! ex) {
				conns[a].push_back(b);
				conns[b].push_back(a);
			}
		}


		int s = -1;
		for (int i = 0; i < C; ++i) {
			if (conns[i].size() == 1) s = i;
		}

		string res;
		bool fail = (s == -1);
		while(! fail) {
			res.push_back(s + 'a');
			if (conns[s].size() == 1) {
				if (res.size() > 1) break;
				else s = conns[s][0];
			} else if (conns[s].size() == 2) {
				int m = res.size();
				if (res[m-2] - 'a' == conns[s][0]) s = conns[s][1];
				else s = conns[s][0];
			} else {
				fail = 1;
			}
		}

		if (n == 1) fail = false;
		if (! fail) {
			for (int i = 0; i < C; ++i) {
				if (conns[i].empty()) res.push_back('a' + i);
			}
		}

		if (fail) cout << "NO\n";
		else cout << "YES\n" << res << '\n';

		for (int i = 0; i < C; ++i) conns[i].clear();
	}
}