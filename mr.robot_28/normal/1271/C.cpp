#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n, sx ,sy;
	cin >> n >> sx >> sy;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		if(x < sx && y < sy)
		{
			cnt1++;
			cnt2++;
		}
		if(x < sx && y > sy)
		{
			cnt1++;
			cnt4++;
		}
		if(x > sx && y < sy)
		{
			cnt2++;
			cnt3++;
		}
		if(x > sx && y > sy)
		{
			cnt3++;
			cnt4++;
		}
		if(x > sx && y == sy)
		{
			cnt3++;
		}
		if(x < sx && y == sy)
		{
			cnt1++;
		}
		if(y < sy && sx == x)
		{
			cnt2++;
		}
		if(y > sy && sx == x)
		{
			cnt4++;
		}
	}
	int h = max(max(cnt1, cnt2), max(cnt3, cnt4));
	cout << h << "\n";
	if(h == cnt1)
	{
		cout << sx - 1 << " " << sy;
	}
	else if(h == cnt2)
	{
		cout << sx << " " << sy - 1;
	}
	else if(h == cnt3)
	{
		cout << sx + 1 << " " << sy;
	}
	else
	{
		cout << sx << " " << sy + 1;
	}
	return 0;
}