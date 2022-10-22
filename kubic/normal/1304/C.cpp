#include <bits/stdc++.h>
using namespace std;
#define N 505
int T,n,m,nwL,nwR;struct node {int x,l,r;}a[N];
bool cmp(node x,node y) {return x.x<y.x;}
void slv()
{
	nwL=nwR=m;sort(a+1,a+n+1,cmp);
	for(int i=1,d;i<=n;++i)
	{
		if(a[i].l>a[i].r) {puts("NO");return;}
		d=a[i].x-a[i-1].x;nwL-=d;nwR+=d;nwL=max(nwL,a[i].l);nwR=min(nwR,a[i].r);
		if(nwL>nwR) {puts("NO");return;}
	}puts("YES");
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i) scanf("%d %d %d",&a[i].x,&a[i].l,&a[i].r);slv();	
	}return 0;
}