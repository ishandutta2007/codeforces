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

int n, u;
int E[100010];

void solve() {
	scanf("%d%d", &n, &u);
	for(int i=1;i<=n;i++) scanf("%d", E+i);
	double ans = -1;
	for(int i=1, j=1;i<=n;i++) {
		while(j <= n && E[j] - E[i] <= u) ++j;
		if(j - i > 2) {
			ans = max(ans, (double)(E[j-1] - E[i+1]) / (E[j-1] - E[i]));
		}
	}
	if(ans < 0) puts("-1");
	else printf("%.12f\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}