#include <stdio.h>
#include <algorithm>

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int n,i,j,t[100],t1[100],a[100],m;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) t1[i]=false;
	for(i=0;i<n;i++){
		scanf("%d",&t[i]);
		t1[i]=t[i];
	}
	std::sort(t1,t1+n);
	for(i=0;i<n;i++){
		a[t1[i]]=i%2;
	}
	for(i=0;i<n;i++){
		printf("%d ",a[t[i]]);
	}
}