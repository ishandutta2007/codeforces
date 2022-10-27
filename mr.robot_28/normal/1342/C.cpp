#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, q;
		cin >> a >> b >> q;
		int e = a * b / __gcd(a, b);
		while(q--)
		{
			int l, r;
			cin >> l >> r;
			int left = (l / e) * e;
			int ans = 0;
			if(left < l)
			{
				if(left + max(a, b) - 1 >= l)
				{
					ans += min(left + max(a, b), r + 1) - l;
				}
				left += e;
			}
			int right = (r / e) * e;
			if(right + max(a, b) - 1 >= r && right >= l)
			{
				ans += r - right + 1;
			}
			else if(right >= l)
			{
				ans += max(a, b);
			}
			if(right >= left && left >= l)
			{
				ans += (right - left) / e * max(a, b);
			}
			cout << r - l + 1 - ans << " ";
		}
		cout << "\n";
	}
	return 0;
}