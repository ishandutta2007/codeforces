#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, w, h;
	cin >> n >> w >> h;
	vector <pair <pair <int, int>, int> > mass1;
	vector <pair <pair <int, int>, int> > mass2;
	for(int i = 0; i < n; i++)
	{
		int g, p, t;
		cin >> g >> p >> t;
		if(g == 1)
		{
			mass1.push_back({{t - p, p}, i});
		}
		else
		{
			mass2.push_back({{t - p, p}, i});
		}
	}
	sort(mass1.begin(), mass1.end());
	sort(mass2.begin(), mass2.end());
	vector <pair <int, int> > ans(n);
	int j = 0;
	for(int i = 0; i < mass1.size(); i++)
	{
		while(j < mass2.size() && mass2[j].first.first < mass1[i].first.first)
		{
			j++;
		}
		int y = -1;
		int cnt = 0;
		int j1 = j;
		while(j < mass2.size() && mass2[j].first.first == mass1[i].first.first)
		{
			cnt++;
			y = mass2[j].first.second;
			j++;
		}
		int cnt1 = 0;
		int r = i;
		int x = -1;
		while(r < mass1.size() && mass1[r].first.first == mass1[i].first.first)
		{
			x = mass1[r].first.second;
			cnt1++;
			r++;
		}
		r = i;
		while(r < mass1.size() && mass1[r].first.first == mass1[i].first.first){
			int ind = mass1[r].second;
			cnt1--;
			if(cnt > cnt1)
			{
				y = mass2[j1 + cnt1].first.second;
				ans[ind] = {w, y};
			}
			else
			{
				x = mass1[r + cnt].first.second;
				ans[ind] = {x, h};
			}
			r++;
		}
		i = r - 1;
	}
	j = 0;
	for(int i = 0; i < mass2.size(); i++){
		while(j < mass1.size() && mass1[j].first.first < mass2[i].first.first)
		{
			j++;
		}
		int cnt = 0;
		int j1 = j;
		while(j < mass1.size() && mass1[j].first.first == mass2[i].first.first)
		{
			cnt++;
			j++;
		}
		int cnt1 = 0;
		int r = i;
		while(r < mass2.size() && mass2[r].first.first == mass2[i].first.first)
		{
			cnt1++;
			r++;
		}
		r = i;
		while(r < mass2.size() && mass2[r].first.first == mass2[i].first.first){
			int ind = mass2[r].second;
			int x = -1, y = -1;
			cnt1--;
			if(cnt > cnt1)
			{
				x = mass1[j1 + cnt1].first.second;
				ans[ind] = {x, h};
			}
			else
			{			
				y = mass2[r + cnt].first.second;
				ans[ind] = {w, y};
			}
			r++;
		}
		i = r - 1;
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
    return 0;
}