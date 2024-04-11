#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,len;
int x[N],y[N];
string s;
int d[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
inline int calc(int x0,int y0)
{
	int res=0;
	register int i;
	for(i=1;i<=n;i++)
		if(x[i]<=x0&&y[i]<=y0)
			res=max(res,max(x0-x[i],y0-y[i]));
		else if(x[i]<=x0&&y[i]>y0)
			res=max(res,(x0-x[i]+y[i]-y0));
		else if(x[i]>x0&&y[i]<=y0)
			res=max(res,(x[i]-x0+y0-y[i]));
		else
			res=max(res,max(x[i]-x0,y[i]-y0));
	return res;
}
signed main()
{
	int flag;
	register int i,j;
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(char j:s)
			if(j=='N')
				x[i]++;
			else
				y[i]++;
		len=max(len,x[i]+y[i]);
	}
	int xl=0,xr=1000000,yl=0,yr=1000000;
	int midx[2],midy[2],val[4],ttt,dddd;
	int ans=1e9,dx,dy;
	if(n*len*len<=100000000)
	{
		for(i=0;i<=len;i++)
			for(j=0;j<=len;j++)
				if(calc(i,j)<ans)
					ans=calc(i,j),dx=i,dy=j;
		goto end;
	}
	while(n*(xr-xl+1)*(yr-yl+1)>100000000)
	{
		midx[0]=(xl*2+xr)/3;midx[1]=(xl+xr*2)/3;
		midy[0]=(yl*2+yr)/3;midy[1]=(yl+yr*2)/3;
		ttt=1e9;dddd=-1;
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				if(calc(midx[i],midy[j])<ttt)
					ttt=calc(midx[i],midy[j]),dddd=i*2+j;
		switch(dddd)
		{
			case 0:xr=midx[1];yr=midy[1];break;
			case 1:xr=midx[1];yl=midy[0];break;
			case 2:xl=midx[0];yr=midy[1];break;
			case 3:xl=midx[0];yl=midy[0];break;
		}
	}
	for(i=xl;i<=xr;i++)
		for(j=yl;j<=yr;j++)
			if(calc(i,j)<ans)
				ans=calc(i,j),dx=i,dy=j;
	end:;
	if(dx+dy==0)
	{
		ans=1e9;
		for(i=0;i<=2;i++)
			for(j=0;j<=2;j++)
				if((i||j)&&calc(i,j)<ans)
					ans=calc(i,j),dx=i,dy=j;
	}
	cout<<ans<<endl;
	for(i=1;i<=dx;i++)
		cout<<'N';
	for(j=1;j<=dy;j++)
		cout<<'B';
	cout<<endl;
	return 0;
}