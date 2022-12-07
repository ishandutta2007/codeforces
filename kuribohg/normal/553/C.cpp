#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
const int MOD=1000000007;
int n,m,tot,x,y,z;
int fa[MAXN],w[MAXN],ans=1;
int find(int x)
{
	if(x==fa[x]) return x;
	int a=find(fa[x]);
	w[x]=w[x]^w[fa[x]];
	return fa[x]=a;
}
inline void uni(int i,int j,int z)
{
	int fi=find(i),fj=find(j);
	w[fi]=w[i]^w[j]^z;
	fa[fi]=fj;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	tot=n-1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		z^=1;
		int fi=find(x),fj=find(y);
		if(fi==fj)
		{
			int wi=w[x],wj=w[y];
			if((wi^wj)!=z) {puts("0");return 0;}
		}
		else uni(x,y,z),tot--;
	}
	for(int i=1;i<=tot;i++) ans=(ans+ans)%MOD;
	printf("%d\n",ans);
	return 0;
}