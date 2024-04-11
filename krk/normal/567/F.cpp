#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 105;

int n, k;
int a[Maxn], b[Maxn], c[Maxn];
ll dp[Maxn][Maxn];

bool Check(int f, int s, int l, int r)
{
	for (int i = 0; i < k; i++)
		if (a[i] == f || a[i] == s) {
			if (b[i] == f || b[i] == s) { if (abs(c[i]) > 1) return false; }
			else if (l <= b[i] && b[i] <= r) { if (c[i] < 1) return false; }
		} else if (l <= a[i] && a[i] <= r)
				if (b[i] == f || b[i] == s) { if (c[i] > -1) return false; }
	return true;
}

ll Get(int l, int r)
{
	if (dp[l][r] == -1) {
		int lft = (r - l + 1) / 2;
		if (lft == 1) dp[l][r] = Check(l, r, r + 1, r);
		else {
			ll res = 0ll;
			if (Check(l, l + 1, l + 2, r)) res += Get(l + 2, r);
			if (Check(l, r, l + 1, r - 1)) res += Get(l + 1, r - 1);
			if (Check(r - 1, r, l, r - 2)) res += Get(l, r - 2);
			dp[l][r] = res;
		}
	}
	return dp[l][r];
}

int main()
{
	char str[10];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %s %d", &a[i], str, &b[i]);
		if (str[0] == '=') c[i] = 0;
		else if (strlen(str) == 2) c[i] = str[0] == '<'? 1: -1;
			 else c[i] = str[0] == '<'? 2: -2;
	}
	fill((ll*)dp, (ll*)dp + Maxn * Maxn, -1);
	printf("%I64d\n", Get(1, 2 * n));
	return 0;
}