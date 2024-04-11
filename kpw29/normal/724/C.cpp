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
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
int n, m, k, a, b, c, T;
#define maxn 100100

multiset <PPI> s[4];
PII punkty[1000100];
ll ans[maxn]; int OSTATNI;

inline int distance(int a, int b) {
	return abs(a - b);
}

inline void insertPoint(int x, int y, int numer) {
	s[0].insert({{x-y, x}, numer});
	s[1].insert({{y+x, x}, numer});
	s[2].insert({{x-y, -x}, numer});
	s[3].insert({{y+x, -x}, numer});
}

inline int getPoint(int kt, int x, int y, int numer) {
	//cout << kt << ' ' << x << ' ' << y << ' ' << numer << endl;
	PPI miejsce;
	if (kt == 0) miejsce = *s[kt].upper_bound({{x-y, x}, numer});
	if (kt == 1) miejsce = *s[kt].upper_bound({{y+x, x}, numer});
	if (kt == 2) miejsce = *s[kt].upper_bound({{x-y, -x}, numer});
	if (kt == 3) miejsce = *s[kt].upper_bound({{y+x, -x}, numer});
	return miejsce.e2;
}

int main() {
	boost;
	cin >> n >> m >> k;
	FOR(i, 1, k) ans[i] = -1;
	int DL = 0;
	FOR(i, 1, n-1) {
		insertPoint(i, 0, ++DL);
		punkty[DL] = mp(i, 0);
	}
	FOR(i, 1, n-1) {
		insertPoint(i, m, ++DL);
		punkty[DL] = mp(i, m);
	}
	FOR(i, 1, m-1) {
		insertPoint(0, i, ++DL);
		punkty[DL] = mp(0, i);
	}
	FOR(i, 1, m-1) {
		insertPoint(n, i, ++DL);
		punkty[DL] = mp(n, i);
	}
	insertPoint(0, 0, ++DL);
	punkty[DL] = mp(0, 0);
	insertPoint(0, m, ++DL);
	punkty[DL] = mp(0, m);
	insertPoint(n, 0, ++DL);
	punkty[DL] = mp(n, 0);
	insertPoint(n, m, ++DL);
	punkty[DL] = mp(n, m);
	
	OSTATNI = DL;

	FOR(i, 1, k) {
		cin >> punkty[OSTATNI + i].e1 >> punkty[OSTATNI + i].e2;
		insertPoint(punkty[OSTATNI + i].e1, punkty[OSTATNI + i].e2, OSTATNI + i);
	}
	
	int kier = 0, NUMER = OSTATNI - 3;
	ll CZAS = 0;
	int x = 0, y = 0;
	while (1) {
		int gp = getPoint(kier, x, y, NUMER);
		PII nowypunkt = punkty[gp];
		CZAS += distance(x, nowypunkt.e1);
		if (gp > OSTATNI) {
			if (ans[gp - OSTATNI] == -1) ans[gp - OSTATNI] = CZAS;
		}
		else if (gp + 4 > OSTATNI) break;
		else {
			if (kier == 0 && punkty[gp].e2 == m) kier = (kier + 1) % 4;
			else if (kier == 1 && punkty[gp].e1 == n) kier = (kier + 1) % 4;
			else if (kier == 2 && punkty[gp].e2 == 0) kier = (kier + 1) % 4;
			else if (kier == 3 && punkty[gp].e1 == 0) kier = (kier + 1) % 4;
			else kier = (kier + 3)%4;
		}
		x = nowypunkt.e1; y = nowypunkt.e2;
		NUMER = gp;
	}
	
	FOR(i, 1, k) cout << ans[i] << "\n";
}