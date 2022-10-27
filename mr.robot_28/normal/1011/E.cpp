#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		int d = __gcd(a, k);
		ans = __gcd(ans, d);
	}
	cout << k / ans << "\n";
	for(int i = 0; i * ans < k; i++)
	{
		cout << i * ans << " ";
	}
	return 0;
}