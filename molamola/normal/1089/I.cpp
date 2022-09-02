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
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

ll mod;
ll fact[420];
ll dp[420], X[420][420], F[420];

void init() {
	int N = 400;
	fact[0] = 1;
	for(int i=1;i<=N;i++) fact[i] = fact[i-1] * i % mod;
	for(int i=1;i<=N;i++) {
		F[i] = fact[i];
		for(int j=1;j<i;j++) F[i] = (F[i] - F[i-j] * fact[j] % mod + mod) % mod;
	}
	X[0][0] = 1;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			for(int k=1;k<=i;k++) {
				X[i][j] = (X[i][j] + X[i-k][j-1] * fact[k]) % mod;
			}
		}
	}
	for(int i=1;i<=N;i++) {
		dp[i] = fact[i];
		for(int j=1;j<i;j++) dp[i] = (dp[i] - 2LL * F[j] * fact[i-j] % mod + mod) % mod;
		for(int j=3;j<i;j++) dp[i] = (dp[i] - X[i][j] * dp[j] % mod + mod) % mod;
	}
}

void solve() {
	int N;
	scanf("%d", &N);
	printf("%lld\n", N == 2 ? 2 : dp[N]);
}

int main() {
	int T; scanf("%d%lld", &T, &mod);
	init();
	for(int t=1;t<=T;t++) {
		solve();
	}
	return 0;
}