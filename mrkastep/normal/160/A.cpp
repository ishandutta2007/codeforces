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
	int a[100],n,i,s,t;
	scanf("%d",&n);
	s=0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		s=s+a[i];
	}
	std::sort(a,a+n,qwe);
	t=0;
	for(i=0;t<=s-t;i++) t=t+a[i];
	printf("%d",i);
}