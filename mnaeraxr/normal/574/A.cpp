#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int ans = 0;
	while (true){
		pii m(v[0], 0);
		for (int i = 1; i < n; ++i){
			if (v[i] >= m.first)
				m = {v[i], i};
		}
		if (m.second == 0) break;
		ans++;
		v[m.second]--;
		v[0]++;
	}

	cout << ans << endl;

	return 0;
}