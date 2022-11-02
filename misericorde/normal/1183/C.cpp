#include <bits/stdc++.h>
int q,k,a,b,n;
int main() {
	scanf("%d",&q);
	while (q--) {
		scanf("%d%d%d%d",&k,&n,&a,&b);
		int l=0,r=n,mid,ans=-1;
		while (l<=r) {
			mid=(l+r)>>1;
		//	printf("%d %d\n",mid,(k-(a*mid))/b+mid<n);
			if ((long long)a*mid>=k||(k-(a*mid)-1)/b+mid<n) {r=mid-1;}
			else {ans=mid;l=mid+1;}
		}printf("%d\n",ans);
	}
	return 0;
}