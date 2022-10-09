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
#define maxn 100100
int t[maxn], nast[maxn], pom[maxn];
vector <char> literki;
int gdzie[27];
bool jest[maxn];

inline int dist(int a, int b) {
	return b - a + 1;
}
string s;
char tab[maxn];
int main() {
	boost;
	cin >> m;
	cin >> s;
	n = s.length();
	if (m == 1) {
		FOR(i, 0, n-1) tab[i] = s[i];
		sort(tab, tab + n);
		FOR(i, 0, n-1) cout << tab[i];
		exit(0);
	}
	
	for (int i=n-1; i>=0; --i) {
		int lit = s[i] - 'a';
		if (gdzie[lit] == 0) nast[i] = inf;
		else nast[i] = gdzie[lit];
		gdzie[lit] = i;
	}
	
	for (int a=0; a<26; ++a) {
		bool ans = 1;
		vector <char> literki;
		FOR(i, 0, n-1) jest[i] = 0;
		FOR(i, 0, n-1)
		  if (s[i] - 'a' < a) {
			  literki.pb(s[i]);
			  jest[i] = 1;
		  }
		pom[n] = n;
		for (int i=n-1; i>=0; --i) {
			if (jest[i]) pom[i] = i;
			else pom[i] = pom[i + 1];
		}
		int LAST = -1;
		FOR(i, 0, n-1) {
			if (jest[i]) LAST = i;
			else {
				int literka = s[i] - 'a';
				if (literka == a) {
					int gdzie = min(pom[i], nast[i]);
					if (dist(LAST + 1, gdzie - 1) >= m) {
						jest[i] = 1;
						literki.pb(s[i]);
						LAST = i;
					}
				}
				if (!jest[i]) {
					if (dist(LAST + 1, i) >= m) ans = 0;
				}
			}
		}
		if (ans) {
			sort(literki.begin(), literki.end());
			for (auto u : literki) cout << u;
			exit(0);
		}	  
	}
	cout << "LOL";
}