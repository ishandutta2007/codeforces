#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll mul_inv(ll a, ll b) {
	ll t1 = a, t2 = b, t3;
	ll v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		ll x = t1 / t2;
		t3 = t1 - x*t2;
		v3 = v1 - x*v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}
ll getphi(ll A, ll Q) {
	ll v = 1;
	for (ll i = 1;; i++) {
		v = (v * A) % Q;
		if (v == 1) return i;
	}
}

ll mypow(ll a, ll b, ll M) {
	ll rv = 1;
	while (b) {
		if (b % 2) rv = (rv * a) % M;
		a = (a*a) % M;
		b /= 2;
	}
	return rv;
}
ll F[1000500];
ll Finv[1000500];
ll C(ll a, ll b, ll M) {
	if (b > a || b < 0 || a < 0) return 0;
	ll rv = F[a] * Finv[b] % M;
	return rv * Finv[a - b] % M;
}
ll ans[1000500];
int main() {
	ll N, M, A, Q, i, j;
	scanf("%lld %lld %lld %lld", &N, &M, &A, &Q);

	ll phi = getphi(A, Q);
	F[0] = 1;
	for (i = 1; i <= M; i++) F[i] = F[i - 1] * i % phi;
	for (i = 0; i <= M; i++) Finv[i] = mul_inv(F[i], phi);

	for (i = N; i >= 1; i--) ans[i] = (ans[i + 1] + C(M, N - i, phi)) % phi;
	for (i = 1; i <= N; i++) printf("%lld ", mypow(A, ans[i], Q));
	return !printf("\n");
}