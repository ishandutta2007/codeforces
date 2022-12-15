#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int P=998244353;
LL qpow(LL x,LL y){
	LL mod=P,re=1;
	while(y){
		if(y&1) re=re*x%mod;
		x=x*x%mod;y>>=1;
	}
	return re;
}
int n,k,l;
void add(int &x,int y){
	x+=y;if(x>=P)x-=P;
}
int f[4050][4050];
int jc[4050];
int main(){
	scanf("%d%d%d",&n,&k,&l);
	f[0][0]=1;
	int v;
	for(int i=0;i<=n*2;++i){
		for(int j=0;j<=i;++j){
			add(f[i+1][j+1],f[i][j]);
			if(j){
				v=(LL)f[i][j]*(LL)j%(LL)P;
				add(f[i+1][j-1],v);
			}
		}
	}
	jc[0]=1;for(int i=1;i<=n+n+1;++i) jc[i]=(LL)jc[i-1]*(LL)i%(LL)P;
	LL g=qpow((LL)(n+n+1),(LL)(P-2))*(LL)l%(LL)P,ans=0;
	for(int i=1;i<n*2;++i)
		for(int j=k;j<=n;++j)
			ans=(ans+(LL)f[i][j]*(LL)f[n+n-i][j]%P*g%P*jc[j]%P)%P;
	ans=ans*qpow((LL)f[n+n][0],P-2)%P;
	printf("%I64d\n",ans);
	return 0;
}