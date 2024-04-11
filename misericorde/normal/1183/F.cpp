#include <bits/stdc++.h>
int n,q,arr[200005],now=0,ans=0;
//ouuantxdy
int main() {
	scanf("%d",&q);
	while (q--) {
		scanf("%d",&n);
		for (int i=1;i<=n;++i) {
			scanf("%d",&arr[i]);
		}std::sort(arr+1,arr+n+1);
		n=std::unique(arr+1,arr+n+1)-(arr+1);
		ans=0;
		for (register int i=n;i>=1;i--) {
			int now=arr[i];
			if (arr[i]*3<ans) break;
			for (register int j=i-1;j>=1;--j) {
				if (arr[i]%arr[j]==0) continue;
				now+=arr[j];
				for (register int k=j-1;k>=1;--k) {
					if (arr[i]%arr[k]==0||arr[j]%arr[k]==0) continue;
					now+=arr[k];
					break;
				}break;
			}ans=std::max(ans,now);
		}printf("%d\n",ans);
	}
	return 0;
}