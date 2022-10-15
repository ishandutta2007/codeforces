#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	int sq = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = LONG_MAX;
		int t = sqrtl(a[i]);
		if (t * t == a[i])
		{
			sq++;
		}
		else
		{
			for (int j = t - 1; j <= t + 1; j++)
				b[i] = min(b[i], abs(j * j - a[i]));
		}
	}
	if (sq < n / 2)
	{
		ll ans = 0;
		sort(b.begin(), b.end());
		for (int i = 0; i < n / 2 - sq; i++)
			ans += b[i];
		cout << ans;
	}
	else
	{
		int ans = 0, e = sq - n / 2;
		sort(a.begin(), a.end());
		for (int i = n - 1; i >= 0, e > 0; i--)
		{
			int t = sqrtl(a[i]);
			if (t * t == a[i])
			{
				e--;
				ans++;
				if (a[i] == 0)
					ans++;
			}
		}
		cout << ans;
	}
	return 0;
}