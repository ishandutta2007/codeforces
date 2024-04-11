#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int a[maxn] , q[maxn] , num[maxn] , par[maxn];

bool visited[maxn];

vector<int> ind[maxn] , cycle[maxn];

int f(int v)
{
	return (par[v] == -1)? v : par[v] = f(par[v]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(par , -1 , sizeof par);

	int n , s;
	cin >> n >> s;

	vector<int> tmp;
	for(int i = 0; i < n; i++)
		cin >> a[i] , tmp.pb(a[i]);

	sort(tmp.begin() , tmp.end());
	tmp.resize(unique(tmp.begin() , tmp.end()) - tmp.begin());

	for(int i = 0; i < n; i++)
		a[i] = lower_bound(tmp.begin() , tmp.end() , a[i]) - tmp.begin();

	for(int i = 0; i < n; i++)
		ind[a[i]].pb(i);

	int t = 0;

	for(int i = 0; i < (int)tmp.size(); i++)
	{
		int sz = ind[i].size();
		vector<int> tmp2 = ind[i];

		for(auto &x : ind[i])
			if(t <= x && x < t + sz)
			{
				a[x] = x;
				visited[x] = 1;
				x = 1e9;
			}

		sort(ind[i].begin() , ind[i].end());

		while(!ind[i].empty() && ind[i].back() > n)
			ind[i].pop_back();

		tmp2 = ind[i];
		for(int j = t; j < t + sz; j++)
			if(!visited[j])
				a[tmp2.back()] = j , tmp2.pop_back();

		t += sz;
	}

	t = 0;

	memset(par , -1 , sizeof par);
	for(int i = 0; i < n; i++)
		if(!visited[i])
		{
			while(!visited[i])
			{
				visited[i] = 1;
				cycle[t].pb(i);
				i = a[i];
			}

			for(int j = 1; j < (int)cycle[t].size(); j++)
				par[cycle[t][j]] = cycle[t][0];

			t++;
		}

	for(int i = 0; i < (int)tmp.size(); i++)
	{
		if(ind[i].empty())
			continue;
		int marja = ind[i].back();
		ind[i].pop_back();

		for(auto shit : ind[i])
		{
			if(f(shit) == f(marja))
				continue;

			par[f(shit)] = f(marja);
			swap(a[shit] , a[marja]);
		}
	}

	memset(visited , 0 , sizeof visited);

	for(int i = 0; i < t; i++)
		cycle[i].clear();
	t = 0;

	int T = 0;
	for(int i = 0; i < n; i++)
		if(!visited[i])
		{
			int sz = 0;
			while(!visited[i])
			{
				sz++;
				cycle[t].pb(i);
				visited[i] = 1;
				i = a[i];
			}
			if(sz != 1)
				t++;
			else
				cycle[t].clear();
		}

	if(!t)
		return cout << 0 << endl , 0;

	if(t == 1)
	{
		if(s < (int)cycle[0].size())
			return cout << -1 << endl , 0;

		cout << 1 << endl;

		cout << cycle[0].size() << endl;

		for(auto x : cycle[0])
			cout << x + 1 << " ";
		cout << endl;

		return 0;
	}

	for(int i = 0; i < t; i++)
		T += (int)cycle[i].size();

	if(s >= T + t)
	{
		cout << 2 << endl;

		cout << T << endl;
		for(int i = 0; i < t; i++)
			for(auto x : cycle[i])
				cout << x + 1 << " ";
		cout << endl;

		cout << t << endl;
		for(int i = t - 1; i >= 0; i--)
			cout << cycle[i][0] + 1 << " ";
		cout << endl;

		return 0;
	}

	if(s < T)
		return cout << -1 << endl , 0;
	s -= T;

	if(s < 2)
	{
		cout << t << endl;
		for(int i = 0; i < t; i++)
		{
			cout << cycle[i].size() << endl;
			for(auto x : cycle[i])
				cout << x + 1 << " ";
			cout << endl;
		}

		return 0;
	}

	cout << 2 + (t - s) << endl;
	for(int i = s; i < t; i++)
	{
		cout << cycle[i].size() << endl;
		for(auto x : cycle[i])
			cout << x + 1 << " ";
		cout << endl;
	}
	t = s;

	T = 0;
	for(int i = 0; i < t; i++)
		T += (int)cycle[i].size();

	cout << T << endl;
	for(int i = 0; i < t; i++)
		for(auto x : cycle[i])
			cout << x + 1 << " ";
	cout << endl;

	cout << t << endl;
	for(int i = t - 1; i >= 0; i--)
		cout << cycle[i][0] + 1 << " ";
	cout << endl;
}