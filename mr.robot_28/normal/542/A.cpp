#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int>cost;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <pair <pair <int, int>, int> > scan;
	int ans = 0;
	int ind1 = 0, ind2 = 0;
	vector <int> left1(n), right1(n);
	for(int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		left1[i] = l;
		right1[i] = r;
		scan.push_back({{l, -2}, i});
	}
	cost.resize(m);
	vector <int> left(m), right(m);
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		left[i] = a;
		right[i] = b;
		cost[i] = c;
		scan.push_back({{a, -1}, i});
	}
	sort(scan.begin(), scan.end());
	int maxr = 0;
	int p = -1;
	set <pair <int, int>  >s;
	for(int i=  0; i < scan.size(); i++)
	{
		if(scan[i].first.second == -2)
		{
			set <pair <int, int> > :: iterator it;
			it = s.lower_bound({right1[scan[i].second], 0});
			if(it != s.end() && cost[it -> second] * (right1[scan[i].second] - scan[i].first.first) > ans)
			{
				ans = cost[it -> second] * (right1[scan[i].second] - scan[i].first.first);
				ind2 = it -> second;
				ind1 = scan[i].second;
			}
			int ind = scan[i].second;
			if(right1[ind] > maxr)
			{
				maxr = right1[ind];
				p =ind;
			}
		}
		else if(p != -1 && (min(maxr, right[scan[i].second]) - scan[i].first.first) * cost[scan[i].second] > ans) 
		{
			ind1 = p;
			ind2 = scan[i].second;
			ans = (min(maxr, right[scan[i].second]) - scan[i].first.first) * cost[scan[i].second];
		}
		if(scan[i].first.second == -1)
		{
			set <pair <int, int> > :: iterator it;
			it = s.upper_bound({right[scan[i].second], 1e9});
			vector <pair <int, int> > del;
			while(it != s.begin())
			{
				it--;
				if(cost[it -> second] <= cost[scan[i].second])
				{
					del.push_back(*it);
				}
				else
				{
					break;
				}
			}
			for(int j = 0; j < del.size(); j++)
			{
				s.erase(del[j]);
			}
			s.insert({right[scan[i].second], scan[i].second});
		}
	}
	scan.clear();
	for(int i = 0; i < n; i++)
	{
		scan.push_back({{right1[i], 2}, i});
	}
	for(int i = 0; i < m; i++)
	{
		scan.push_back({{right[i], 1}, i});
	}
	int minl = 1e9 + 1;
	p = -1;
	sort(scan.begin(), scan.end());
	for(int i = scan.size() - 1;  i >= 0; i--)
	{
		if(scan[i].first.second == 2)
		{
			int ind = scan[i].second;
			if(left1[ind] < minl)
			{
				minl = left1[ind];
				p = ind;
			}
		}
		else if(p != -1 && (scan[i].first.first - max(left[scan[i].second], minl)) * cost[scan[i].second] > ans)
		{
			ans = (scan[i].first.first - max(left[scan[i].second], minl)) * cost[scan[i].second];
			ind1 = p;
			ind2 = scan[i].second;
		}
	}
	cout << ans << "\n";
	if(ans != 0)
	{
	 cout << ind1 + 1 << " " << ind2 + 1;
	}
	return 0;
}