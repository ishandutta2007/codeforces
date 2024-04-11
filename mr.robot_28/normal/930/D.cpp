#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans = 0;
int max(int a, int b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}
void solve(vector <pair <int, int> > x)
{
	multiset <int> a, b;
	for(int i = 0; i < x.size(); i++)
	{
		b.insert(x[i].second);
	}
	int l = 0;
	for(int i = 0; i <= 2000000; i++)
	{
		while(l < x.size() && x[l].first <= i)
		{
			b.erase(b.find(x[l].second));
			a.insert(x[l].second);
			l++;
		}
		int t1 = 1e5;
		if(a.size() != 0)
		{
			t1 = *a.begin();
		}
		int t2 = 1e5;
		if(b.size() != 0)
		{
			t2 = *b.begin();
		}
		int t3 = -1e5;
		if(a.size() != 0)
		{
			t3 = *a.rbegin();
		}
		int t4 = -1e5;
		if(b.size() != 0)
		{
			t4 = *b.rbegin();
		}
		ans += max(0, min(t3, t4) - max(t1, t2));
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <pair <int, int> > a, b;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		x += 1e5;
		y += 1e5;
		if((x + y) % 2 == 0)
		{
			a.push_back({(x + y) / 2, (x - y + 200000) / 2});
		}
		else
		{
			b.push_back({(x + y) / 2, (x - y + 200000) / 2});
		} 
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	solve(a);
	solve(b);
	cout << ans;
	return 0; 
}