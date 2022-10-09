#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
#define milion 1000100
#define tysiac 1010
#define dwa_tysiace 2010
#define sto_tysiecy 100100
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <ll, ll> LONG;
typedef pair <BONG, BONG> DONG;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c;
#define maxn 200100
int t[maxn], ile[maxn], depth;
int d[maxn];
int f[maxn];
BONG help[maxn];
bool odw[maxn];
vector <int> graf[maxn];
int wynik[maxn];
int _find(int a)
{
	int fa = f[a];
	if (fa == a) return a;
	f[a] = _find(fa);
	return f[a];
}
ll wyn = 0;
bool _union(int a, int b)
{
	int fa = _find(a);
	int fb = _find(b);
	if (fb == fa) return true;
	if (ile[fa] <= ile[fb]) ile[fb] += ile[fa], f[fa] = fb, ile[fa] = 0;
	else ile[fa] += ile[fb], f[fb] = fa, ile[fb] = 0;
	return false;
}

void dfs(int x)
{
	odw[x] = true;
	d[x] = ++depth;
	for (ui i=0; i<graf[x].size(); ++i)
	if (!odw[graf[x][i]]) dfs(graf[x][i]);
	--depth;
}
ll potmod(ll a, ll b)
{
	if (!b) return 1;
	if (b & 1) return a % mod * potmod(a * a %mod, b >> 1)%mod;
	return potmod(a*a%mod, b>>1);
}
int main()
{
	scanf("%d%d", &n, &m);
	vector <BONG> v, nowy;
	for (int i=1; i<=n; ++i) f[i] = i, ile[i] = 1; //0 - nth, 1 love -1 hate
	for (int i=1; i<=m; ++i)
	{
		int type;
		scanf("%d%d%d", &a, &b, &type);
		if (type == 1) _union(a,b);
		else v.push_back(mp(a,b));
	}
	
	for (ui i=0; i<v.size(); ++i)
	{
		a = v[i].e1, b = v[i].e2;
		int fa = _find(a), fb = _find(b);
		if (fa == fb) wyn = -1;
		else 
		{
			graf[fa].pb(fb);
			graf[fb].pb(fa);
			nowy.pb(mp(fb, fa));
		}
	}
	
	for (ui i=0; i<v.size(); ++i)
	{
		a = v[i].e1, b = v[i].e2;
		int fa = _find(a), fb = _find(b);
		_union(fa, fb);
	}

	for (int i=1; i<=n; ++i) 
	if (!odw[i])
	{
		depth = 0;
		dfs(i);
	 }
	 
	for (int i=1; i<=n; ++i) d[i] = (d[i] & 1);
	for (ui i=0; i<nowy.size(); ++i)
	if (d[nowy[i].e1] == d[nowy[i].e2]) wyn = -1;
	
	if (wyn == -1) cout << "0";
	else
	{
		vector <int> w; ll allel = 1;
		for (int i=1; i<=n; ++i) w.push_back(_find(i));
		sort(w.begin(), w.end());
		for (ui i=1; i<w.size(); ++i) if (w[i] != w[i-1]) ++allel;
		wyn = potmod(2, allel - 1) % mod;
		cout << wyn;
	}
}