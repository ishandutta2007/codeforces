#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if(a > b * c)
		{
			cout << -1 << "\n";
		}
		else if(a <= b * (d - 1))
		{
			cout << a << "\n";
		}
		else
		{
			int cnt = (a + d * b - 1) / (d * b);
			int cnt1 = c / d + 1;
			cnt = min(cnt, cnt1);
			int k1 = (cnt - 1) * (cnt) / 2 * d * b;
	//		cout << cnt << " ";
			int sum = cnt * a - k1;
			cout << sum << "\n";
		}
	}
	return 0;
}