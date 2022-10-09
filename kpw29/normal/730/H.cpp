#include <bits/stdc++.h>
#include <string>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 103
int n, m;
string s[maxn];
int tab[maxn];
bool us[maxn];

char pattern[maxn];

bool canBe[maxn];

int main() {
	boost;
	cin >> n >> m;
	int maxx = -1;
	FOR(i, 1, n) cin >> s[i];
	FOR(i, 1, m) {
		cin >> tab[i];
		us[tab[i]] = 1;
		if (i == 1) maxx = s[tab[i]].length();
		else if (s[tab[i]].length() != maxx) OUT("No");
	}
	
	FOR(j, 0 , maxx-1) {
		pattern[j] = '#';
		FOR(i, 1, n)
		  if (us[i]) {
			  if (pattern[j] == '#') pattern[j] = s[i][j];
			  else if (pattern[j] != s[i][j]) pattern[j] = '?';
		  }
	}
	
	FOR(i, 1, n)
	  if (!us[i] && s[i].length() == maxx) canBe[i] = 1;
	  
	FOR(j, 0, maxx-1) {
		FOR(i, 1, n)
		  if (!us[i] && s[i].length() == maxx) {
			  if (pattern[j] != '?' && s[i][j] != pattern[j]) canBe[i] = 0;
		  }
	}
	
	bool ans = 0;
	FOR(i, 1, n) ans |= canBe[i];
	if (ans) OUT("No");
	cout << "Yes\n";
	FOR(j, 0, maxx-1) cout << pattern[j];
	
	
}