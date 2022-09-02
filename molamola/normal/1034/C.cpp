#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;

int N;
int A[1000010], p[1000010];
ll S[1000010];
int cnt[1000010];
ll dp[1000010];
const int MOD = 1e9 + 7;

ll gc(ll x, ll y) { return y?gc(y, x%y) : x; }

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) {
		scanf("%d", A+i);
		S[i] = A[i];
	}
	for(int i=2;i<=N;i++) scanf("%d", p+i);
	for(int i=N;i>=2;i--) {
		S[p[i]] += S[i];
	}
	ll TS = S[1];
	for(int i=1;i<=N;i++) {
		ll temp = gc(S[i], TS);
		ll t2 = TS / temp;
		if(t2 > N) continue;
		for(int i=(int)t2;i<=N;i+=(int)t2) {
			cnt[i]++;
		}
	}
	dp[1] = 1;
	ll ans = 0;
	for(int i=1;i<=N;i++) {
		if(TS % i == 0 && cnt[i] == i) {
			ans += dp[i];
			if(ans >= MOD) ans -= MOD;
			for(int j=i+i;j<=N;j+=i) {
				dp[j] += dp[i];
				if(dp[j] >= MOD) dp[j] -= MOD;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}