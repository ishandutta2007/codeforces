/*
PROG: cf821a
LANG: C++
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define MP make_pair
#define PB push_back

#define SINF 10001
#define INF 1000000007
#define MOD INF
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 55

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int N;
int grid[MAXN][MAXN];

bool good(int x, int y)
{
	if (grid[x][y] == 1)
	{
		return true;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[x][i] + grid[j][y] == grid[x][y])
			{
				return true;
			}
		}
	}
	return false;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf821a.in", "r"))
	{	
		freopen ("cf821a.in", "r", stdin);
		freopen ("cf821a.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!good(i, j))
			{
				cout << "No\n";
//				cerr << i << ' ' << j << endl;
				return 0;
			}
		}
	}
	cout << "Yes\n";
	return 0;
}