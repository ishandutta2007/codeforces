//
//
#include<bits/stdc++.h>
using namespace std;typedef map<int,int> mtp;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,mxw=100005;mtp T[100005];
inline void add(mtp &t,int x,int y) {for(;x<=mxw;x+=x&(-x)) t[x]=max(t[x],y);}
inline int qry(mtp &t,int x) {int r=0;for(;x;x-=x&(-x)) r=max(r,t[x]);return r;}
int main()
{
	read(n),read(m);int mx=0;
	for(int i=1,x,y,w;i<=m;i++)
	{
		read(x),read(y),read(w);
		int q=qry(T[x],w);add(T[y],w+1,q+1),mx=max(mx,q+1);
	}
	return printf("%d\n",mx),0;
}