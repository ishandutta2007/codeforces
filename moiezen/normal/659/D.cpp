#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 100005
int n,i,j,k;
int x[N],y[N],dir[N];
int bo;
int ans;
int main(){
	scanf("%d",&n);
	rpt(i,1,n+1) scanf("%d%d",&x[i],&y[i]);
	rpt(i,1,n){
		if(x[i+1]>x[i]) dir[i]=0;
		if(y[i+1]>y[i]) dir[i]=1;
		if(x[i+1]<x[i]) dir[i]=2;
		if(y[i+1]<y[i]) dir[i]=3;
	}
	bo=dir[n+1]=dir[1];
	ans=0;
	rpt(i,1,n){
		if(bo==0){
			if(dir[i]==(dir[i+1]+1)%4) ans++;
		}
		else{
			if((dir[i]+1)%4==dir[i+1]) ans++;
		}
	}
	printf("%d",ans);
}