#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1001000
int f[110][110], n, m;

int _find(int a, int par) {
	if (f[a][par] == a) return a;
	f[a][par] = _find(f[a][par], par);
	return f[a][par];
}

void _union(int a, int b, int par) {
	a = _find(a, par), b = _find(b, par);
	if (rand() & 1) f[a][par] = b;
	else f[b][par] = a;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; ++i)
	  for (int j=1; j<=m; ++j) f[i][j] = i;
	for (int i=1; i<=m; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		_union(a, b, c);
	}
	int k, a, b;
	scanf("%d", &k);
	while (k--) {
		int wyn = 0;
		scanf("%d%d", &a, &b);
		for (int i=1; i<=m; ++i)
		  if (_find(a, i) == _find(b, i)) ++wyn;
		printf("%d\n", wyn);
		  
	}
	
}