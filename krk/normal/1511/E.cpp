#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 300005;

char tmp[Maxn];
int pw[Maxn];
int n, m;
string B[Maxn];
int res;

void Read(string &s)
{
	scanf("%s", tmp);
	s = tmp;
}

int main()
{
	pw[0] = 1;
	for (int i = 1; i < Maxn; i++)
		pw[i] = ll(pw[i - 1]) * 2ll % mod;
	scanf("%d %d", &n, &m);
	int w = 0;
	for (int i = 0; i < n; i++) {
		Read(B[i]);
		for (int j = 0; j < m; j++)
			if (B[i][j] == 'o') w++;
	}
	for (int i = 0; i < n; i++) {
		int myw = w;
		int dp0 = 1, dp1 = 0;
		for (int j = 0; j < m; j++)
			if (B[i][j] == 'o') {
				myw--;
				res = (res + ll(dp1) * pw[myw]) % mod;
				int old0 = dp0;
				dp0 = (ll(dp0) + 2ll * ll(dp1)) % mod;
				dp1 = old0;
			} else {
				dp0 = (dp0 + dp1) % mod;
				dp1 = 0;
			}
	}
	for (int j = 0; j < m; j++) {
		int myw = w;
		int dp0 = 1, dp1 = 0;
		for (int i = 0; i < n; i++)
			if (B[i][j] == 'o') {
				myw--;
				res = (res + ll(dp1) * pw[myw]) % mod;
				int old0 = dp0;
				dp0 = (ll(dp0) + 2ll * ll(dp1)) % mod;
				dp1 = old0;
			} else {
				dp0 = (dp0 + dp1) % mod;
				dp1 = 0;
			}
	}
	printf("%d\n", res);
    return 0;
}