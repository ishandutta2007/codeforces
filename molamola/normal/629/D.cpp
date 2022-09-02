#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <time.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

int n;
typedef pair<ll, int> PL;
PL p[100010];
ll T[100010];

int main(){
	scanf("%d", &n);
	rep(i, n){
		int x, y;
		scanf("%d%d", &x, &y);
		p[i] = PL((ll)x * x * y, -i);
	}
	sort(p, p+n);
	ll ans = 0;
	rep(i, n){
		int w = -p[i].Se + 1;
		ll mx = 0;
		for(int i=w;i;i-=(i&-i))mx = max(mx, T[i]);
		mx += p[i].Fi;
		ans = max(ans, mx);
		for(int i=w;i<=n;i+=(i&-i))T[i] = max(T[i], mx);
	}
	printf("%.15f\n", ans * 3.141592653589793238);
	return 0;
}