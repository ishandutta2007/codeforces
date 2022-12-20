#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef double db;
using namespace std;

ll s,n,k,t;

int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld%lld%lld", &s, &n, &k);
		if(s < k) printf("NO\n");
		if(s == k) printf("YES\n");
		if(s > k) {
			ll cnta = s - (s / k) * k + 1, cntb = k - cnta, cnt;
			if((s / k) % 2) cnt = s + k - cnta;
			else cnt = s + k - cntb;
			if(2 * n + 1 > cnt) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}