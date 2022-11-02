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
	int a[12],i,k,s;
	scanf("%d",&k);
	for(i=0;i<12;i++){
		scanf("%d",&a[i]);
	}
	s=0;
	std::sort(a,a+12,qwe);
	for(i=0;s<k && i<12;i++){
		s=s+a[i];
	}
	if(s<k) printf("-1");
	else printf("%d",i);
}