#include<bits/stdc++.h>
using namespace std;
int n,m,ta,tb,k;
int a[300000];
int b[300000];
int main() {
	scanf("%d %d %d %d %d",&n,&m,&ta,&tb,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<m;i++) scanf("%d",&b[i]);
	if(k>=n || k>=m) {
		printf("-1");
		return 0;
	}
	int l=k;
	int r=0;
	int ans=2000000000;
	for(r=m;r>=0;r--) {
		if(r==0 || a[l]+ta>b[r-1]) break;
	}
	ans=b[r]+tb;
	if(r==m) {
		printf("-1");
		return 0;
	}
	for(int i=1;i<=k;i++) {
		l--;
		while(true) {
			if(r==0 || a[l]+ta>b[r-1]) break;
			r--;
		}
		ans=max(ans,b[r+i]+tb);
		if(r+i==m) {
			printf("-1");
			return 0;
		}	
	}
	printf("%d",ans);
	return 0;
}