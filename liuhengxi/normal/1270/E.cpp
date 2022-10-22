#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e3+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,x[N],y[N],a;
int main()
{
	read(n);
	F(i,0,n)read(x[i]),read(y[i]);
	while(true)
	{
		a=0;
		F(i,0,n)a+=(x[i]^y[i])&1;
		if(a!=0&&a!=n)break;
		F(i,0,n)
		{
			int xx=(x[i]+y[i])>>1,yy=(x[i]-y[i])>>1;
			x[i]=xx;y[i]=yy;
		}
	}
	printf("%d\n",a);
	F(i,0,n)if((x[i]^y[i])&1)printf("%d ",i+1);
	puts("");
	return 0;
}