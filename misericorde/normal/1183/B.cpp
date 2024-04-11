#include <bits/stdc++.h>
int q,n,k,arr[100005];
int main() {
	int q;scanf("%d",&q);
	while (q--) {
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;++i) {
			scanf("%d",&arr[i]);
		}std::sort(arr+1,arr+n+1);
		if (std::abs(arr[n]-(arr[1]+k))>k) {printf("-1\n");continue;}
		else printf("%d\n",arr[1]+k);
	}
	return 0;
}