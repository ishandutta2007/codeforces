#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
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
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
const int maxn = 1000100;
int n, m, k, a, b, c;

ld v1, v2, l, x, y, ulamek;

inline int sufit(int x, int k) {
	int ile = (x / k);
	if (ile * k < x) return ile + 1;
	return ile;
}

inline bool check(ld t) {
	//if (v2 * t >= l) return 1;
	ld K = sufit(n, k);
	ld eQ = (K - 1) + K * ulamek - ulamek + 1;
	ld T = (t / eQ); //tyle czasu przewozi kazdego pasazera
	//cout << t << ' ' << T << endl;
	return ((T * v1 + (t - T) * v2) >= l);
}

int main() {
	cin >> n >> l >> v2 >> v1 >> k;
	ulamek = (v1 - v2) / (v1 + v2);
	x = 0.0, y = (l / v2);
	FOR(step, 1, 1000) {
		ld sr = (x + y) / 2;
		if (check(sr)) y = sr;
		else x = sr;
	}
	printf("%.15lf", x);
}