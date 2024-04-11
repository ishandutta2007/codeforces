#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

UL M, N;
vector<ULL> X;
ULL K;

UL XNum(ULL uBound) {
	UL l, r; l = 0; r = X.size() + 1;
	while (l + 1 < r) {
		UL m = (l + r) >> 1;
		if (X[m - 1] <= uBound) l = m;
		else r = m;
	}
	return l;
}

int main() {
	UL T; scanf("%u", &T);
	while (T--) {
		scanf("%u%u", &N, &M);
		K = (1ull << M) - N;
		X.clear();
		rep(i, N) {
			scanf(" ");
			ULL tmp = 0;
			rep(j, M) {
				char c; scanf("%c", &c);
				if (c == '1') tmp |= (1ull << (M - 1 - j));
			}
			X.push_back(tmp);
		}
		sort(X.begin(), X.end());
		ULL l, r; l = 0; r = (1ull << M);
		while (l + 1 < r) {
			ULL m = (l + r) >> 1;
			ULL t = (m - 1) - XNum(m - 1) + 1;
			if (t < (K - 1) / 2 + 1) l = m;
			else r = m;
		}
		rep(j, M) {
			printf("%c", '0' + ((l & 1ull << (M - 1 - j)) >> (M - 1 - j)));
		} printf("\n");
	}
	return 0;
}