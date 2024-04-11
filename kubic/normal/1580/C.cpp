#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define M 405
const int B=400;int n,m,nw,a[N],b[N],z[N],lst[N],w[M][M];
void ins(int x,int y)
{
	if(a[y]<=B) for(int i=a[y];i>b[y];--i) ++w[a[y]][(x+i-1)%a[y]];
	else for(int i=x;i<=m;i+=a[y])
	{if(i+b[y]<=m) ++z[i+b[y]];if(i+a[y]<=m) --z[i+a[y]];}lst[y]=x;
}
void dlt(int x,int y)
{
	if(a[y]<=B) for(int i=a[y];i>b[y];--i) --w[a[y]][(lst[y]+i-1)%a[y]];
	else for(int i=lst[y];i<=m;i+=a[y])
	{
		if(i+b[y]<=m) --z[i+b[y]];if(i+a[y]<=m) ++z[i+a[y]];
		if(i+b[y]<x) --nw;if(i+a[y]<x) ++nw;
	}
}
int qry(int x) {int res=nw;for(int i=1;i<=B;++i) res+=w[i][x%i];return res;}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d %d",&b[i],&a[i]),a[i]+=b[i];
	for(int i=1,op,x;i<=m;++i)
	{
		scanf("%d %d",&op,&x);if(op==1) ins(i,x);if(op==2) dlt(i,x);
		nw+=z[i];printf("%d\n",qry(i));
	}return 0;
}