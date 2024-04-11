#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

ULL m, M;
ULL t;
ULL ans;

pair<ULL, ULL> F(ULL x) {
	LL a = m * (x - 1) + M * x;
	a -= (LL)(t * (2 * x - 1));
	return { abs(a), 2 * x - 1 };
}

int main() {
	UL T; scanf("%u", &T);
	while (T--) {
		scanf("%llu%llu", &M, &m);
		scanf("%llu", &t);
		if (m + M >= t + t) { printf("2\n"); continue; }
		ULL l, r; l = 0; r = 1000001;
		while (l + 2 < r) {
			ULL m1 = (l + l + r) / 3;
			ULL m2 = (l + r + r) / 3;
			auto f1 = F(m1);
			auto f2 = F(m2);
			if (f1.first * f2.second <= f1.second * f2.first) r = m2;
			else l = m1;
		}
		printf("%llu\n", (l + 1) * 2 - 1);
	}
	return 0;
}