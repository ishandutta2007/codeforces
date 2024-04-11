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
const int mod = 998244353;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1001000;
int n;
ll I;
int arr[maxn];

vector <PII> val;
ll pref[maxn];

inline ll getSum(int a, int b) {
	if (a > b) return 0;
	return pref[b + 1] - pref[a];
}

int max_equals;

int test()
{
	int sz = val.size();
	pref[0] = 0;
	FOR(i, 1, sz) pref[i] = pref[i-1] + val[i - 1].e2;
	ll ret = inf;
	for (int i=0; i<sz; ++i) {
		int f = i + max_equals - 1;
		f = min(f, sz - 1);
		ret = min(ret, getSum(0, i - 1) + getSum(f + 1, sz - 1));
	}
	
	return ret;
}

int main()
{
	boost;
	cin >> n >> I;
	I *= 8;
	
	FOR(i, 1, n) cin >> arr[i];
	int log_max_equals = (int)I/n;
	if (log_max_equals <= 25) max_equals = (1 << log_max_equals);
	else max_equals = inf;
	sort(arr+1, arr+n+1);
	
	val.pb(mp(arr[1], 1));
	FOR(i, 2, n)
		if (val.back().e1 == arr[i]) val.back().e2++;
		else val.pb(mp(arr[i], 1));
		
	int wyn = test();
	cout << wyn;
}