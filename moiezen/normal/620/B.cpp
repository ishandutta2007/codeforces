#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 100005
int v[10]={6,2,5,5,4,5,6,3,7,6};
int a,b,i,res;
int cnt(int x){
	int ans=0;
	while(x) ans+=v[x%10],x/=10;
	return ans;
}
int main(){
	scanf("%d%d",&a,&b);
	res=0;
	rpt(i,a,b) res+=cnt(i);
	printf("%d",res);
}