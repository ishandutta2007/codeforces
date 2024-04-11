#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(m);
	for (int i = 0; i < m; ++i)
		cin >> v[i];
	int f; cin >> f;
	int ans = 0;
	for (int i = 0; i < m; ++i){
		int x = f ^ v[i];
		if (__builtin_popcount(x) <= k)
			++ans;
	}
	cout << ans << endl;
}