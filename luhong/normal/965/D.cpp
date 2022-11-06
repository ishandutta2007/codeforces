#include<iostream>
#include<cstdio>
#define INF 2000000000
using namespace std;
int c[101000],a[101000],w,length;
int nxt[101000];
bool check(int x)
{
	int lst=x,sum=0,l=0,r=nxt[1];
	for(int i=w-1;i>=1;i--)a[i]=min(a[i],x);
	while(1)
	{
		if(lst<a[r]-sum)
		{
			if(r-l>length)return false;
			sum+=lst;l=nxt[l+1];lst=a[l];
		}
		else if(lst==a[r]-sum)
		{
			if(r-l>length)return false;
			sum=0;l=nxt[l+1];lst=a[l];r=nxt[r+1];
		}
		else
		{
			if(r-l>length)return false;
			lst-=a[r]-sum;sum=0;r=nxt[r+1];
		}
		if(l==w&&r==w)return true;
	}
}
int main()
{
	scanf("%d%d",&w,&length);
	a[0]=a[w]=INF;for(int i=1;i<w;i++)scanf("%d",&a[i]),c[i]=a[i];
	for(int i=0;i<=w;i++)if(a[i])nxt[i]=i;else nxt[i]=i+1;
	int L=1,R=INF/2+1;
	while(L<R)
	{
		int mid=L+R>>1;
		for(int i=1;i<w;i++)a[i]=c[i];
		if(check(mid))L=mid+1;
		else R=mid;
	}
	printf("%d\n",R-1);return 0;
}