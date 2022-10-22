#include <bits/stdc++.h>
using namespace std;
#define N 5005
#define M 100005
int n,m,tp,vl[N][N*2];struct Query {int op,x,y,len,ans;}a[M];
struct Node {int x,y,w;}st[M*2];
void upd(int x,int y,int w,bool fl=1)
{
	if(!x || !y) return;if(fl) st[++tp]=(Node) {x,y,w};
	for(int i=x;i;i-=i&-i) for(int j=y;j;j-=j&-j) vl[i][j]+=w;
}
int qSm(int x,int y)
{
	int res=0;
	for(int i=x;i<=n;i+=i&-i) for(int j=y;j<=n*2;j+=j&-j)
		res+=vl[i][j];return res;
}
void clear() {while(tp) upd(st[tp].x,st[tp].y,-st[tp].w,0),--tp;}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,op1;i<=m;++i)
	{
		scanf("%d",&op1);if(op1==2) scanf("%d %d",&a[i].x,&a[i].y);
		if(op1==1) scanf("%d %d %d %d\n",&a[i].op,&a[i].x,&a[i].y,&a[i].len);
	}
	for(int i=1,op,x,y,len;i<=m;++i)
	{
		op=a[i].op;x=a[i].x;y=a[i].y;len=a[i].len;
		if(!op) a[i].ans+=qSm(x,y);
		if(op==1) upd(x+len,y-1,-1),upd(x-1,y-1,1);
		if(op==2) upd(x+len,y,1),upd(x-1,y,-1);
		if(op==3) upd(x,y-1,-1),upd(x-len-1,y-1,1);
		if(op==4) upd(x,y,1),upd(x-len-1,y,-1);
	}clear();
	for(int i=1,op,x,y,len;i<=m;++i)
	{
		op=a[i].op;x=a[i].x;y=a[i].y;len=a[i].len;
		if(!op) a[i].ans+=qSm(x,x+y-1);
		if(op==1) upd(x+len,x+y+len-1,1),upd(x-1,x+y+len-1,-1);
		if(op==4) upd(x,x+y-len-2,-1),upd(x-len-1,x+y-len-2,1);
	}clear();
	for(int i=1,op,x,y,len;i<=m;++i)
	{
		op=a[i].op;x=a[i].x;y=a[i].y;len=a[i].len;
		if(!op) a[i].ans+=qSm(x,y-x+n);
		if(op==2) upd(x+len,y-x-len-1+n,-1),upd(x-1,y-x-len-1+n,1);
		if(op==3) upd(x,y-x+len+n,1),upd(x-len-1,y-x+len+n,-1);
	}for(int i=1;i<=m;++i) if(!a[i].op) printf("%d\n",a[i].ans);return 0;
}