#include<bits/stdc++.h>
 
using namespace std;

#define int long long
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, d, m;
	cin >> n >> d >> m;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	int sum1 = 0;
	sort(a.begin(), a.end());
	vector <int> pref(n + 1, 0);
	int c1 = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		if(a[i] <= m)
		{
			pref[c1 + 1] = pref[c1] + a[i];
			c1++;
		}
	}
	ans = max(ans, pref[c1]);
	for(int j = 1; j <= n; j++)
	{
		if(a[n - j] > m)
		{
			sum1 += a[n - j];
			int c2 = n - j - c1;
			if((j - 1) * (d + 1) + 1 <= n && c2 <= (j) * d)
			{
				int sum = sum1 + pref[n - j - max(c2, ((j - 1) * (d)))];
				ans = max(ans, sum);
			}
		}
	}
	cout << ans;
	return 0;
}