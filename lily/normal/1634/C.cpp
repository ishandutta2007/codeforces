#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


int n, K;
void check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < K; j++) {
			int sum = 0;
			for (int k = j + 1; k <= K; k++) {
				sum += 1 + i + (k - 1) * n;
				int len = k - j;
				if (sum % len != 0) {
					puts("NO");
					return;
				}
			}
		}
	}
	puts("YES");
	for (int i = 0; i < n; i++) {
		for (int k = 1; k <= K; k++) {
			printf("%d ", 1 + i + (k - 1) * n);
		}
		puts("");
	}
}

int main() {
	int T;
	read(T);
	while (T--) {
		read(n); read(K);
		check();
	}

}