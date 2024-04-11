#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 330;

struct ed
{
	int a, b, c, f;
};


int was[MAXN];
vector<int> eds[MAXN];
vector<ed> ee;

int n;
int s, t;

int arr[MAXN];

vector<pair<int, int> > vv;

vector<int> v1;
vector<int> v2;

vector<int> eds2[MAXN];
vector<int> gr[MAXN];
int cnt;

int dis[MAXN];


int dfs(int v, int ff)
{
	if (v == t)
		return ff;
	was[v] = 1;
	for (int i = 0; i < (int)eds[v].size(); ++i)
	{
		int u = eds[v][i];
		if (ee[u].c - ee[u].f > 0 && !was[ee[u].b])
		{
			int k = dfs(ee[u].b, min(ff, ee[u].c - ee[u].f));
			if (k != 0)
			{
				ee[u].f += k;
				ee[u ^ 1].f -= k;
				return k;
			}
		}
	}
	return 0;
}


bool pr(int a)
{
	for (int i = 2; i * i <= a; ++i)
		if (a % i == 0)
			return 0;
	return 1;
}


void dfs2(int v, int c)
{
	was[v] = 1;
	if (v < (int)v1.size())
		gr[c].push_back(v1[v]);
	else
		gr[c].push_back(v2[v - v1.size()]);
	for (int i = 0; i < (int)eds2[v].size(); ++i)
	{
		int u = eds2[v][i];
		if (!was[u])
			dfs2(u, c);
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n; ++i)
		vv.push_back({arr[i], i});
	sort(vv.begin(), vv.end());


	for (int i = 0; i < n; ++i)
	{
		if (arr[i] % 2 == 0)
			v1.push_back(arr[i]);
		else
			v2.push_back(arr[i]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	if (v1.size() != v2.size())
	{
		cout << "Impossible";
		return 0;
	}
	int k = v1.size();

	for (int i = 0; i < (int)v1.size(); ++i)
		for (int j = 0; j < (int)v2.size(); ++j)
		{
			if (pr(v1[i] + v2[j]))
			{
				ed x;
				x.a = i;
				x.b = k + j;
				x.f = 0;
				x.c = 1;
				ee.push_back(x);
				eds[i].push_back(ee.size() - 1);
				swap(x.a, x.b);
				x.c = 0;
				ee.push_back(x);
				eds[k + j].push_back(ee.size() - 1);
			}
		}

	s = v1.size() + v2.size();
	t = s + 1;
	for (int i = 0; i < (int)v1.size(); ++i)
	{
		ed x;
		x.a = s;
		x.b = i;
		x.f = 0;
		x.c = 2;
		ee.push_back(x);
		eds[s].push_back(ee.size() - 1);
		swap(x.a, x.b);
		x.c = 0;
		ee.push_back(x);
		eds[i].push_back(ee.size() - 1);
	}

	
	for (int i = 0; i < (int)v2.size(); ++i)
	{
		ed x;
		x.a = t;
		x.b = k +i;
		x.f = 0;
		x.c = 0;
		ee.push_back(x);
		eds[t].push_back(ee.size() - 1);
		swap(x.a, x.b);
		x.c = 2;
		ee.push_back(x);
		eds[i + k].push_back(ee.size() - 1);
	}


	int fl = 0;
	while (true)
	{
		for (int i = 0; i <= t; ++i)
			was[i] = 0;
		int xx = dfs(s, 2000);
		if (xx == 0)
			break;
		fl += xx;
	}

	if (fl != 2 * (int)v1.size())
	{
		cout << "Impossible";
		return 0;
	}

	for (int i = 0; i < (int)v1.size(); ++i)
	{
		for (int j = 0; j < (int)eds[i].size(); ++j)
		{
			int u = eds[i][j];
			int k = ee[u].b;
			if (k != s && ee[u].f)
			{
				eds2[i].push_back(k);
				eds2[k].push_back(i);
			}
		}
	}
//	cout << v1.size() << "\n";
	//for (int i = 0; i < v1.size(); ++i)
	//{
//		for (int j = 0; j < eds2[i].size(); ++j)
//			cout << eds2[i][j] << " ";
//		cout << "\n";
//	}
//	cout << "hello";
//	cout.flush();

	memset(was, 0, sizeof(was[0]) * (t + 1));
	for (int i = 0; i < (int)v1.size(); ++i)
	{
		if (!was[i])
		{
			dfs2(i, cnt);
			cnt++;
		}
	}
	cout << cnt << "\n";
	for (int i = 0; i < cnt; ++i)
	{
		cout << gr[i].size() << " ";
		/*
		for (int j = 0; j < gr[i].size() - 1; ++j)
		{
			if (!pr(gr[i][j] + gr[i][j + 1]))
				cout << "KJSHFD";
		}
		if (!pr(gr[i][0] + gr[i][gr[i].size() - 1]))
			cout << "KJ";*/
		for (int j = 0; j < (int)gr[i].size(); ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if (!dis[k] && vv[k].first == gr[i][j])
				{
					cout << vv[k].second + 1 << " ";
					dis[k] = 1;
					break;
				}
			}
		}
		cout << "\n";
	}


	return 0;
}