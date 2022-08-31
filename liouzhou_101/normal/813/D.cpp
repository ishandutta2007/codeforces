#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MAXN = 5010;

int n;
int a[MAXN];
int F[MAXN][MAXN];

int q[5][MAXN][2];
int q1[MAXN], q2[MAXN], q3[MAXN], q4[MAXN];

int main()
{
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%d", &a[i]);
		for (int j = 1; j < i; ++ j)
		{ 
			if (a[j]+1 == a[i])
			{
				q[1][i][1] = q[1][i][0];
				q[1][i][0] = j;
			}
			if (a[j]-1 == a[i])
			{
				q[2][i][1] = q[2][i][0];
				q[2][i][0] = j;
			}
			if (a[j]%7 == a[i]%7)
			{
				q[3][i][1] = q[3][i][0];
				q[3][i][0] = j;
			}
			if (a[j] == a[i])
			{
				q[4][i][1] = q[4][i][0];
				q[4][i][0] = j;
			}
		}
	}
	for (int i = 0; i <= n; ++ i)
		for (int j = 0; j <= n; ++ j)
			F[i][j] = -10000;
	int ans = 0;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
		{
			if (i == j)
			{
				F[i][j] = -10000;
				for (int p = 0; p <= 1; ++ p)
				{
					F[i][j] = max(F[i][j], F[i][q[4][j][p]]);
					F[i][j] = max(F[i][j], F[q[4][i][p]][j]);
				}
				continue;
			}
			else
			{
				F[i][j] = 2;
			}
			
			for (int p = 0; p <= 1; ++ p)
			{
				F[i][j] = max(F[i][j], F[i][q[4][j][p]]);
				F[i][j] = max(F[i][j], F[q[4][i][p]][j]);
				for (int k = 1; k <= 3; ++ k)
				{
					F[i][j] = max(F[i][j], F[i][q[k][j][p]]+1);
					F[i][j] = max(F[i][j], F[q[k][i][p]][j]+1);
				}
				/*
			F[i][j] = max(F[i][j], F[q1[i]][q1[j]]+2);
			F[i][j] = max(F[i][j], F[q1[i]][q2[j]]+2);
			F[i][j] = max(F[i][j], F[q1[i]][q3[j]]+2);
			F[i][j] = max(F[i][j], F[q2[i]][q1[j]]+2);
			F[i][j] = max(F[i][j], F[q2[i]][q2[j]]+2);
			F[i][j] = max(F[i][j], F[q2[i]][q3[j]]+2);
			F[i][j] = max(F[i][j], F[q3[i]][q1[j]]+2);
			F[i][j] = max(F[i][j], F[q3[i]][q2[j]]+2);
			F[i][j] = max(F[i][j], F[q3[i]][q3[j]]+2);
			*/
			}
			ans = max(ans, F[i][j]);
		}
	cout << ans << endl;
	
	return 0;
}