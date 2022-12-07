#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
struct Node
{
	int x,id,l,r,k;
	friend bool operator<(const Node &p,const Node &q){return p.x<q.x;}
}Q[MAXN<<1];
char str[MAXN];
int n,m,a[MAXN],Sta[MAXN],top,l[MAXN],r[MAXN],tot,ans[MAXN];
int BIT[MAXN],now;
void Change(int x,int tar)
{
	if(x==0) return;
	for(int i=x;i<=n;i+=(i&(-i)))
		BIT[i]+=tar;
}
int Query(int x)
{
	int con=0;
	for(int i=x;i>0;i^=(i&(-i)))
		con+=BIT[i];
	return con;
}
int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='(') Sta[++top]=i;
		else if(top) a[i]=Sta[top--];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&l[i],&r[i]);
	for(int i=1;i<=m;i++)
	{
		tot++,Q[tot].id=i,Q[tot].l=l[i],Q[tot].r=r[i],Q[tot].x=l[i]-1,Q[tot].k=-1;
		tot++,Q[tot].id=i,Q[tot].l=l[i],Q[tot].r=r[i],Q[tot].x=r[i],Q[tot].k=1;
	}
	sort(Q+1,Q+tot+1);
	for(int i=1;i<=tot;i++)
	{
		while(now<Q[i].x) now++,Change(a[now],1);
		ans[Q[i].id]+=Q[i].k*(Query(Q[i].r)-Query(Q[i].l-1));
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]<<1);
	return 0;
}