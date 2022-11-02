#include <bits/stdc++.h>

int arr[300005],ans=0,p=0;

int main() {
	int n,t;
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		scanf("%d",&arr[i]);
		if (arr[i]!=arr[1]&&!p) p=i; 
	} for (int i=1;i<=n;++i) {
		if (arr[i]==arr[1]) ans=std::max(ans,i-p);
		else ans=std::max(ans,i-1);
	}printf("%d",ans);
	return 0;
}