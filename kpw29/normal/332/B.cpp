#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1001000
ll dp[maxn], pref[maxn];
int poz[maxn];
int n, k, a;
ll W;
PII wyn;
ll sum(int a, int b) {
	return pref[b] - pref[a-1];

}
int main()
{
	boost;
	cin >> n >> k;
	for (int i=1; i<=n; ++i) {
		cin >> a;
		pref[i] = pref[i-1] + a;
	}
	
	for (int i=k; i<=n; ++i) {
		dp[i] = max(dp[i-1], sum(i - k + 1, i));
		if (dp[i] == dp[i-1]) poz[i] = poz[i-1];
		else poz[i] = i - k + 1;
	}
	
	for (int i=k+k; i<=n; ++i) {
		ll W2 = W;
		W = max(W, dp[i - k] + sum(i - k + 1, i));
		if (W2 != W) wyn = mp(poz[i-k], i - k + 1);
	}
	cout << wyn.e1 << ' ' << wyn.e2;
}