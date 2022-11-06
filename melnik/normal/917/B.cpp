#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 105;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

vector <pair <int, char>> edge[maxn];
int dp[maxn][maxn][256][2];

void Solve(int u, int v, int c, int type) {
	if (dp[u][v][c][type])
		return;
	if (!type) {
		bool was = false;
		for (pair <int, char> to : edge[u])
			if (to.s >= c) {
				Solve(to.f, v, to.s, type ^ 1);
				if (dp[to.f][v][to.s][type ^ 1] == 1)
					was = true;
			}
		if (was)
			dp[u][v][c][type] = 1;
		else
			dp[u][v][c][type] = 2;
	} else {
		bool was = false;
		for (pair <int, char> to : edge[v])
			if (to.s >= c) {
				Solve(u, to.f, to.s, type ^ 1);
				if (dp[u][to.f][to.s][type ^ 1] == 2)
					was = true;
			}
		if (was)
			dp[u][v][c][type] = 2;
		else
			dp[u][v][c][type] = 1;
	}
}

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	char c;
    	scanf ("%d%d %c", &u, &v, &c);
    	edge[u].pb(mp(v, c));
    }
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		Solve(i, j, 0, 0);
    		if (dp[i][j][0][0] == 1)
    			printf("A");
    		else
    			printf("B");
    	}
    	printf("\n");
    }
    return 0;
}