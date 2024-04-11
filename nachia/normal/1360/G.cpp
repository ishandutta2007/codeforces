#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
	UL T; scanf("%u", &T);
	while (T--) {
		UL H, W, X, Y;
		scanf("%u%u%u%u", &H, &W, &X, &Y);
		if (H * X != W * Y) { printf("NO\n"); continue; }
		char ans[51][51] = {};
		rep(y, H) rep(x, W) ans[y][x] = '0';
		rep(y, H) {
			rep(x, X) {
				ans[y][(X * y + x) % W] = '1';
			}
		}
		printf("YES\n");
		rep(y, H) printf("%s\n", ans[y]);
	}
	return 0;
}