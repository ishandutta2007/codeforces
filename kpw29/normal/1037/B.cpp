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
typedef pair <PII, PII > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1000100;
int n, m, k, a, b, c, s;
int arr[maxn];
inline ll dist(ll x, ll y) {return abs(x - y); }

int main()
{
	boost;
	cin >> n >> s;
	ll sum = 0, cnt = 0, elo = 0, sum2 = 0;
	
	for (int i=1; i<=n; ++i) {
		cin >> arr[i];
		if (arr[i] < s) ++cnt, sum += arr[i];
		if (arr[i] > s) ++elo, sum2 += arr[i];
	}
	sort(arr+1, arr+n+1);
	int need = (n + 1)/ 2;
	if (arr[need] == s) OUT(0);
	if (cnt < need)
	{
		ll ret = 0;
		FOR(i, cnt + 1, need) ret += dist(arr[i], s);
		OUT(ret);
	}
	if (elo < need)
	{
		ll ret = 0;
		for (int i = n - elo; i >= need; --i) ret += dist(arr[i], s);
		OUT(ret);
	}
	
}