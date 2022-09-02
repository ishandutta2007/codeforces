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

int n, k1, k2, k;
int A[1010], B[1010];

void solve() {
	scanf("%d%d%d", &n, &k1, &k2);
	k = k1 + k2;
	for(int i=1;i<=n;i++) scanf("%d", A+i);
	for(int i=1;i<=n;i++) scanf("%d", B+i);
	for(int i=1;i<=n;i++) A[i] = abs(A[i] - B[i]);
	for(int i=1;i<=k;i++) {
		int f = 1;
		for(int j=2;j<=n;j++) if(A[j] > A[f]) f = j;
		A[f]--; if(A[f] == -1) A[f] = 1;
	}
	ll ans = 0;
	for(int i=1;i<=n;i++) ans += (ll) A[i] * A[i];
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}