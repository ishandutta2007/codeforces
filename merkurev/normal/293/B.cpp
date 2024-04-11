#include <iostream>
#include <map>
using namespace std;


int q[21][21], a[21][21], isBad[21][21][21];
long long mod = 1e9 + 7;

int k;

struct some
{
	int a[11];
	some() : a() {for (int i = 1; i <= k; i++) a[i] = 11;}
	bool operator < (const some &A) const
	{
		for (int i = 1; i <= k; i++)
		{
			if (a[i] != A.a[i] )
				return a[i] < A.a[i];
		}
		return false;
	}
};

long long C(long long n, long long k)
{
	long long ans = 1;
	for (int i = 2; i <= n; i++)
		ans *= i;
	for (int i = 2; i <= n - k; i++)
		ans /= i;
	return ans;
}
map <some, long long> answ[11][11];

bool used[11];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n, m;
	scanf("%d%d%d", &n, &m, &k);
	memset(q, -1, sizeof q);

	if (n + m - 1 > k)
	{
		printf("0");
		return 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &q[i][j] );
			used[q[i][j] ] = true;
			a[i][j] = q[i][j];
		}
	if (n > m)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				q[i][j] = a[j][i]; 
		}
		swap(n, m);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int c = 1; c <= k; c++)
			{
				for (int a = i; a < n; a++)
					for (int b = j; b < m; b++)
					{
						if (a == i && b == j)
							continue;
						if (q[a][b] == c)
							isBad[i][j][c] = 1;
					}
			}
	int usedCnt = 0;
	for (int i = 1; i <= k; i++)
	{
		if (used[i] )
			usedCnt++;
	}
	answ[0][0][some() ] = 1;
	long long answer = 0;

	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			int nj = j;
			int ni = i + 1;
			if (ni == n)
			{
				ni = 0;
				nj++;
			}
			for (auto x = answ[i][j].begin(); x != answ[i][j].end(); x++)
			{
			bool XX = true;
				long long curans = x->second;
				some B = x->first;

				for (int color = 1; color <= k; color++)
				{
					if (isBad[i][j][color] )
						continue;
					some A = B;
					if (q[i][j] != 0 && q[i][j] != color)
						continue;
					if (A.a[color] == 11 && !used[color] && !XX)
						continue;

					if (A.a[color] <= i)
						continue;
					A.a[color] = i;


					if (nj != m)
					{
						answ[ni][nj][A] = (answ[ni][nj][A] + curans) % mod;
					}
					else
					{
						int varC = 0;
						for (int i = 1; i <= k; i++)
						{
							if (!used[i] && A.a[i] != 11)
								varC++;
						}
						long long cans = (curans * C(k - usedCnt, varC) ) % mod; 
						answer = (answer + cans) % mod;
					}

					
					if (!used[color] && B.a[color] == 11)
						XX = false;
				}
			}
		}
	}
	
	printf("%d\n", answer);



	return 0;
}