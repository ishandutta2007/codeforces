#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> BONG;
typedef pair <ll, ll> LONG;
typedef pair <ld, ld> DONG;
typedef pair <BONG, BONG> PAIR;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c,p,q, k;
ll N,M,P,Q,A,B,C;
#define maxn 3010
ll silnia[maxn];

ll potmod(ll a, ll b)
{
	if (!b) return 1;
	if (b & 1) return a % mod * potmod(a * a %mod, b >> 1)%mod;
	return potmod(a*a%mod, b>>1);
}

ll mdiv(ll a, ll b)
{
	ll ret = potmod(b, mod - 2) % mod;
	ret = ret * a % mod;
	return ret%mod;
}
ll dwumian(ll n, ll k)
{
	ll gora = silnia[n];
	ll dol = (silnia[k] * silnia[n-k])  %mod;
	return mdiv(gora, dol)%mod;
}

int main()
{
	scanf("%d", &n);
	silnia[0] = 1;
	ll wyn = 1, sum = 0;
	for (int i=1; i<=2000; ++i) silnia[i] = (silnia[i-1] * i)%mod;
	for (int i=1; i<=n; ++i) 
	{
		scanf("%d", &k);
		sum += k;
		ll el = k - 1;
		wyn = wyn * dwumian(sum - 1, el) % mod;
	}
	cout << wyn;
	return 0;
}