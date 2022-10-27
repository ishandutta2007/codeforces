#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > g;
vector <int> dsu, rang, col, cntcol1, cntcol2;
vector <int> type;
pair <int, int> pred(int u)
{
	if(dsu[u] == u)
	{
		return {u, 0};
	}
	else
	{
		pair <int, int> t = pred(dsu[u]);
		dsu[u] = t.first;
		col[u] = t.second ^ col[u];
		return {dsu[u], col[u]};
	}
}
int sum = 0;
signed main() {	
	int n, k;
	cin >> n >> k;
	g.resize(n);
	type.resize(k);
	dsu.resize(k);
	rang.resize(k);
	cntcol1.resize(k);
	cntcol2.resize(k);
	col.resize(k);
	string s;
	cin >> s;
	vector <int> used(k);
	for(int i = 0; i < k; i++)
	{
		rang[i] = 1;
		dsu[i] = i;
		cntcol1[i] = 1;
		cntcol2[i] = 0;
		col[i] = 0;
		type[i] = 0;
	}
	vector <vector <int> > mass(k);
	for(int i = 0; i < k; i++)
	{
		int m;
		cin >> m;
		mass[i].resize(m);
		for(int j = 0; j < m; j++)
		{
			cin >> mass[i][j];
			mass[i][j]--;
			g[mass[i][j]].push_back(i);
		}
	}
	for(int i = 0; i < n; i++)
	{
		int t = (s[i] - '0') ^ 1;
		if(g[i].size() == 2)
		{
			pair <int, int> t1 = pred(g[i][0]);
			pair <int, int> t2 = pred(g[i][1]);
			if(t1.first == t2.first)
			{
				cout << sum << "\n";
				continue;
			}
			sum -= min(cntcol1[t1.first], cntcol2[t1.first]);
			sum -= min(cntcol1[t2.first], cntcol2[t2.first]);
			if(rang[t1.first] < rang[t2.first])
			{
				swap(t1, t2);
			}
			if(t1.second ^ t2.second ^ t)
			{
				swap(cntcol1[t2.first], cntcol2[t2.first]);
				col[t2.first] = 1;
			}
			rang[t1.first] += rang[t2.first];
			dsu[t2.first] = t1.first;
			cntcol1[t1.first] += cntcol1[t2.first];
			cntcol2[t1.first] += cntcol2[t2.first];
			sum += min(cntcol1[t1.first], cntcol2[t1.first]);
		}
		else if(g[i].size() == 1)
		{
			pair <int, int> r = pred(g[i][0]);
			sum -= min(cntcol1[r.first], cntcol2[r.first]);
			used[g[i][0]] = 1;
			cntcol1[r.first] += (r.second == t) * 1e9;
			cntcol2[r.first] += (r.second != t) * 1e9;
			sum += min(cntcol1[r.first], cntcol2[r.first]);
		}
		cout << sum << "\n";
	}
    return 0;
}