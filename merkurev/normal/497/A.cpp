#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1005;
char f[maxn][maxn];
bool diff[maxn];


int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", f[i] );
	int cnt = 0;
	for (int j = 0; j < m; j++)
	{
		bool del = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (!diff[i] && f[i][j] > f[i + 1][j] )
				del = true;
		}
		if (del)
			cnt++;
		else
		{
			for (int i = 0; i < n - 1; i++)
				if (f[i][j] != f[i + 1][j] )
					diff[i] = true;
		}
	}

	printf("%d\n", cnt);

	return 0;
}