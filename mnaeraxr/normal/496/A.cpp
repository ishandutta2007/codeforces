#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> v(n);
	int val = 0, ans = -1;

	for (int i = 0; i < n; ++i){
		cin >> v[i];
		if (i) val = max(val, v[i] - v[i - 1]);
	}

	for (int i = 1; i + 1 < n; ++i){
		int cur = max(v[i + 1] - v[i - 1], val);
		ans = ans == -1 ? cur : min(ans, cur);
	}

	cout << ans << endl;

	return 0;
}