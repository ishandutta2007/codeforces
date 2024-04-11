#include <iostream>
#include <math.h>
using namespace std;
#define f first
#define s second
pair<pair<int,int>,char> arr[8];
int kx,ky;
pair<pair<int,int>,char> min(pair<pair<int,int>,char> a,pair<pair<int,int>,char> b)
{
	if (a.s=='N')
	return b;
	if (b.s=='N')
	return a;
	if (max(abs(kx-a.f.f),abs(ky-a.f.s))>max(abs(kx-b.f.f),abs(ky-b.f.s)))
	return b;
	return a;
}
int main()
{
	int n;
	scanf("%d%d%d",&n,&kx,&ky);
	for (int i=0;i<8;i++)
	arr[i].second='N';
	while (n--)
	{
		getchar();
		pair<pair<int,int>,char> p;
		scanf("%c%d%d",&p.s,&p.f.f,&p.f.s);
		if (p.f.f==kx)
		{
			if (p.f.s>ky)
			arr[0]=min(arr[0],p);
			else
			arr[1]=min(arr[1],p);
		}
		else if (p.f.s==ky)
		{
			if (p.f.f>kx)
			arr[2]=min(arr[2],p);
			else
			arr[3]=min(arr[3],p);
		}
		else if (p.f.f-kx==p.f.s-ky)
		{
			if (p.f.f<kx)
			arr[4]=min(arr[4],p);
			else
			arr[5]=min(arr[5],p);
		}
		else if (p.f.f-kx==-(p.f.s-ky))
		{
			if (p.f.f<kx)
			arr[6]=min(arr[6],p);
			else
			arr[7]=min(arr[7],p);
		}
	}
	for (int i=0;i<4;i++)
	{
		if (arr[i].s=='Q' || arr[i].s=='R')
		{
			printf("YES");
			return 0;
		}
	}
	for (int i=4;i<8;i++)
	{
		if (arr[i].s=='Q' || arr[i].s=='B')
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}