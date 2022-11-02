//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,m,L[100005],R[100005],F[100005];const int P=998244353;
int pr[100005],pc,mu[100005],sm[100005],vl[100005];char pv[100005];
inline void init()
{
	mu[1]=pv[1]=1;for(int i=1;i<=100000;i++)
	{
		if(!pv[i]) pr[++pc]=i,mu[i]=P-1;
		for(int j=1;j<=pc&&i*pr[j]<=100000;j++)
		{
			mu[i*pr[j]]=P-!!(i%pr[j])*mu[i];
			pv[i*pr[j]]=1;if(i%pr[j]==0) break;
		}
	}
}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(L[i]),read(R[i]);
	int rs=0;init();
	for(int i=1;i<=m;i++)
	{
		int tt=m/i;for(int j=1;j<=tt;j++) F[j]=0;
		char fg=0;for(int j=1;j<=n;j++)
		{
			int dl=(L[j]+i-1)/i,dr=R[j]/i;dl=max(dl,1);
			if(dr==0||dl>dr) {fg=1;break;}
			if(j==1)
			{
				for(int k=1;k<=tt;k++) sm[k]=0;
				for(int k=dl;k<=dr;k++) sm[k]=1;
				for(int k=2;k<=tt;k++) sm[k]=(sm[k-1]+sm[k])%P;
			}
			else
			{
				for(int k=1;k<=tt;k++) vl[k]=(sm[max(k-dl,0)]-sm[max(k-dr-1,0)]+P)%P;
				sm[0]=0;for(int k=1;k<=tt;k++) sm[k]=(vl[k]+sm[k-1])%P;
			}
		}
		if(!fg)
		{
			int res=0;for(int j=1;j<=tt;j++) res=(res+vl[j])%P;
			rs=(rs+1ll*mu[i]*res)%P;
		}
	}
	return printf("%d\n",rs),0;
}