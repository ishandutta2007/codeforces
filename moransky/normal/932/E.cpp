#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const int L = 5005, P = 1e9 + 7;

int n, K, S[L][L];

int inline power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}

int main() {
	scanf("%d%d", &n, &K);
	S[0][0] = 1;
	for (int i = 1; i <= K; i++) 
		for (int j = 1; j <= i; j++)
			S[i][j] = (S[i - 1][j - 1] + (LL)j * S[i - 1][j]) % P;
	int fact = 1, c = 1, ans = 0;
	for (int j = 1; j <= min(n, K); j++) {
		fact = (LL)fact * j % P;
		c = (LL)c * (n - j + 1) % P * power(j, P - 2) % P;
		ans = (ans + (LL)S[K][j] * fact % P * c % P * power(2, n - j)) % P;
	}
	printf("%d\n", ans);
	return 0;
}