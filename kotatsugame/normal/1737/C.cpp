#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,x,y;
		int r[3],c[3];
		cin>>N;
		for(int i=0;i<3;i++)cin>>r[i]>>c[i];
		cin>>x>>y;
		while(true)
		{
			int er=0,ec=0;
			for(int i=0;i<3;i++)er^=r[i],ec^=c[i];
			if(er==max({r[0],r[1],r[2]})&&ec==max({c[0],c[1],c[2]}))break;
			for(int i=0;i<3;i++)
			{
				int nr=c[i],nc=N+1-r[i];
				r[i]=nr,c[i]=nc;
			}
			{
				int nx=y,ny=N+1-x;
				x=nx,y=ny;
			}
		}
		int er=0,ec=0;
		for(int i=0;i<3;i++)er^=r[i],ec^=c[i];
		if(er==2&&ec==2)
		{
			cout<<(x==1||y==1?"YES\n":"NO\n");
		}
		else
		{
			int dx=er-x,dy=ec-y;
			dx%=2;
			dy%=2;
			cout<<(dx==0&&dy==0?"NO\n":"YES\n");
		}
	}
}