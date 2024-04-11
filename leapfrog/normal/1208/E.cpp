//Coded by leap_frog on 2021.11.19 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=1000005,INF=1e9+5;
struct segm{ll lz,sm;int ln;}T[N<<2];
int m,n,a[N],q[N],hd,tl;ll cf[N];
inline void add(int l,int r,ll w) {cf[l]+=w,cf[r+1]-=w;}
int main()
{
	read(m,n);
	for(int C=1,l;C<=m;C++)
	{
		hd=1,tl=0,read(l);for(int i=1;i<=l;i++) read(a[i]);
		int mx=0;for(int i=1;i<=l;i++) mx=max(mx,a[i]);
		int llim=l,rlim=n-l+1;if(llim<rlim)
		{
			add(llim,rlim,mx);int lm=0,rm=0;
			for(int i=1;i<llim;i++) lm=max(lm,a[i]),add(i,i,lm);
			for(int i=n;i>rlim;i--) rm=max(rm,a[i-n+l]),add(i,i,rm);
		}
		else
		{
			q[hd=tl]=0,a[l+1]=0;for(int i=1;i<=n;i++)
			{
				while(hd<=tl&&n-i<l-q[hd]) hd++;
				if(i<=l+1) {while(hd<=tl&&a[q[tl]]<=a[i]) tl--;q[++tl]=i;}
				add(i,i,a[q[hd]]);
			}
		}
	}
	for(int i=1;i<=n;i++) cf[i]+=cf[i-1];
	for(int i=1;i<=n;i++) printf("%lld%c",cf[i],i==n?'\n':' ');
	return 0;
}