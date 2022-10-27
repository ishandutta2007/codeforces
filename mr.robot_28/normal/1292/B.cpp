#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, y, ax, ay, bx, by;
	cin >> x >> y >> ax >> ay >> bx >> by;
	int xs, ys, t;
	cin >> xs >> ys >> t;
	vector <pair <int, int> > point;
	while(x < 2e16 && y < 2e16)
	{
		point.push_back({x, y});
		x = x * ax + bx;
		y = y * ay + by;
	}
	int n = point.size();
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int t1 = t, t2 = t;
		int cnt1 = 1, cnt2 = 1;
		t1 -= abs(point[i].first - xs) + abs(point[i].second - ys);
		t2 -= abs(point[i].first - xs) + abs(point[i].second - ys);
		for(int j = i - 1; j >= 0; j--)
		{
			if(t1 >= abs(point[j].first - point[j + 1].first) + abs(point[j].second - point[j + 1].second))
			{
				cnt1++;
				t1 -= abs(point[j].first - point[j + 1].first) + abs(point[j].second - point[j + 1].second);
			}
			else
			{
				break;
			}
		}
		int st1 = 0;
		for(int j = i + 1; j < n; j++)
		{
			if(t1 >= abs(point[j].first - point[st1].first) + abs(point[j].second - point[st1].second))
			{
				cnt1++;
				t1 -= abs(point[j].first - point[st1].first) + abs(point[j].second - point[st1].second);
			}
			else
			{
				break;
			}
			st1 = j;
		}
		for(int j = i + 1; j < n; j++)
		{
			if(t2 >= abs(point[j].first - point[j - 1].first) + abs(point[j].second - point[j - 1].second))
			{
				cnt2++;
				t2 -= abs(point[j].second - point[j - 1].second) + abs(point[j].first - point[j - 1].first);
			}
			else
			{
				break;
			}
		}
		int st2 = n - 1;
		for(int j = i - 1; j >= 0; j--)
		{
			if(t2 >= abs(point[j].first - point[st2].first) + abs(point[j].second - point[st2].second))
			{
				cnt2++;
				t2 -= abs(point[j].first - point[st2].first) + abs(point[j].second - point[st2].second);
			}
			else
			{
				break;
			}
		}
		if(t1 >= 0)
		{
			ans = max(ans, cnt1);
		}
		if(t2 >= 0)
		{
			ans = max(ans, cnt2);
		}
	}
	cout << ans;
	return 0;
}