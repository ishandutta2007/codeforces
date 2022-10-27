#include<bits/stdc++.h>
using namespace std;
#define int long long
const int CONST = 1e9 + 7;

signed main() {
	int n, m;
	cin >> n >> m;
	vector <pair <int, pair <int, int> > > A(m);
	for(int i = 0; i < m; i++)
	{
		cin >> A[i].first >> A[i].second.first;
		A[i].second.second = i;
	}
	vector <pair <int, int> > ans(m);
	sort(A.begin(), A.end());
	int cnt = 0;
	vector <int> minedge(n);
	set <pair <int, int> > Min;
	vector <int> edge(n);
	vector <int> next(n);
	for(int i = 0; i < m; i++)
	{
		if(A[i].second.first)
		{
			ans[A[i].second.second] = {cnt, cnt + 1};
			edge[cnt] = A[i].first;
			next[cnt] = cnt + 2;
			cnt++;
		}
	}
	for(int i = 0; i < n - 2; i++)
	{
		minedge[i] = max(edge[i + 1], edge[i]);
		Min.insert({minedge[i], i});
	}
	int j = 0;
	while(j < m && A[j].second.first == 1)
	{
		j++;
	}
	while(j < m && Min.size() > 0)
	{
		pair <int, int> v = *Min.begin();
		Min.erase(Min.begin());
		if(v.first > A[j].first)
		{
			cout << -1;
			return 0;
		}
		ans[A[j].second.second] = {v.second, next[v.second]};
		minedge[v.second] = max(minedge[v.second], edge[next[v.second]]);
		next[v.second]++;
		if(next[v.second] < n)
		{
			Min.insert({minedge[v.second], v.second});
		}
		j++;
		while(j < m && A[j].second.first == 1)
		{
			j++;
		}
	}
	for(int i = 0; i < m; i++)
	{
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
	}
	return 0;
}