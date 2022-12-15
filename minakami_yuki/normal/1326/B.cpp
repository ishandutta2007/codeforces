#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring> 
#include<cmath> 
#define LL long long
using namespace std;
const int N=1e6+10;
const LL P=998244353;

LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
int n;
int a[N],b[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	int x=0;
	for(int i=1;i<=n;++i){
		a[i]=b[i]+x;
		x=max(x,a[i]);
		printf("%d ",a[i]);
	}
	cout<<endl;
	return 0;
}