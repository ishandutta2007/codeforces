#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <pair <pair <int, int>, int > > events, events1;
	vector <pair <int, int> > qw(n);
	vector <pair <int, int> > qw1(n);
	for(int i = 0; i < n; i++)
	{
		int l, r, l1, r1;
		cin >> l >> r >> l1 >> r1;
		qw[i] = {l1, r1};
		qw1[i] = {l, r};
		events1.push_back({{l1, -1}, i});
		events1.push_back({{r1, 1}, i});
		events.push_back({{l, -1}, i});
		events.push_back({{r, 1}, i});
	}
	sort(events1.begin(), events1.end());
	sort(events.begin(), events.end());
	set <pair <int, int> > t1;
	set <pair <int, int> > t2;
	for(int i = 0; i < events.size(); i++)
	{
		int l1 = qw[events[i].second].first;
		int r1 = qw[events[i].second].second;
		set <pair <int, int> > :: iterator it;
		it = t1.upper_bound({r1, n * 2});
		if(it != t1.end())
		{
			cout << "NO";
			return 0;
		}
		it = t2.upper_bound({-l1, n * 2});
		if(it != t2.end())
		{
			cout << "NO";
			return 0;
		}
		if(events[i].first.second == 1)
		{
			t1.erase({l1, events[i].second});
			t2.erase({-r1, events[i].second});
		}
		else
		{
			t1.insert({l1, events[i].second});
			t2.insert({-r1, events[i].second});
		}
	}
	for(int i = events.size() - 1; i >= 0; i--){
		int l1 = qw[events[i].second].first;
		int r1 = qw[events[i].second].second;
		set <pair <int, int> > :: iterator it;
		it = t1.upper_bound({r1, n * 2});
		if(it != t1.end())
		{
			cout << "NO";
			return 0;
		}
		it = t2.upper_bound({-l1, n * 2});
		if(it != t2.end())
		{
			cout << "NO";
			return 0;
		}
		if(events[i].first.second == -1)
		{
			t1.erase({l1, events[i].second});
			t2.erase({-r1, events[i].second});
		}
		else
		{
			t1.insert({l1, events[i].second});
			t2.insert({-r1, events[i].second});
		}
	}
	for(int i = 0; i < events1.size(); i++)
	{
		int l1 = qw1[events1[i].second].first;
		int r1 = qw1[events1[i].second].second;
		set <pair <int, int> > :: iterator it;
		it = t1.upper_bound({r1, n * 2});
		if(it != t1.end())
		{
			cout << "NO";
			return 0;
		}
		it = t2.upper_bound({-l1, n * 2});
		if(it != t2.end())
		{
			cout << "NO";
			return 0;
		}
		if(events1[i].first.second == 1)
		{
			t1.erase({l1, events1[i].second});
			t2.erase({-r1, events1[i].second});
		}
		else
		{
			t1.insert({l1, events1[i].second});
			t2.insert({-r1, events1[i].second});
		}
	}
	for(int i = events1.size() - 1; i >= 0; i--){
		int l1 = qw1[events1[i].second].first;
		int r1 = qw1[events1[i].second].second;
		set <pair <int, int> > :: iterator it;
		it = t1.upper_bound({r1, n * 2});
		if(it != t1.end())
		{
			cout << "NO";
			return 0;
		}
		it = t2.upper_bound({-l1, n * 2});
		if(it != t2.end())
		{
			cout << "NO";
			return 0;
		}
		if(events1[i].first.second == -1)
		{
			t1.erase({l1, events1[i].second});
			t2.erase({-r1, events1[i].second});
		}
		else
		{
			t1.insert({l1, events1[i].second});
			t2.insert({-r1, events1[i].second});
		}
	}
	cout << "YES";
	return 0;
}