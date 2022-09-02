#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> cs(n);
	for (int i = 0; i < n; ++i) cin >> cs[i];
	
	int a = 0;
	int b = n-1;
	int p = 0;
	vector<char> res;
	while(a <= b) {
		if (cs[a] == cs[b]) {
			if (cs[a] <= p) break;

			int la = 1;
			int lb = 1;
			for (int i = a+1; i <= b; ++i) {
				if (cs[i] <= cs[i-1]) break;
				++la;
			}
			for (int i = b-1; i >= a; --i) {
				if (cs[i] <= cs[i+1]) break;
				++lb;
			}
			if (la >= lb) {
				for (int i = 0; i < la; ++i) res.push_back('L');
			} else {
				for (int i = 0; i < lb; ++i) res.push_back('R');
			}
			break;
		} else {
			if ((cs[a] > p) && (cs[a] < cs[b] || cs[b] <= p)) {
				res.push_back('L');
				p = cs[a];
				++a;
			} else if ((cs[b] > p) && (cs[a] > cs[b] || cs[a] <= p)) {
				res.push_back('R');
				p = cs[b];
				--b;
			} else {
				break;
			}
		}
	}

	cout << res.size() << '\n';
	for (auto c :res) cout << c; cout << '\n';
}