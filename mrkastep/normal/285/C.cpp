#include <stdio.h>
#include <algorithm>
#

long long int s;

bool qwe(int i1,int i2){
	if(i1>i2) return true;
	return false;
}

/*int abs(int a){
	if(a<0) return -a;
	else return a;
}*/

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	#pragma comment(linker, "/STACK:268435456")
	int a[300000],n,i;
	s=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	std::sort(a,a+n);
	for(i=0;i<n;i++) s=s+abs(a[i]-i-1);
	printf("%I64d",s);
}