#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)


const ULL M = 998244353;
const ULL Z = 1000000;

ULL F[Z + 1];
ULL I[Z + 1];
ULL iF[Z + 1];

ULL C(UL n, UL r) {
	if (n < r) return 0;
	return F[n] * iF[r] % M * iF[n - r] % M;
}

int main() {
	UL N, K; scanf("%u%u", &N, &K);
	F[0] = 1;
	I[1] = 1;
	iF[0] = 1;
	for (UL i = 1; i <= Z; i++) F[i] = F[i - 1] * i % M;
	for (UL i = 2; i <= Z; i++) I[i] = M - M / i * I[M % i] % M;
	for (UL i = 1; i <= Z; i++) iF[i] = iF[i - 1] * I[i] % M;
	ULL ans = 0;
	for (UL i = 1; i <= N; i++) {
		UL x = N / i - 1;
		ans += C(x, K - 1);
	}
	ans %= M;
	printf("%lld\n", ans);
	return 0;
}