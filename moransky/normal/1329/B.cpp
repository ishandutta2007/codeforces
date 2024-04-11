#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int S = 31;

int d, P, f[S];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		memset(f, 0, sizeof f);
		scanf("%d%d", &d, &P);
		for (int i = 0; i < S; i++) {
			if ((1 << i) > d) continue;
			int c = min((LL)d, (1ll << (i + 1)) - 1) - (1 << i) + 1;
			f[i] = c;
		}
		for (int i = 0; i < S; i++) {
			if (f[i] == 0) continue;
			for (int j = i + 1; j < S; j++) {
				if ((1 << j) > d) continue;
				int c = min((LL)d, (1ll << (j + 1)) - 1) - (1 << j) + 1;
				f[j] = (f[j] + (LL)c * f[i]) % P;
			}
		}
		int ans = 0;
		for (int i = 0; i < S; i++) (ans += f[i]) %= P;
		printf("%d\n", ans); 
	}
	return 0;
}