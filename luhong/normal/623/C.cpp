#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long lmx[100100],rmx[100100],lmn[100100],rmn[100100];//()y
int n;
struct xxx{long long x,y;}a[100100];
bool cmp(xxx a,xxx b){return a.x<b.x;}
long long Abs(long long x){return x>0?x:-x;}
long long sq(long long a){return a*a;}
bool check(long long val)
{
	int l,r=1;
	for(l=1;l<=n;l++)
	{
		r=max(r,l);
		while(r<n&&sq(a[r+1].x-a[l].x)<=val&&Abs(a[r+1].x)<=Abs(a[l].x))r++;
		while(r>1&&Abs(a[r].x)>Abs(a[l].x))r--;
	//	cout<<l<<" "<<r;
		if(l==1&&r==n)return true;
		long long Max=max(lmx[l-1],rmx[r+1]),Min=min(lmn[l-1],rmn[r+1]);
		if(sq(Max-Min)<=val&&sq(Max)+sq(a[l].x)<=val&&sq(Min)+sq(a[l].x)<=val&&sq(Max)+sq(a[r].x)<=val&&sq(Min)+sq(a[r].x)<=val)return true;
	}l=n;
	for(r=n;r>=1;r--)
	{
		l=min(r,l);
		while(l>1&&sq(a[r].x-a[l-1].x)<=val&&Abs(a[l-1].x)<=Abs(a[r].x))l--;
		while(l<n&&Abs(a[l].x)>Abs(a[r].x))l++;
		if(l==1&&r==n)return true;
		long long Max=max(lmx[l-1],rmx[r+1]),Min=min(lmn[l-1],rmn[r+1]);
		if(sq(Max-Min)<=val&&sq(Max)+sq(a[l].x)<=val&&sq(Min)+sq(a[l].x)<=val&&sq(Max)+sq(a[r].x)<=val&&sq(Min)+sq(a[r].x)<=val)return true;
	}
	return false;
}
int main()
{
	scanf("%d",&n);long long Maxx=-4e16,Maxy=-4e16,Minx=4e16,Miny=4e16;
	for(int i=1;i<=n;i++)scanf("%I64d%I64d",&a[i].x,&a[i].y),Maxx=max(Maxx,a[i].x),Minx=min(Minx,a[i].x),Maxy=max(Maxy,a[i].y),Miny=min(Miny,a[i].y);sort(a+1,a+n+1,cmp);
	lmx[1]=lmn[1]=a[1].y;for(int i=2;i<=n;i++)lmx[i]=max(lmx[i-1],a[i].y),lmn[i]=min(lmn[i-1],a[i].y);
	rmx[n]=rmn[n]=a[n].y;for(int i=n-1;i>=1;i--)rmx[i]=max(rmx[i+1],a[i].y),rmn[i]=min(rmn[i+1],a[i].y);
	long long l=0,r=4e16;
	while(l<r)
	{
		long long mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%I64d",min(r,min(sq(Maxx-Minx),sq(Maxy-Miny))));
	return 0;
}