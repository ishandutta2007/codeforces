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
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 10010
int n, m, a, b, c, d;
int k;
int t[maxn];
bool jest[maxn];

int main() {
	boost;
	cin >> n >> k;
	if (n == 4) OUT(-1);
	cin >> a >> b >> c >> d;
	jest[a] = jest[b] = jest[c] = jest[d] = 1;
	int e = 1;
	while (jest[e]) ++e;
	jest[e] = 1;
	if (k <= n) OUT(-1);
	printf("%d %d %d %d ", a, c, e, d);
	for (int i=1; i<=n; ++i)
	  if (!jest[i]) printf("%d ", i);
	printf("%d\n", b);
	
	printf("%d %d %d %d ", c, a, e, b);
	for (int i=n; i>0; --i)
	  if (!jest[i]) printf("%d ", i);
	printf("%d\n", d);
}