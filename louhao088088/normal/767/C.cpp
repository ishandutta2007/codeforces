///
#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,next;
}zry[2000010];
int a,n,g,cnt,sum,jl;
int b[2000010],head[2000010],ans[5000];
void build(int x,int y)
{
	cnt++;
	zry[cnt].v=y,zry[cnt].next=head[x];
	head[x]=cnt;
}
void js(int x,int fa)
{
	for(int i=head[x];i;i=zry[i].next)
	{
		int p=zry[i].v;
		if(p!=fa)
		{
			js(p,x);
			b[x]=b[x]+b[p];
		}
	}
	if(b[x]==sum)
	{
		ans[++jl]=x,b[x]=0;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b[i]);
		if(a)
		{
		    build(a,i),build(i,a);
		}
		else g=i;
		sum=sum+b[i];
	}
	if(sum%3)
	{
		printf("-1");
		return 0;
	}
	sum=sum/3;
	js(g,0);
	if(jl<=2) printf("-1");
	else printf("%d %d\n",ans[1],ans[2]);
	return 0;
}