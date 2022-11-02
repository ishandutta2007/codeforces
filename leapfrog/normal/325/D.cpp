//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int dx[8]={0,0,-1,1,-1,-1,1,1},dy[8]={-1,1,0,0,-1,1,-1,1};
int fa[18000005],n,m,Q,res=0;char vs[18000005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y;}
inline int id(int x,int y) {return (x-1)*m+y;}
inline char ck(int &x,int &y)
{
	if(y==0) y=m;else if(y==m+1) y=1;
	return x>0&&x<=n&&vs[id(x,y)];
}
inline void ins(int x,int y)
{
	int a=x,b=y+m/2;vs[id(x,y)]=vs[id(a,b)]=1;for(int i=0;i<8;i++)
	{
		int p=x+dx[i],q=y+dy[i];if(ck(p,q)) mrg(id(x,y),id(p,q));
		int f=a+dx[i],g=b+dy[i];if(ck(f,g)) mrg(id(a,b),id(f,g));
	}
}
inline char chk(int x,int y)
{
	int a=x,b=y+m/2;for(int i=0;i<8;i++)
	{
		int p=x+dx[i],q=y+dy[i];if(!ck(p,q)) continue;
		for(int j=0;j<8;j++)
		{
			int f=a+dx[j],g=b+dy[j];if(!ck(f,g)) continue;
			if(getf(id(p,q))==getf(id(f,g))) return 0;
		}
	}
	return 1;
}
int main()
{
	read(n),read(m),m*=2,read(Q);if(m==2) return puts("0"),0;
	for(int i=1;i<=n*m;i++) fa[i]=i;
	for(int x,y;Q--;) read(x),read(y),chk(x,y)?ins(x,y),res++:0;
	return printf("%d\n",res),0;
}