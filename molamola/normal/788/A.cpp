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
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;
typedef long double ldouble;

int N, A[100010], B[100010];

void solve(){
	scanf("%d", &N);
	for(int i=1;i<=N;i++)scanf("%d", A+i);
	for(int i=1;i<N;i++)B[i] = abs(A[i] - A[i+1]);
	ll mx1 = -1e18, mx2 = -1e18;
	ll ans = -1e18;
	for(int i=N-1, t = 1;i;i--){
		mx1 = max(mx1 + t * B[i], (ll)t * B[i]);
		mx2 = max(mx2 - t * B[i], (ll)-t * B[i]);
		if(t == 1){
			ans = max(ans, mx1);
		}
		else{
			ans = max(ans, mx2);
		}
		t = -t;
	}
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}