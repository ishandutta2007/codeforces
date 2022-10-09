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
const int maxn = 100100;

ll tab[maxn];

PLL que[maxn];
ll odp[maxn];
int n, m;
ll df[maxn];

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> tab[i];
	sort(tab+1, tab+n+1);
	FOR(i, 2, n) df[i - 1] = tab[i] - tab[i-1];
	sort(df + 1, df + n);
	
	//uwazac na zero
	cin >> m;
	FOR(i, 1, m) {
		ll a, b;
		cin >> a >> b;
		que[i] = mp(b - a + 1, i);
	}
	
	ll wynik = 0, open = n;
	sort(que+1, que+m+1);
	int wsk = 1;
	FOR(i, 1, m)
	{
		while (wsk < n && df[wsk] < que[i].e1) wynik += max(0LL, df[wsk] - que[i-1].e1), --open, ++wsk;
		wynik += open * (que[i].e1 - que[i-1].e1);
		odp[que[i].e2] = wynik;
	}
	
	FOR(i, 1, m) cout << odp[i] << " ";
}