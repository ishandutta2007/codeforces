#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	vector<int> as(n);
	for (int& a : as) cin >> a;
	sort(as.begin(), as.end());
	while(!as.empty() && as.back() >= x) as.pop_back();

	bool fail = 0;
	int curv = 0, curc = 0;
	if (! as.empty()) {
		as.push_back(x);
		for (int a : as) {
			while(a > curv) {
				int dv = curv + 1;
				if (curc % dv != 0) {
					fail = 1;
					break;
				}
				curc /= dv;
				curv += 1;
			}
			if (fail) break;
			++curc;
		}
	}

	if (! fail) cout << "Yes\n";
	else cout << "No\n";
}