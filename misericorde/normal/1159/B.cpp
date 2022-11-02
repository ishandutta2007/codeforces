#include <bits/stdc++.h>
#define ll long long
int n,arr[300005];

int check(int k) {
	for (int i=1;i<=n;++i) {
		if ((ll)k*(ll)std::max(i-1,n-i)>(ll)arr[i]) return 0;
	}return 1;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&arr[i]);
	int l=0,r=1e9+2,ans;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (check(mid)) {ans=mid;l=mid+1;}
		else r=mid-1;
	}printf("%d",ans);
	return 0;
}