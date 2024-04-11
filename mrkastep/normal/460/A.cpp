#include <stdio.h>
#include <algorithm>
#include <string.h>

int day(int a,int b){
	if(a<b) return a;
	else return day(a-b+1,b)+b;
}


int main(){
	#pragma comment(linker, "/STACK:268435456")
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d",day(n,m));
}