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

#define y1 howcouldthishappentome
#define y2 imademymistakes
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
#define MAXN 53

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
bitset<MAXN> grid[MAXN];
int pref[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];
bitset<MAXN> vis[MAXN][MAXN][MAXN];
int ans;

int rect(int x1, int x2, int y1, int y2)
{
	return pref[x2 + 1][y2 + 1] - pref[x1][y2 + 1] - pref[x2 + 1][y1] + pref[x1][y1];
}
int solve(int x1, int x2, int y1, int y2)
{
	if (vis[x1][x2][y1][y2]) return dp[x1][x2][y1][y2];
	vis[x1][x2][y1][y2] = true;
	int sum = rect(x1, x2, y1, y2);
	// cerr << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << ' ' << sum << endl;
	if (sum == 0)
	{
		dp[x1][x2][y1][y2] = 0;
		return dp[x1][x2][y1][y2];
	}
	if (sum == (x2 - x1 + 1) * (y2 - y1 + 1))
	{
		dp[x1][x2][y1][y2] = max(x2 - x1, y2 - y1) + 1;
		return dp[x1][x2][y1][y2];
	}
	int res = max(x2 - x1, y2 - y1) + 1;
	FOR(i, x1, x2)
	{
		ckmin(res, solve(x1, i, y1, y2) + solve(i + 1, x2, y1, y2));
	}
	FOR(i, y1, y2)
	{
		ckmin(res, solve(x1, x2, y1, i) + solve(x1, x2, i + 1, y2));
	}
	dp[x1][x2][y1][y2] = res;
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	FOR(i, 0, N)
	{
		string temps; cin >> temps;
		FOR(j, 0, N)
		{
			if (temps[j] == '#')
			{
				grid[i][j] = 1;
			}
		}
	}
	FOR(i, 0, N)
	{
		FOR(j, 0, N)
		{
			pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + grid[i][j];
			// cerr << i << ' ' << j << ' ' << pref[i + 1][j + 1] << endl;
		}
	}
	ans = solve(0, N - 1, 0, N - 1);
	cout << ans << '\n';
	return 0;
}