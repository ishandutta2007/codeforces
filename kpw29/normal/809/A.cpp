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
#define maxn 1001000
int tab[maxn], n;
ll pot[maxn];

int main()
{
	boost;
	cin >> n;
	pot[0] = 1;
	FOR(i, 1, n + 5) pot[i] = (2 * pot[i-1]) %mod;
	
	ll ret = 0, sumapoprz = 0;
	FOR(i, 1, n) cin >> tab[i];
	sort(tab+1, tab+n+1);
	FOR(i, 1, n)
	{
		ret += (tab[i] * ((pot[i - 1] + mod - 1) % mod) - sumapoprz + mod)%mod;
		ret %= mod;
		sumapoprz *= 2;
		sumapoprz += tab[i];
		sumapoprz %= mod;
	}
	cout << ret;
}