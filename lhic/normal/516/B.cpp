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


char s[2100][2100];

int cnt[5000000];


int n, m;


void dfs(int i, int j);

void dfs2(int i, int j)
{
	if (i != 0 && s[i - 1][j] == '.')
	{
		--cnt[(i - 1) * m + j];
		if (cnt[(i - 1) * m + j] == 1)
			dfs(i - 1, j);
	}

	if (i != n - 1 && s[i + 1][j] == '.')
	{
		--cnt[(i + 1) * m + j];
		if (cnt[(i + 1) * m + j] == 1)
			dfs(i + 1, j);
	}
	if (j != 0 && s[i][j - 1] == '.')
	{
		--cnt[i * m + j - 1];
		if (cnt[i * m + j - 1] == 1)
			dfs(i, j - 1);
	}
	if (j != m - 1 && s[i][j + 1] == '.')
	{
		--cnt[i * m + j + 1];
		if (cnt[i * m + j + 1] == 1)
			dfs(i, j + 1);
	}
}


void dfs(int i, int j)
{
	if (i != 0 && s[i - 1][j] == '.')
	{
		s[i][j] = 'v';
		s[i - 1][j] = '^';
		dfs2(i - 1, j);
		return;
	}
	if (i != n - 1 && s[i + 1][j] == '.')
	{
		s[i + 1][j] = 'v';
		s[i][j] = '^';
		dfs2(i + 1, j);
		return;
	}
	if (j != 0 && s[i][j - 1] == '.')
	{
		s[i][j - 1] = '<';
		s[i][j] = '>';
		dfs2(i, j - 1);
		return;
	}
	if (j != m - 1 && s[i][j + 1] == '.')
	{
		s[i][j + 1] = '>';
		s[i][j] = '<';
		dfs2(i, j + 1);
		return;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf(" %s", s[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (s[i][j] == '*')
				continue;
			if (i != 0 && s[i - 1][j] != '*')
				++cnt[i * m + j];
			if (i != n - 1 && s[i + 1][j] != '*')
				++cnt[i * m + j];
			if (j != 0 && s[i][j - 1] != '*')
				++cnt[i * m + j];
			if (j != m - 1 && s[i][j + 1] != '*')
				++cnt[i * m + j];
		}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (s[i][j] == '.' && cnt[i * m + j] <= 1)
			{
				if (cnt[i * m + j] <= 0)
				{
					cout << "Not unique";
					return 0;
				}
				dfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j  =0 ; j < m; ++j)
			if (s[i][j] == '.')
			{
				cout << "Not unique";
				return 0;
			}
	for (int i = 0; i < n; ++i)
		printf("%s\n", s[i]);
	return 0;
}