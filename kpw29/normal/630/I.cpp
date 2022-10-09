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
ll potmod(ll a, ll b)
{
	ll ret = 1;
	while (b)
	{
		if (b & 1) ret *= a;
		a *= a;
		b /= 2;
	}
	return ret;
}

ll f(ll dl)
{
	if (dl == 0) return 1;
	if (dl == 1) return 3;
	return 3 * potmod(4, dl - 1);
}

int main()
{
	ll result = 0;
	ll N;
	cin >> N;
	ll DL = 2 * N - 2;
	swap(N, DL);
	for (int i=1; i<=N-DL+1; ++i) 
	  result += 4 * f(i-1) * f(N - (i + DL - 1));
	cout << result;
}