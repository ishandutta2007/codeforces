#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long ll;

using namespace std;

int run() {
	int n, r;
	cin >> n >> r;
	vector <int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	sort(x.begin(), x.end());
	int ans = 1, sum = r;
	for (int i = (int)x.size() - 2; i >= 0; i--)
		if (x[i + 1] != x[i] && x[i] <= sum)
			break;
		else if (x[i + 1] != x[i])
			sum += r, ans++;
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		cout << run() << '\n';
	return 0;
}