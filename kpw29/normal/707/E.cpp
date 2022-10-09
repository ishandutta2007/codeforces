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
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int T, n, m, k, a, b, c, d, g, Q, DL;
#define MX 2010

vector <PP> chains[MX];
PP zap[1000100];
char s[10];

ll Answer[MX][MX];
ll dr[MX + 5];

inline ll get(int p) {
	ll ret = 0;
	for (; p > 0; p -= p & (-p)) ret += dr[p];
	return ret;
}
inline void add(int p, int v) {
	for (; p < MX; p += p & (-p)) dr[p] += v;
}
vector <PP> queries;

inline void addQuery(int a, int b, int place, int sign) {
	queries.pb(mp(mp(a, b), mp(place, sign)));
}


bool is[MX];

inline int readint() {
	int x = 0; char zn;
	while (1) {
		zn = getchar();
		if (zn >= '0' && zn <= '9') break;
	}
	while (1) {
		x = (x << 1) + (x << 3) + zn - '0';
		zn = getchar();
		if (isspace(zn)) return x;
	}
}

int main() {
	n = readint(); m = readint(); g = readint();
	PP help;
	FOR(z, 1, g) {
		k = readint();
		FOR(i, 1, k) {
			a = readint(); b = readint(); c = readint();
			help = mp(mp(a, b), mp(-1, c));
			chains[z].pb(help);
		}
	}
	
	Q = readint();
	FOR(z, 1, Q) {
		scanf("%s", s);
		if (s[0] == 'S') {
			a = readint(); 
			zap[z] = mp(mp(a, -1), mp(-1, -1));
		}
		else if (s[0] == 'A') {
			++DL;
			a = readint(); b = readint(); c = readint(); d = readint();
			zap[z] = mp(mp(a, b), mp(c, d));
			addQuery(c, d, DL, 1);
			addQuery(a-1, b-1, DL, 1);
			addQuery(a-1, d, DL, -1);
			addQuery(c, b-1, DL, -1);
		}
	}
	
	DL = 0;
	
	FOR(z, 1, g) {
		vector <PP> v;
		v.clear();
		for (auto u : queries) v.pb(u);
		for (auto u : chains[z]) v.pb(u);
		sort(v.begin(), v.end());
		for (auto u : v) {
			if (u.e2.e1 < 0) add(u.e1.e2, u.e2.e2);
			else Answer[z][u.e2.e1] += u.e2.e2 * get(u.e1.e2);
		}
		for (auto u : v)
			if (u.e2.e1 < 0) add(u.e1.e2, -u.e2.e2);
	}
	
	//Answer[][] found
	FOR(i, 1, g) is[i] = 1;
	FOR(h, 1, Q) {
		if (zap[h].e1.e2 < 0) is[zap[h].e1.e1] ^= 1;
		else {
			++DL;
			ll wyn = 0;
			FOR(i, 1, g)
			  if (is[i]) wyn += Answer[i][DL];
			printf("%lld\n", wyn);
		}
	}
	
}