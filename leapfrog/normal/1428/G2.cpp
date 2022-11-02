//
//
#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int k,m=1000000,p[15],g[1000005];
inline void push(int v,int w) {for(int i=m;i>=v;i--) g[i]=max(g[i],g[i-v]+w);}
inline void back(int v,int w) {int q=min(k,m/v);for(int i=1;i<q;i<<=1) q-=i,push(v*i,w*i);push(v*q,w*q);}
signed main()
{
	read(k),--k,k=(k<<1)+k;
	for(int i=0;i<6;i++) read(p[i]);
	for(int i=0;i<=m;i++)
	{
		int q=0,x=i,qwq=i%10;
		while(x)
		{
			if(qwq%3==0) g[i]+=p[q]*(qwq/3);
			x/=10,++q,qwq=x%10;
		}
	}
	int nw=1;for(int i=0;i<6;i++) back(nw*3,p[i]),nw*=10;
	int q,x;for(read(q);q--;) read(x),printf("%lld\n",g[x]);
	return 0;
}