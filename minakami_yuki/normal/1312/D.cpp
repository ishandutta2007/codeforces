#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1000;
const LL P=998244353;
int n,m;
LL K;
LL a[N];
LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
bool jud(){
	for(int i=1;i<=n;++i) if(a[i]) return 1;
	return 0;
}
int main(){
	cin>>n>>m;
	if(n==2){
		cout<<0<<endl;
		return 0;
	}
	LL ans=n-2;
	for(int i=1;i<=n-3;++i) ans=(ans+ans)%P;
	for(LL i=1;i<=m;++i) ans=ans*i%P;
	for(int i=1;i<=n-1;++i) ans=ans*qpow(i,P-2)%P;
	for(int i=1;i<=m-n+1;++i) ans=ans*qpow(i,P-2)%P;
	cout<<ans<<endl;
	return 0;
}