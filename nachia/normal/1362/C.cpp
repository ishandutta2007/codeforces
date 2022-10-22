#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
	ULL N;
	UL T; scanf("%u", &T);
	while (T--) {
		scanf("%llu", &N);
		ULL ans = 0;
		rep(i, 70) { ans += N; N >>= 1; }
		printf("%llu\n", ans);
	}
	return 0;
}