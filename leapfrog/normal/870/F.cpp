//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,ls[10000005],pc,p[4000005],ph[10000005],S[10000005],t[10000005];char v[10000005];
inline int sum(int l,int r) {return r<=l?0:S[r]-S[l];}
int main()
{
	read(n),v[1]=1;for(int i=1;i<=n;i++)
	{
		if(!v[i]) p[++pc]=i,ls[i]=i,ph[i]=i-1;
		for(int j=1;j<=pc&&i*p[j]<=n;j++)
		{
			ls[i*p[j]]=p[j],ph[i*p[j]]=ph[i]*(p[j]-!!(i%p[j]));
			v[i*p[j]]=1;if(i%p[j]==0) break;
		}
	}
	for(int i=2;i<=n;i++) t[ls[i]]++;
	for(int i=1;i<=n;i++) S[i]=S[i-1]+t[i];
	ll cn=0;for(int i=2;i<=n;i++) cn+=ph[i]-1;
	ll rs1=1ll*(n-2)*(n-1)/2-cn,rs2=0,rs3=0,rs4=0;
	for(int i=1;i<=pc;i++) rs3+=1ll*t[p[i]]*sum(max(n/p[i],p[i]),n/2),rs4+=1ll*t[p[i]]*sum(max(n/2,p[i]),n);
//	printf("qwq : %lld %lld %lld %lld\n",rs1,cn-rs3-rs4,rs3,rs4);
	return rs2=cn-rs3-rs4,printf("%lld\n",rs1+2*rs2+3*rs3),0;
}