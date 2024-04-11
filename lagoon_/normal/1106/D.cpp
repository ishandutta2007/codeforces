#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
#define re register
#define dmin(a,b) ((a)<(b)?(a):(b))
struct edge{int to;edge*nx;}e[2000100];edge*last[1000010],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(edge){b,last[a]};last[a]=cnt;
	*++cnt=(edge){a,last[b]};last[b]=cnt;
}
bool cc[1000100];
inline bool cmp(re int a,re int b){return a>b;}
struct heap
{
	int c[1000100],cnt;
	void push(re int v)
	{
		c[++cnt]=v;
		push_heap(c+1,c+cnt+1,cmp);
	}
	void pop()
	{
		pop_heap(c+1,c+cnt+1,cmp);
		cnt--;
	}
}a1;
int main()
{
	re int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);addE(x,y);
	}a1.push(1);cc[1]=1;
	for(re int i=1;i<=n;i++)
	{
		x=a1.c[1];
		a1.pop();
		for(re edge*i1=last[x];i1;i1=i1->nx)
		if(!cc[i1->to]){
			cc[i1->to]=1;a1.push(i1->to);
		}
		printf("%d ",x);
	}
}