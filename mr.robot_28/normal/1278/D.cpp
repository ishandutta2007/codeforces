#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
const int  CONST = 998244353;
vector <int> dsu, rang;
int get(int a)
{
	if(dsu[a] == a) return a;
	else return dsu[a] = get(dsu[a]);
}
void unite(int a, int b)
{
	a = get(a);
	b = get(b);
	if(a != b)
	{
		if(rang[a] > rang[b])
		{
			swap(a, b);
		}
		dsu[a] = b;
		if(rang[a] == rang[b]){
			rang[b]++;
		}
	}
}
bool cmp(pair <int, int> a, pair <int, int> b)
{
	if(a.first == b.first)
	{
		return a.second > b.second;
	}
	else
	{
		return a.first < b.first;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	dsu.resize(n);
	rang.resize(n);
	for(int i = 0; i < n; i++)
	{
		dsu[i] = i;
		rang[i] = 0;
	}
	vector <pair <int, int> > A;
	vector <pair <int, int> > events;
	for(int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		A.push_back({l - 1, r - 1});
		events.push_back({l - 1, i});
		events.push_back({r - 1, i});
	}
	sort(events.begin(), events.end());
	sort(A.begin(), A.end(), cmp);
	int cnt = 0;
	set <pair <int, int> > H;
	for(int i = 0; i < n; i++)
	{
		if(cnt >= n)
		{
			break;
		}
		set <pair <int, int> > :: iterator it;
		it = H.lower_bound({A[i].first, 0});
		for(; it != H.end(); it++)
		{
			if(it -> first >= A[i].second)
			{
				break;
			}
			unite(i, it -> second);
			cnt++;
			if(cnt >= n)
			{
				break;
			}
		}
		H.insert({A[i].second, i});
	}
	if(cnt != n - 1)
	{
		cout << "NO";
		return 0;
	}
	set <int> k;
	for(int i = 0; i < n; i++)
	{
		k.insert(get(i));
	}
	if(k.size() > 1)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
	return 0;
}