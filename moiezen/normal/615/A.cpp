#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 105
int n,m,i,j,k,t,flag;
int a[N]={0};
int main(){
	scanf("%d%d",&m,&n);
	rpt(i,1,m){
		scanf("%d",&k);
		while(k--){
			scanf("%d",&t);
			a[t]=1;
		}
	}
	flag=0;
	rpt(i,1,n) if(a[i]==0){
		flag=1;
		break;
	}
	if(flag==0) printf("Yes\n");
	else printf("No\n");
}