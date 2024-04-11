#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 1005
int n,m,i,j,k,ans;
int s[N];
void input(){
	scanf("%d",&n);
}
void init(){
	memset(s,0,sizeof(s));
	rpt(i,1,n) scanf("%d",&k),s[k]++;
}
void work(){
	k=0;
	rpt(i,1,1000){
		if(s[i]>k) k=s[i];
	}
	ans=n-k;
}
void output(){
	printf("%d",ans);
	
}
int main(){
	input();
	init();
	work();
	output();
}