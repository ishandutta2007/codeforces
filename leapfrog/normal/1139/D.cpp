#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;int n,r,mu[100005],pc,p[100005];char v[100005];
inline int qpow(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r%P;}
signed main()
{
	scanf("%d",&n),memset(v,0,sizeof(v)),mu[1]=v[1]=1,pc=0,r=1;
	for(int i=2;i<=n;i++)
	{
		if(!v[i]) p[++pc]=i,mu[i]=-1;
		for(int j=1;j<=pc&&i*p[j]<=n;j++) {v[i*p[j]]=1;if(i%p[j]) mu[i*p[j]]=-mu[i];else {mu[i*p[j]]=0;break;}}
	}
	for(int i=2;i<=n;i++) r=(r-1ll*mu[i]*(n/i)%P*qpow(n-n/i)%P+P)%P;
	return printf("%d\n",(r+P)%P),0;
}