#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1020000;

string s1, s2, s;
int n, m, k;

vector <PII> moves;
int ban[1010][1010], x, y;

int type(int p, int q) {
	if (p > 0 && q > 0) {
		return 0;
	}
	if (p > 0 && q < 0) {
		return 2;
	}
	if (p < 0 && q < 0) {
		return 4;
	}
	if (p < 0 && q > 0) {
		return 6;
	}
}

bool isprime(ll x) {
	for (ll i = 2; i * i <= x; ++i)
		if (x % i == 0) return 0;
	return 1;
}
int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) {
		ll a, b;
		cin >> a >> b;
		if (a == b + 1 && isprime(a + b)) cout << "YES\n";
		else cout << "NO\n";
	}
	
}