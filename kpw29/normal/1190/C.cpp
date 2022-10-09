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
const ll mod = 1e9+696969;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1000100;
ll pref[maxn];

inline int sum(int a, int b)
{
	return pref[b] - pref[a-1];
}

void out(int x) {
	if (x == 1) OUT("quailty");
	if (x == 0) OUT("tokitsukaze");
}

int n, k;
char s[maxn];
set <int> pos[2];

bool test(int x, int y, int range)
{
	int target = (range ^ 1);
	int R = 0, L = 0;
	R = *(--(--pos[target].end()));
	//cout << "Testing: " << x << ' ' << y << ' ' << target << endl;
	if (x <= R && R <= y) R = *(--pos[target].lower_bound(x));

	L = *(++pos[target].begin());
	if (x <= L && L <= y) L = *pos[target].upper_bound(y);
	//cout << L << ' ' << R << endl;
	
	assert(L <= R);
	return (R - L + 1 <= k);
}

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s+1);
	pref[0] = 0;
	FOR(i, 1, n) 
	{
		pref[i] = pref[i-1] + (s[i] == '1');
		if (s[i] == '1') pos[1].insert(i);
		else pos[0].insert(i);
	}
	
	pos[0].insert(-inf); pos[1].insert(-inf);
	pos[0].insert(inf); pos[1].insert(inf);
	
	int sm = sum(1, n);
	if (sm == 0 || sm == n) out(0);
	
	FOR(i, 1, n-k+1)
	{
		int suma = sum(i, i + k  - 1);
		int err = sm - suma, len = n - k;
		if (err == 0 || err == len) out(0);
	}
	
	//when first wins, now do second
	test(1, 1, 0);
	
	bool canWin = true;
	FOR(i, 1, n-k+1)
	{
		canWin &= test(i, i + k - 1, 0);
		canWin &= test(i, i + k - 1, 1);
		if (!canWin) OUT("once again");
	}
	

	OUT("quailty");
}