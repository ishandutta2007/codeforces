#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 400;
int ids[MAXN];
bool e[MAXN][MAXN];
int a[MAXN], b[MAXN];
vector <int> ans;

int main()
{
	int m, k;
	cin >> m >> k;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i];
		ids[i * 2] = a[i], ids[i * 2 + 1] = b[i];
	}
	sort(ids, ids + 2 * m);
	int n = unique(ids, ids + 2 * m) - ids;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			e[i][j] = false;
		}
	}
	for (int i = 0; i < m; i++)
	{
		a[i] = lower_bound(ids, ids + n, a[i]) - ids;
		b[i] = lower_bound(ids, ids + n, b[i]) - ids;
		e[a[i]][b[i]] = e[b[i]][a[i]] = true;
	}
	for (int i = 0; i < n; i++)
	{
		ans.clear();
		for (int j = 0; j < n; j++)
		{
			if (j == i) continue;
			if (e[i][j]) continue;
			int tot = 0, nd = 0;
			for (int l = 0; l < n; l++)
			{
				if (e[i][l]) 
				{
					tot++;
					if (e[j][l]) nd++;
				}
			}
			if (tot * k <= nd * 100) ans.push_back(ids[j]);
		}
		cout << ids[i] << ": " << ans.size();
		for (int j = 0; j < ans.size(); j++) cout << " " << ans[j];
		cout << endl;
	}
	return 0;
}