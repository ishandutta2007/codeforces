 #include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 510

int mat[maxn][maxn], odl[maxn][maxn], A[maxn], n;
bool jest[maxn];
ll wyn[maxn];
int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
	  for (int j=1; j<=n; ++j) cin >> mat[i][j], odl[i][j] = mat[i][j];
	for (int i=1; i<=n; ++i) cin >> A[i];
	for (int i=n; i>0; --i) {
		int akt = A[i];
		jest[akt] = 1;
		for (int u=1; u<=n; ++u)
		  for (int v=1; v<=n; ++v) odl[u][v] = min(odl[u][v], odl[u][akt] + odl[akt][v]);
		ll result = 0;

		for (int u=1; u<=n; ++u)
		  for (int v=1; v<=n; ++v)
		    if (jest[u] && jest[v]) result += odl[u][v];
		wyn[i] = result;    
	}
	for (int i=1; i<=n; ++i) cout << wyn[i] << ' ';
}