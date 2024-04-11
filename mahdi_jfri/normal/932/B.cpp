#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;
const int maxm = 10;

int f[maxn] , g[maxn] , t[maxn][maxm];

int main()
{
	f[0] = 1;
	for(int i = 1; i < maxn; i++)
	{
		if(i % 10)
			f[i] = f[i / 10] * (i % 10);
		else
			f[i] = f[i / 10];
		if(i < 10)
			g[i] = i;
		else
			g[i] = g[f[i]];
	}
	for(int i = 1; i < maxn; i++)
		for(int j = 0; j < maxm; j++)
		{
			t[i][j] = t[i - 1][j];
			if(g[i] == j)
				t[i][j]++;
		}

	int q;
	scanf("%d", &q);

	while(q--)
	{
		int l , r , k;
		scanf("%d%d%d", &l, &r, &k);
		l--;

		printf("%d\n", t[r][k] - t[l][k]);
	}
}