#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int T,a[4],b[4],x[4][4],y[4][4];
int main()
{
	read(T);
	while(T--)
	{
		int ans=-1;
		read(x[0][0]);read(y[0][0]);read(a[0]);read(b[0]);
		read(x[1][0]);read(y[1][0]);read(a[1]);read(b[1]);
		read(x[2][0]);read(y[2][0]);read(a[2]);read(b[2]);
		read(x[3][0]);read(y[3][0]);read(a[3]);read(b[3]);
		x[0][0]-=a[0];y[0][0]-=b[0];
		x[1][0]-=a[1];y[1][0]-=b[1];
		x[2][0]-=a[2];y[2][0]-=b[2];
		x[3][0]-=a[3];y[3][0]-=b[3];
		x[0][1]=-y[0][0];y[0][1]=x[0][0];
		x[0][2]=-y[0][1];y[0][2]=x[0][1];
		x[0][3]=-y[0][2];y[0][3]=x[0][2];
		x[1][1]=-y[1][0];y[1][1]=x[1][0];
		x[1][2]=-y[1][1];y[1][2]=x[1][1];
		x[1][3]=-y[1][2];y[1][3]=x[1][2];
		x[2][1]=-y[2][0];y[2][1]=x[2][0];
		x[2][2]=-y[2][1];y[2][2]=x[2][1];
		x[2][3]=-y[2][2];y[2][3]=x[2][2];
		x[3][1]=-y[3][0];y[3][1]=x[3][0];
		x[3][2]=-y[3][1];y[3][2]=x[3][1];
		x[3][3]=-y[3][2];y[3][3]=x[3][2];
		x[0][0]+=a[0];y[0][0]+=b[0];
		x[1][0]+=a[1];y[1][0]+=b[1];
		x[2][0]+=a[2];y[2][0]+=b[2];
		x[3][0]+=a[3];y[3][0]+=b[3];
		x[0][1]+=a[0];y[0][1]+=b[0];
		x[1][1]+=a[1];y[1][1]+=b[1];
		x[2][1]+=a[2];y[2][1]+=b[2];
		x[3][1]+=a[3];y[3][1]+=b[3];
		x[0][2]+=a[0];y[0][2]+=b[0];
		x[1][2]+=a[1];y[1][2]+=b[1];
		x[2][2]+=a[2];y[2][2]+=b[2];
		x[3][2]+=a[3];y[3][2]+=b[3];
		x[0][3]+=a[0];y[0][3]+=b[0];
		x[1][3]+=a[1];y[1][3]+=b[1];
		x[2][3]+=a[2];y[2][3]+=b[2];
		x[3][3]+=a[3];y[3][3]+=b[3];
		F(i0,0,4)F(i1,0,4)F(i2,0,4)F(i3,0,4)
		{
			int x0=x[0][i0],y0=y[0][i0];int x1=x[1][i1],y1=y[1][i1];
			int x2=x[2][i2],y2=y[2][i2];int x3=x[3][i3],y3=y[3][i3];
			bool ok=true;
			long long xx=x0-x1,yy=y0-y1;
			long long a=xx*xx+yy*yy;
			xx=x0-x2,yy=y0-y2;
			if(xx*xx+yy*yy<a)a=xx*xx+yy*yy;
			if(a==0)ok=false;
			xx=x0-x1,yy=y0-y1;
			if(xx*xx+yy*yy!=a&&xx*xx+yy*yy!=2*a)ok=false;
			xx=x0-x2,yy=y0-y2;
			if(xx*xx+yy*yy!=a&&xx*xx+yy*yy!=2*a)ok=false;
			xx=x0-x3,yy=y0-y3;
			if(xx*xx+yy*yy!=a&&xx*xx+yy*yy!=2*a)ok=false;
			xx=x1-x0,yy=y1-y0;
			if(xx*xx+yy*yy!=a&&xx*xx+yy*yy!=2*a)ok=false;
			xx=x1-x2,yy=y1-y2;
			if(xx*xx+yy*yy!=a&&xx*xx+yy*yy!=2*a)ok=false;
			xx=x1-x3,yy=y1-y3;
			if(xx*xx+yy*yy!=a&&xx*xx+yy*yy!=2*a)ok=false;
			xx=x2-x0,yy=y2-y0;
			if(xx*xx+yy*yy!=a&&xx*xx+yy*yy!=2*a)ok=false;
			xx=x2-x1,yy=y2-y1;
			if(xx*xx+yy*yy!=a&&xx*xx+yy*yy!=2*a)ok=false;
			xx=x2-x3,yy=y2-y3;
			if(xx*xx+yy*yy!=a&&xx*xx+yy*yy!=2*a)ok=false;
			xx=x3-x0,yy=y3-y0;
			if(xx*xx+yy*yy!=a&&xx*xx+yy*yy!=2*a)ok=false;
			xx=x3-x1,yy=y3-y1;
			if(xx*xx+yy*yy!=a&&xx*xx+yy*yy!=2*a)ok=false;
			xx=x3-x2,yy=y3-y2;
			if(xx*xx+yy*yy!=a&&xx*xx+yy*yy!=2*a)ok=false;
			if(ok&&(i0+i1+i2+i3<ans||ans==-1))ans=i0+i1+i2+i3;
		}
		printf("%d\n",ans);
	}
	return 0;
}