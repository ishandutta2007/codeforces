#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
	UL T; scanf("%u", &T);
	while (T--) {
		UL N, M, K; scanf("%u%u%u", &N, &M, &K);
		UL ans = 0;
		if (M < N / K) ans = M;
		else {
			ans += N / K;
			M -= N / K;
			N -= N / K;
			K--;
			M = (M + K - 1) / K;
			ans -= M;
		}
		printf("%u\n", ans);
	}
	return 0;
}