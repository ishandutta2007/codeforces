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
#define maxn 5010
int n, m, a, b, c;

int t[maxn];
int wyn[maxn], occ[maxn];

int main() {
	boost;
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> t[i];
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) occ[j] = 0;
		PII maks = mp(0, 0);
		
	  for (int j=i; j<=n; ++j) {
		  int x = t[j];
		  occ[x]++;
		  if (occ[x] > maks.e1 || (occ[x] == maks.e1 && x < maks.e2)) maks = mp(occ[x], x);
		  wyn[maks.e2]++;
	  }
  }
	for (int i=1; i<=n; ++i) printf("%d ", wyn[i]);
}