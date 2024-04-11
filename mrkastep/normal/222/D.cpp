#include <stdio.h>
#include <algorithm>

int a[100000],b[100000],n,x,y;

bool qwe(int i1,int i2){
	if(i1>i2) return true;
	return false;
}

bool chk(int c){
	for(;y>-1;y--){
		if(a[c]+b[y]>=x && b[y]!=-1){
			return true;
		}
	}
	return false;
}

int main(){	
	#pragma comment(linker, "/STACK:268435456")
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int i,j,t;
	scanf("%d%d",&n,&x);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++) scanf("%d",&b[i]);
	std::sort(a,a+n,qwe);
	std::sort(b,b+n,qwe);
	y=n-1;
	for(i=0;chk(i) && i<n;i++){
		b[y]=-1;
	}
	printf("1 %d",i);
}