#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define x first
#define y second
#define tysiac 1010
#define milion 1000100
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define OUT(x) { cout << x; return 0; }
#define PRINT(x, y) {printf("%d %d\n", x, y); return;} 
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
typedef pair <double, int> PDI;

const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int T, n, m, k, b, c, g, Q, DL;
#define maxn 100100
PLL t[maxn];
PDI A[maxn], B[maxn];

inline double odl(PLL &a, PLL &b) {
	return sqrt((a.e1 - b.e1) * (a.e1 - b.e1) + (a.e2 - b.e2) * (a.e2 - b.e2));
}

int main() {
	PLL adil, bera, bin;
	scanf("%d%d%d%d%d%d", &adil.e1, &adil.e2, &bera.e1, &bera.e2, &bin.e1, &bin.e2);
	scanf("%d", &n);
	double wyn = 0;
	FOR(i, 1, n) {
		scanf("%d%d", &t[i].e1, &t[i].e2);
		double D = odl(t[i], bin);
		A[i] = mp(odl(adil, t[i]) - D, i);
		B[i] = mp(odl(bera, t[i]) - D, i);
		wyn += D * 2.0;
	}
	sort(A + 1, A + n + 1);
	sort(B + 1, B + n + 1);
	//wyn to wynik startowy
	double ans = 1e18;
	if (A[1].e2 != B[1].e2) ans = min(ans, wyn + A[1].e1 + B[1].e1);
	else ans = min(ans, wyn + A[1].e1 + B[2].e1), ans = min(ans, wyn + A[2].e1 + B[1].e1);
	ans = min(ans, wyn + A[1].e1);
	ans = min(ans, wyn + B[1].e1);
	printf("%.15lf", ans);
}