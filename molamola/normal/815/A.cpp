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

int n, m, A[550][550];
int r[505], c[505];
int rr[505], cc[505];
int ans = 1e9;

void solve(){
	scanf("%d%d", &n, &m);
	rep(i, n) rep(j, m) scanf("%d", A[i] + j);
	int f = 0;
	for(int a=0;a<=500;a++) {
		r[0] = a;
		for(int i=0;i<m;i++) {
			c[i] = A[0][i] - r[0];
		}
		for(int i=1;i<n;i++) {
			r[i] = A[i][0] - c[0];
		}
		int ok = 1;
		rep(i, n) rep(j, m) if(c[j] < 0 || r[i] < 0 || c[j] + r[i] != A[i][j]) ok = 0;
		if(ok) {
			int k = 0;
			rep(i, n) k += r[i];
			rep(i, m) k += c[i];
			if(ans > k) {
				ans = k;
				rep(i, n) rr[i] = r[i];
				rep(i, m) cc[i] = c[i];
			}
			f = 1;
		}
	}
	if(f == 0) puts("-1");
	else {
		printf("%d\n", ans);
		rep(i, n) rep(j, rr[i]) printf("row %d\n", i + 1);
		rep(i, m) rep(j, cc[i]) printf("col %d\n", i + 1);
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