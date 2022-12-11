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
#define MAXN 1000013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, M;
vector<bool> grid[MAXN], res[MAXN];
vi sum[MAXN], chk[MAXN];

bool check(int x)
{
	// cerr << "CHECK " << x << endl;
	int sz = (2 * x + 1) * (2 * x + 1);
	FOR(i, 0, N)
	{
		FOR(j, 0, M)
		{
			chk[i][j] = 0;
			res[i][j] = false;
		}
	}
	FOR(i, 0, N)
	{
		FOR(j, 0, M)
		{
			// cerr << "HEY " << i << ' ' << j << endl;
			// cerr << i - x << ' ' << j - x << ' ' << i + x << ' ' << j + x << endl;
			if (i - x < 0 || j - x < 0 || i + x >= N || j + x >= M)
			{
				res[i][j] = 0;
				continue;
			}
			// cerr << "HEY " << i << ' ' << j << endl;
			int cur = sum[i + x + 1][j + x + 1] - sum[i - x][j + x + 1] - sum[i + x + 1][j - x] + sum[i - x][j - x];
			if (cur == sz)
			{
				res[i][j] = true;
				chk[i - x][j - x]++; chk[i - x][j + x + 1]--; chk[i + x + 1][j - x]--; chk[i + x + 1][j + x + 1]++;
			}
		}
	}
	// FOR(i, 0, N)
	// {
	// 	FOR(j, 0, M)
	// 	{
	// 		cerr << res[i][j];
	// 	}
	// 	cerr << endl;
	// }
	FOR(i, 0, N)
	{
		FOR(j, 0, M)
		{
			int sum = chk[i][j];
			if (i != 0) sum += chk[i - 1][j];
			if (j != 0) sum += chk[i][j - 1];
			if (i != 0 && j != 0) sum -= chk[i - 1][j - 1];
			chk[i][j] = sum;
			// cerr << sum << ' ';
			if (sum > 0 && !grid[i][j]) return false;
			if (sum == 0 && grid[i][j]) return false;
		}
		// cerr << endl;
	}
	return true;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);
	cerr << fixed << setprecision(4);
	cin >> N >> M;
	FOR(i, 0, N)
	{
		string temps; cin >> temps;
		grid[i].resize(M);
		sum[i].resize(M + 1);
		chk[i].resize(M + 1);
		res[i].resize(M);
		FOR(j, 0, M)
		{
			grid[i][j] = (temps[j] == 'X');
		}
	}
	sum[N].resize(M + 1);
	chk[N].resize(M + 1);
	FOR(i, 0, N)
	{
		FOR(j, 0, M)
		{
			sum[i + 1][j + 1] = grid[i][j] + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
		}
	}
	int lo = 0, hi = (min(N, M) - 1) / 2;
	while(hi > lo)
	{
		int mid = (lo + hi + 1) >> 1;
		if (check(mid))
		{
			lo = mid;
		}
		else
		{
			hi = mid - 1;
		}
	}
	check(lo);
	cout << lo << '\n';
	FOR(i, 0, N)
	{
		FOR(j, 0, M)
		{
			cout << (res[i][j] ? 'X' : '.');
		}
		cout << '\n';
	}
	return 0;
	//bleh now just do prefix sums.
	//you overlayed a bunch of squares of size 2x+1 to get the picture. what's maximum value of x?
}