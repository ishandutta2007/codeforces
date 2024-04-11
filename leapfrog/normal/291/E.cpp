//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct edge{int to,nxt;}e[4000005];int n,m,et,head[4000005];char c[3000005],v[4000005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
typedef unsigned long long ull;ull bs=1145141,pw=1,hs=0,hg[4000005];int res=0;
inline void dfs(int x,int dep)
{
	if(dep) hg[dep]=bs*hg[dep-1]+v[x];
	if(dep>=m) res+=(hg[dep-m]*pw+hs==hg[dep]);
	for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to,dep+1);
}
int main()
{
	read(n);for(int i=2,ed=n,fa;i<=ed;i++)
	{
		read(fa),scanf("%s",c+1);int m=strlen(c+1);
		for(int nw=fa,j=1;j<m;j++) ++n,adde(nw,n),v[n]=c[j],nw=n;
		v[i]=c[m],adde(m==1?fa:n,i);
	}
	scanf("%s",c+1),m=strlen(c+1);for(int i=1;i<=m;i++) pw*=bs,hs=hs*bs+c[i];
	//for(int i=1;i<=n;i++) printf("%d : %c\n",i,v[i]);
	return dfs(1,1),printf("%d\n",res),0;
}