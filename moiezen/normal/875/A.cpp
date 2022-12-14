#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
int f(int x){
	int s=x;
	while(x){
		s+=x%10;
		x/=10;
	}
	return s;
}
int n,m,a[233];
int main(){
	scanf("%d",&n);m=0;
	rep(i,std::max(1,n-100),n) if(f(i)==n) a[++m]=i;
	printf("%d\n",m);
	rep(i,1,m) printf("%d\n",a[i]);
}