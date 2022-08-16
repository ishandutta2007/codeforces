#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

const int MaxN=200010;

int n,Lp,Rp,UL,UR,DL,DR;
long long x[MaxN],y[MaxN];
map<int,int> U,D;

void init()
{
	cin>>n;
	Lp=1;
	Rp=1;
	for (int i=1;i<=n;++i)
	{
		int tmpx,tmpy;
		scanf("%d%d",&tmpx,&tmpy);
		x[i]=tmpx;
		y[i]=tmpy;
		x[i+n]=x[i];
		y[i+n]=y[i];
		if (x[Lp]>x[i]) Lp=i;
		if (x[Rp]<x[i]) Rp=i;
	}
	UL=Lp;
	while (x[UL]==x[UL+1]) ++UL;
	for (int i=UL;i<=2*n;++i)
		if (x[i]==x[Rp])
		{
			UR=i;
			break;
		}
	DL=UR;
	while (x[DL]==x[DL+1]) ++DL;
	for (int i=DL;i<=2*n;++i)
		if (x[i]==x[Lp])
		{
			DR=i;
			break;
		}
	for (int i=UL;i<=UR;++i)
		U.insert(map<int,int>::value_type(x[i],i));
	for (int i=DL;i<=DR;++i)
		D.insert(map<int,int>::value_type(x[i],i));
}

long long area(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
	return x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3;
}

void work()
{
	int m;
	cin>>m;
	while (m--)
	{
		int tmpx,tmpy;
		long long px,py;
		scanf("%d%d",&tmpx,&tmpy);
		px=tmpx;
		py=tmpy;
		if (!(x[Lp]<px&&px<x[Rp]))
		{
			puts("NO");
			return;
		}
		int way=U.upper_bound(px)->second;
		if (area(x[way],y[way],px,py,x[way-1],y[way-1])>=0)
		{
			puts("NO");
			return;
		}
		way=D.upper_bound(px)->second;
		if (area(x[way],y[way],px,py,x[way+1],y[way+1])<=0)
		{
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main()
{
	init();
	work();
	return 0;
}