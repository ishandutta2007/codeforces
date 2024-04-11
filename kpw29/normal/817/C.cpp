#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
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
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
int  k, a, b, c, d, x, y, DL = 0, T;
#define maxn 1000100

ll calc(ll n) {
	ll res = 0;
	while (n > 0) {
		res += (n % 10);
		n /= 10;
	}
	return res;
}


int main()
{
	ll N, S;
	cin >> N >> S;
	PLL i2 = mp(min(S - 1, N) + 1, min(S + 10000, N));
	PLL i3 = mp(min(S + 10000, N) + 1, N);
	
	ll ret = i3.e2 - i3.e1 + 1;
	for (ll i = i2.e1; i <= i2.e2; ++i)
		if ( i - calc(i) >= S) ++ret;
	
	cout << ret;
}