#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
#include<time.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int maxn = 1e5 + 500;
ll n, h;
bool ok(ll x) {
	if (x <= h)
		return x *(x + 1) >= 2*n ? true : false;
	else {
		ll t = x - h;
		if (t % 2)
			return (1 + h + t / 2)*(h + t / 2) + (h + h + t / 2)*(t / 2 + 1) >= 2 * n ? true : false;
		else
			return (1 + h + t / 2)*(h + t / 2) + (h + h + t / 2 - 1)*t / 2 >= 2 * n ? true : false;
	}
}
int main() {
	while (~scanf("%lld%lld", &n, &h)) {
		ll l = 1,r = 2*inf;
		while (l<=r-1){
			ll mid = (l + r) >> 1;
			if (ok(mid))
				r = mid;
			else
				l = mid+1;
		}
		cout << l << endl;
	}
	return 0;
}