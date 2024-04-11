 #include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1010100

ll dp[maxn];
char s[maxn];
int main() {
	boost;
	dp[0] = 0;
	scanf("%s", s + 1);
	int n = 1;
	while (s[n]) ++n; --n;
	for (int i=1; i<=n; ++i) {
		dp[i] = dp[i-1];
		int elem = s[i] - '0';
		if (elem % 4 == 0) ++dp[i];
		if (i > 1) {
			elem += 10 * (s[i-1] - '0');
			if (elem % 4 == 0) dp[i] += i-1;
		}
	}
	cout << dp[n];
}