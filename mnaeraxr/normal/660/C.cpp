#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1);

	pair<int,int> ans(0, -1);

	for (int i = 1; i <= n; ++i){
		cin >> v[i];
		v[i] = v[i - 1] + 1 - v[i];

		if (v[i] <= k) ans = {i, i};
		else{
			int lo = 0, hi = i;
			while (lo + 1 < hi){
				int m = (lo + hi) / 2;
				if (v[i] - v[m] <= k) hi = m;
				else lo = m;
			}
			ans = max(ans, {i - hi, i});
		}
	}

	cout << ans.first << endl;
	for (int i = 1; i <= n; ++i){
		if (i + ans.first > ans.second && i <= ans.second) cout << 1 << " ";
		else{
			int val = 1 - (v[i] - v[i - 1]);
			cout << val << " ";
		}
	}
	cout << endl;


	return 0;
}