#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005; 
int n,q;
int fa[N];
int nxt[N];
int getf(int v)
{
	if(v==fa[v]) return v;
	fa[v]=getf(fa[v]);
	return fa[v];
}
void merge(int u,int v)
{
	int f1=getf(u),f2=getf(v);
	if(f1!=f2) fa[f2]=f1;
	return;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		fa[i]=i,nxt[i]=i+1;
	while(q--)
	{
		int type,x,y;
		scanf("%d%d%d",&type,&x,&y);
		if(type==1) merge(x,y);
		else if(type==2)
		{
			for(int i=x+1,j;i<=y;i=j)
			{
				merge(i,x);
				j=nxt[i],nxt[i]=nxt[y];
			}		
		}
		else if(type==3)
		{
			if(getf(x)==getf(y)) printf("YES\n");
			else printf("NO\n"); 
		}
	}
	return 0;
}