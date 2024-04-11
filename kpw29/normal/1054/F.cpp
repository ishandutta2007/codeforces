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
const int maxn = 2010;

int n, m;
const int W = 2010;
PII pox[maxn], poy[maxn];

int skoj[W];
vector <int> v[W];

bool odw[W], chosen[W];

bool dfs(int x)
{
	if (odw[x]) return false;
	odw[x] = 1;
	for (auto u : v[x])
		if (skoj[u] == -1 || dfs(skoj[u]))
		{
			skoj[u] = x;
			skoj[x] = u;
			return true;
		}
	return false;
}
queue <int> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto u : v[x])
		{
			assert(skoj[u] != -1);
			if (!chosen[skoj[u]])
			{
				chosen[skoj[u]] = 1;
				q.push(skoj[u]);
			}
		}
	}
}
int DL = 0;
int INVERT[2010], KT[2010];

inline ll det(PLL a, PLL b) {
	return a.e1 * b.e2 - a.e2 * b.e1;
}
inline ll area(PLL a, PLL b, PLL c) {
	return det(a, b) + det(b, c) + det(c, a);
}

inline bool isLeft(PLL a, PLL b, PLL c) {
	return (area(a, b, c) > 0);
}

inline ll sqr(ll x) { return x * x; }
inline ll dist(PLL a, PLL b) {
	return sqr(a.e1 - b.e1) + sqr(a.e2 - b.e2);
}


inline bool Inside(PLL a, PLL b, PLL c) {
	if (area(a, b, c) != 0) return 0;
	ll dbc = dist(b, c), dac = dist(a, c), dab = dist(a, b);
	if (dbc <= dab && dac <= dab) return 1;
	return 0; 
}

inline bool Intersect(PLL a, PLL b, PLL c, PLL d) { //czy odcinki <a,b> i <c,d> si przecinaja
	if (Inside(a, b, c)) return 0;
	if (Inside(a, b, d)) return 0;
	if (Inside(c, d, a)) return 0;
	if (Inside(c, d, b)) return 0;
	ll A1 = area(a, b, c), A2 = area(a, b, d); 
	ll B1 = area(c, d, a), B2 = area(c, d, b);
	if (A1 > 0 && A2 > 0) return 0;
	if (A1 < 0 && A2 < 0) return 0;
	if (B1 > 0 && B2 > 0) return 0;
	if (B1 < 0 && B2 < 0) return 0;
	if (A1 == 0 || A2 == 0 || B1 == 0 || B2 == 0) return 0;
	return 1;
}

vector <PP> odc1, odc2;
bool gold[maxn];

int main()
{
	boost;
	int t = 1;
	while (t--) 
	{
		cin >> n;
		FOR(i, 1, n) cin >> pox[i].e1 >> pox[i].e2;
		sort(pox+1, pox+n+1);
		FOR(i, 1, n) 
		{
			poy[i] = pox[i];
			swap(poy[i].e1, poy[i].e2);
		}
		sort(poy+1, poy+n+1);
		FOR(i, 1, n) swap(poy[i].e1, poy[i].e2);
		//the whole thing is sorted
		
		FOR(i, 2, n)
			if (pox[i].e1 == pox[i-1].e1)
			{
				KT[i] = ++DL; INVERT[DL] = i;
			}
		
		FOR(i, 2, n)
			if (poy[i].e2 == poy[i-1].e2)
			{
				KT[i + n] = ++DL; INVERT[DL] = i + n;
			}
		
		/*FOR(i, 1, n) cout << KT[i] << ' ';
		cout << endl;
		FOR(i, 1, n) cout << KT[i + n] << ' ';
		cout << endl;*/
		
		FOR(i, 2, n)
			FOR(j, 2, n)
				if (pox[i].e1 == pox[i-1].e1 && poy[j].e2 == poy[j-1].e2)
				{
					PP jed = mp(mp(pox[i-1].e1, pox[i-1].e2), mp(pox[i].e1, pox[i].e2));
					PP dwa = mp(mp(poy[j-1].e1, poy[j-1].e2), mp(poy[j].e1, poy[j].e2));
					if (Intersect(jed.e1, jed.e2, dwa.e1, dwa.e2))
					{
						v[KT[i]].pb(KT[j + n]);
						v[KT[j + n]].pb(KT[i]);
					}
				}
				
		FOR(i, 1, DL) skoj[i] = -1;
		int ult_result = 2 * n;
		
		bool ist = 1; int sz = 0;
		while (ist)
		{
			ist = false;
			FOR(i, 1, DL) odw[i] = false;
			FOR(i, 1, DL)
				if (!odw[i] && skoj[i] == -1 && dfs(i)) ist = true, ++sz;
		}

		while (!q.empty()) q.pop();
		int cnt = 0;

		FOR(i, 1, DL)
			if (skoj[i] == -1) ++cnt, q.push(i), chosen[i] = 1;
		
		bfs();
		FOR(i, 1, DL)
			if (!chosen[i] && !chosen[skoj[i]]) chosen[i] = 1;
		
		FOR(i, 1, DL) gold[INVERT[i]] = chosen[i];
		//int iter = 0;
		//FOR(i, 1, DL) { cout << chosen[i] << ' '; iter += chosen[i]; }
		//assert(iter == DL - sz);
		//printf("%d\n", ult_result - (DL - sz));
		FOR(i, 1, n)
			if (!gold[i]) odc1.pb(mp(pox[i], pox[i]));
			else
			{
				int sajs = (int)odc1.size() - 1;
				odc1[sajs].e2 = pox[i];
			}
		
		FOR(i, 1, n)
			if (!gold[i + n]) odc2.pb(mp(poy[i], poy[i]));
			else
			{
				int sajs = (int)odc2.size() - 1;
				odc2[sajs].e2 = poy[i];
			}
			
		//assert((int)(odc1.size() + odc2.size()) == ult_result - (DL - sz));
		swap(odc1, odc2);
		cout << (int)odc1.size() << "\n";
		for (auto u : odc1) cout << u.e1.e1 << ' ' << u.e1.e2 << ' ' << u.e2.e1 << ' ' << u.e2.e2 << "\n";
		cout << (int)odc2.size() << "\n";
		for (auto u : odc2) cout << u.e1.e1 << ' ' << u.e1.e2 << ' ' << u.e2.e1 << ' ' << u.e2.e2 << "\n";
	}
}