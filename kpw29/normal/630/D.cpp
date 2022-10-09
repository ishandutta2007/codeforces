#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 100;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;
#define maxn 1500100
int n, m, a, b, c, d;

ll silnia[maxn];
ll potmod(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if ( b & 1) res = (res * a) %mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return res;
}

ll dwumian(ll n, ll k)
{
	ll gora = 1;
	ll pol = (n / 2);
	for (int i=pol+1; i<=n; ++i) gora = gora * i;
	ll dol = silnia[k];
	return (gora / dol);
}
int main()
{
	ll n;
	cin >> n;
	ll x = 0;
	x = n * (n + 1) /2 ;
	x *= 6;
	++x;
	cout << x;
}