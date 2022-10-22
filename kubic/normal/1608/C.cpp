#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,fa[N];bool ans[N];
struct Node {int id,x,y;}a[N];
bool cmp1(Node x,Node y) {return x.x<y.x;}
bool cmp2(Node x,Node y) {return x.y<y.y;}
int findRt(int u) {return u==fa[u]?u:fa[u]=findRt(fa[u]);}
void merge(int u,int v) {u=findRt(u);v=findRt(v);if(u!=v) fa[u]=v;}
void slv()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) a[i].id=fa[i]=i,scanf("%d",&a[i].x);
	for(int i=1;i<=n;++i) scanf("%d",&a[i].y);
	sort(a+1,a+n+1,cmp1);
	for(int i=1,mx=0,ps=0;i<=n;++i)
	{if(a[i].y>mx) mx=a[i].y,ps=i;else merge(a[i].id,a[ps].id);}
	sort(a+1,a+n+1,cmp2);
	for(int i=1,mx=0,ps=0;i<=n;++i)
	{if(a[i].x>mx) mx=a[i].x,ps=i;else merge(a[i].id,a[ps].id);}
	for(int i=1;i<=n;++i) if(findRt(i)==findRt(a[n].id))
		putchar('1');else putchar('0');puts("");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}