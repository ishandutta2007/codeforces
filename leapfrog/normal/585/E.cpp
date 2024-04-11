//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int N=10000005,P=1000000007;
int m,n,c[N],s[N],f[N],g[N],pr[N/10],pc,mu[N],pw[N];char pv[N];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void ck(int &x) {x>=P?x-=P:x;}
int main()
{
	read(m);for(int x;m--;) read(x),n=max(n,x),c[x]++;
	pv[1]=1,mu[1]=1;for(int i=1;i<=n;i++)
	{
		if(!pv[i]) pr[++pc]=i,mu[i]=-1;
		for(int j=1;j<=pc&&i*pr[j]<=n;j++)
		{
			mu[i*pr[j]]=-mu[i]*!!(i%pr[j]);
			pv[i*pr[j]]=1;if(i%pr[j]==0) break;
		}
	}
	for(int i=1;i<=n;i++) s[i]=c[i];
	for(int i=1;i<=pc;i++) for(int j=n/pr[i];j;j--) s[j]+=s[j*pr[i]];
	for(int i=1;i<=n;i++) f[i]=mu[i]*s[i];
	for(int i=1;i<=pc;i++) for(int j=1,e=n/pr[i];j<=e;j++) f[j*pr[i]]+=f[j];
	pw[0]=1;for(int i=1;i<=n;i++) pw[i]=(pw[i-1]*2)%P;
	for(int i=1;i<=n;i++) g[i]=pw[s[i]]-1;
	for(int i=1;i<=pc;i++) for(int j=1,e=n/pr[i];j<=e;j++) ck(g[j]+=P-g[j*pr[i]]);
	int rs=0;for(int i=2;i<=n;i++) rs=(rs+1ll*f[i]*g[i])%P;
	return printf("%d\n",(rs+P)%P),0;
}