#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 100005
#define M 500005
int n,i,j,k,lim;
int a[N];
long long ans;
void input(){
	scanf("%d",&n);
	rpt(i,1,n) scanf("%d",&a[i]);
}
void init(){
	rpt(i,1,n-1) rpt(j,i+1,n) if(a[i]<a[j]){
		k=a[i];
		a[i]=a[j];
		a[j]=k;
	}
	lim=1<<30;
	ans=0;
}
void work(){
	rpt(i,1,n){
		if(a[i]<lim) lim=a[i];
		if(lim<0) lim=0;
		ans+=lim;
		lim--;
	}
}
void output(){
	printf("%I64d",ans);
}
int main(){
	input();
	init();
	work();
	output();
	return 0;
}