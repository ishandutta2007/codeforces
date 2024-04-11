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
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int n, k, A[300030];
int pre[300030];
int d[300030], nd[300030], res;

void solve() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) scanf("%d", A+i);
	sort(A+1, A+1+n);
	int low = 0, high = *max_element(A+1, A+1+n);
	while(low <= high) {
		int mid = (low + high) >> 1;
		for(int i=1, j=1;i<=n;i++) {
			while(A[i] - A[j] > mid) ++j;
			pre[i] = j;
		}
		d[0] = nd[0] = 1;
		for(int i=1;i<=n;i++) {
			int r = i - k, l = pre[i] - 1;
			if(l <= r && (nd[r] - (l?nd[l-1]:0)) > 0) d[i] = 1;
			else d[i] = 0;
			nd[i] = nd[i-1] + d[i];
		}
		if(d[n]) res = mid, high = mid - 1;
		else low = mid + 1;
	}
	printf("%d\n", res);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}