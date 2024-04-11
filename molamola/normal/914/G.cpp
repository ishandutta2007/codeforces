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
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

const int SZ = 17, N = 1 << SZ;

int Rev(int x) {
	int i, r = 0;
	for (i = 0; i < SZ; i++) {
		r = r << 1 | (x & 1);
		x >>= 1;
	}
	return r;
}

void FFT(ll *a, bool f) {
	int i, j, k;
	ll z;
	for (i = 0; i < N; i++) {
		j = Rev(i);
		if (i < j) {
			z = a[i];
			a[i] = a[j];
			a[j] = z;
		}
	}
	for (i = 1; i < N; i <<= 1) for (j = 0; j < N; j += i << 1) for (k = 0; k < i; k++) {
		z = a[i + j + k];
		a[i + j + k] = a[j + k] - z;
		a[j + k] += z;
	}
	if (f) for (i = 0; i < N; i++) a[i] /= N;
}

const int MOD = 1e9 + 7;
ll X[3][N], Y[3][N], Z[N];
ll S[N];
ll F[N + 10];

void solve() {
	F[0] = 0, F[1] = 1;
	for(int i=2;i<N+10;i++) F[i] = (F[i-1] + F[i-2]) % MOD;
	int n; scanf("%d", &n);
	rep(i, n) {
		int x; scanf("%d", &x); S[x]++;
	}
	rep(i, N) X[1][i] = S[i];
	for(int i=0;i<N;i++) {
		int ni = (N - 1 - i);
		for(int j=i;;j=(j-1)&i) {
			X[0][ni | j] += S[ni] * S[j];
			if(j == 0) break;
		}
	}
	FFT(S, false);
	for (int i = 0; i < N; i++) S[i] *= S[i];
	FFT(S, true);
	for(int i=0;i<N;i++) X[2][i] = S[i];
	rep(u, 3) rep(i, N) {
		X[u][i] %= MOD;
		X[u][i] = X[u][i] * F[i] % MOD;
	}
	rep(u, 3) {
		rep(i, N) {
			for(int j=i;;j=(j-1)&i) {
				Y[u][j] += X[u][i];
				if(j == 0) break;
			}
		}
		rep(i, N) Y[u][i] %= MOD;
	}
	rep(i, N) Z[i] = Y[0][i] * Y[1][i] % MOD * Y[2][i] % MOD;
	for(int i=1;i<N;i++) {
		int ni = N - 1 - i;
		for(int j=(i-1)&i;;j=(j-1)&i) {
			int nj = N - 1 - j;
			Z[ni] -= Z[nj];
			if(j == 0) break;
		}
	}
	rep(i, N) Z[i] = (Z[i] % MOD + MOD) % MOD;
	ll ans = 0;
	rep(i, SZ) ans = (ans + Z[1<<i]) % MOD;
	printf("%lld\n", ans);
//	rep(u, 3) rep(i, N) if(X[u][i] > 0) printf("%d : %d, %lld\n", u, i, X[u][i]);
	
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}