#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 200000 + 10;

LL a[N], b[N], s[N];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]); 
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 1; i <= m; i++) {
		scanf("%lld", &b[i]);
		int l = 0, r = n;
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			if(s[mid] < b[i]) l = mid;
			else r = mid - 1;
		}
		printf("%d %lld\n", l + 1, b[i] - s[l]);
	}
	return 0;
}