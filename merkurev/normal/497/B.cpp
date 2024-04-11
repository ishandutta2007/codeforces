#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;



const int maxn = 1e5 + 100;
int a[maxn];
const int ST = 18;
int kth[maxn][2][ST];


int getNxt(int pos, int s, int x)
{
	for (int i = 0; i < ST; i++)
	{
		if (s & (1 << i) )
			pos = kth[pos][x][i] + 1;
	}
	return pos - 1;
}

int test(int n, int s)
{
	int pos = 0, lst = -1;
	int ans[2] = {0, 0};
	while (pos < n)
	{
		int n0 = getNxt(pos, s, 0);
		int n1 = getNxt(pos, s, 1);
		
//		fprintf(stderr, "s = %d, pos = %d, n0 = %d, n1 = %d\n", s, pos, n0, n1);
		
		int x = 0;
		if (n0 > n1)
			x = 1;
		int nn = min(n0, n1);
		if (nn == n)
			return -1;
		pos = nn + 1;
		ans[x]++;
		lst = x;
	}
	if (ans[lst] <= ans[lst ^ 1] )
		return -1;
	return ans[lst];
}


int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		a[i]--;
	}

	vector <pair <int, int> > ans;

	for (int i = 0; i < ST; i++)
		for (int j = 0; j < 2; j++)
			kth[n + 1][j][i] = kth[n][j][i] = n;

	for (int i = n - 1; i >= 0; i--)
	{
		kth[i][0][0] = kth[i + 1][0][0];
		kth[i][1][0] = kth[i + 1][1][0];
		kth[i][a[i] ][0] = i;
		for (int x = 0; x < 2; x++)
			for (int j = 1; j < ST; j++)
			{
				kth[i][x][j] = kth[kth[i][x][j - 1] + 1][x][j - 1];
			}
	}

	for (int s = 1; s <= n; s++)
	{
		int x = test(n, s);
		if (x != -1)
			ans.push_back(make_pair(x, s) );
	}
	sort(ans.begin(), ans.end() );
	printf("%d\n", (int) ans.size() );
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);


	return 0;
}