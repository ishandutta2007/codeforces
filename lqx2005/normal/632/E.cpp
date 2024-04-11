#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int maxn=2000100;
const LL P1=998244353;
const LL P2=1004535809; 
const LL E=3;
LL a[maxn],b[maxn],c[maxn];
int rev[maxn];
int n,k,lim;
LL qpow(LL a,LL b,LL mod)
{
	LL res=1;
	for(;b>0;b>>=1,a=a*a%mod) if(b&1) res=res*a%mod;
	return res;
}
LL inv(LL a,LL mod)
{
	return qpow(a,mod-2,mod);
}
void Init(int tot)
{
	lim=1;
	while(lim<=tot) lim<<=1;
	rev[0]=0;
	for(register int i=1;i<lim;i++) rev[i]=(rev[i>>1]>>1)|((i&1)*(lim>>1));
	return;
}
void FFT(LL *A,LL G,LL mod)
{
	for(register int i=0;i<lim;i++) if(i<rev[i]) swap(A[i],A[rev[i]]);
	for(register int i=2;i<=lim;i<<=1)
	{
		LL wn=qpow(G,(mod-1)/i,mod);
		for(register int j=0;j<lim;j+=i)
		{
			LL w=1;
			for(register int k=0;k<(i>>1);k++,w=w*wn%mod)
			{
				LL x=A[j+k],y=A[j+k+(i>>1)]*w%mod;
				A[j+k]=(x+y)%mod;
				A[j+k+(i>>1)]=(x-y+mod)%mod;
			}
		}
	}
	return;
}
void DFT(LL *A,LL G,LL mod)
{
	FFT(A,G,mod);
	return;
}
void IDFT(LL *A,LL G,LL mod)
{
	FFT(A,G,mod);
	LL ilim=inv(lim,mod);
	for(register int i=0;i<lim;i++) A[i]=A[i]*ilim%mod;
	return;
}
void Polypow(LL *A,LL *C,LL k,LL G,LL mod)
{
	LL IG=inv(G,mod);
	for(int i=0;i<lim;i++) C[i]=A[i];
	DFT(C,G,mod);
	for(int i=0;i<lim;i++) C[i]=qpow(C[i],k,mod);
	IDFT(C,IG,mod);
	return;
}
signed main()
{
	scanf("%d%d",&n,&k);
	int num,mnu=0;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&num);
		a[num]=1;
		mnu=max(num,mnu);
	}
	Init(mnu*k);
	Polypow(a,b,k,E,P1);
	Polypow(a,c,k,E,P2);
	
	for(int i=0;i<lim;i++)
	{
		if(b[i]==0&&c[i]==0) continue;
		printf("%d ",i);
	}
	printf("\n");
	return 0;
	
	
}