#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 105
int n,m,i,j,k;
int a[N];
long long res;
int main(){
	scanf("%d",&n);
	rpt(i,1,n) scanf("%d",&a[i]);
	i=1;
	while(a[i]==0&&i<=n) i++;
	if(i>n){
		printf("0");
		return 0;
	}
	res=1;
	while(i<=n){
		j=++i;
		while(a[j]==0&&j<=n) j++;
		if(j>n) break;
		res*=j-i+1;
		i=j;
	}
	printf("%I64d",res);
}