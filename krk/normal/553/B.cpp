#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 2000000000000000000ll;

const int Maxn = 52;

int n;
ll k;
ll dp[Maxn];
int res[Maxn];
bool tk[Maxn];

ll Add(ll a, ll b) { return min(Inf, a + b); }

int main()
{
	scanf("%d %I64d", &n, &k);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = Add(dp[i - 1], dp[i - 2]);
	int i = n;
	for (; i >= 2; )
		if (k <= dp[i - 1]) {
			res[n - i] = 1; i--;
		} else {
			k -= dp[i - 1];
			res[n - i] = 2; res[n - i + 1] = 1; i -= 2;
		}
	if (i >= 1) res[n - i] = 1;
	for (int i = 0; i < n; i++) {
		int pnt = 1;
		while (res[i]) {
			while (tk[pnt]) pnt++;
			if (--res[i] == 0) { printf("%d%c", pnt, i + 1 < n? ' ': '\n'); tk[pnt] = true; }
			pnt++;
		}
	}
	return 0;
}