#include <stdio.h>
#include <algorithm>

bool qwe(int i1,int i2){
	if(i1>i2) return true;
	return false;
}

int main(){	
	#pragma comment(linker, "/STACK:268435456")
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int a[100],n,i,tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	tmp=a[0];
	a[0]=a[n-1];
	a[n-1]=tmp;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}