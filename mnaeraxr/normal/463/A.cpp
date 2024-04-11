#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s;
	int ans = 100;
	bool ok = false;
	for (int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		if (x < s && y > 0)
			ans = min(ans, y);
		if (x < s || (x == s && y == 0))
			ok = true;
	}
	if (ok) cout << 100 - ans << endl;
	else cout << -1 << endl;

	return 0;
}