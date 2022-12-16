#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 110;
int a[maxn],T,n,l,r,k,ans;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d", &n, &l, &r, &k);
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n && k >= a[i]; ++i) {
			if(a[i] < l || a[i] > r) continue;
			k -= a[i], ans++;
		}
		printf("%d\n", ans);
		ans = 0;
	}
	return 0;
}