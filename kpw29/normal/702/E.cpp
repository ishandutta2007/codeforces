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
#define OUT(x) { cout << x; exit(0); }
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
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
#define maxn 100100

int n, m, a, b, c;
ll k;
int t[maxn][60];
ll sum[maxn][60], MIN[maxn][60];

PLL ans[maxn];

PLL query(int i) {
	PLL wynik = mp(0, INF);
	FOR(j, 0, 59) {
		if (k & (1LL << j)) {
			wynik.e1 += sum[i][j];
			wynik.e2 = min(wynik.e2, MIN[i][j]);
			i = t[i][j];
		}
	}
	return wynik;
}

int main() {
	scanf("%d%lld", &n, &k);
	FOR(i, 1, n) {
		scanf("%d", &t[i][0]);
		t[i][0]++;
	}
	FOR(i, 1, n) {
		scanf("%lld", &sum[i][0]);
		MIN[i][0] = sum[i][0];
	}
	
	FOR(j, 1, 59) 
	  FOR(i, 1, n) {
		int srodek = t[i][j-1];
		t[i][j] = t[srodek][j-1];
		sum[i][j] = sum[i][j-1] + sum[srodek][j-1];
		MIN[i][j] = min(MIN[i][j-1], MIN[srodek][j-1]);
	}
	
	FOR(i, 1, n) {
		ans[i] = query(i);
		printf("%lld %lld\n", ans[i].e1, ans[i].e2);
	}
}