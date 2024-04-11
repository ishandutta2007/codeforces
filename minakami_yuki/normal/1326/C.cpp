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
int n,K;
int a[N],b[N];
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	int v=n;
	LL x=0,y=1,z;
	for(int j=1;j<=K;--v,++j) x=x+(LL)v;
	int l=0;
	for(int i=1;i<=n;++i){
		if(b[i]<=v) continue;
		if(l>0){
			z=i-l;
			y=y*z%P;
		}
		l=i;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}