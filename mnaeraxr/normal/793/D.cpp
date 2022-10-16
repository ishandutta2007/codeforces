#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 82;
const int maxk = maxn;

int mat[ maxn ][ maxn ];
vi adj[ maxn ];

bool between(int w, int x, int y){
	return min(x, y) <= w && w <= max(x, y);
}

int dp1[ maxn ][ maxn ][ maxk ];
int dp2[ maxn ][ maxn ][ maxn ][ maxk ];

int solve2(int a, int x, int b, int k){
	if (k == 0) return 0;
	int &ans = dp2[a][x][b][k];
	if (ans != -1) return ans;
	ans = oo;

	for (auto u : adj[x]){
		if (u <= a || u >= b) continue;

		if (u < x){
			int cost = mat[x][u] + solve2(a, u, x, k - 1);
			ans = min(ans, cost);
		}
		else{
			int cost = mat[x][u] + solve2(x, u, b, k - 1);
			ans = min(ans, cost);
		}
	}

	return ans;
}

int solve1(int a, int b, int k){
	if (k == 0) return 0;
	int &ans = dp1[a][b][k];	
	if (ans != -1) return ans;
	ans = oo;

	for (auto j : adj[b]){
		if (between(a, b, j))
			continue;

		if (between(j, a, b))
		{
			int cost = mat[b][j] + solve2( min(a, b), j, max(a, b), k - 1 );
			ans = min(ans, cost);
		}
		else{
			int cost = mat[b][j] + solve1( b, j, k - 1 );
			ans = min(ans, cost);
		}
	}

	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	if (k == 1)
		return cout << 0 << endl, 0;

	int m;
	cin >> m;

	memset( mat, oo, sizeof mat );

	for (int i = 0; i < m; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		mat[u][v] = min( mat[u][v], c );
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j && mat[i][j] < oo)
				adj[ i ].push_back( j );


	int answer = oo;
	memset( dp1, -1, sizeof dp1 );
	memset( dp2, -1, sizeof dp2 );

	for (int i = 1; i <= n; ++i)
		for (auto u : adj[i]){
			int cost = mat[i][u] + solve1(i, u, k - 2);
			answer = min(answer, cost);
		}

	cout << (answer == oo ? -1 : answer) << endl;

	return 0;
}