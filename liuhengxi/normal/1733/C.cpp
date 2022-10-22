#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=1e5+5;
int tt,n,a[N],x[N],y[N],m,pos[N],cnt;
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,0,n)read(a[i]);
		m=0;cnt=0;
		F(i,0,n)if((a[i]&1)==(a[0]&1))pos[cnt++]=i;
		for(int i=cnt-1;~--i;)
		{
			x[m]=pos[i];y[m]=pos[i+1];
			++m;
		}
		F(i,0,n)if((a[i]^a[0])&1)
		{
			x[m]=0;y[m]=i;
			++m;
		}
		printf("%d\n",m);
		F(i,0,m)printf("%d %d\n",x[i]+1,y[i]+1);
	}
	return 0;
}