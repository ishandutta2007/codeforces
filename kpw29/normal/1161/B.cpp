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
const int maxn = 200100;
PII tab[maxn];
int LEN, n, m;

int jest[maxn];

void upd(PII &seg) {
	seg.e1--; seg.e2--;
	int dist = seg.e2 - seg.e1;
	if (2 * dist > n) {
		seg.e1+=n;
		swap(seg.e1, seg.e2);
	}
}

bool cmp(PII a, PII b) {
	if (a.e2 - a.e1 != b.e2 - b.e1) return (a.e2 - a.e1 < b.e2 - b.e1);
	return a.e1 < b.e1;
}

bool check(int rot) {
	FOR(i, 1, maxn-1) jest[i] = 0;
	//cout << "Checking: " << rot << endl;
	for (int i=1; i<=m; ++i) {
		int x = i;
		while (x < m && tab[x + 1].e2 - tab[x + 1].e1 == tab[i].e2 - tab[i].e1) ++x;
		LEN = tab[i].e2 - tab[i].e1 + 1;
		FOR(j, i, x) jest[tab[j].e1 % n] = LEN;
		FOR(j, i, x)
			if (jest[(tab[j].e1 + rot) % n] != LEN) {
				if (rot * 2 == n && (LEN-1) * 2 == n) continue;
				return 0;
			}
		
		i = x;
	}
	
	return 1;
}

int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 1, m) {
		cin >> tab[i].e1 >> tab[i].e2;
		if (tab[i].e1 > tab[i].e2) swap(tab[i].e1, tab[i].e2);
		upd(tab[i]);
	}
	
	sort(tab+1, tab+m+1, cmp);
	//FOR(i, 1, m) cout << tab[i].e1 << ' ' << tab[i].e2 << endl;
	for (int div = 1; div < n; ++div) {
		if (n % div == 0) {
			if (check(div)) OUT("Yes");
		}
	}
	
	cout << "No";
}