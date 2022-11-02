//{{{
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
int n,f[1000008][21],dep[1000008],fr,tw,nwd;
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;~i;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	for(int i=20;~i;i--) if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	return x^y?f[x][0]:y;
}
inline int dis(int x,int y) {return dep[x]+dep[y]-(dep[LCA(x,y)]<<1);}
inline void add(int x,int fa)
{
	dep[x]=dep[fa]+1,f[x][0]=fa;
	for(int i=1;i<=20;i++) f[x][i]=f[f[x][i-1]][i-1];
}
inline void updat(int x)
{
	if(nwd<dis(x,fr)) nwd=dis(x,fr),tw=x;
	if(nwd<dis(x,tw)) nwd=dis(x,tw),fr=x;
}
int main()
{
	read(n),add(fr=2,0),add(tw=3,0),add(4,0),nwd=2;
	for(int i=1,x,cnt=4;i<=n;i++)
	{
		read(x),add(++cnt,x),add(++cnt,x);
		updat(cnt),printf("%d\n",nwd);
	}
}