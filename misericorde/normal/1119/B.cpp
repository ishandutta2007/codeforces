#include <bits/stdc++.h>

int n,h,arr[1005],arr2[1005]={0};

int check(int k) {
	for (int i=1;i<=n;++i) arr2[i]=arr[i];
	int p,sum=0;
	std::sort(arr2+1,arr2+k+1);
	for (int i=1;i<=k;i+=2) {
		int p=std::max(arr2[i],arr2[i+1]);
		sum+=p; if (sum>h) return 0;
	}return 1;
}

int check2(int k) {
	for (int i=1;i<=n;++i) arr2[i]=arr[i];
	int p,sum=0;
	std::sort(arr2+1,arr2+k+1);
	for (int i=1;i<=k+1;i+=2) {
		int p=std::max(arr2[i],arr2[i-1]);
		sum+=p; if (sum>h) return 0;
	}return 1;
}

int main() {
	scanf("%d%d",&n,&h);
	for (int i=1;i<=n;++i) {
		scanf("%d",&arr[i]);
	}int l=1,r=n,ans;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (check(mid)||check2(mid)) {ans=mid;l=mid+1;}
		else r=mid-1;
	}printf("%d",ans);
	return 0;
}