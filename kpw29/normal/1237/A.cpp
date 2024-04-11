#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); }
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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1001000;
string s;
int n, m, a, b, c;

inline int ru(int x) {
	if (x >= 0) return (x + 1) / 2;
	return x / 2;
}

inline int rd(int x) {
	if (x >= 0) return x / 2;
	return (x - 1) / 2;
}

int main()
{
	boost;
	cin >> n;
	int ra = 0;
	FOR(i, 1, n) {
		int x;
		cin >> x;
		if (x % 2 == 0) cout << x / 2 << "\n";
		else {
			++ra;
			if (ra & 1) cout << rd(x) << "\n";
			else cout << ru(x) << "\n";
		}
	}
}