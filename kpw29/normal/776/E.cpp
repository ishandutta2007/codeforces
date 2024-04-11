#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll mod = 1e9+7;
const ll INF = 1e18;
#define maxn 1001000
ll sth, k;
int zloz[maxn], phi;

ll find_phi(ll n) {
	if (n == 1) return 1;
	ll ret = n, prim = n;
	for (ll i=2; i*i<=n; ++i)
	  if (!zloz[i] && n % i == 0) {
		  while (prim % i == 0) prim /= i;
		  ret /= i;
		  ret *= (i-1);
	  }
	if (prim > 1) ret /= prim, ret *= (prim-1);
	return ret;
}

int main()
{
	cin >> sth >> k;
	zloz[0] = zloz[1] = 1;
	for (int i=2; i<maxn; ++i)
	  for (int j=i+i; j<maxn; j += i) zloz[j] = 1;
	ll currN = sth;
	for (ll op=1; op<=k; ++op)
	{
		if (op % 2 == 0) continue;
		if (currN == 1) OUT(1);
		currN = find_phi(currN);
	}
	cout << currN % mod;
}