#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 100005
int n,d,h,m,i,j,k;
int main(){
	scanf("%d%d%d",&n,&d,&h);
	if(d<2&&n>2){
		printf("-1");
		return 0;
	}
	if(d>h*2){
		printf("-1");
		return 0;
	}
	rpt(i,1,h) printf("%d %d\n",i,i+1);
	rpt(i,1,d-h) printf("%d %d\n",i==1?1:h+i,1+h+i);
	rpt(i,1,n-1-d) printf("%d %d\n",1+h-1,1+d+i);
}