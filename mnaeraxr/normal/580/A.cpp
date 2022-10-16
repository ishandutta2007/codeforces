#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	int ans = 1;
	int cur = 1;
	int prev; cin >> prev;

	for (int i = 1; i < n; ++i){
		int ttt; cin >> ttt;
		if (ttt >= prev) ++cur;
		else cur = 1;
		prev = ttt;
		ans = max(cur, ans);
	}

	cout << ans << endl;

	return 0;
}