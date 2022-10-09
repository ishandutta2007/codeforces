#include <bits/stdc++.h>
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
const ll mod = 1e9+9;
const ll MOD = 1e9+696969;
int n, m, k, a, b, DL = 0, CC = 0, T;

#define maxn 1000100
vector <int> v[maxn];
bool odw[maxn];
int SS = 0;
int skl[maxn], TYPE[maxn], ROZ[maxn];
ll EDGES[maxn];
bool dobre[maxn];

void dfs(int x) {
	odw[x] = 1;
	skl[x] = SS;
	if (dobre[x]) TYPE[SS] = 1;
	ROZ[SS]++;
	EDGES[SS] += (int)v[x].size();
	for (auto u : v[x])
	if(!odw[u]) dfs(u);
}
ll F(ll x) {
	return x * (x-1)/2;
}

PLL tab[maxn];

int main() {
	boost;
	cin >> n >> m >> k;
	FOR(i, 1, k) {
		cin >> a;
		dobre[a] = 1;
	}
	
	FOR(i, 1, m) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	FOR(i, 1, n) {
		if (!odw[i]) {
			++SS;
			dfs(i);
		}
	}
	
	
	ll wyn = 0;
	FOR(i, 1, SS) tab[i] = mp(TYPE[i], ROZ[i]);
	sort(tab+1, tab+SS+1);
	
		int wsk = 1;
		while (tab[wsk].e1 == 0) {
			tab[wsk].e1 = 0;
			tab[SS].e2 += tab[wsk].e2;
			tab[wsk].e2 = 0;
			wsk++;
		}
	
	FOR(i, 1, SS) {
		wyn += F(tab[i].e2);
	}

	cout << wyn - m;
}