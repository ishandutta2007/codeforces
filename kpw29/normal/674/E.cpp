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
#define maxn 500010
int n, m, a, b, c, d;
int k, type;

double prob[maxn][62];
int parent[maxn], ILE = 1;

vector <int> v[maxn];
int STOS[maxn];

int main() {
	scanf("%d", &n);
	for (int i=0; i<=60; ++i) prob[1][i] = 1.0;
	for (int z=1; z<=n; ++z) {
		scanf("%d%d", &type, &a);
		if (type == 2) {
			double res = 0.0;
			for (int i=1; i<=60; ++i)
			  res += ((prob[a][i] - prob[a][i - 1]) * i);
			printf("%.9lf\n", res);
		}
		else {
			parent[++ILE] = a;
			int x = ILE, DL = 0;
			
			for (int i=0; i<=60; ++i) prob[x][i] = 1.0;
			double last = prob[a][0] , akt = ( prob[ a ][ 0 ] *= 0.5 );
			a = parent[a];
			
			while (DL <= 60) {
				++DL;
				if (a <= 0) break;
				double pom = prob[a][DL];
				prob[a][DL] *= (0.5 + 0.5 * akt) / (0.5 + 0.5 * last);
				last = pom;
				akt = prob[a][DL];
				a = parent[a];
			}
		}
	}
}