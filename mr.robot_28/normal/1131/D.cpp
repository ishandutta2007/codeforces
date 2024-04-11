#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector <vector <int> > P;
vector <int> par, rang;
vector <bool> used;
vector <int> used1;
vector <int> Count;
int pred(int v)
{
	if(par[v] == v) return v;
	else return par[v] = pred(par[v]);
}
void in(int a, int b)
{
	a = pred(a);
	b = pred(b);
	if(a != b && rang[a] < rang[b])
	{
		swap(a, b);
	}
	par[b] = a;
	if(rang[a] == rang[b])
	{
		rang[a]++;
	}
}
void dfs(int v)
{
	if(used1[v] == 1)
	{
		cout << "No";
		exit(0);
	}
	used1[v] = 1;
	int min1 = 0; 
	int cnt = 0;
	for(int i = 0; i < P[v].size(); i++)
	{
		if(used1[P[v][i]] != 2)
		{
			dfs(P[v][i]);
		}
		min1 = max(min1, Count[P[v][i]]);
	}
	if(P[v].size() == 0)
	{
		Count[v] = 1;
	}
	else
	{
		Count[v] = min1 + 1;
	}
	used1[v] = 2;
}
int main()
{
	int n, m;
	cin >> n >> m;
	par.resize(n + m);
	for(int i = 0; i < n + m; i++)
	{
		par[i] = i;
	}
	Count.resize(n + m, 0);
	rang.resize(n + m, 1);
	vector <vector <char> > A(n, vector <char> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}
	for(int i = 0; i <n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(A[i][j] == '=')
			{
				in(i, j + n);
			}
		}
	}
	int count = 0;
	used.resize(n + m, false);
	for(int i = 0; i < n + m; ++i)
	{
		if(!used[pred(i)])
		{
			count++;
			used[pred(i)] = true;
		}
	}
	P.resize(n + m);
	for(int i = 0; i < n + m; i++)
	{
		used[i] = false;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(A[i][j] == '>')
			{
				if(par[i] == par[j + n])
				{
					cout << "No";
					return 0;
				}
				P[par[i]].push_back(par[j + n]);
				used[par[j + n]] = true;
			}
			else if(A[i][j] == '<')
			{
				if(par[i] == par[j + n])
				{
					cout << "No";
					return 0;
				}
				P[par[j + n]].push_back(par[i]);
				used[par[i]] = true;
			}
		}
	}
	int start = -1;
	used1.resize(n + m, 0);
	for(int i = 0; i < m + n; i++)
	{
		if(used1[par[i]] != 2)
		{
			dfs(par[i]);
		}
	}
	cout << "Yes" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << Count[pred(i)] << " ";
	}
	cout << endl;
	for(int i = n; i < m + n; i++)
	{
		cout << Count[pred(i)] << " ";
	}
	return 0;
}