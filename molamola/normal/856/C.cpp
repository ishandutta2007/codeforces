#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

const int mod = 998244353;

int N, A[2020];
int L[2020];
int dp[2020][2020][11];
int dp2[2020][2020][11];

void solve() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) {
		char buf[20];
		scanf("%s", buf);
		int c = 0;
		for(int j=0;buf[j];j++) L[i] ^= 1, c = 10 * c + buf[j] - '0';
		A[i] = c % 11;
	}
	int cnt[2] = {};
	for(int i=1;i<=N;i++) cnt[L[i]]++;
	int ap = (cnt[1] + 1) / 2;
	int am = cnt[1] / 2;
	dp[0][0][0] = 1;
	vector <int> ov, ev;
	for(int i=1;i<=N;i++) {
		if(L[i]) ov.pb(A[i]);
		else ev.pb(A[i]);
	}
	for(int i=0;i<=ap;i++) for(int j=0;j<=am;j++) {
		if(i == ap && j == am) continue;
		int x = ov[i+j];
		rep(k, 11) {
			if(i < ap) {
				int nk = (k + x) % 11;
				dp[i+1][j][nk] = (dp[i+1][j][nk] + (ll)dp[i][j][k] * (ap-i)) % mod;
			}
			if(j < am) {
				int nk = (k - x + 11) % 11;
				dp[i][j+1][nk] = (dp[i][j+1][nk] + (ll)dp[i][j][k] * (am-j)) % mod;
			}
		}
	}
	rep(v, 11) dp2[0][0][v] = dp[ap][am][v];
	int bp = cnt[1] / 2 + 1;
	int bm = (cnt[1] + 1) / 2;
	int b = cnt[0];
	for(int i=0;i<b;i++) for(int j=0;i+j<b;j++) {
		int x = ev[i+j];
		rep(k, 11) {
			int nk = (k + x) % 11;
			dp2[i+1][j][nk] = (dp2[i+1][j][nk] + (ll)dp2[i][j][k] * (bp+i)) % mod;
			nk = (k - x + 11) % 11;
			dp2[i][j+1][nk] = (dp2[i][j+1][nk] + (ll)dp2[i][j][k] * (bm+j)) % mod;
		}
	}
	ll ans = 0;
	for(int i=0;i<=b;i++) ans = (ans + dp2[i][b-i][0]) % mod;
	printf("%lld\n", ans);
	
	for(int i=0;i<=N+1;i++) for(int j=0;j<=N+1;j++) rep(k, 11) dp[i][j][k] = dp2[i][j][k] = 0;
	for(int i=1;i<=N;i++) L[i] = 0;
}

int main() {
	int T; scanf("%d", &T);
	for(int tc=1;tc<=T;tc++) {
		solve();
	}
	return 0;
}