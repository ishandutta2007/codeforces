#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const LL P=1e9+7;
int n,K;
int L;
int W,B;
struct jz{
	LL x[110][110];
}z,ans;
jz operator * (jz A,jz B){
	jz C;
	for(int i=0;i<=L;++i)
		for(int j=0;j<=L;++j)
			C.x[i][j]=0;
	for(int i=0;i<=L;++i)
		for(int j=0;j<=L;++j){
			if(!A.x[i][j]) continue;
			for(int k=0;k<=L;++k)
				C.x[i][k]=(C.x[i][k]+A.x[i][j]*B.x[j][k]%P)%P;
		}
	return C;
}
int a[110];
LL D;
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		W+=1-a[i];
		B+=a[i];
	}
	L=min(W,B);
	LL x,y;
	for(int i=0;i<=L;++i){
		y=(LL)n*(LL)(n-1)/(LL)2;
		x=i*i;
		if(i>0){
			z.x[i][i-1]=(z.x[i][i-1]+x)%P;
			y=y-x;
		}
		x=(W-i)*(B-i);
		if(i<L){
			z.x[i][i+1]=(z.x[i][i+1]+x)%P;
			y=y-x;
		}
		z.x[i][i]=(z.x[i][i]+y)%P;
	}
	int t=0;
	for(int i=1;i<=W;++i)
		if(a[i]) ++t;
	ans.x[0][t]=1;
	int kk=K;
	while(K){
		if(K&1) ans=ans*z;
		z=z*z;K>>=1;
	}
	D=1;x=(LL)n*(LL)(n-1)/(LL)2;
	K=kk;
	while(K){
		if(K&1) D=D*x%P;
		x=x*x%P;K>>=1;
	}
	K=P-2;x=D;D=1;
	while(K){
		if(K&1) D=D*x%P;
		x=x*x%P;K>>=1;
	}
	D=ans.x[0][0]*D%P;
	printf("%I64d\n",D);
	return 0;
}