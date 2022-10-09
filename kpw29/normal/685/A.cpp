#include <bits/stdc++.h>
/*#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>*/
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
typedef pair <int, int> PII;
typedef pair <int, int> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll mod = 1e9+7;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;

inline bool MN(PLL jed, PLL dwa) {
	return (jed.y < dwa.y || (jed.y == dwa.y && jed.x < dwa.x));
}
inline bool WI(PLL jed, PLL dwa) {
	return (jed.y > dwa.y || (jed.y == dwa.y && jed.x > dwa.x));
}
inline ll det(PLL &a, PLL &b) {
	return (ll)a.x * b.y - (ll)a.y * b.x;
}
inline ll area2(PLL &a, PLL &b, PLL &c) {
	return det(a, b) + det(b, c) + det(c, a);
}
inline ll aarea2(PLL &a, PLL &b, PLL &c) {
	return abs(area2(a, b, c));
}
inline bool na_lewo(PLL &a, PLL &b, PLL &c) {
	return area2(a, b, c) > 0;
}
inline bool na_prawo(PLL &a, PLL &b, PLL &c) {
	return area2(a, b, c) < 0;
}
inline bool linia(PLL &a, PLL &b, PLL &c) {
	return area2(a, b, c) == 0;
}
inline ll dist2(PLL &a, PLL &b) {
	return (ll)(a.x - b.x) * (ll)(a.x - b.x) + (ll)(a.y - b.y) * (ll)(a.y - b.y);
}
inline bool cmp(PLL &start, PLL &a, PLL &b) {
	if (WI(a, start) && MN(b, start)) return 1;
	if (WI(b, start) && MN(a, start)) return 0;
	ll D = area2(start, a, b);
	if (D == 0) return dist2(start, a) < dist2(start, b);
	return D > 0;
}

inline bool Inside(PLL &a, PLL &b, PLL &c) {
	return max(max(dist2(a, b), dist2(b, c)), dist2(a, c)) == dist2(a, b);
}

inline bool InTriangle(PLL &a, PLL &b, PLL &c, PLL &d) {
	if (area2(a, b, c) == 0) return Inside(a, b, d) || Inside(a, c, d) || Inside(b, c, d);
    return (aarea2(a, b, c) == aarea2(a, b, d) + aarea2(a, c, d) + aarea2(b, c, d));
}

int n, m, k, DL = 0, T, t0, a, b, f1, f2;
ll pot7[50];
ll silnia[50];

ll places[8];
int all;

int get(int x) {
	int num = 1;
	ll ile = 7;
	while (x > ile) {
		++num;
		ile = pot7[num];
	}
	return num;
}
ll wynik = 0;
void rec(int pos) {
	if (pos == all) {
		int cnt[8];
		FOR(i, 0, 6) cnt[i] = 0;
		FOR(i, 0, all - 1) cnt[places[i]]++;
		FOR(i, 0, 6) if (cnt[i] > 1) return;
		
		//check 1
		ll N = 0;
		FOR(i, 0, f1-1) {
			N = 7 * N;
			N += places[i];
		}
		if (N >= n) return;
		ll M = 0;
		FOR(i, f1, all-1) {
			M = 7 * M;
			M += places[i];
		}
		
		if (M >= m) return;
		++wynik;
		//FOR(i, 0, all-1) cout << places[i] << ' ';
		//cout << endl;
		return;
	}
	FOR(i, 0, 6) places[pos] = i, rec(pos + 1);
}

int main() {
	cin >> n >> m;
	
	pot7[0] = 1;
	silnia[0] = 1;
	FOR(i, 1, 25) {
		pot7[i] = pot7[i-1] * 7;
		silnia[i] = silnia[i-1] * i;
	}
	f1 = get(n), f2 = get(m);
	all = f1 + f2;
	//cout << f1 << ' ' << f2 << endl;
	if (f1 + f2 > 7) OUT(0);
	rec(0);
	cout << wynik;
}