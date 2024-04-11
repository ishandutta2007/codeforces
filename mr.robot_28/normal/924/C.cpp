#include<bits/stdc++.h>

using namespace std;

signed main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	int maxst = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector <int> t(n);
	for(int i = n - 1, val = 0; i >= 0; i--)
	{
		val = max(val - 1, 0);
		val = max(val, a[i] + 1);
		t[i] = val;
	}
	long long ans = 0;
	for(int i = 0, val = 0; i < n; i++)
	{
		val = max(val, t[i]);
		ans += val;
	}
	for(int i= 0; i < n; i++)
	{
		ans -= (a[i] + 1);
	}
	cout << ans;
	return 0;
}