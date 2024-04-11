#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200000 + 10;

LL a[N], b[N], s[N];
int n, m;

int main() {
	// second
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	LL tmp = 0;
	for(int i = 1; i <= m; i++) {
		scanf("%lld", &b[i]);
		tmp += b[i];
		if(tmp >= s[n]) {
			tmp = 0;
			printf("%d\n", n);
			continue;
		}
		int l = 0, r = n - 1;
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			if(s[mid] <= tmp) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", n - l);
	}
	return 0;
}