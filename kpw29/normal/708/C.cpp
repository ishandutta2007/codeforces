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
int T, n, m, K, a, b, c, g, Q, DL;
#define maxn 400100
bool odw[maxn];
vector <int> v[maxn];
int r[maxn], rng, maks[maxn], bestBottom[maxn], bestWithout[maxn];
vector <int> children[maxn];

inline int over(int x) {
	return n - r[x];
}

void dfs(int x) {
	odw[x] = 1;
	r[x] = 1;
	for (auto u : v[x])
	  if (!odw[u]) {
		  children[x].pb(u);
		  dfs(u);
		  r[x] += r[u];
		  maks[x] = max(maks[x], r[u]);
		  bestBottom[x] = max(bestBottom[x], bestBottom[u]);
	  }
	if (r[x] <= K) bestBottom[x] = r[x];
}

bool canBe[maxn];
void find(int x) {
	odw[x] = 1;
	vector <int> pref, suf;
	pref.clear(); suf.clear();
	for (int i=0; i<(int)children[x].size(); ++i) {
		int u = children[x][i];
		pref.pb(bestBottom[u]);
		if (r[u] > K) {
			int ile = bestBottom[u];
			if (r[u] - ile > K) {
				//puts("YES!");
				canBe[x] = 0;
			}
		}
	}
	suf = pref;
	/*cout << x << ' ' << endl;
	for (auto p : pref) cout << p << ' ';
	cout << endl;
	for (auto p : suf) cout << p << ' ';
	cout << endl;*/
	
	for (int i=1; i<(int)pref.size(); ++i) pref[i] = max(pref[i], pref[i - 1]);
	for (int i=suf.size()-2; i>=0; --i) suf[i] = max(suf[i], suf[i + 1]);

	
	for (int i=0; i<(int)children[x].size(); ++i) {
		int u = children[x][i];
		if (over(u) <= K) bestWithout[u] = over(u);
		if (bestWithout[x] <= K) bestWithout[u] = max(bestWithout[u], bestWithout[x]);
		if (i > 0 && pref[i-1] <= K) bestWithout[u] = max(bestWithout[u], pref[i-1]);
		if (i + 1 < (int)children[x].size() && suf[i + 1] <= K) bestWithout[u] = max(bestWithout[u], suf[i + 1]);
	}
	
	//teraz czas na naddrzewo
	int ov = over(x);
	if (ov > K) {
		int ile = bestWithout[x];
		if (ov - ile > K) {
			canBe[x] = 0;
			//cout << "LOL : " << rng << ' ' << x << endl;
		}
	}
	
	for (auto u : children[x]) find(u);
}

int main() {
	boost;
	cin >> n;
	FOR(i, 1, n) canBe[i] = 1;
	K = (n / 2);
	FOR(i, 2, n) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	/*FOR(pp, 1, 5) {
		rng = rand()%n + 1;
		FOR(i, 1, n) maks[i] = bestBottom[i] = bestWithout[i] = r[i] = odw[i] = 0, children[i].clear();
		dfs(rng);
		FOR(i, 1, n) odw[i] = 0;
		find(rng);
	}*/
	
	dfs(1);
	find(1);
	//FOR(i, 1, n) cout << bestWithout[i] << ' ';
	//cout << endl;
	FOR(i, 1, n) cout << canBe[i] << ' ';
}