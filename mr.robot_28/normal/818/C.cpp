#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int d;
	cin >> d;
	int n, m;
	cin >> n >> m;
	vector <vector <int> > x(d, vector <int> (4));
	vector <int> minx, maxx, miny, maxy;
	for(int i = 0; i < d; i++)
	{
		cin >> x[i][0] >> x[i][1] >> x[i][2] >> x[i][3];
		if(x[i][0] > x[i][2])
		{
			swap(x[i][0], x[i][2]);
		}
		if(x[i][1] > x[i][3])
		{
			swap(x[i][1], x[i][3]);
		}
		minx.push_back(min(x[i][0], x[i][2]));
		maxx.push_back(max(x[i][0], x[i][2]));
		miny.push_back(min(x[i][1], x[i][3]));
		maxy.push_back(max(x[i][1], x[i][3]));
	}
	int cntleft, cntright, cntup, cntdown;
	cin >> cntleft >> cntright >> cntup >> cntdown;
	sort(maxx.begin(), maxx.end());
	sort(minx.begin(), minx.end());
	sort(maxy.begin(), maxy.end());
	sort(miny.begin(), miny.end());
	for(int i = 0; i < d; i++)
	{
		int cnt1 = lower_bound(minx.begin(), minx.end(), max(x[i][0], x[i][2])) - minx.begin();
		int cnt2 = (d - (upper_bound(maxx.begin(), maxx.end(), min(x[i][0], x[i][2])) - maxx.begin()));
		if(x[i][2] > x[i][0])
		{
			cnt1--;
			cnt2--;
		}
		int cnt3 = lower_bound(miny.begin(), miny.end(), max(x[i][1], x[i][3])) - miny.begin();
		int cnt4 = (d - (upper_bound(maxy.begin(), maxy.end(), min(x[i][1], x[i][3])) - maxy.begin()));
		if(x[i][3] > x[i][1])
		{
			cnt4--;
			cnt3--;
		}
		if(cnt1 == cntleft && cnt2 == cntright && cnt3 == cntup && cnt4 == cntdown)
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << -1;
	return 0;
}