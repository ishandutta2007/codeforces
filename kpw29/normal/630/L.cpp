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
ll potmod(ll a, ll b, ll mod)
{
	ll ret = 1;
	while (b)
	{
		if (b & 1) ret = (ret * a)%mod;
		a = (a * a)%mod;
		b /= 2;
	}
	return ret%mod;
}

int main()
{
	ll N;
	cin >> N;
	ll E = (N % 10);
	N /= 10;
	ll D = (N % 10);
	N /= 10;
	ll C = (N % 10);
	N /= 10;
	ll B = (N % 10);
	N /= 10;
	ll A = (N % 10);
	N = 0;
	N += 10000 * A + 1000*C + 100*E + 10*D+B;
	ll num = potmod(N, 5, 100000)%100000;
	int dig = 0;
	if (num < 10) dig++;
	if (num < 100) ++dig;
	if (num < 1000) ++dig;
	if (num < 10000) ++dig;
	for (int i=1; i<=dig; ++i) cout << '0';
	cout << num;
}