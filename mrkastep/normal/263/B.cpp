#include <stdio.h>
#include <algorithm>

bool qwe(int i1,int i2){
	if(i1>i2) return true;
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int i,k,n,a[50];
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	std::sort(a,a+n,qwe);
	if(k>n) printf("%d",-1);
	else printf("%d %d",a[k-1],a[k-1]);
}