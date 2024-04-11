#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int N;
	cin >> N;
	pair<int, int> left{2e9, 0}, right{0, 0}, longest{-1, 0};
	for (int i=1;i<=N;i++){
		int s, e, c; cin >> s >> e >> c;
		pair<int, int> l(s, c), r(e, -c);
		left = min(left, {s, c});
		right = max(right, {e, -c});
		longest = max(longest, {e-s, -c});
		int ans = left.second-right.second;
		if (longest.first == right.first-left.first){
			ans = min(ans, -longest.second);
		}
		cout << ans << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;) solve();
}