#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <int, int> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef vector <int> vi;
typedef unsigned int ui;
const int inf = 1e9+9;

int n, m, a, b, c;
#define maxn 200100
PII prz;
PII tab[maxn];

int main() {
	boost;
	cin >> n;
	prz = {-inf, inf};
	int overallChange = 0;
	FOR(i, 1, n) {
		cin >> a >> b;
		if (b == 2) {
			prz.e2 = min(prz.e2, 1899);
		}
		else prz.e1 = max(prz.e1, 1900);
		prz.e1 += a;
		prz.e2 += a;
		overallChange += a;
		if (prz.e1 > prz.e2) OUT("Impossible");
	}
	
	if (prz.e2 > 100000000) OUT("Infinity");
	cout << prz.e2;
	
}