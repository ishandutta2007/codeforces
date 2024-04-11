#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			for(int d = j; d < n; d++)
			{
				ans = max(ans, a[i] | a[j] | a[d]);
			}
		}
	}
	cout << ans;
	return 0;
}