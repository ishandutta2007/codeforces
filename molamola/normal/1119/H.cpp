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
#define pb push_back
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

const ll mod = 998244353;

ll pw(ll x, ll y = mod - 2) {
	ll res = 1;
	while(y) {
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}

// XOR convolution
void FFT_XOR(ll A[], int rev, int K) {
	const int N = 1<<K;
	for(int len=1;len<N;len<<=1) {
		for(int i=0;i<N;i+=len*2) {
			for(int j=0;j<len;j++) {
				ll x = A[i+j];
				ll y = A[i+j+len];
				A[i+j] = (x + y >= mod ? x + y - mod : x + y);
				A[i+j+len] = (x - y < 0 ? x - y + mod : x - y);
			}
		}
	}
	if(rev) rep(i, N) A[i] = A[i] * pw(N) % mod;
}

int N, K;
ll XV, YV, ZV;
int A[100010], B[100010], C[100010];
ll V[3][1<<17], W[1<<17];
ll ans[1<<17];

int main() {
	scanf("%d%d", &N, &K);
	scanf("%lld%lld%lld", &XV, &YV, &ZV);
	for(int i=1;i<=N;i++) scanf("%d%d%d", A+i, B+i, C+i);
	int ta = 0;
	for(int i=1;i<=N;i++) B[i] ^= A[i], C[i] ^= A[i], ta ^= A[i];
	for(int i=1;i<=N;i++) V[0][B[i]]++;
	FFT_XOR(V[0], 0, K);
	for(int i=1;i<=N;i++) V[1][C[i]]++;
	FFT_XOR(V[1], 0, K);
	for(int i=1;i<=N;i++) V[2][B[i]^C[i]]++;
	FFT_XOR(V[2], 0, K);
	ll wx = (XV + YV + ZV) % mod;
	ll wy = (XV + YV - ZV + mod) % mod;
	ll wz = (XV - YV + ZV + mod) % mod;
	ll ww = (XV - YV - ZV + mod * 2) % mod;
	ll i4 = pw(4);
	rep(i, 1<<K) {
		ll v1 = V[0][i], v2 = V[1][i], v3 = V[2][i], v4 = N;
		ll x = (v1 + v2 + v3 + v4) * i4 % mod;
		ll y = (v1 - v2 - v3 + v4 + mod * 2) * i4 % mod;
		ll z = (-v1 + v2 - v3 + v4 + mod * 2) * i4 % mod;
		ll w = (-v1 - v2 + v3 + v4 + mod * 2) * i4 % mod;
		W[i] = pw(wx, x) * pw(wy, y) % mod * pw(wz, z) % mod * pw(ww, w) % mod;
	}
	FFT_XOR(W, 1, K);
	rep(i, 1<<K) ans[i ^ ta] = W[i];
	rep(i, 1<<K) printf("%lld ", ans[i]); puts("");
	
	return 0;
}