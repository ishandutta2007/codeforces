#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 21000;
const int SQ = 150;

int n, m, p;
int x[MAXN];
int y[MAXN];
int dp[MAXN];
int dp2[MAXN];
char go[MAXN];
vector<int> sv;
char gog[SQ][MAXN];
char svg[SQ][MAXN];

int dpg[SQ][MAXN];
int svd[SQ][MAXN];

int f(int a, int b) {
	return (x[a] + y[b]) % p;
}


void calc(int x, int dp[], int dp2[], char go2[]) {
	dp2[0] = dp[0] + f(x + 1, 0);
	go2[0] = 0;
	for (int i = 1; i < m; ++i) {
		if (dp2[i - 1] > dp[i])
			dp2[i] = dp2[i - 1] + f(x + 1, i), go2[i] = 1;
		else
			dp2[i] = dp[i] + f(x + 1, i), go2[i] = 0;
	}
}


void save(int x) {
	int now = sv.size();
	memcpy(svd[now], dp, sizeof(dp[0]) * m);
	memcpy(svg[now], go, sizeof(go[0]) * m);
	sv.push_back(x);
}


int main() {
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; ++i)
		scanf("%d", x + i);
	for (int i = 0; i < m; ++i)
		scanf("%d", y + i);
	dp[0] = f(0, 0);
	for (int i = 1; i < m; ++i)
		dp[i] = dp[i - 1] + f(0, i), go[i] = 1;
	save(0);
	for (int i = 1; i < n; ++i) {
		calc(i - 1, dp, dp2, go);
		memcpy(dp, dp2, sizeof(dp[0]) * m);
		if (i % SQ == 0)
			save(i);
	}
	int nx = n - 1;
	int ny = m - 1;
	cout << dp[m - 1] << "\n";
	string ans;
	while (nx >= 0) {
		int g = upper_bound(sv.begin(), sv.end(), nx) - sv.begin();
		--g;
		memcpy(dpg[0], svd[g], sizeof(svd[g][0]) * m);
		memcpy(gog[0], svg[g], sizeof(svg[g][0]) * m);
		int now = sv[g];
		while (now < nx)
			calc(now, dpg[now - sv[g]], dpg[now - sv[g] + 1], gog[now - sv[g] + 1]), ++now;
		while (nx >= sv[g]) {
			if (gog[nx - sv[g]][ny] == 1)
				ans += 'S', --ny;
			else
				ans += 'C', --nx;
		}
	}
	ans.pop_back();
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";

	return 0;
}