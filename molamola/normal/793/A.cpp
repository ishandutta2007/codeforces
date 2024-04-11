#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
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
typedef pair<ll, ll> PL;
typedef long double ldouble;

int n, a[100010], k;

void solve(){
	scanf("%d", &n);scanf("%d", &k);
	rep(i, n)scanf("%d", a+i);
	for(int i=1;i<n;i++){
		if(a[i] % k != a[0] % k){
			puts("-1");
			return;
		}
	}
	sort(a, a+n);
	ll ans = 0;
	for(int i=1;i<n;i++){
		ans += (a[i] - a[0]) / k;
	}
	printf("%lld\n", ans);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}