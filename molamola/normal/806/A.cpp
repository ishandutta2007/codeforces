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

using namespace std;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int, int> t4;
typedef long double ldouble;

void solve(){
	int x, y, p, q; scanf("%d%d%d%d", &x, &y, &p, &q);
	if(p == q){
		if(x != y) puts("-1");
		else puts("0");
	}
	else if(p == 0){
		if(x != 0) puts("-1");
		else puts("0");
	}
	else{
		int t = max((x+p-1) / p, (y-x+q-p-1) / (q-p));
		printf("%lld\n", (ll)t * q - y);
	}
}

int main(){
	int Tc = 1; scanf("%d", &Tc);
	for(int tc=1; tc<=Tc; tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}