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
char s[maxn];

int main() {

	scanf("%s", s + 1);
	n = 1;
	while (s[n]) ++n; --n;
	int start = 1;
	while (start <= n) {
		if (s[start] != 'a') break;
		++start;
	}
	
	if (start == n + 1) {
		FOR(i, 1, n-1) putchar(s[i]);
		putchar('z');
	}
	else {
		int koniec = start;
		while (koniec <= n && s[koniec] != 'a') ++koniec;
		if (koniec == n + 1 || s[koniec] == 'a') --koniec;
		FOR(i, 1, n) {
			if (i >= start && i <= koniec) putchar(s[i] - 1);
			else putchar(s[i]);
		}
	}
}