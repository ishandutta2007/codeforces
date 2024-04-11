#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if(e > f)
	{
		int ans = 0;
		ans += min(a, d) * e;
		d -= min(a, d);
		ans += min(min(b, c), d) * f;
		cout << ans;
	}
	else
	{
		int ans = 0;
		ans += min(min(b, c), d) * f;
		d -= min(min(b, c), d);
		ans += min(a, d) * e;
		cout << ans;
	}
	return 0;
}