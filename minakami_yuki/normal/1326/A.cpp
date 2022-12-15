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
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1) cout<<-1<<endl;
		else {
			cout<<2;
			for(int i=2;i<=n;++i) printf("%d",3);
			cout<<endl;
		}
	}
	return 0;
}