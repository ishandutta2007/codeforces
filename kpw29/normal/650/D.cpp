#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1001000
map <int, int> skal;
vector <int> z[maxn];
int tab[maxn], t[maxn], DL = 0, SKAL = 0;
int n, zap;
PII q[maxn];

int LIS, lewo[maxn], prawo[maxn], LEWO[maxn], PRAWO[maxn];
int dr[maxn + 100];

void add(int p, int v) {
	for (; p < maxn; p += p & (-p)) dr[p] = max(dr[p], v);
}
int get(int p) {
	int res = 0;
	for (; p > 0; p -= p & (-p)) res = max(res, dr[p]);
	return res;
}
inline void radd(int p, int v) {
	add(maxn - p, v);
}
inline int rget(int p) {
	return get(maxn - p);
}
int cnt[maxn];

int main()
{
	scanf("%d%d", &n, &zap);
	for (int i=1; i<=n; ++i) scanf("%d", &t[i]), tab[++DL] = t[i];
	for (int i=1; i<=zap; ++i) scanf("%d%d", &q[i].e1, &q[i].e2), tab[++DL] = q[i].e2;
	sort(tab + 1, tab + DL + 1);
	for (int i=1; i<=DL; ++i)
	{
		if (tab[i] != tab[i-1]) ++SKAL;
		skal[tab[i]] = SKAL;
	}
	for (int i=1; i<=n; ++i) t[i] = skal[t[i]];
	for (int i=1; i<=zap; ++i) {
		q[i].e2 = skal[q[i].e2];
		z[q[i].e1].pb(i);
	}
	for (int i=1; i<=n; ++i)
	{
		lewo[i] = get(t[i] - 1) + 1;
		for (ui j=0; j<z[i].size(); ++j)
		{
			int nr = z[i][j], wart = q[nr].e2;
			LEWO[nr] = get(wart - 1);
		}
		add(t[i], lewo[i]);
		LIS = max(LIS, lewo[i]);
	}
	fill(dr, dr + maxn + 10, 0);
	for (int i=n; i>0; --i)
	{
		prawo[i] = rget(t[i] + 1) + 1;
		for (ui j=0; j<z[i].size(); ++j)
		{
			int nr = z[i][j], wart = q[nr].e2;
			PRAWO[nr] = rget(wart + 1);
		}
		radd(t[i], prawo[i]);
	}

	for (int i=1; i<=n; ++i)
	  if (lewo[i] + prawo[i] == LIS + 1) cnt[lewo[i]]++;
	for (int i=1; i<=zap; ++i)
	{
		int nr = q[i].e1, l = LEWO[i], r = PRAWO[i];
		if (r + l == LIS) printf("%d\n", LIS + 1);
		else if (lewo[nr] + prawo[nr] == LIS + 1 /*byl dobrym*/ && cnt[lewo[nr]] <= 1 /*byl jedynym dobrym*/ && r + l <= LIS - 2) printf("%d\n", LIS - 1);
		else printf("%d\n", LIS);
	}
}