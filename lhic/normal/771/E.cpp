#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <memory>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <ctime> 
#include <stack>

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 400001;
const int LG = 22;
int a[MAXN], b[MAXN];
int na[MAXN][LG], nb[MAXN][LG];
int nx[MAXN];

pair <ll, int> cur[MAXN];

int f[MAXN];
int f1[MAXN];
int f2[MAXN];
int n;

void upd(int x, int y, int val)
{
	for (int j = LG - 1; j >= 0; j--)
	{
		if (na[x][j] <= y) val += (1 << j), x = na[x][j];
		if (nb[y][j] <= x) val += (1 << j), y = nb[y][j];
	}
	if (x > n) return;
	if (y > n) return;
	if (x >= y)
	{
		if (f[x] < val) f[x] = val, f1[x] = y, f2[x] = n + 1;
		else if (f[x] == val) f1[x] = min(f1[x], y);
	}
	if (y >= x)
	{
		if (f[y] < val) f[y] = val, f2[y] = x, f1[y] = n + 1;
		else if (f[y] == val) f2[y] = min(f2[y], x);
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		nx[i] = na[i][0] = nb[i][0] = n + 1;
	}
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < LG; i++)
	{
		na[n + 1][i] = nb[n + 1][i] = na[n][i] = nb[n][i] = nx[n] = nx[n + 1] = n + 1;
	}

	cur[0] = mp(0, 0);
	for (int i = 0; i < n; i++)
	{
		cur[i + 1] = mp(cur[i].first + (ll)a[i], i + 1);
	}
	sort(cur, cur + n + 1);
	for (int i = 0; i < n; i++)
	{
		if (cur[i].first == cur[i + 1].first)
			na[cur[i].second][0] = cur[i + 1].second;
	}
	for (int i = n; i >= 0; i--)
	{
		na[i][0] = min(na[i][0], na[i + 1][0]);
		for (int j = 1; j < LG; j++)
		{
			na[i][j] = na[na[i][j - 1]][j - 1];
		}
	}

	cur[0] = mp(0, 0);
	for (int i = 0; i < n; i++)
	{
		cur[i + 1] = mp(cur[i].first + b[i], i + 1);
	}
	sort(cur, cur + n + 1);
	for (int i = 0; i < n; i++)
	{
		if (cur[i].first == cur[i + 1].first)
			nb[cur[i].second][0] = cur[i + 1].second;
	}
	for (int i = n; i >= 0; i--)
	{
		nb[i][0] = min(nb[i][0], nb[i + 1][0]);
		for (int j = 1; j < LG; j++)
		{
			nb[i][j] = nb[nb[i][j - 1]][j - 1];
		}
	}

	cur[0] = mp(0, 0);
	for (int i = 0; i < n; i++)
	{
		cur[i + 1] = mp(cur[i].first + a[i] + b[i], i + 1);
	}
	sort(cur, cur + n + 1);
	for (int i = 0; i < n; i++)
	{
		if (cur[i].first == cur[i + 1].first)
			nx[cur[i].second] = cur[i + 1].second;
	}
	for (int i = n; i >= 0; i--) nx[i] = min(nx[i], nx[i + 1]);

	for (int i = 1; i <= n; i++) f[i] = -1;
	f[0] = 0;
	for (int i = 0; i < n; i++)
	{
		upd(na[f2[i]][0], i, f[i] + 1);
		upd(i, nb[f1[i]][0], f[i] + 1);

		upd(i + 1, f1[i], f[i]);
		upd(f2[i], i + 1, f[i]);

		upd(i, nb[i][0], f[i] + 1);
		upd(na[i][0], i, f[i] + 1);
		upd(nx[i], nx[i], f[i] + 1);
	}
	cout << f[n] << endl;
	return 0;
}