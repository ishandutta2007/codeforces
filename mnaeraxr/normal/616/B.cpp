#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n; ++i){
		int cur; cin >> cur;
		for (int j = 1; j < m; ++j){
			int t; cin >> t;
			cur = min(cur, t);
		}
		ans = max(cur, ans);
	}

	cout << ans << endl;

	return 0;
}