#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	bool can = 1;
	ll sum = 0;
	vector<int> ls(m);
	for (int i = 0; i < m; ++i) {
		cin >> ls[i];
		sum += ls[i];
		if (i + ls[i] >= n+1) can = 0;
	}
	can &= (sum >= n);

	if (can) {
		int a = 0;
		for (int i = 0; i < m; ++i) {
			a = max((ll)a, n - sum);
			cout << a+1 << ' ';

			++a;
			sum -= ls[i];
		}
		cout << '\n';
	} else cout << -1 << '\n';

}