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

int m,a,b,c;
ll n,k;
int t[milion];
int nowe[110];

ll potmod(ll a, ll b)
{
	if (!b) return 1;
	if (b & 1) return a%mod*potmod(a*a%mod, b>>1)%mod;
	return potmod(a*a%mod, b>>1)%mod;
}

ll moddiv(ll a, ll b)
{
	ll ret = potmod(b, mod-2) % mod;
	ret = ret * a %mod;
	return ret%mod;
}
char s[milion];

int main()
{
	scanf("%s%I64d", s+1, &k);

	n = 1;
	while (s[n]) ++n;
	--n;
	for (int i=1; i<=n; ++i) t[i] = s[i] - '0';
	ll q = potmod(2, n);
	ll q_k = potmod(q ,k) %mod;
	ll wyn = 0;
	for (int i=1; i<=n; ++i)
		if (t[i] % 5 == 0) 
		{
			ll a1 = potmod(2, i-1);
			ll prawa = moddiv(1 - q_k, 1 - q);
			prawa = prawa * a1 % mod;
			wyn = (wyn + prawa) %mod;
		}
	printf("%I64d", wyn % mod);
}