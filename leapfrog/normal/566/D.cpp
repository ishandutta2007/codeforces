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
int n,q,fa[200005],nx[200005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[y]=x;}
int main()
{
	read(n),read(q);for(int i=1;i<=n;i++) fa[i]=i,nx[i]=i+1;
	for(int op,x,y;q--;)
	{
		read(op),read(x),read(y);
		if(op==3) puts(getf(x)^getf(y)?"NO":"YES");
		else if(op==1) mrg(x,y);
		else for(int i=x+1,t;i<=y;) mrg(i-1,i),t=nx[i],nx[i]=nx[y],i=t;
	}
	return 0;
}