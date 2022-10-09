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
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1001000
int a, b, c, n, m, k, wym, money;
PII cost[maxn], cena[maxn];
int buy[maxn];
pair <long long, int> tab[maxn];
PLL pcost[maxn];
int NUM[maxn][3];

bool check(int day) {
	if (day > n) return 1;
	for (int i=1; i<=m; ++i) 
	  if (cena[i].e1 == 1) tab[i] = mp(cena[i].e2 * pcost[day].e1, i);
	  else tab[i] = mp(cena[i].e2 * pcost[day].e2, i);
	sort(tab + 1, tab + m + 1);

	ll mon = 0;
	for (int i=1; i<=wym; ++i) {
		mon += tab[i].e1;
		if (mon > money) return 0;
	}
	return (mon <= money);
}

int binsearch(int x, int y) {
	while (x < y) {
		int sr = (x + y) >> 1;
		if (check(sr) == false) x = sr + 1;
		else y = sr;
	}
	check(x);
	if (x <= n) {
		printf("%d\n", x);
		for (int i=1; i<=wym; ++i) printf("%d %d\n", tab[i].e2, NUM[x][cena[tab[i].e2].e1]);
	}
	return x;
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &wym, &money);
	pcost[0] = mp(inf, inf);
	for (int i=1; i<=n; ++i) scanf("%d", &cost[i].e1);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &cost[i].e2);
		pcost[i].e1 = min(pcost[i-1].e1, (ll)cost[i].e1);
		pcost[i].e2 = min(pcost[i-1].e2, (ll)cost[i].e2);
		if (pcost[i].e1 < pcost[i-1].e1) NUM[i][1] = i;
		else NUM[i][1] = NUM[i-1][1];
		
		if (pcost[i].e2 < pcost[i-1].e2) NUM[i][2] = i;
		else NUM[i][2] = NUM[i-1][2];
	}
	for (int i=1; i<=m; ++i) scanf("%d%d", &cena[i].e1, &cena[i].e2);
	int wyn = binsearch(1, n + 1);
	if (wyn > n) puts("-1");
}