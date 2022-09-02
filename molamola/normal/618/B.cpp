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

void solve() {
	int n, a[55][55];
	scanf("%d", &n);
	rep(i, n) rep(j, n) scanf("%d", a[i]+j);
	rep(i, n) rep(j, n) if(a[i][j] == n - 1) {
		int p[55] = {};
		p[i] = n, p[j] = n-1;
		rep(k, n) if(k != i && k != j) p[k] = a[i][k];
		rep(k, n) printf("%d ", p[k]); puts("");
		return;
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}