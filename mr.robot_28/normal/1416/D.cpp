#include<bits/stdc++.h>
using namespace std;
 
int n, m, q;
vector <int> p;
vector <vector <int> > g;
vector <int> dsu, rang;
vector <int> color;
vector <vector <pair <int, int>> > cells;
int _sz = 0;
int pred(int a)
{
	if(a == dsu[a]) return a;
	return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
	a = pred(a);
	b = pred(b);
	if(a != b)
	{
		if(rang[a] < rang[b])
		{
			swap(a, b);
		}
		dsu[b] = a;
		rang[a] += rang[b];
	}
}
void gen(int i)
{
	cells.push_back({});
	queue <int> q;
	q.push(i);
	color[i] = _sz;
	while(q.size() != 0)
	{
		int v = q.front();
		q.pop();
		if(p[v] != 0)
		{
			cells[_sz].push_back({p[v], v});
		}
		for(int j = 0;j < g[v].size(); j++)
		{
			int to = g[v][j];
			if(color[to] != _sz)
			{
				color[to] = _sz;
				q.push(to);
			}
		}
	}
	sort(cells[_sz].begin(), cells[_sz].end());
	_sz++;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> q;
	g.resize(n);
	p.resize(n);
	dsu.resize(n);
	rang.resize(n);
	color.resize(n, -1);
	for(int i = 0; i < n; i++)
	{
		dsu[i] = i;
		rang[i] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	vector <bool> used(m);
	vector <pair <int, int> > mass(m);
	for(int i = 0; i < m; i++)
	{
		cin >> mass[i].first >> mass[i].second;
		mass[i].first--;
		mass[i].second--;
	}
	vector <pair <int, int> > query(q);
	for(int i = 0; i < q; i++)
	{
		cin >> query[i].first >> query[i].second;
		query[i].second--;
		if(query[i].first == 2)
		{
			used[query[i].second] = 1;
		}
	}
	for(int i = 0; i < m; i++){
		if(!used[i])
		{
			if(pred(mass[i].first) != pred(mass[i].second))
			{
		g[mass[i].first].push_back(mass[i].second);
		g[mass[i].second].push_back(mass[i].first);
			}
			unite(mass[i].first, mass[i].second);
		}
	}
	for(int i = q - 1; i >= 0; i--)
	{
		if(query[i].first == 2)
		{
			int a = mass[query[i].second].first;
			int b = mass[query[i].second].second;
			g[a].push_back(b);
			g[b].push_back(a);
		}
	}
	vector <bool> val(q);
	vector <int> fs(q);
	for(int i = q - 1; i >= 0; i--)
	{
		if(query[i].first == 2)
		{
			int a = mass[query[i].second].first;
			int b = mass[query[i].second].second;
			if(pred(a) != pred(b))
			{
				if(rang[pred(a)] > rang[pred(b)])
				{
					fs[i] = b;
				}
				else
				{
					fs[i] = a;
				}
				unite(a, b);
				val[i] = 1;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(color[i] == -1)
		{
			gen(i);
		}
	}
	for(int i = 0; i< q; i++)
	{
		if(query[i].first == 1)
		{
			int v = query[i].second;
			while(cells[color[v]].size() > 0 && color[cells[color[v]].back().second] != color[v])
			{
				cells[color[v]].pop_back();
			}
			if(cells[color[v]].size() == 0)
			{
				cout << 0 << "\n";
				continue;
			}
			pair <int, int> a = cells[color[v]].back();
			p[a.second] = 0;
			cells[color[v]].pop_back();
	//		cout << a.second << " ";
			cout << a.first << "\n";
		}
		else if(val[i])
		{
			int a = mass[query[i].second].first;
			int b = mass[query[i].second].second;
			g[a].pop_back();
			g[b].pop_back();
			if(fs[i] == a)
			{
				gen(a);
			}
			else
			{
				gen(b);
			}
		}
		else
		{
			int a = mass[query[i].second].first;
			int b = mass[query[i].second].second;
			g[a].pop_back();
			g[b].pop_back();
		}
	}
	return 0;
}