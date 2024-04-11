#include<bits/stdc++.h>
using namespace std;
const int P=998244353;int n,m,pw[200005],r;
inline int qpow(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*x*r%P;return r;}
inline int C(int n,int m) {return 1ll*pw[n]*qpow(pw[m])%P*qpow(pw[n-m])%P;}
int main()
{
	scanf("%d%d",&n,&m),pw[0]=1,r=0;
	if(n==2) return puts("0"),0;
	for(int i=1;i<=200000;i++) pw[i]=1ll*pw[i-1]*i%P;
	int k=C(m,m-n+1),z=n-2,g=qpow(2,n-3);
	//n-1
	//
	//n-3
	printf("%lld\n",1ll*k*z%P*g%P);
	return 0;
}