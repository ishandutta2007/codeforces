#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 55
int p[N],t[N];
int n,c,i,j,k,a,b;
int main(){
	scanf("%d%d",&n,&c);
	rpt(i,1,n) scanf("%d",&p[i]);
	rpt(i,1,n) scanf("%d",&t[i]);
	a=k=0;
	rpt(i,1,n){
		k+=t[i];
		if(p[i]-k*c>0) a+=p[i]-k*c;
	}
	b=k=0;
	rpd(i,n,1){
		k+=t[i];
		if(p[i]-k*c>0) b+=p[i]-k*c;
	}
	if(a>b) printf("Limak");
	else if(a<b) printf("Radewoosh");
	else printf("Tie");
}