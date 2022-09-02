#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		cin >> n;

		int diff = 0;
		vector<int> as(2*n);
		for (int& v : as) {
			cin >> v;
			v = 2*v - 3;
			diff += v;
		}
		if (diff < 0) {
			diff *= -1;
			for (int& v : as) v = -v;
		}

		vector<int> offs1 = {0};
		int cur = 0;
		for (int i = n-1; i >= 0; --i) {
			cur += as[i];
			if (cur >= (int)offs1.size()) offs1.push_back(n-i);
		}
		int x = offs1.size();

		vector<int> offs2 = {0};
		cur = 0;
		for (int i = n; i < 2*n; ++i) {
			cur += as[i];
			if (cur >= (int)offs2.size()) offs2.push_back(i+1-n);
		}
		int y = offs2.size();

		int res = 2*n;
		for (int a = x - 1; a >= 0; --a) {
			int b = diff - a;
			if (b >= y || b < 0) continue;
			res = min(res, offs1[a] + offs2[b]);
		}
		cout << res << '\n';
	}
}