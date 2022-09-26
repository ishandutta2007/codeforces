#include <bits/stdc++.h>
using namespace std;
int n,x[100005],y[100005];
long long ccw(int o,int a,int b){
	return 1LL * (x[a] - x[o]) * (y[b] - y[o]) - 1LL * (x[b] - x[o]) * (y[a] - y[o]);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d %d",&x[i], &y[i]);
	long long area = 0;
	
	for(int i=0;i<n;i++)
		area -= ccw(0, i, (i + 1) % n);
	
	int t; scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&x[n], &y[n]);
		long long narea = 0;
		for(int i = 0;i < n;++i) {
			narea += abs(ccw(n, i, (i + 1) % n));
		}
		if (area != narea){
			printf("0\n");
			continue;
		}
		
		long long res = 0;
		int l = 0, r = 1;
		for(; l < n; ++l) {
			for(;; r = (r + 1) % n)
				if (ccw(l, n, r) <= 0) break;
			res += 1LL * ((r - l - 2 + 2 * n) % n) * ((r - l - 1 + n) % n) / 2;
		}
		printf("%lld\n", 1LL * n * (n - 1) * (n - 2) / 6 - res);
	}
}