#include<cstdio>
#include<cmath>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,x[N],y[N];
int main()
{
	read(t);
	while(t--)
	{
		int a=0,b=0;
		double ans=0.0;
		read(n);
		F(i,0,2*n)
		{
			int xx,yy;read(xx);read(yy);
			if(xx==0)y[b++]=yy>0?yy:-yy;
			if(yy==0)x[a++]=xx>0?xx:-xx;
		}
		sort(x,x+n);sort(y,y+n);
		F(i,0,n)ans+=sqrt((double)x[i]*x[i]+(double)y[i]*y[i]);
		printf("%0.13lf\n",ans);
	}
	return 0;
}