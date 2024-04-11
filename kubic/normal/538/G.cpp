#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
int n,m;ll LX,RX,LY,RY;struct Node {ll x,y,vl1,vl2;}a[N];
bool cmp(Node x,Node y) {return x.vl2<y.vl2;}
ll div1(ll x,ll y) {return floor((long double)(x)/y);}
ll div2(ll x,ll y) {return ceil((long double)(x)/y);}
int main()
{
	scanf("%d %d",&n,&m);RX=RY=m;
	for(int i=1;i<=n;++i)
	{
		ll t,x,y;scanf("%lld %lld %lld",&t,&x,&y);
		if(x+y+t&1) {puts("NO");return 0;}
		a[i]=(Node) {(x+y+t)/2,(y-x+t)/2,t/m,t%m}; 
		if(a[i].x<0 || a[i].y<0) {puts("NO");return 0;}
	}a[++n]=(Node) {0,0,-1,m};sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		ll x=a[i].x-a[i-1].x,y=a[i].y-a[i-1].y,vl1,vl2;
		vl1=a[i].vl1-a[i-1].vl1;vl2=a[i].vl2-a[i-1].vl2;
		if(vl1>0)
		{
			LX=max(LX,div2(x-vl2,vl1));RX=min(RX,div1(x,vl1));
			LY=max(LY,div2(y-vl2,vl1));RY=min(RY,div1(y,vl1));
		}
		else if(vl1<0)
		{
			LX=max(LX,div2(x,vl1));RX=min(RX,div1(x-vl2,vl1));
			LY=max(LY,div2(y,vl1));RY=min(RY,div1(y-vl2,vl1));
		}
		else if(x-vl2>0 || x<0 || y-vl2>0 || y<0)
		{puts("NO");return 0;}
	}if(LX>RX || LY>RY) {puts("NO");return 0;}
	for(int i=1;i<=n;++i)
	{
		ll x,y,nwX=0,nwY=0;
		x=a[i].x-a[i-1].x-LX*(a[i].vl1-a[i-1].vl1);
		y=a[i].y-a[i-1].y-LY*(a[i].vl1-a[i-1].vl1);
		for(int j=a[i-1].vl2;j<a[i].vl2;++j)
			if(nwX<x)
			{
				if(nwY<y) putchar('U'),++nwY;
				else putchar('R');++nwX;
			}
			else
			{
				if(nwY<y) putchar('L'),++nwY;
				else putchar('D');
			}
	}return 0;
}