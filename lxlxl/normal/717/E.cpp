#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
struct node
{
	int y,next;
}a[400010];
int first[200010],len;
int A[200010];
void ins(int x,int y)
{
	a[++len].y=y;
	a[len].next=first[x];
	first[x]=len;
}
void dfs(int x,int fa)
{
    int k,y;
	A[x]^=1;
	printf("%d ",x);
	for(k=first[x];k;k=a[k].next)
	{
	  y=a[k].y;
	  if(y==fa)continue;
	  dfs(y,x);
	  A[x]^=1;
	  printf("%d ",x);
	}
	if(A[x]&&fa){printf("%d %d ",fa,x);A[fa]^=1;}
}
int main()
{
	int n,i,j,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	  scanf("%d",&x);
	  if(x==1)A[i]=0;
	  else A[i]=1;
	}
	A[1]^=1;
	for(i=1;i<n;i++)
	{
	  scanf("%d%d",&x,&y);
	  ins(x,y);ins(y,x);
	}
	dfs(1,0);
	if(A[1])printf("%d %d %d ",a[first[1]].y,1,a[first[1]].y);
	printf("\n");
	return 0;
}