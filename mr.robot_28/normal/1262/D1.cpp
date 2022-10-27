#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair <int, int> a, pair <int, int> b)
{
	if(a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first > b.first;
}
vector <int> t;
void update(int v, int l, int r, int ind)
{
	t[v]++;
	if(l == r)
	{
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) /2 , ind);
	}
	else
	{
		update(v * 2 + 1, (r + l) /2  + 1, r, ind);
	}
}
int query(int v, int l, int r, int cnt)
{
	if(l == r)
	{
		return l;
	}
	if(t[v * 2] >= cnt)
	{
		return query(v * 2, l, (r + l) / 2, cnt);
	}
	else
	{
		return query(v * 2 + 1, (r + l) / 2 + 1, r, cnt - t[v * 2]);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	t.resize(4 * n);
	vector <pair <int, int> > a(n);
	vector <int> e(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
		e[i] = a[i].first;
	}
	sort(a.begin(), a.end(), cmp);
	int m;
	cin >> m;
	vector <pair <pair <int, int>, int> > quest(m);
	for(int i = 0; i < quest.size(); i++)
	{
		cin >> quest[i].first.first >> quest[i].first.second;
		quest[i].second = i;
	}
	sort(quest.begin(), quest.end());
	int pred = 0;
	vector <int> ans(m);
	for(int i = 0; i < m; i++)
	{
		while(pred < quest[i].first.first){
			update(1, 0, n - 1, a[pred].second);
			pred++;
		}
		ans[quest[i].second] = query(1, 0, n - 1, quest[i].first.second); 
	}
	for(int i = 0; i < m; i++)
	{
		cout << e[ans[i]] << "\n";
	}
	return 0;
}