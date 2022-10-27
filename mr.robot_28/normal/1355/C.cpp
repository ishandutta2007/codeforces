#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = 0;
	int j = a;
	int j1 = a;
	for(int i = c; i <= d; i++)
	{
		while(j <= b && i - j + 1 > c)
		{
			j++;
		}
		while(j1 <= b && i - j1 + 1 > b)
		{
			j1++;
		}
		ans += (b - j1 + 1) * (c - b + 1);
		ans += (j1 - j) * (c - (i - j + 1) + 1 + c - (i - (j1 - 1) + 1) + 1) / 2;
	}
	cout << ans;
    return 0;
}