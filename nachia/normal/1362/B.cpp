#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

UL N;
bool S[1024];
UL V[1024];

int main() {
	UL T; scanf("%u", &T);
	while (T--) {
		rep(i, 1024) S[i] = false;
		scanf("%u", &N);
		rep(i, N) {
			UL v; scanf("%u", &v);
			V[i] = v;
			S[v ^ V[0]] = true;
		}
		UL ans = 0;
		for (UL i = 1; i < 1024; i++) {
			if (!S[i]) continue;
			bool ok = true;
			rep(j, 1024) if (S[j] && !S[j ^ i])  ok = false;
			if (ok) { ans = i; break; }
		}
		if (ans == 0) printf("-1\n");
		else printf("%u\n", ans);
	}
	return 0;
}