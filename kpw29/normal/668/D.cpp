#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1001000
int n, m, a, b, c, k;

const int R = (1 << 19);

PP zap[maxn];
int ans[maxn];
vector <int> czasy, elem;
int DL = 0;
map <int, int> CZAS, TYPE;
vector <PPI> queries[maxn];

int dr[2 * R + 5];

int get(int x) {
	x += R-1;
	int ret = 0;
	while (x) {
		ret += dr[x];
		x >>= 1;
	}
	return ret;
}
inline void insert(int x, int y, int ile) {
	x += R-1; y += R-1;
	dr[x]+=ile;
	if (x == y) return;
	dr[y]+=ile;
	while (x + 1 < y) {
		if (!(x & 1)) dr[x + 1] += ile;
		if (y & 1) dr[y - 1] += ile;
		x >>= 1; y >>= 1;
	}
}
int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d%d%d", &zap[i].e1.e2, &zap[i].e1.e1, &zap[i].e2.e1);
		czasy.pb(zap[i].e1.e1);
		elem.pb(zap[i].e2.e1);
		zap[i].e2.e2 = i;
	}
	for (int i=1; i<=n; ++i) ans[i] = -1;
	sort(czasy.begin(), czasy.end());
	CZAS[czasy[0]] = ++DL;
	for (ui i=1; i<czasy.size(); ++i) {
		if (czasy[i] != czasy[i-1]) ++DL;
		CZAS[czasy[i]] = DL;
	}
	DL = 0;
	sort(elem.begin(), elem.end());
	TYPE[elem[0]] = ++DL;
	for (ui i=1; i<elem.size(); ++i) {
		if (elem[i] != elem[i-1]) ++DL;
		TYPE[elem[i]] = DL;
	}
	for (int i=1; i<=n; ++i) {
		int EL = TYPE[zap[i].e2.e1];
		int TIM = CZAS[zap[i].e1.e1];
		queries[EL].pb(mp(mp(zap[i].e1.e2, TIM), zap[i].e2.e2));
	}
	
	for (int i=1; i<maxn; ++i) {
		if (queries[i].empty()) continue;
		//printf("Jestem w : %d\n", i);
		for (ui j=0; j<queries[i].size(); ++j) {
			int type = queries[i][j].e1.e1, cz = queries[i][j].e1.e2;
			if (type == 1) insert(cz, n + 100, 1);
			if (type == 2) insert(cz, n + 100, -1);
			if (type == 3) ans[queries[i][j].e2] = get(cz);
		}
		
		//zerowanie drzewa potegowego
		for (ui j=0; j<queries[i].size(); ++j) {
			int type = queries[i][j].e1.e1, cz = queries[i][j].e1.e2;
			if (type == 1) insert(cz, n + 100, -1);
			if (type == 2) insert(cz, n + 100, + 1);
		}
	}
	
	for (int i=1; i<=n; ++i)
	  if (ans[i] != -1) printf("%d\n", ans[i]);
}