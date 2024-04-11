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


const int maxn = 1e5;
int w[maxn];
int ans[maxn];
int b[maxn];
int st[maxn];

int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	memset(ans, -1, sizeof ans);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &w[i] );
	int sz = 0;
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		x--;
		b[i] = x;
		if (ans[x] == -1)
			ans[x] = sz++;
	}
	for (int i = 0; i < n; i++)
		if (ans[i] == -1)
			ans[i] = sz++;

	for (int i = 0; i < n; i++)
		st[ans[i] ] = i;

	int answer = 0;
	for (int i = 0; i < m; i++)
	{
		int cur = 0;
		int pos = -1;
		for (int j = 0; j < n; j++)
		{
			if (st[j] == b[i] )
			{
				pos = j;
				break;
			}
			else
				cur += w[st[j] ];
		}
		for (int j = pos - 1; j >= 0; j--)
			st[j + 1] = st[j];
		st[0] = b[i];
		answer += cur;
	}
	printf("%d\n", answer);

	return 0;
}