#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
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
int n, m, k, a, b, c, T;
#define maxn 25
int t[maxn][maxn], start[maxn][maxn];

int main() {
	boost;
	cin >> n >> m;
	FOR(i ,1, n)
	  FOR(j, 1, m) cin >> t[i][j], start[i][j] = t[i][j];
	
	FOR(zamien, 1, m)
	  FOR(zam2, 1, m) {
		  FOR(i, 1, n)
		    FOR(j, 1, m) t[i][j] = start[i][j];
		    bool ans = 1;
		  FOR(i, 1, n) swap(t[i][zamien], t[i][zam2]);

		  FOR(i, 1, n) {
			  int swaps = 1;
			  FOR(j, 1, m)
			    if (t[i][j] != j) {
					if (swaps == 0) ans = 0;
					swap(t[i][j], t[i][t[i][j]]);
					swaps = 0;
				}
			  
		  }
		  if (ans) OUT("YES");
	  }
	  OUT("NO");
}