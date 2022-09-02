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

int n, A[510];

ll get(int x){
	for(int i=1;i<=n;i++)if(A[i] < x)return 1e18;
	ll res = 0;
	for(int i=1;i<=n;i++){
		ll low = (A[i] + x) / (x + 1);
		ll high = A[i] / x;
		if(low > high)return 1e18;
		res += low;
	}
	return res;
}

void solve(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d", A+i);
	sort(A+1, A+1+n);
	ll ans = 1e18;
	for(int i=1;i<=A[1] && i<=40000;i++){
		int low = (A[1] - 1) / i;
		int high = (A[1]) / i;
		for(int j=max(1, low);j<=high;j++)ans = min(ans, get(j));
	}
	for(int i=1;i<=40000;i++)ans = min(ans, get(i));
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