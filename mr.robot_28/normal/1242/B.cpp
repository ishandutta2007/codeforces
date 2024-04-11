#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
vector <int> dsu, rang;
vector <int> comp, size1;
int pred(int v)
{
	if(dsu[v] == v) return v;
	else return dsu[v] = pred(dsu[v]);
}
int unite(int a, int b)
{
	a = pred(a);
	b = pred(b);
	if(a != b){
		if(rang[a] < rang[b])
		{
			swap(a, b);
		}
		dsu[b] = a;
		size1[a] += size1[b];
		if(rang[a] == rang[b])
		{
			rang[a]++;
		}
		return a;
	}
	return a;
}
int main() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	comp.resize(n);
	dsu.resize(n);
	rang.resize(n);
	size1.resize(n);
	for(int i = 0; i < n; i++)
	{
		rang[i] = 1;
		size1[i] = 1;
		dsu[i] = i;
	}
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x - 1].push_back(y - 1);
		g[y - 1].push_back(x - 1);
	}
	set  <int> component;
	for(int i = 0; i  < n; i++)
	{
		set <int> l;
		for(int j = 0; j < g[i].size(); j++)
		{
			if(g[i][j] < i)
			{
				comp[pred(g[i][j])]++;
			}
		}
		set <int> :: iterator it;
		for(it = component.begin(); it != component.end(); it++)
		{
			if(comp[*it] < size1[*it])
			{
				l.insert(*it);
			}
			comp[*it] = 0;
		}
		if(l.size() == 0)
		{
			component.insert(i);
		}
		for(it = l.begin(); it != l.end(); it++){
			int k = *it;
			component.erase(pred(k));
			component.erase(pred(i));
			component.insert(unite(k, i));
		}
	}
	cout << component.size() - 1;
	return 0;
}