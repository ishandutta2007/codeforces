#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	// Trivial way: flip first if necessary, then flip it to the correct position
	// Need to support operation: flip range, reverse range
	// Just maintain the middle interval string. We need access to both ends and a "flip all" operation

	string src, tar;
	cin >> src >> tar;

	// Active range
	int a = 0;
	int b = n-1;
	int rev = 0;
	int flip = 0;

	vector<int> ops;
	for (int i = 0; i < n; ++i) {
		int t = n-1-i;
		int f = (rev ? b : a);
		if ((src[f] == '1') ^ flip == (tar[t] == '1')) {
			ops.push_back(1);
		}

		ops.push_back(t+1);
		if (rev) --b;
		else ++a;
		rev ^= 1;
		flip ^= 1;
	} 

	cout << ops.size() << '\n';
	for (auto i : ops) cout << i << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}


	
}