#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 105;
int n, k1, k2, cnt[N];
int main() {	
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &k1, &k2);
		for (int i = 1; i <= n; i++) cnt[i] = 1;
		for (int i = 1, x; i <= k1; i++)
			scanf("%d", &x);
		for (int i = 1, x; i <= k2; i++) scanf("%d", &x), cnt[x] = 0;
		puts(cnt[n] ? "Yes" : "No");
	}
	return 0;
	
}