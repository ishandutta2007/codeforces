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
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;



int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int k; scanf("%d", &k);
		int a[7]; rep(i, 7) scanf("%d", a+i);
		ll ans = 1e18;
		rep(i, 7) {
			rotate(a, a+1, a+7);
			int s = 0;
			rep(i, 7) s += a[i];
			ll C = (k - 1) / s * 7;
			int nk = k - (k - 1) / s * s;
			for(int q=0;q<7;q++) {
				if(a[q]) --nk;
				if(nk == 0) {
					C += q + 1;
					break;
				}
			}
			if(ans > C) ans = C;
		}
		printf("%lld\n", ans);
	}
	return 0;
}