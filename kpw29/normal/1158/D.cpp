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

inline ll det(PLL a, PLL b) {
	return a.e1 * b.e2 - a.e2 * b.e1;
}

inline bool na_lewo(PLL a, PLL b, PLL c) {
	return det(a, b) + det(b, c) + det(c, a) > 0;
}
inline bool na_prawo(PLL a, PLL b, PLL c) {
	return det(a, b) + det(b, c) + det(c, a) < 0;
}

int p[maxn];
string s;
PLL tab[maxn];
int DL, n;
vector <int> kol;

int main()
{	
	boost;
	cin >> n;
	int id = -1; 
	PLL MAX = {inf, inf};

	FOR(i, 1, n) {
		cin >> tab[i].e1 >> tab[i].e2;
		//cout << id << endl;
		if (tab[i].e1 < MAX.e1) {
			MAX = tab[i];
			id = i;
		}
		else if (tab[i].e1 == MAX.e1 && tab[i].e2 < MAX.e2) {
			id = i;
			MAX = tab[i];
		}
	}
	
	cin >> s;
	p[id] = 1; kol.pb(id);
	//cout << id << endl;
	PLL curr = tab[id];
	FOR(step, 0, n-2) {
		int f = 1;
		if (s[step] == 'R') {
			while (p[f]) ++f;
			PLL sec = tab[f];
			FOR(i, f + 1, n) {
				if (p[i]) continue;
				if (na_lewo(curr, sec, tab[i])) sec = tab[i], f = i;
			}
			
			curr = sec;
		}
		else {
			while (p[f]) ++f;
			PLL sec = tab[f];
			FOR(i, f+1, n) {
				if (p[i]) continue;
				if (na_prawo(curr, sec, tab[i])) sec = tab[i], f = i;
			}
			
			curr = sec;
		}
		
		
		p[f] = 1;
		kol.pb(f);
	}
	
	for (auto u : kol) cout << u << ' ';
}