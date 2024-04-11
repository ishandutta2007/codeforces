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

ll X, D;
ll q[40];

void solve() {
	scanf("%lld%lld", &X, &D);
	for(int i=1;i<40;i++) q[i] = (1LL << i) - 1;
	vector <ll> ans;
	ll bs = 1;
	for(int i=31;i;i--) while(X >= q[i]) {
		X -= q[i];
		rep(j, i) ans.pb(bs);
		bs += 1e10;
	}
	printf("%d\n", szz(ans));
	for(ll e : ans) printf("%lld ", e); puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}