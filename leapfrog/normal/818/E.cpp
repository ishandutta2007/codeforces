//Coded by Kamiyama_Shiki on 2021.11.12 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=100005;int n,K,a[N],le[N],vl[N];
inline int fac(int x,int w) {int r=0;while(x%w==0) r++,x/=w;return r;}
inline void deal(int x)
{
	int cnt=0;while(K%x==0) K/=x,cnt++;
	for(int i=1;i<=n;i++) vl[i]=fac(a[i],x);
	for(int r=n,l=n+1,nw=0;r>=1;r--)
	{
		while(l>=1&&nw<cnt) nw+=vl[--l];
		le[r]=min(le[r],l),nw-=vl[r];
	}
}
int main()
{
	read(n,K);for(int i=1;i<=n;i++) read(a[i]),le[i]=i;
	for(int x=2;x*x<=K;x++) if(K%x==0) deal(x);
	if(K!=1) deal(K);
	ll rs=0;for(int i=1;i<=n;i++) rs+=le[i];
	return printf("%lld\n",rs),0;
}