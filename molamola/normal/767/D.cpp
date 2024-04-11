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

int n, m, k;
int A[1000010];
pii B[1000010];
int C[2000010];

void solve(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=n;i++) scanf("%d", A+i);
	sort(A+1, A+1+n);
	for(int i=1;i<=m;i++) {
		int x; scanf("%d", &x);
		B[i] = pii(x, i);
	}
	sort(B+1, B+1+m);
	vector <int> ans;
	int low = 0, high = m, res = -1;
	while(low <= high) {
		int mid = (low + high) >> 1;
		int z = 0, j = mid + 1;
		for(int i=1;i<=n;i++) {
			while(j <= m && B[j].Fi < A[i]) C[z++] = B[j++].Fi;
			C[z++] = A[i];
		}
		while(j <= m) C[z++] = B[j++].Fi;
		int ok = 0;
		for(int i=0;i<z;i++) {
			if(i / k > C[i]) ok = 1;
		}
		if(ok) low = mid + 1;
		else res = mid, high = mid - 1;
	}
	if(res == -1) {
		puts("-1");
		return;
	}
	for(int i=res+1;i<=m;i++) ans.pb(B[i].Se);
	printf("%d\n", sz(ans));
	for(int e : ans) printf("%d ", e); puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d\n", tc);
		solve();
	}
	return 0;
};