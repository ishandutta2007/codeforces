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
#define MAXN 113

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int TC;
int N, M, K, C;
int grid[MAXN][MAXN];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
string alphanumeric = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int num[MAXN * MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);
	cerr << fixed << setprecision(4);
	cin >> TC;
	while(TC--)
	{
		C = 0;
		cin >> N >> M >> K;
		FOR(i, 0, N)
		{
			string temps; cin >> temps;
			FOR(j, 0, M)
			{
				if (temps[j] == '.')
				{
					grid[i][j] = -2;
				}
				else
				{
					grid[i][j] = -1;
					C++;
				}
			}
		}
		FOR(i, 0, K)
		{
			num[i] = C / K;
		}
		FOR(i, 0, C % K)
		{
			num[i]++;
		}
		//that's the trick. you assign till you
		int i = 0, j = 0, guy = 0;
		while(i < N)
		{
			int cur = guy;
			if (grid[i][j] == -1)
			{
				num[guy]--;
				if (num[guy] == 0 && guy != K - 1)
				{
					guy++;
				}
			}
			grid[i][j] = cur;
			if (i & 1)
			{
				if (j == 0)
				{
					i++;
				}
				else
				{
					j--;
				}
			}
			else
			{
				if (j == M - 1)
				{
					i++;
				}
				else
				{
					j++;
				}
			}
		}
		FOR(i, 0, N)
		{
			FOR(j, 0, M)
			{
				// cout << grid[i][j] << ' ';
				cout << alphanumeric[grid[i][j]];
			}
			cout << '\n';
		}
	}
	return 0;
}