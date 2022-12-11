#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
	if (a > b) a = b;
}
template<class T, class U>
void ckmax(T &a, U b)
{
	if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define SZ(x) ((int) ((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define MAXN 12
#define MAXM 2013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int TC;
int N, M;
int grid[MAXN + 1][MAXM];
int best[MAXM][(1 << MAXN) + 10];
int dp[2][(1 << MAXN) + 10];
int ans;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> TC;
	while(TC--)
	{
		cin >> N >> M;
		FOR(i, 0, N)
		{
			FOR(j, 0, M)
			{
				cin >> grid[i][j];
			}
		}
		//time complexity:
		//for each column and each bitmask, compute best sum.
		FOR(i, 0, M)
		{
			FOR(j, 0, (1 << N))
			{
				best[i][j] = 0;
				FOR(k, 0, N)
				{
					if (j & (1 << k))
					{
						best[i][j] += grid[k][i];
					}
				}
			}
			FOR(j, 0, (1 << N))
			{
				int sum = best[i][j];
				int mask = j;
				FOR(k, 1, N)
				{
					mask = (mask | (mask << N)) >> 1;
					mask &= ((1 << N) - 1);
					ckmax(sum, best[i][mask]);
				}
				best[i][j] = sum;
			}
		}
		FOR(i, 0, (1 << N))
		{
			dp[0][i] = 0;
			dp[1][i] = 0;
		}
		FOR(i, 0, M)
		{
			FOR(j, 0, (1 << N))
			{
				dp[i & 1][j] = 0;
				for (int k = j; ; k = (k - 1) & j)
				{
					ckmax(dp[i & 1][j], dp[i & 1 ^ 1][k] + best[i][j ^ k]);
					if (k == 0) break;
				}
			}
		}
		ans = dp[M & 1 ^ 1][(1 << N) - 1];
		cout << ans << '\n';
	}
	return 0;
}