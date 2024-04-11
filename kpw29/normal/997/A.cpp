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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1000100;
char s[maxn];
int x, y, n;

int main()
{
	boost;
	cin >> n >> y >> x;
	int st = -1;
	cin >> s;
	int zero = 0;
	for (int i=0; i<n; ++i)
	{
		int tmp = s[i] - '0';
		if (tmp == st) continue;
		st = tmp;
		if (st == 0) ++zero;
	}
	
	if (zero == 0) OUT(0);
	if (y >= x) cout << (ll)zero * x;
	else cout << (ll)(zero - 1) * y + x;
}