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
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

const int MOD = 1e9 + 7;
int A[200020], N;

int pw(int x, int y) {
	int res = 1;
	while(y) {
		if(y & 1) res = (ll)res * x % MOD;
		x = (ll)x * x % MOD;
		y >>= 1;
	}
	return res;
}

int Do(int l, int r) {
	int n = (r - l) / 2;
	int res = 0;
	int C = 1;
	for(int i=0;i<=n;i++) {
		if(i) {
			C = (ll)C * (n-i+1) % MOD;
			C = (ll)C * pw(i, MOD - 2) % MOD;
		}
		res = (res + (ll)C * A[l + 2 * i]) % MOD;
	}
	return res;
}

void solve(){
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%d", A+i);
	if(N == 1) {
		printf("%d\n", A[1]);
		return;
	}
	if(N & 1) {
		int temp[200020] = {};
		for(int i=1;i<N;i++) {
			if(i & 1) temp[i] = (A[i] + A[i+1]) % MOD;
			else temp[i] = (A[i] - A[i+1] + MOD) % MOD;
		}
		for(int i=1;i<N;i++) A[i] = temp[i]; --N;
	}
	int x = Do(1, N-1);
	int y = Do(2, N);
	if(N % 4 == 0) {
		printf("%d\n", (x - y + MOD) % MOD);
	}
	else {
		printf("%d\n", (x + y) % MOD);
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
};