#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];
	sort(vals.begin(), vals.end());

	int res = 0;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		while(vals[j] < vals[i] - 5) ++j;
		res = max(res, i-j+1);
	}
	cout << res << '\n';
}