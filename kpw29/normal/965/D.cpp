#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(ll i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = (ll)1e18+3;
const int maxn = 200100;

int tab[maxn];

ll pref[maxn];
int n, m;

int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 1, n-1) 
	{
		cin >> tab[i];
		pref[i] = pref[i-1] + tab[i];
	}
	
	ll MIN = INF + 1;
	FOR(i, m, n-1) MIN = min(MIN, pref[i] - pref[i-m]);
	cout << MIN;
}