#include <stdio.h>
#include <algorithm>
#include <math.h>

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int a[100],i,n,k,temp;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	for(i=0;i<n/2;i++){
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;
	}
	printf("%d",a[k-1]);
}