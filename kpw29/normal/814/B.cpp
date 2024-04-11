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
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
typedef vector <int> vi;
const ll mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int tab[maxn], t[maxn], perm[maxn], jest[maxn];
ll n, m, k, a, b, c;

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) {
		cin >> tab[i];
		perm[i] = tab[i];
	}
	
	FOR(i, 1, n) cin >> t[i];
	int same = 0;
	FOR(i, 1, n)
		if (tab[i] != t[i]) {same = i; break; }
	
	if (same == 0)
	{
		cout << "2 1 ";
		FOR(i, 3, n) cout << i << ' ';
		exit(0);
	}
	
	int zle = n;
	while (tab[zle] == t[zle]) --zle;
	if (zle == same)
	{
		//cout << "HERE\n";
		FOR(i, 1, n)
			if (i != zle) jest[perm[i]]++;
		
		FOR(i, 1, n)
			if (!jest[i]) perm[zle] = i;
	}
	else 
	{
		//cout << same << ' ' << zle << endl;
		FOR(i, 1, n)
			if (i != zle && i != same) jest[tab[i]]++;
		
		if (!jest[t[zle]] && !jest[tab[same]]) perm[zle] = t[zle];
		else perm[same] = t[same];
	}
	FOR(i, 1, n) cout << perm[i] << ' ';
	
}