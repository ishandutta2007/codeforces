//Coded by Kamiyama_Shiki on 2021.11.18 {{{
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
const int N=100005;int n,a[N],lg[N];
struct sttable
{
	int st[17][N];inline int& operator[](int x) {return st[0][x];}
	inline void init() {for(int i=0;i<16;i++) for(int j=1;j+(1<<i)<=n;j++) st[i+1][j]=min(st[i][j],st[i][j+(1<<i)]);}
	inline int qry(int l,int r) {if(l>r) return 1e9;int g=lg[r-l+1];return min(st[g][l],st[g][r-(1<<g)+1]);}
}L,R,W;
int main()
{
	lg[0]=-1;for(int i=1;i<N;i++) lg[i]=lg[i>>1]+1;
	read(n);for(int i=1;i<=n;i++) read(a[i]),L[i]=a[i]-i,R[i]=a[i]+i,W[i]=a[i];
	L.init(),R.init(),W.init();int nw=1,rs=1e9;
	for(int T=1;T<=n;T++)
	{
		while(nw<=T&&nw*2-a[nw]<=T) nw++;
		int ps=(nw<=T?nw:-1),a,b;if(nw>T)
		{
			for(int l=T,r=n,md=(l+r)>>1;l<=r;md=(l+r)>>1)
				if(W.qry(T,md)<T) ps=md,r=md-1;else l=md+1;
		}if(!~ps) continue;
		if(ps<=T) a=L.qry(1,ps-1)+T,b=min(L.qry(ps,T)+T,R.qry(T+1,n)-T);
		else a=min(L.qry(1,T)+T,R.qry(T+1,ps-1)-T),b=R.qry(ps,n)-T;
		rs=min(rs,max(a,b));
	}return printf("%d\n",rs>=1000000000?-1:rs),0;
}