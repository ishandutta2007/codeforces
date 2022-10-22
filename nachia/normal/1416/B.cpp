#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
LL A[100000];

void loop() {
	scanf("%d", &N);
	rep(i, N) scanf("%lld", &A[i]);

	LL S = 0; rep(i, N) S += A[i];
	if (S % N != 0) { printf("-1\n"); return; }

	printf("%d\n", (N - 1) * 3);

	for (int i = 2; i <= N; i++) {
		int x = i - (A[i - 1] - 1) % i - 1;
		printf("1 %d %d\n", i, x); A[0] -= x; A[i - 1] += x;
		x = A[i - 1] / i;
		printf("%d 1 %d\n", i, x); A[0] += i; A[i - 1] -= x * i;
	}

	for (int i = 2; i <= N; i++) {
		printf("1 %d %d\n", i, S / N);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) loop();
	return 0;
}