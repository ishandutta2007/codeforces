#include<bits/stdc++.h>
using namespace std;
#define double long double
const double eps = 1e-9;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> k;
	double x = 1;
	double y = 1;
	if(x * x + 3 * y * y > 4 * k * k)
	{
		cout << 0;
		return 0;
	}
	int cnt = 1;
	while((x * x + 3 * (y + 2) * (y + 2)) <= 4 * k * k && (x + 1) * (x + 1) + 3 * (y + 1) * (y + 1) <= k * k * 4)
	{
		y += 2;
		cnt += 2;
	}
	bool fl = false;
	while(true){
		x += 3;
		y += 1;
		while(y > 0 && ((x * x + 3 * y * y) > 4 * k * k || (x + 1) * (x + 1) + 3 * (y - 1) * (y - 1) > 4 * k * k))
		{
			y -= 2;
		}
		if(y < 0)
		{
			break;
		}
		if(fl)
		{
			cnt += 2;
		}
		int t = (y / (2));
		cnt += t * 4;
		fl = !fl;
	}
	cout << cnt;
	return 0;
}