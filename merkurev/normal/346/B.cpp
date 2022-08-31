#include <iostream>
#include <algorithm>
using namespace std;


char a[105], b[105], virus[105];

int dp[105][105][105];
int parent[105][105][105], parj[105][105][105], parb[105][105][105];

char answer[105];

int turn[105][205];
int ta[105][205], tb[105][205];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s\n%s\n%s", a + 1, b + 1, virus);

	a[0] = '#';
	b[0] = '#';

	int n = strlen(a);
	int m = strlen(b);
	int l = strlen(virus);



	for (int i = 0; i < l; i++)
		for (char j = 'A'; j <= 'Z'; j++)
		{
			for (int h = 0; h <= i; h++)
			{
				bool good = true;
				for (int g = 0; g < i - h; g++)
					if (virus[g] != virus[g + h] )
					{
						good = false;
						break;
					}
				if (!good)
					continue;
				if (virus[i - h] == j)
				{
					turn[i][j] = i - h + 1;
					break;
				}
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 'A'; j <= 'Z'; j++)
		{
			ta[i][j] = i + 1;
			while (ta[i][j] < n && a[ta[i][j] ] != j)
				ta[i][j]++;
		}
	for (int i = 0; i < m; i++)
		for (int j = 'A'; j <= 'Z'; j++)
		{
			tb[i][j] = i + 1;
			while (tb[i][j] < m && b[tb[i][j] ] != j)
				tb[i][j]++;
		}

	memset(dp, -1, sizeof dp);
	dp[0][0][0] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < l; j++)
			for (int pb = 0; pb < m; pb++)
			{
				if (dp[i][j][pb] == -1)
					continue;
				int pinv = j;
				int ndp = dp[i][j][pb] + 1;

				for (int hh = 'A'; hh <= 'Z'; hh++)
				{
					int h = ta[i][hh];
					if (h == n)
						continue;
					int pbnew = tb[pb][hh];
					if (pbnew == m)
						continue;

					int pvnew = turn[pinv][a[h] ];


					if (ndp > dp[h][pvnew][pbnew] )
					{
						dp[h][pvnew][pbnew] = ndp;
						parent[h][pvnew][pbnew] = i;
						parj[h][pvnew][pbnew] = j;
						parb[h][pvnew][pbnew] = pb;
					}
				}
			}

	int ans = -1, anspos = -1, ansj = -1, ansh = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++)
			for (int h = 0; h < m; h++)
				if (dp[i][j][h] > ans)
				{
					ans = dp[i][j][h];
					anspos = i;
					ansj = j;
					ansh = h;
				}
	}

	if (ans == 0)
	{
		printf("0");
		return 0;
	}

	int al = 0;
	while (anspos != 0)
	{
		answer[al++] = a[anspos];
		int nanspos = parent[anspos][ansj][ansh];
		int nansj = parj[anspos][ansj][ansh];
		ansh = parb[anspos][ansj][ansh];
		anspos = nanspos;
		ansj = nansj;
	}

	for (int i = al - 1; i >= 0; i--)
		printf("%c", answer[i] );


	return 0;
}