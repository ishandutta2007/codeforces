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
#define MAXN 2013

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
bitset<MAXN> arr;
vpi edge[MAXN << 1];
int req[MAXN << 1];
int ans[MAXN << 1];
vi guys;

void dfs(int u, bool b)
{
	if (ans[u] == (b ^ 1) || req[u] == (b ^ 1))
	{
		cout << "-1\n";
		exit(0);
	}
	if (ans[u] == b) return;
	ans[u] = b;
	for (pii p : edge[u])
	{
		dfs(p.fi, b ^ p.se);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(69);
	cin >> N;
	FOR(i, 0, N)
	{
		string temps; cin >> temps;
		FOR(j, 0, N)
		{
			bool b = (temps[j] == '1');
			grid[i][j] = grid[i][j] ^ b;
		}
	}
	FOR(i, 0, N)
	{
		string temps; cin >> temps;
		FOR(j, 0, N)
		{
			bool b = (temps[j] == '1');
			grid[i][j] = grid[i][j] ^ b;
			// cerr << grid[i][j] << ' ';
		}
		// cerr << endl;
	}
	string temps; cin >> temps;
	FOR(i, 0, 2 * N)
	{
		req[i] = -1;
		ans[i] = -1;
	}
	FOR(i, 0, N)
	{
		arr[i] = (temps[i] == '1');
		// cerr << arr[i] << ' ';
	}
	// cerr << endl;
	FOR(i, 0, N)
	{
		FOR(j, 0, N)
		{
			//if you take row i, it xors with arr[j]
			//if you take column j, it xors with arr[i]
			if (arr[i])
			{
				if (arr[j])
				{
					edge[j].PB({i + N, grid[i][j]});
					edge[i + N].PB({j, grid[i][j]});
				}
				else
				{
					req[j] = grid[i][j];
				}
			}
			else
			{
				if (arr[j])
				{
					req[i + N] = grid[i][j];
				}
				else
				{
					if (grid[i][j])
					{
						cout << "-1\n";
						return 0;
					}
				}
			}
		}
	}
	// FOR(i, 0, 2 * N)
	// {
	// 	cerr << ans[i] << ' ' << req[i] << endl;
	// }
	FOR(i, 0, 2 * N)
	{
		if (ans[i] != -1) continue;
		if (req[i] != -1)
		{
			dfs(i, req[i]);
		}
	}
	FOR(i, 0, 2 * N)
	{
		if (ans[i] != -1) continue;
		dfs(i, (rand() & 1));
	}
	FOR(i, 0, 2 * N)
	{
		if (ans[i] == 1)
		{
			guys.PB(i);
		}
	}
	cout << SZ(guys) << '\n';
	for (int x : guys)
	{
		if (x < N)
		{
			cout << "col " << x << '\n';
		}
		else
		{
			cout << "row " << x - N << '\n';
		}
	}
	return 0;
	//each row can be: you must take it. you must not take it. you must take it XOR take that.
}