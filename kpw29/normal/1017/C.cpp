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
const int maxn = 1000100;
int suf(int p, int q) {
	if (p % q == 0) return p / q;
	return 1 + p / q;
}
int n;
int main()
{
	boost;
	cin >> n;
	if (n == 1) OUT("1");
	if (n == 2) OUT("1 2");
	if (n == 3) OUT("3 1 2");
	int mx = 0, val = n + 1;
	for (int i=1; i<=n; ++i)
		if (i + suf(n, i) < val) mx = i, val = i + suf(n, i);
	
	//gen blocks(mx)
	int SIZE = mx;
	for (int i = 1; i <= suf(n, mx); ++i)
	{
		for (int j = 1; j <= SIZE; ++j) {
			int value = (i - 1) * SIZE + (SIZE - j + 1);
			if (value <= n) cout << value << ' ';
		}
	}
}