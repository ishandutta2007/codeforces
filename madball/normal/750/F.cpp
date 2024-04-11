#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define FILENAME ""
typedef long long ll;

vector<int> neigh[128];
int asks = 0;
vector<int> asked;

void ask(int v)
{
	if (!neigh[v].empty())
		return;
	asked.push_back(v);
	++asks;
	if (asks == 17)
		throw;
	cout << "? " << v << endl;
	int s;
	cin >> s;
	for (int i = 0; i < s; ++i)
	{
		int a;
		cin >> a;
		neigh[v].push_back(a);
	}
}

void dfs(int v, int from, int from2, vector<int> &res)
{
	res.push_back(v);
	ask(v);
	if (neigh[v][0] != from && neigh[v][0] != from2)
		dfs(neigh[v][0], v, 0, res);
	else if (neigh[v].size() > 1)
	{
		if (neigh[v][1] != from && neigh[v][1] != from2)
			dfs(neigh[v][1], v, 0, res);
		else if (neigh[v].size() > 2)
			dfs(neigh[v][2], v, 0, res);
	}
}

void solve()
{
	for (int i = 0; i < asked.size(); ++i)
		neigh[asked[i]].clear();
	asked.clear();
	asks = 0;
	int h;
	cin >> h;
	vector<int> line;
	dfs(1, 0, 0, line);
	reverse(line.begin(), line.end());
	if (neigh[1].size() != 1)
		dfs(neigh[1][1], 1, 0, line);
	int mid = line[line.size() / 2];
	int middist = h - line.size() / 2 - 1;
	while (middist > 3)
	{
		int noway = line[line.size() / 2 + 1];
		while (line.back() != noway)
			line.pop_back();
		line.pop_back();
		line.pop_back();
		dfs(mid, line.back(), noway, line);
		mid = line[line.size() / 2];
		middist = h - line.size() / 2 - 1;
	}
	if (middist == 0)
	{
		cout << "! " << mid << endl;
		return;
	}
	for (int i = 0; i < 3; ++i)
		if (neigh[neigh[mid][i]].empty())
		{
			mid = neigh[mid][i];
			--middist;
			break;
		}
	if (middist == 0)
	{
		cout << "! " << mid << endl;
		return;
	}
	ask(mid);
	if (middist == 1)
	{
		for (int i = 0; i < 3; ++i)
		{
			ask(neigh[mid][i]);
			if (neigh[neigh[mid][i]].size() == 2)
			{
				cout << "! " << neigh[mid][i] << endl;
				return;
			}
		}
	}
	if (middist == 2)
	{
		vector<int> q1;
		vector<int> q2;
		for (int i = 0; i < 3; ++i)
			if (neigh[neigh[mid][i]].empty())
			{
				ask(neigh[mid][i]);
				q1.push_back(neigh[mid][i]);
			}
		for (int i = 0; i < q1.size(); ++i)
			for (int j = 0; j < 3; ++j)
				if (neigh[neigh[q1[i]][j]].empty())
					q2.push_back(neigh[q1[i]][j]);
		for (int i = 0; i < q2.size() - 1; ++i)
		{
			ask(q2[i]);
			if (neigh[q2[i]].size() == 2)
			{
				cout << "! " << q2[i] << endl;
				return;
			}
		}
		cout << "! " << q2.back() << endl;
	}
}

int main()
{
#ifdef LOCAL
	if (FILENAME == "TODO")
		throw;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	if (FILENAME != "")
	{
		freopen(FILENAME".in", "r", stdin);
		freopen(FILENAME".out", "w", stdout);
	}
#endif
	int n;
	for (cin >> n; n; --n)
		solve();
	return 0;
}