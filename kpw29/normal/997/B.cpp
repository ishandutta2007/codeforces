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
const int maxn = 1000 * 50;
#define int long long
vector <int> tmp = {1, 5, 10, 50};

bitset <maxn + 5> da[2];
bitset <maxn + 5> poda[2];

int32_t main()
{
	da[0].set(0, 1);
	
	int n, mn;
	cin >> n;
	mn = min(n, 1000LL);
	FOR(i, 1, mn)
	{
		da[i & 1].reset();
		da[i & 1] = (da[(i & 1) ^ 1] << 1) | (da[(i & 1) ^ 1] << 5) | (da[(i & 1) ^ 1] << 10) | (da[(i & 1) ^ 1] << 50);
	}
	
	if (n == mn)
	{
		int ret = 0;
		FOR(i, 1, 50 * n) ret += da[n & 1][i];
		OUT(ret);
	}
	
	/*ll ret = 0;
	FOR(i, 1, 50 * 1000) ret += da[mn & 1][i];
	int beg = 50 * 1000 + 1;
	int nd = max(beg - 1, (ll)50 * n - 20000);
	
	ret += max(0LL, nd - beg + 1);
	
	for (int i = 19999; i >= 0; --i)
	{
		if (50 * n - i > max(beg, nd)) ret += da[mn & 1][50 * 1000 - i];
	}*/
	
	
	int ret = 0;
	FOR(i, 1, 50 * mn) ret += da[mn & 1][i];
	cout << 49LL * (n - mn) + ret;
	
}