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
const int N=300000,B=550,blt=N/B+5;
int n,cb[blt+5],ca[N+5];ll sb[blt+5],sa[N+5],vl[blt+5],res=0;
inline int qryc(int x) {x=min(x,N);return cb[(x-1)/B+1]+ca[x];}
inline ll qrys(int x) {return sb[(x-1)/B+1]+sa[x];}
inline void modif(int x)
{
	int wh=(x-1)/B+1;for(int i=wh+1;i<=blt;i++) cb[i]++,sb[i]+=x;
	for(int i=x;i<=min(N,wh*B);i++) ca[i]++,sa[i]+=x;
	for(int i=1;i<=B;i++) vl[i]+=x/i;
}
int main()
{
	read(n);for(int i=1,x;i<=n;printf("%lld ",res),modif(x),i++)
	{
		read(x),res+=1ll*(i-1)*x;//ai mod ? = ai * x - \sum ai / ? * ?
		for(int l=1,r;l<=x;l=r+1) r=x/(x/l),res-=1ll*(qrys(r)-qrys(l-1))*(x/l);
		res+=qrys(N);if(x<=B) res-=vl[x]*x;else//? mod ai
			for(int i=x;i<=N;i+=x) res-=1ll*i*(qryc(i+x-1)-qryc(i-1));
	}
	return putchar('\n'),0;
}