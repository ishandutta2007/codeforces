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

const int A = 7 * 17, B = 23, P = A << B | 1, R = 3;
 
int Pow(int x, int y) {
    int r = 1;
    while (y) {
        if (y & 1) r = (long long)r * x % P;
        x = (long long)x * x % P;
        y >>= 1;
    }
    return r;
}
 
void FFT(int N, int *a, bool f) {
    int i, j, k, x, y, z;
    j = 0;
    for (i = 1; i < N; i++) {
        for (k = N >> 1; j >= k; k >>= 1) j -= k;
        j += k;
        if (i < j) {
            k = a[i];
            a[i] = a[j];
            a[j] = k;
        }
    }
    for (i = 1; i < N; i <<= 1) {
        x = Pow(f ? Pow(R, P - 2) : R, P / i >> 1);
        for (j = 0; j < N; j += i << 1) {
            y = 1;
            for (k = 0; k < i; k++) {
                z = (long long)a[i | j | k] * y % P;
                a[i | j | k] = a[j | k] - z;
                if (a[i | j | k] < 0) a[i | j | k] += P;
                a[j | k] += z;
                if (a[j | k] >= P) a[j | k] -= P;
                y = (long long)y * x % P;
            }
        }
    }
    if (f) {
        j = Pow(N, P - 2);
        for (i = 0; i < N; i++) a[i] = (long long)a[i] * j % P;
    }
}

vector <int> F[100010];
int TA[500050], TB[500050];

void multiply(vector <int> a, vector <int> b, vector <int> &c) {
	int n = 1;
	while(n < szz(a) + szz(b)) n <<= 1;
	rep(i, n) TA[i] = (i < szz(a) ? a[i] : 0);
	rep(i, n) TB[i] = (i < szz(b) ? b[i] : 0);
	FFT(n, TA, false);
	FFT(n, TB, false);
	rep(i, n) TA[i] = (ll) TA[i] * TB[i] % P;
	FFT(n, TA, true);
	int f = n - 1; while(f >= 0 && TA[f] == 0) --f;
	c.clear();
	rep(i, f + 1) c.pb(TA[i]);
}

ll f[100010];
ll pw(ll x, ll y = P - 2) {
	ll res = 1;
	while(y) {
		if(y & 1) res = (ll) res * x % P;
		x = (ll) x * x % P;
		y >>= 1;
	}
	return res;
}

void solve() {
	int N, A, B; scanf("%d%d%d", &N, &A, &B);
	if(A == 0 || B == 0) { puts("0"); return; }
	--A; --B; --N;
	for(int i=0;i<N;i++) {
		F[i].pb(i);
		F[i].pb(1);
	}
	for(int i=1;i<N;i+=i) {
		for(int j=0;j+i<N;j+=2*i) {
			int nj = j + i;
			multiply(F[j], F[nj], F[j]);
		}
	}
	if(N == 0) F[0].push_back(1);
	f[0] = 1;
	for(int i=1;i<100010;i++) f[i] = (ll) i * f[i-1] % P;
	ll ans = (A + B < szz(F[0]) ? F[0][A+B] : 0);
	ans = ans * f[A + B] % P;
	ans = ans * pw(f[A]) % P;
	ans = ans * pw(f[B]) % P;
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}