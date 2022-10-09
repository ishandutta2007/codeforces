#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for (int i=(a); i<=(b); ++i)
#define boost ios_base::sync_with_stdio(false);
#define OUT(x) {cout << x; exit(0); }
typedef pair <int, int> PII;
typedef long long ll;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int maxn = 200100;
int tab[maxn], m, k;

int dr[maxn];

void add(int p, int val) {
	for (; p < maxn; p += p & (-p)) dr[p] += val;
}

int get(int p) {
	int res = 0;
	for (; p > 0; p -= p & (-p)) res += dr[p];
	return res;
}

int query(int a, int b) {
	return get(b) - get(a-1);
}

int MAX[maxn], MIN[maxn], n, q;
vector <int> v[maxn];

int main()
{
	boost;
	cin >> n >> q;
	FOR(i, 0, q) MAX[i] = -1, MIN[i] = inf;
	
	FOR(i, 1, n) 
	{
		cin >> tab[i];
		MAX[tab[i]] = max(MAX[tab[i]], i);
		MIN[tab[i]] = min(MIN[tab[i]], i);
		v[tab[i]].pb(i);
	}
	
	FOR(i, 1, q)
	{
		if (MIN[i] == inf) continue;
		if (query(MIN[i], MAX[i]) > 0) OUT("NO");
		for (auto u : v[i]) add(u, 1);
	}
	
	
	int nq = 0;
	FOR(i, 1, n)
		if (tab[i] == q) ++nq;
	
	//musimy wstawic to jedno q, tylko pytanie brzmi - gdzie.
	if (nq == 0) {
		int iter = 0;
		FOR(i, 1, n)
			if (tab[i] == 0) iter = i;
		
		if (iter == 0) OUT("NO");
		tab[iter] = q;
	}
	
	cout << "YES\n";
	FOR(i, 2, n)
		if (tab[i] == 0 && tab[i-1] != 0) tab[i] = tab[i-1];
	
	for (int i=n-1; i>0; --i)
		if (tab[i] == 0 && tab[i+1] != 0) tab[i] = tab[i + 1];
	
	FOR(i, 2, n)
		if (tab[i] == 0 && tab[i-1] != 0) tab[i] = tab[i-1];
	
	
	FOR(i, 1, n) cout << tab[i] << ' ';	
	
	
}