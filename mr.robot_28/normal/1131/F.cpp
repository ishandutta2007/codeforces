#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector <int> par, rang;
vector <int> Count;
vector <vector <int> > A;
int pr;
int find_set(int v)
{
	if(par[v] == v) return v;
	else
	{
		int d = find_set(par[v]);
	 	return par[v] = d;
	}
}
void union_(int a, int b, int count)
{
	a = find_set(a);
	b = find_set(b);
	if(a != b && rang[a] < rang[b])
	{
		swap(a, b);
	}
	par[b] = a;
	A[a].push_back(b);
	if(count == A.size() - 1)
	{
		pr = a;
	}
	if(rang[a] == rang[b])
	{
		rang[a]++;
	}
}
int dfs(int v)
{
	int p = 0, rez = 0;
	for(int i = 0; i < A[v].size(); i++)
	{
		Count[A[v][i]] = rez + Count[v];
		rez += dfs(A[v][i]);
	}
	return rez + 1;
}
int main()
{
	int n;
	cin >> n;
	par.resize(n);
	rang.resize(n);
	A.resize(n);
	vector <pair <int, int> > P(n);
	Count.resize(n);
	for(int i = 0; i < n; i++)
	{
		par[i] = i;
		rang[i] = 1;
	}
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		union_(x - 1, y - 1, i + 1);
	}
	dfs(pr);
	for(int i = 0; i < n; i++)
	{
		P[i].first = Count[i];
		P[i].second = i + 1;
	}
	sort(P.begin(), P.end());
	for(int i = 0; i < n; i++)
	{
		cout << P[i].second << " ";
	}
	return 0;
}