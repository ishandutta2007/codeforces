#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int x0,y00,ax,ay,bx,by;
int xs,ys,t,ans;
struct point
{
	int x,y;
}d[N],st;
int n;
int dis(point a,point b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}
main()
{
    x0=read(),y00=read(),ax=read(),ay=read(),bx=read(),by=read();
	xs=read(),ys=read(),t=read();

	int xn=x0,yn=y00;
	while(xn<=2e16&&yn<=2e16)
	{
		d[++n].x=xn,d[n].y=yn;
		xn=xn*ax+bx,yn=yn*ay+by;
	}
	st.x=xs,st.y=ys;
	for(int i=1;i<=n;i++) //start
	{
		int cur=dis(st,d[i]);
		if(cur>t) continue ;
		int tmp=1;
		for(int j=i-1;j>=1;j--)
		{
			cur+=dis(d[j+1],d[j]);
			if(cur>t) break ;
			tmp++;
		}
		ans=max(ans,tmp);
	}

	for(int i=1;i<=n;i++) //start
	{
		int cur=dis(st,d[i]);
		if(cur>t) continue ;
		int tmp=1;
		for(int j=i+1;j<=n;j++)
		{
			cur+=dis(d[j-1],d[j]);
			if(cur>t) break ;
			tmp++;
		}
		ans=max(ans,tmp);
	}

	cout<<ans<<endl;
}