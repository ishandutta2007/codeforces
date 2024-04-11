#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=405;int n,m,P,fa[N*N],a[N][N],di[N*N];char ch[N][N];
inline int id(int x,int y) {return(x-1)*(m+1)+y;}
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y;}
inline int det(int n)
{
	int rs=1;for(int i=1;i<n;i++) for(int j=i+1;j<n;j++)
	{
		while(a[i][i])
		{
			int w=a[j][i]/a[i][i];
			for(int k=i;k<n;k++) a[j][k]=(a[j][k]-1ll*w*a[i][k]%P+P)%P;
			for(int k=1;k<n;k++) swap(a[i][k],a[j][k]);
			rs=(rs?P-rs:rs);
		}rs=(rs?P-rs:rs);for(int k=1;k<n;k++) swap(a[i][k],a[j][k]);
	}
	for(int i=1;i<n;i++) rs=1ll*rs*a[i][i]%P;
	return rs;
}
inline int solve(int xtw)
{
	int cn=0;memset(a,0,sizeof(a));
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++)
		if(((i+j)&1)==xtw&&id(i,j)==getf(id(i,j))) di[id(i,j)]=++cn;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(ch[i][j]=='*')
	{
		int u,v;if(((i+j)&1)==xtw) u=di[getf(id(i,j))],v=di[getf(id(i+1,j+1))];
		else u=di[getf(id(i+1,j))],v=di[getf(id(i,j+1))];
		if(u^v) a[u][u]++,a[v][v]++,a[u][v]--,a[v][u]--;
	}return det(cn);
}
int main()
{
	read(n,m,P);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1,e=(n+1)*(m+1);i<=e;i++) fa[i]=i;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		if(ch[i][j]=='/') mrg(id(i+1,j),id(i,j+1));
		else if(ch[i][j]=='\\') mrg(id(i,j),id(i+1,j+1));
	return printf("%d\n",(solve(0)+solve(1))%P),0;
}