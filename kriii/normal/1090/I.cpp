#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 20000005;

int n;
lint a[MAXN];

void solve(){
	lint ret = 6e18;
	lint curmax = 1e10;
	for(int i=1; i<=n; i++){
		if(a[i] >= 0){
			if(curmax < a[i]){
				ret = min(ret, a[i] * curmax);
			}
		}
		curmax = min(curmax, a[i]);
	}
	curmax = -1e10;
	for(int i=n; i; i--){
		if(a[i] < 0){
			if(curmax > a[i]){
				ret = min(ret, a[i] * curmax);
			}
		}
		curmax = max(curmax, a[i]);
	}
	if(ret > 5e18){
		puts("IMPOSSIBLE");
		return;
	}
	cout << ret << endl;
}

int main(){
	int tc; scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		lint l, r, x, y, z;
		scanf("%lld %lld %lld %lld %lld %lld %lld",&l,&r,&x,&y,&z,&a[1],&a[2]);
		for(int i=3; i<=n; i++){
			a[i] = a[i-2] * x + a[i-1] * y + z;
			a[i] &= ((1ll << 32) - 1ll);
		}
		for(int i=1; i<=n; i++){
			a[i] %= (r - l + 1);
			a[i] += l;
		}
		solve();
	}
}