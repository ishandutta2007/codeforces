#include<bits/stdc++.h>
#define re register
using namespace std;
int n,l;
struct lim{long long t,x,y;}c[200100];
inline bool cmp(const lim&A,const lim&B){return A.t%l<B.t%l;}
long long xpy1,xpy2,xmy1,xmy2;
void nw(re long long px,re long long py,re long long pt)
{
	if(px==0){if(pt<0)puts("NO"),exit(0);return;}
	if(px<0)//>=
	{
		px=-px,py=-py,pt=-pt;pt=ceil((long double)pt/px);py/=px;px/=px;
		if(py<0)xmy1=max(xmy1,pt);
		else xpy1=max(xpy1,pt);
	}
	else//<=
	{
		pt=floor((long double)pt/px);py/=px;px/=px;
		if(py<0)xmy2=min(xmy2,pt);
		else xpy2=min(xpy2,pt);
	}
}
void rnw(re int a,re int b)
{
	re long long tt=c[b].t%l-c[a].t%l,ta=c[a].t/l,tb=c[b].t/l;
	nw(-(ta-tb),-(ta-tb),tt-(c[a].x-c[b].x)-(c[a].y-c[b].y));
	nw(+(ta-tb),-(ta-tb),tt+(c[a].x-c[b].x)-(c[a].y-c[b].y));
	nw(-(ta-tb),+(ta-tb),tt-(c[a].x-c[b].x)+(c[a].y-c[b].y));
	nw(+(ta-tb),+(ta-tb),tt+(c[a].x-c[b].x)+(c[a].y-c[b].y));
}
char ss[2000100];
int main()
{
	scanf("%d%d",&n,&l);
	re long long xx,yy,xc,yc,xk=0,yk=0,tt=0;
	for(re int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&c[i].t,&c[i].x,&c[i].y);
		if(c[i].t%2!=abs(c[i].x+c[i].y)%2){puts("NO");return 0;}
	}n++;
	xpy1=-l;xpy2=l;xmy1=-l;xmy2=l;
	sort(c+1,c+n+1,cmp);
	for(re int i=1;i<n;i++)rnw(i,i+1);
	nw((1+c[n].t/l),(1+c[n].t/l),(l-c[n].t%l)+c[n].x+c[n].y);
	nw((1+c[n].t/l),-(1+c[n].t/l),(l-c[n].t%l)+c[n].x-c[n].y);
	nw(-(1+c[n].t/l),(1+c[n].t/l),(l-c[n].t%l)-c[n].x+c[n].y);
	nw(-(1+c[n].t/l),-(1+c[n].t/l),(l-c[n].t%l)-c[n].x-c[n].y);
	if(abs(xpy1)%2!=l%2)xpy1++;if(abs(xmy1)%2!=l%2)xmy1++;if(xpy1>xpy2||xmy1>xmy2){puts("NO");;return 0;}
	xx=(xpy1+xmy1)/2;
	yy=xpy1-xx;
	for(re int i=1;i<=n;i++)
	{
		xc=c[i].x-c[i].t/l*xx;
		yc=c[i].y-c[i].t/l*yy;
		while(tt<c[i].t%l)
		{
			if(xk<xc)ss[++tt]='R',xk++;
			else if(xk>xc)ss[++tt]='L',xk--;
			else if(yk<yc)ss[++tt]='U',yk++;
			else ss[++tt]='D',yk--;
		}
	}
	xc=xx;
	yc=yy;
	while(tt<l)
	{
		if(xk<xc)ss[++tt]='R',xk++;
		else if(xk>xc)ss[++tt]='L',xk--;
		else if(yk<yc)ss[++tt]='U',yk++;
		else ss[++tt]='D',yk--;
	}
	puts(ss+1);
}