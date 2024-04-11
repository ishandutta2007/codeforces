#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

UL N;
char G[51][51];

int main() {
	UL T; scanf("%u", &T);
	while (T--) {
		scanf("%u", &N);
		rep(y, N) {
			scanf(" ");
			rep(x, N) scanf("%c", &G[x][y]);
		}
		rep(i, N) G[N][i] = G[i][N] = '1';
		bool ng = false;
		rep(y, N) rep(x, N) {
			if (G[x][y] == '1') {
				if (G[x + 1][y] != '1' && G[x][y + 1] != '1')
					ng = true;
			}
		}
		printf(ng ? "NO\n" : "YES\n");
	}
	return 0;
}