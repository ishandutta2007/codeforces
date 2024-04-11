#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1000100;
string s, w;

int pref[maxn];

int main()
{
	boost;
	cin >> s;
	w = s;
	int n = s.length(), a = 0;
	FOR(i, 0, n-1) {
		if (s[i] == '1') ++a;
	}
	
	cin >> s;
	s = "#" + s;
	int m = s.length() - 1;
	int b = 0;
	pref[0] = pref[1] = 0;
	FOR(i, 2, m) {
		while (b > 0 && s[b + 1] != s[i]) b = pref[b];
		if (s[b + 1] == s[i]) ++b;
		pref[i] = b;
	}
	
	int ones = a, zeros = n - a;
	int jed = 0, zer = 0;
	int ovzer = 0, ovjed = 0;
	FOR(i, pref[m] + 1, m) {
		if (s[i] == '0') ++zer;
		else ++jed;
	}
	
	FOR(i, 1, m) {
		if (s[i] == '0') ++ovzer;
		else ++ovjed;
	}
	
	if (m > n) OUT(w);
	if (ovzer > zeros || ovjed > ones) OUT(w);
	
	int tries = 0;
	while (ovzer + zer * (tries + 1) <= zeros && ovjed + jed * (tries + 1) <= ones) ++tries;
	FOR(i, 1, m) cout << s[i];
	FOR(step, 1, tries)
		FOR(i, pref[m] + 1, m) cout << s[i];
	
	FOR(i, 1, zeros - (ovzer + zer * tries)) cout << 0;
	FOR(i, 1, ones - (ovjed+ jed * tries)) cout << 1;
		
}