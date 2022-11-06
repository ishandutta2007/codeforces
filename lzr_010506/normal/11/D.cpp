#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 19;

int n, m, c[N][N]; ll res = 0;
ll f[1 << N][N];

int main()
{
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a --;
		b --;
		c[a][b] = c[b][a] = 1;
	}

	for(int i = 0; i < n; i ++)
		f[1 << i][i] = 1;
	for(int mask = 0; mask < (1 << n); mask ++)
	{
		int fst = 0, bn = 0;
		for(int i = 0; i < n; i ++)
			if ((mask >> i) & 1)
				fst = i, i = n;
		for(int i = 0; i < n; i ++)
			bn += (mask >> i) & 1;
		for(int i = 0; i < n; i ++)
			if (f[mask][i])
			{
				if (c[i][fst] && bn >= 3)
					res += f[mask][i];
				for(int j = 0; j < n; j ++)
					if (j > fst && !((mask >> j) & 1) && c[i][j])
						f[mask | (1 << j)][j] += f[mask][i];
			}
	}
	cout << res / 2 << endl;
	return 0;
}