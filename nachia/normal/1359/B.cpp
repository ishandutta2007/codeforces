#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
	UL T; scanf("%u", &T);
	while (T--) {
		UL H, W; scanf("%u%u", &H, &W);
		UL X, Y; scanf("%u%u", &X, &Y);
		Y = min(Y, X * 2);
		UL ans = 0;
		rep(y, H) {
			scanf(" ");
			bool buf = false;
			rep(x, W) {
				char c; scanf("%c", &c);
				if (c == '*') { ans += (buf ? X : 0); buf = false; }
				else if (c == '.') {
					if (buf) { ans += Y; buf = false; }
					else { buf = true; }
				}
			}
			ans += (buf ? X : 0);
		}
		printf("%u\n", ans);
	}
	return 0;
}