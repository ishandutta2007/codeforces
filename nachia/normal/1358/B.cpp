#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
    UL A[100000];

	UL T; scanf("%u", &T);
	while (T--) {
		UL N; scanf("%u", &N);
		rep(i, N) scanf("%u", &A[i]);
		sort(A, A + N);
		UL ans = 0;
	for (UL i = N - 1; i != ~0u; i--) {
			if (A[i] <= i + 1) { ans = i + 1; break; }
		}
		printf("%u\n", ans + 1);
	}
	return 0;
}