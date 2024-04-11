#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

vector<UL> Divs(UL a, UL p = 2) {
	if (a == 1) return { 1 };
	for (; a % p != 0; p++) if (p * p > a) return { 1, a };
	UL n = 1;
	for (; a % p == 0; n++) a /= p;
	vector<UL> buf = Divs(a, p + 1 | 1);
	UL i = buf.size(), l = buf.size();
	buf.resize(i * n);
	for (; i < buf.size(); i++) buf[i] = buf[i - l] * p;
	return buf;
}

int main() {
	UL T; scanf("%u", &T);
	while (T--) {
	    UL N, K;
		scanf("%u%u", &N, &K);
		auto D = Divs(N);
		sort(D.begin(), D.end());
		UL ans = 0;
		rep(i, D.size()) if (D[i] <= K) ans = i;
		printf("%u\n", N / D[ans]);
	}
	return 0;
}