#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
int cnt[N], n, x, xcnt[N], a[N];
int main() {
	scanf("%d%d", &n, &x);
	int mn = 3;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
		xcnt[a[i] & x]++;
	}
	for(int i = 0; i < (1 << 20); i++) {
		if(cnt[i] >= 2) mn = 0;
		if(cnt[i] >= 1 && cnt[i & x] && ((i & x) != i)) mn = min(mn, 1);
		if(xcnt[i] >= 2) mn = min(mn, 2);
	}
	printf("%d\n", mn == 3 ? -1 : mn);
	return 0;
}