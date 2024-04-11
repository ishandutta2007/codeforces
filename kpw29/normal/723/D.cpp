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
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <int, int> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef pair <ld, ld> PLD;
typedef pair <PLD, ld> PLDD;
typedef pair <PLL, ll> PLLL;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const long long INF = (ll)1e18+3;
int n, m,k, a, b, c, ile, DL = 0, CC = 0, T;
#define maxn 25100
bool odw[maxn];
vector <int> v[maxn];
int STATUS[maxn], skl[maxn], broken[maxn];
char s[250][250];

inline int nr(int a, int b) {
	return a * m + b;
}
inline PII odwroc(int a) {
	return mp(a/m, a%m);
}

void dfs(int x) {
	odw[x] = 1;
	STATUS[ile]++;
	skl[x] = ile;
	PII N = odwroc(x);
	if (N.e1 == 0 || N.e2 == 0 || N.e1 == n-1 || N.e2 == m-1) STATUS[ile] = inf;
	for (auto u : v[x])
	  if (!odw[u]) dfs(u);
}

PII tab[maxn];
int main() {
	boost;
	cin >> n >> m >> k;
	ile = 0;
	FOR(i, 0, n-1)
	  FOR(j, 0, m-1) cin >> s[i][j];
	
	FOR(i, 0, n-1) 
	  FOR(j, 0, m-1) {
		  int N = nr(i, j);
		  if (s[i][j] == '.') {
			 if (i > 0 && s[i-1][j] == '.') v[N].pb(nr(i-1, j));
			 if (i < n-1 && s[i+1][j] == '.') v[N].pb(nr(i+1, j));
			 if (j > 0 && s[i][j-1] == '.') v[N].pb(nr(i, j-1));
			 if (j < m-1 && s[i][j+1] == '.') v[N].pb(nr(i, j+1));
		 }
	 }
	 
	 FOR(i, 0, n-1)
	   FOR(j, 0, m-1)
		  if (!odw[nr(i, j)] && s[i][j] == '.') ++ile, dfs(nr(i, j));
	int dobre = 0;
	
	FOR(i, 1, ile)
	  if (STATUS[i] > n * m) dobre++;
	  
	int wywal = ile - dobre - k;
	int wynik = 0;
	FOR(i, 1, ile) tab[i] = mp(STATUS[i], i);
	sort(tab + 1, tab + ile + 1);

	FOR(i, 1, wywal) {
		broken[tab[i].e2] = 1;
		wynik += STATUS[tab[i].e2];
	}
	
	
	cout << wynik << endl;
	FOR(i, 0, n-1) {
		FOR(j, 0, m-1) {
			int N = nr(i, j);
			if (s[i][j] == '.' && broken[skl[N]]) cout << '*';
			else cout << s[i][j];
		}
		cout << "\n";
	}
	
}