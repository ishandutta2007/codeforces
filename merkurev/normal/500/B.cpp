#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


const int maxn = 305;
int a[maxn];
char f[maxn][maxn];


int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	for (int i = 0; i < n; i++)
	{
		scanf("%s", f[i] );
		f[i][i] = '1';
	}
	for (int h = 0; h < n; h++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (f[i][h] == '1' && f[h][j] == '1')
					f[i][j] = '1';

	for (int i = 0; i < n; i++)
	{
		int bstpos = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[bstpos] && f[i][j] == '1')
			{
				bstpos = j;
			}
		}
		swap(a[i], a[bstpos] );
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i] );



	return 0;
}