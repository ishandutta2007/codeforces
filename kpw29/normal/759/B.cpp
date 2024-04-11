#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector<int> vi;
typedef bitset<51> bset;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1001000
int T, n, m, a, b, c;
int ptr[4];
ll dp[maxn];
int tab[maxn];
int val[4], rub[4];
int main()
{
	val[1] = 90;
	val[2] = 1440;
	rub[1] = 50;
	rub[2] = 120;
	boost;
	cin >> n;
	FOR(i, 0, 2) ptr[i] = 1;
	FOR(i, 1, n)
	{
		cin >> tab[i];
		dp[i] = dp[i-1] + 20;
		FOR(j, 1, 2)
		{
			while (tab[i] - tab[ptr[j]] + 1 > val[j]) ++ptr[j];
			dp[i] = min(dp[i], dp[ptr[j] - 1] + rub[j]);
		}
		cout << max(0LL, dp[i] - dp[i-1]) << "\n";
	}
}