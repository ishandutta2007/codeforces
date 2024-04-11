#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = 50000;

const int max0 = 32;

bool f[max0][max0][maxn + 5] , pre[max0][max0][maxn + 5];

int lyc[maxn + 5], id[maxn + 5];

int n, p;

inline int add(int x,const int &y)
{
	return (x * (y >= 10 ? 100 : 10) + y) % p;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &p);

	bool flag = 0;
	int t = 0;

	f[0][0][0]=1;
	REP(i, 0, n)
	{
		static int x;
		scanf("%d", &x);
		if(x < 32)
		{
			lyc[++t] = x;
			id[t] = i;
			REP(j, 0, 32)
				REP(k, 0, p)
				{
					if (f[t - 1][j][k])
					{
						f[t][j][k] = 1;
						pre[t][j][k] = 0;
						int y = add(k, x);
						f[t][j ^ x][y] = 1;
						pre[t][j ^ x][y] = 1;
						if ((j ^ x) == 0 && y == 0)
						{
							flag = 1;
							goto vfk;
						}
					}
				}
		}
	}
vfk:;

	if (flag)
	{
		printf("Yes\n");
		static int num = 0, q[maxn + 5];
		for(int u = 0, y = 0, i = t; i >= 1; --i)
			if(pre[i][u][y])
			{
				q[num++] = id[i];
				u ^= lyc[i];
				REP(j, 0, p)
					if(f[i - 1][u][j] && add(j, lyc[i]) == y)
					{
						y = j;
						break;
					}
			}
		printf("%d\n",num);
		for(int i = num - 1; i>=0; --i) printf("%d ", q[i] + 1);
	}
	else printf("No\n");

	return 0;
}