#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef unsigned long long int ll;
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

ll silnia[15];
int space[20];
ll dwumian(ll n, ll k)
{
	for (int i=0; i<=10; ++i) space[i] = 0;
	for (ll i=1; i<=k; ++i) space[i] = 1;
	ll gora = 1;
	ll pol = (n - k);
	for (ll i=n; i>pol; --i) {
		gora = gora * i;
		for (ll j=1; j<=k; ++j)
		  if (space[j] && (gora % j == 0)) space[j]--, gora /= j;
	}
	
	return gora;
}

int main()
{
	ll n;
	cin >> n;
	cout << dwumian(n, 7) + dwumian(n, 6) + dwumian(n, 5);
	
}