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
typedef pair <BONG, BONG> LONG;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,a ,b;
#define maxn 200100
long long wyn = 0;
bool odw[maxn];
vector <int> v[maxn];
int wart[maxn];
int REP[maxn];
ll wynik[maxn];
void dfs(int x, int parent)
{
	odw[x] = true;
	int ile = v[x].size();
	for (int i=0; i<v[x].size(); ++i)
	  if (!odw[v[x][i]]) dfs(v[x][i], x);
	//mamy juz policzone dla nich
	ll suma = 0;
	ll minks = inf;
	for (int i=0; i<v[x].size(); ++i)
	{
	  suma += wynik[v[x][i]];
	  minks = min(minks, wynik[v[x][i]]);
	  minks = min(minks, (ll)wart[REP[v[x][i]]]);
	}
	if (ile == 0) 
	{
		REP[x] = x;
		wynik[x] = wart[x];
		return;
	}
	if (ile % 2 == 0) 
	{
		REP[x] = x;
		wynik[x] = suma + wart[x];
	}
	else if (ile == 1) 
	{
		if (wart[x] - minks + wynik[v[x][0]] >= suma)
		{
			REP[x] = x;
			wynik[x] = wart[x] - minks + wynik[v[x][0]];
		}
		else
		{
			REP[x] = REP[v[x][0]];
			wynik[x] = suma;
		}
	}
	else
	{
		if (suma - minks +wart[x] >= suma)
		{
			REP[x] = x;
			wynik[x] = suma - minks + wart[x];
		}
		else
		{
			int r = 0;
			for (int i=0; i<v[x].size(); ++i) 
			if (wart[r] > wart[REP[v[x][i]]]) r = REP[v[x][i]];
			REP[x] = r;
			wynik[x] = suma;
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	wart[0] = inf;
	cin >> n;
	for (int i=1; i<=n; ++i)
	{
		cin >> a >> wart[i];
		if (a != -1) v[a].pb(i);
	}
	dfs(1, 0);
	//for (int i=1; i<=n; ++i) cout << wynik[i] << ' ';
	cout << wynik[1] << endl;
}
/*
7
-1 8
1 3
1 3
3 4
1 6
2 4
1 12*/