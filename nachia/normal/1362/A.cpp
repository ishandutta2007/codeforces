#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
	UL T; scanf("%u", &T);
	while (T--) {
		ULL a, b; scanf("%llu%llu", &a, &b);
		if (a > b) swap(a, b);
		if (b % a) { printf("-1\n"); continue; }
		b /= a;
		if(b & (b - 1)) { printf("-1\n"); continue; }
		ULL L = 0;
		rep(i, 61) if (b == (1ull << i)) L = i;
		printf("%llu\n", (L + 2) / 3);
	}
    return 0;
}