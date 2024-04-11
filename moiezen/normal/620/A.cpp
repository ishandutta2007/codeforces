#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 100005
int a,b,c,d;
int abs(int x){
	if(x>0) return x; else return -x;
}
int max(int x,int y){
	if(x>y) return x; else return y;
}
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d",max(abs(a-c),abs(b-d)));
}