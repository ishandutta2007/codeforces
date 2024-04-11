#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0;  i< n; i++)
	{
		cin >> a[i];
	}
	int sty = 0;
	vector <pair <int, int> > ans;
	deque <pair <int, int> > st;
	set <pair <int, int> > st1;
	for(int i = n - 1; i >= 0; i--)
	{
		if(a[i] == 1)
		{
			st.push_back({i + 1, sty + 1});
			ans.push_back({i + 1, sty + 1});
			sty++;
		}
		else if(a[i] == 2) 
		{
			if(st.size() == 0)
			{
				cout << -1;
				return 0;
			}
			ans.push_back({i + 1, st.back().second});
			st1.insert(ans.back());
			st.pop_back();
		}
	}
	while(st.size() > 0)
	{
		st1.insert(st.back());
		st.pop_back();
	}
	int xmin = -1, ymin = -1;
	if(st1.size() != 0)
	{
		xmin = st1.rbegin() -> first;
		ymin = st1.rbegin() -> second;
	}
	xmin--;
	for(int i = n - 1; i >= 0; i--)
	{
		if(a[i] == 3)
		{
			if(xmin == -1 || xmin < i)
			{
				cout << -1;
				return 0;
			}
			ans.push_back({xmin + 1, sty + 1});
			ans.push_back({i + 1, sty + 1});
			ymin = sty;
			xmin = i;
			sty++;
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)
	{
		ans[i].second = n - ans[i].second + 1;
		swap(ans[i].first, ans[i].second);
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}