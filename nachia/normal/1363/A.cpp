#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

UL N, X;
UL A[1000];

int main() {
	UL T; scanf("%u", &T);
	while (T--) {
		scanf("%u%u", &N, &X);
		rep(i, N) scanf("%u", A + i);
		UL cO, cE; cO = cE = 0;
		rep(i, N) {
			if (A[i] & 1) cO++; else cE++;
		}
		if (cO == 0) { printf("No\n"); continue; }
		if (N == X && (cO & 1) == 0) { printf("No\n"); continue; }
		if (cE == 0 && (X & 1) == 0) { printf("No\n"); continue; }
		printf("Yes\n");
	}
	return 0;
}