#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

bool hr[3605], hc[3605];
int cdp[3605][1805];
int cntr[1805], cntc[1805];
int h, w, n;

int gen_dp(int len, bool ch[], int ret[])
{
	memset(cdp, 0, sizeof(cdp));
	cdp[0][0] = 1;
	
	rep1(i, len) rep(j, i / 2 + 1) {
		cdp[i][j] = cdp[i - 1][j];
		if(i > 1 && !ch[i] && !ch[i - 1]) cdp[i][j] = (cdp[i][j] + cdp[i - 2][j - 1]) % MOD;
	}
	rep(i, len / 2 + 1) ret[i] = cdp[len][i];
	
	int ans = 0;
	rep1(i, len) ans += !ch[i];
	return ans;
}

int C[3605][3605];

int main()
{
	C[0][0] = 1;
	rep1(i, 3600) {
		C[i][0] = 1;
		rep1(j, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	rep1(i, 3600) {
		int cfac = 1;
		rep1(j, i) {
			cfac = 1LL * cfac * j % MOD;
			C[i][j] = 1LL * C[i][j] * cfac % MOD;
		}
	}
	
	scanf("%d%d%d", &h, &w, &n);
	rep(i, n) {
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		hr[r1] = hr[r2] = true;
		hc[c1] = hc[c2] = true;
	}
	
	int rs = gen_dp(h, hr, cntr);
	int cs = gen_dp(w, hc, cntc);
	
	int ans = 0;
	rep(i, rs / 2 + 1) rep(j, cs / 2 + 1)
	ans = (ans + 1LL * cntr[i] * cntc[j] % MOD * C[rs - 2 * i][j] % MOD * C[cs - 2 * j][i]) % MOD;
	
	printf("%d\n", ans);
	return 0;
}