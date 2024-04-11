#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 501;

int T[maxn][maxn];
int A[maxn][maxn];
int D[maxn][maxn];
int E[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	memset(D, oo, sizeof D);
	memset(E, oo, sizeof E);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		D[v][u] = D[u][v] = w;
		E[u][v] = E[v][u] = w;
	}
	
	for (int i = 1; i <= n; ++i)
		D[i][i] = 0;
	
	for (int k = 1; k <= n; ++k){
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
	}
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) if (j != i && D[i][j] < oo)
			for (int t = 1; t <= n; ++t) if (t != j && E[t][j] < oo)
				T[i][j] += D[i][j] == D[i][t] + E[t][j];
				
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) if (j != i && D[i][j] < oo)
			for (int t = 1; t <= n; ++t) if (D[i][j] == D[i][t] + D[t][j])
				A[i][j] += T[i][t];
				
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			cout << A[i][j] << " ";
	cout << endl;

    return 0;
}