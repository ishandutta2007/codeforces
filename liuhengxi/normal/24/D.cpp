#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,x,y;
double f[N],b[N],c[N][N];
#define debug F(i,0,m){F(j,0,m)printf("%2.2lf ",c[i][j]);printf(" | %2.2lf\n",b[i]);}
int main()
{
	read(n);read(m);read(x);read(y);
	x=n-x;--y;
	if(m==1)return printf("%lf\n",x*2.0),0;
	while(x--)
	{
		b[0]=f[0]+3;
		F(i,1,m-1)b[i]=f[i]+4;
		b[m-1]=f[m-1]+3;
		c[0][0]=2;c[0][1]=-1;
		F(i,1,m-1)c[i][i-1]=c[i][i+1]=-1,c[i][i]=3;
		c[m-1][m-1]=2;c[m-1][m-2]=-1;
		F(i,0,m-1)
		{
			double coeff=c[i+1][i]/c[i][i];
			c[i+1][i]-=coeff*c[i][i];
			c[i+1][i+1]-=coeff*c[i][i+1];
			b[i+1]-=coeff*b[i];
		}
		for(int i=m-1;~i;--i)f[i]=(b[i]-c[i][i+1]*f[i+1])/c[i][i];
	}
	printf("%lf\n",f[y]);
	return 0;
}