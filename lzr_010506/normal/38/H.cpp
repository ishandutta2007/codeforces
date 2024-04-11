#include <bits/stdc++.h>
#include <math.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ept 1e-9

using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

const int N = 70;

int dis[N][N];
pii Ds[N][N];
ll dp[N][N][N];
ll ans;

int main()
{
	int n = read();
	int m = read();
	memset(dis, 0x3f, sizeof(dis));
	rep(i, 0, n - 1) dis[i][i] = 0;
	rep(i, 0, m - 1)
	{
		int u = read();
		int v = read();
		int c = read();
		u --;
		v --;
		dis[u][v] = dis[v][u] = c;
	}
	int g1 = read();
	int g2 = read();
	int s1 = read();
	int s2 = read();

	rep(k, 0, n - 1)
		rep(i, 0, n - 1)
			rep(j, 0, n - 1)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);


	int pos = 0;
	rep(i, 0, n - 1)
	{
		pos = 0;
		rep(j, 0, n - 1)
		{
			if (i == j) continue;
			Ds[i][pos ++] = mp(dis[i][j], i);
		}
		pii *mD = Ds[i];
		sort(mD, mD + n - 1);
	}

	pii mindis, maxdis;
	pii *p, *tmp;
	bool bG, bS, bB;
	rep(lastG, 0, n - 1)
		rep(firstB, 0, n - 1)
		{
			mindis = Ds[lastG][0];
			maxdis = Ds[firstB][n - 2];
			if (lastG == firstB || mindis >= maxdis) continue;
			memset(dp, 0, sizeof(dp));
			dp[0][0][0] = 1;

			rep(i, 0, n - 1)
			{
				bG = bS = bB = 0;
				if (i == lastG) bG = 1;
				else if (i == firstB) bB = 1;
				else
				{
					bG = Ds[i][0] < mindis;
					bB = Ds[i][n - 2] > maxdis;
					tmp = Ds[i];
					p = upper_bound(tmp, tmp + n - 1, mindis);
					if (p < tmp + n - 1 && *p < maxdis) bS = 1;
				}
				rep(GNum, 0, n - 1)
					rep(SNum, 0, i - GNum)
					{
						if (bG) dp[i + 1][GNum + 1][SNum] += dp[i][GNum][SNum];
						if (bS) dp[i + 1][GNum][SNum + 1] += dp[i][GNum][SNum];
						if (bB) dp[i + 1][GNum][SNum] += dp[i][GNum][SNum];
					}
			}
			rep(GNum, g1, g2)
				rep(SNum, s1, s2)
					ans += dp[n][GNum][SNum];
		}

	printf("%lld\n", ans);
	return 0;
}