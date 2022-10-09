#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector<int> vi;
typedef bitset<101> bset;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1001000
ll silnia[maxn], r1[maxn], r2[maxn];
ll val1[maxn], val2[maxn], a;

int g[maxn], n, m;

PLL tab[maxn];

int main()
{
	ll CST = 1e6;
	CST *= CST;
	srand(1337);
	silnia[0] = 1;
	FOR(i, 1, maxn-10) silnia[i] = silnia[i-1] * i % mod;
	
	boost;
	cin >> n >> m;
	FOR(i, 1, n) r1[i] = (ll)rand()*(ll)rand() % CST, r2[i] = (ll)rand()*(ll)rand() % CST;
	
	FOR(i, 1, n)
	{
		cin >> g[i];
		FOR(j, 1, g[i]) {
			cin >> a;
			val1[a] += r1[i];
			val2[a] += r2[i];
		}
	}
	
	FOR(i, 1, m) tab[i] = mp(val1[i], val2[i]);
	
	sort(tab+1, tab+m+1);
	ll wyn = 1;
	
	tab[0] = {-1, -1};
	int sila = 0;
	FOR(i, 1, m)
	{
		if (tab[i] == tab[i-1]) ++sila;
		else 
		{
			wyn = (wyn * silnia[sila])%mod;
			sila = 1;
		}
		
	}
	
	wyn = (wyn * silnia[sila])%mod;
	cout << wyn;
}