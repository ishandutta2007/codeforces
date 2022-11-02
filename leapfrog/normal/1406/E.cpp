//Coded by Kamiyama_Shiki on 2021.11.15 {{{
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
const int N=100005;int n;
const int V=N;int pr[V],pc,ls[V];char pv[V];//prinit{{{
inline void prinit(int n=V-1)
{
	pv[1]=1,ls[1]=0;for(int i=1;i<=n;i++)
	{
		if(!pv[i]) pr[++pc]=i,ls[i]=i;
		for(int j=1;j<=pc&&i*pr[j]<=n;j++) {pv[i*pr[j]]=1;if(i%pr[j]==0) break;}
	}
}//}}}
#ifndef ONLINE_JUDGE
int res;char vis[N];
#endif
inline int A(int x)
{
#ifdef ONLINE_JUDGE
	if(x>n) return 0;
	printf("A %d\n",x),fflush(stdout);
	int w;return read(w),w;
#else
	int rs=0;for(int i=x;i<=n;i+=x) rs+=!vis[i];
	return rs;
#endif
}
inline int B(int x)
{
#ifdef ONLINE_JUDGE
	if(x>n) return 0;
	printf("B %d\n",x),fflush(stdout);
	int w;return read(w),w;
#else
	int rs=0;for(int i=x;i<=n;i+=x) rs+=!vis[i],vis[i]=1;
	return vis[res]=0,rs;
#endif
}
inline void C(int x) {printf("C %d\n",x),fflush(stdout);}
int main()
{
	int rs=1,wh=1;read(n),prinit(n);
#ifndef ONLINE_JUDGE
	read(res);
#endif
	for(int i=1;i<=pc&&pr[i]*pr[i]<=n;i++)
	{
		int x=pr[i],nw=0;B(pr[i]),nw=A(pr[i]);
		wh=i+1;while(nw) rs*=pr[i],nw=A(x*=pr[i]);
	}
	if(rs!=1)
	{
		for(int i=wh;i<=pc;i++) if(A(pr[i])>1) return C(pr[i]*rs),0;
		return C(rs),0;
	}
	for(int l=wh,r=l+99,now=A(1),nx;l<=pc;l+=100,r+=100,now=nx)
	{
		for(int i=l;i<=r&&i<=pc;i++) B(pr[i]);
		nx=A(1);if(now==nx+min(r,pc)-l+1) continue;
		for(int i=l;i<=r&&i<=pc;i++) if(A(pr[i])) return C(pr[i]),0;
	}return C(1),0;
}