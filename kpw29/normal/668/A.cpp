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
#define maxn 1001000
int n, m, a, b, c, k;
ll N, M, A, B, C;
int ls[maxn], ps[maxn];
int mac[1010][1010];
PP zap[maxn];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=k; ++i) {
		int type;
		scanf("%d", &type);
		if (type == 3) {
			scanf("%d%d%d", &a, &b, &c);
			zap[i] = mp(mp(type, a), mp(b, c));
		}
		else {
			scanf("%d", &a);
			zap[i] = mp(mp(type, a), mp(0, 0));
		}
	}
	for (int i=1; i<=n; ++i)
	  for (int j=1; j<=m; ++j) mac[i][j] = inf;
	for (int i=k; i>0; --i) {
		int type = zap[i].e1.e1;
		if (type == 3) {
			a = zap[i].e1.e2, b = zap[i].e2.e1, c = zap[i].e2.e2;
			mac[a][b] = c;
		}
		else {
			if (type == 2) {
				a = zap[i].e1.e2;
				//shiftujemy kolumne
				int bylo = mac[n][a];
				for (int i=n-1; i>0; --i) mac[i + 1][a] = mac[i][a];
				mac[1][a] = bylo;
			}
			if (type == 1) {
				a = zap[i].e1.e2;
				//shiftujemy rzad
				int bylo = mac[a][m];
				for (int i=m-1; i>0; --i) mac[a][i + 1] = mac[a][i];
				mac[a][1] = bylo;
			}
		}
	}
	
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) 
		  if (mac[i][j] == inf) printf("0 ");
		  else printf("%d ", mac[i][j]);
		  puts("");
	}
}