//bad_solution
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
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1010
int pref[maxn][9], n, t[maxn], K;
int dp[maxn];

inline int suma(int x, int y, int kolor) {
	if (x > y) return 0;
	return pref[y][kolor] - pref[x-1][kolor];
}

inline int wyszukaj(int start, int kolor, int liczba) {
	if (liczba == 0) return start;
	++start;
	int xx = start, yy = n + 1;
	if (suma(start, n, kolor) < liczba) return n + 1;
	while (xx < yy) {
		int sr = ((xx + yy) / 2);
		if (suma(start, sr, kolor) < liczba) xx = ++sr;
		else yy = sr;
	}
	return min(n+1, xx);
}

int Search(int kk) {

	int maks = (1 << 8);
	dp[0] = 0;
	FOR(i, 1, maks-1) dp[i] = n + 1;
	FOR(i, 1, maks-1) {
		FOR(j, 0, 7) {
			int elem = (1 << j);
			if (i & elem) {
				int w = wyszukaj(dp[i ^ elem], j + 1, kk);
				dp[i] = min(dp[i], w);
			}
		}

	}
	//cout << kk << ' ' << dp[maks - 1] << endl;
	return dp[maks - 1];
}

int neeed[9], global = 0, wyn;

void checkit() {
	int maks = (1 << 8);
	dp[0] = 0;
	FOR(i, 1, maks-1) dp[i] = n + 1;
	FOR(i, 1, maks-1) {
		FOR(j, 0, 7) {
			int elem = (1 << j);
			if (i & elem) {
				int w = wyszukaj(dp[i ^ elem], j + 1, neeed[j + 1]);
				dp[i] = min(dp[i], w);
			}
		}
	}
	
	if (dp[maks-1] <= n) wyn = max(wyn, 8 * K + global);
}
int main() {
	cin >> n;
	FOR(i, 1, n) cin >> t[i];
	FOR(kolor, 1, 8) {
		pref[0][kolor] = 0;
		FOR(i, 1, n) {
			pref[i][kolor] = pref[i-1][kolor];
			if (t[i] == kolor) pref[i][kolor]++;
		}
	}
	
	int x = 0, y = 130;
	while (x < y) {
		int sr = ((x +y ) >> 1)+1;
		if (Search(sr) == n + 1) y = --sr;
		else x = sr;
	}

	K = x;
	int ile = (1 << 8);
	FOR(i, 0, ile-1) {
		global = __builtin_popcount(i);
		FOR(j, 0, 7) {
			int elem = (1 << j);
			if (i & elem) neeed[j + 1] = K + 1;
			else neeed[j + 1] = K;
		}
		checkit();
	}
	
	cout << wyn;
}