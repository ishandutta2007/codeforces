//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}//mt19937 rnd(time(0));
int n,st,K,id[500005],mn=-1,wh,nx;int seed,seed2;
inline void srand(int x,int y) {seed=x,seed2=y;}
inline int rnd() {return (seed*=19260817)+=((seed2+=114514)^=1919810);}
inline int grnd() {int res=rnd();while(res<=0) res+=n;return res;}
int main()
{
	read(n),read(st),read(K);for(int i=1;i<=n;i++) id[i]=i;
	random_shuffle(id+1,id+n+1);srand(998244353u,1000000007u);
	nx=st;for(int i=1,x,w,k;i<=n&&i<=1005;i++)
	{
		k=grnd()%n+1,printf("? %d\n",k),fflush(stdout);
		read(x),read(w);if(x<=K&&mn<x) mn=x,wh=k,nx=w;
	}
	if(mn==K) return printf("! %d\n",K),0;
	for(int rs=mn,ne=nx;rs<K&&~ne;)
	{
		printf("? %d\n",ne),fflush(stdout);int gx,gw;read(gx),read(gw);
		if(gx>=K) return printf("! %d\n",gx),0;else ne=gw,rs=gx;
	}
	return puts("! -1"),0;
}