#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<sum2r, sum2r>
#define vi vector<int>
#define vll vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define sti set<int>::iterator
#define All(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 3e6 + 10, MOD = 998244353;

int b[18][18],n;
int dp[2][1 << 14][14][1 << 6];
long long ans[1 << 17];

int blp(int x)
{
	int cnt = 0;
	while(x)
	{
		cnt += (x & 1);
		x >>= 1;
	}
	return cnt;
}

int main()
{
	int n = read();
	rep0(i, n)
	{
		char s[111];
		scanf("%s", s);
		rep0(j, n) b[i][j] = s[j] - '0';
	}
	rep0(i, n) dp[0][1 << i][i][0] = dp[1][1 << i][i][0] = 1;
	int vl = n / 2;
	int vr = n - vl;
	rep0(i, (1 << n))
		rep0(j, n)
			if((i >> j) & 1)
			{
				int cnt = blp(i);
				if(cnt >= vr) continue;
				rep0(k, (1 << cnt - 1))
					rep0(nxt, n)
						if(!((i >> nxt) & 1))
						{
							dp[0][i ^ (1 << nxt)][nxt][k | (b[j][nxt] << cnt - 1)] += dp[0][i][j][k];
							dp[1][i ^ (1 << nxt)][nxt][(k << 1) | b[j][nxt]] += dp[1][i][j][k];
						}
			}
	rep0(p, n)
		rep0(q, n)
			if(p != q)
				rep0(msk, (1 << n))
				{
					if(!((msk >> p) & 1))continue;
					if((msk >> q) & 1)continue;
					if(blp(msk) != vl)continue;
					int msk2 = ((1 << n) - 1) ^ msk;
					rep0(i, (1 << vl - 1))
						rep0(j, (1 << vr - 1))
							ans[i | (b[p][q] << vl - 1) | (j << vl)] += 1ll * dp[0][msk][p][i] * dp[1][msk2][q][j];
				}
	rep0(i, (1 << n - 1)) printf("%lld ", ans[i]);
	return 0;
}