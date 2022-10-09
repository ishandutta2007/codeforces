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
#define REYNA(i, a, b) for (int i=(a); i<(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int maxn = 10010;

int dp[maxn], n, q;
PPI tab[maxn];
bool ans[maxn];

int main()
{
	dp[0] = maxn;
	cin >> n >> q;
	FOR(i, 1, q) cin >> tab[i].e1.e1 >> tab[i].e1.e2 >> tab[i].e2;
	sort(tab+1, tab+q+1);
	FOR(kt, 1, q)
	{
		for (int i = n - tab[kt].e2; i >= 0; --i)
			if (dp[i] >= tab[kt].e1.e1)
			{
				dp[i + tab[kt].e2] = max(dp[i + tab[kt].e2], min(dp[i], tab[kt].e1.e2));
				if (dp[i + tab[kt].e2] > 0) ans[i + tab[kt].e2] = 1;
			}
	}
	
	int re = 0;
	FOR(i, 1, n)
		if (ans[i]) ++re;
	
	cout << re << endl;
	FOR(i, 1, n)
		if (ans[i]) cout << i << ' ';
}