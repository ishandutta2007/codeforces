#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

lld N, H;

int main()
{
	cin >> N >> H;
	lld s = 1, e = 2e9, t;
	while (s <= e){
		lld m = s+e >> 1;
		if (m*(m+1) < N+N) s = m+1;
		else e = m-1, t = m;
	}
	if (t <= H) printf("%lld\n", t);
	else{
		N -= H*(H-1)/2;
		lld ans = H-1;
		lld s = 1, e = 2e9, t;
		while (s <= e){
			lld m = s+e >> 1;
			lld k = m+1 >> 1;
			lld v = (H+H+k-1) * k;
			if (m&1) v -= H+k-1;
			if (v < N) s = m+1;
			else e = m-1, t = m;
		}
		printf("%lld\n", ans + t);
	}
}