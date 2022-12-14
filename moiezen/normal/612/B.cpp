#include<cstdio>
#include<iostream>
#include<cstring>
int a[200005];
int n,i,j,k;
long long s;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		a[k]=i;
	}
	s=0;
	for(i=1;i<n;i++){
		if(a[i]<a[i+1]) s+=a[i+1]-a[i];
		else s+=a[i]-a[i+1];
	}
	printf("%I64d",s);
}