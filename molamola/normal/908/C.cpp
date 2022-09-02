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

int n, r, A[1010];
double ans[1010];

void solve() {
	scanf("%d%d", &n, &r);
	for(int i=1;i<=n;i++) scanf("%d", A+i);
	for(int i=1;i<=n;i++) {
		double res = r;
		for(int j=1;j<i;j++) if(A[i] - 2 * r <= A[j] && A[j] <= A[i] + 2 * r) {
			double p = 4 * r * r - (A[i] - A[j]) * (A[i] - A[j]);
			p = sqrt(max(p, 0.0));
			res = max(res, ans[j] + p);
		}
		ans[i] = res;
	}
	for(int i=1;i<=n;i++) printf("%.12f ", ans[i]); puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}