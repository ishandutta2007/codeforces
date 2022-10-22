#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define v(x) (x==n-1?1:1<<(n-x-2))
using namespace std;
const int M=496;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int l,r,x,n=2,m,u[M],v[M],w[M];
bool one;
inline void adline(int a,int b,int c){u[m]=a,v[m]=b,w[m++]=c;}
int main()
{
	read(l,r);
	if(l==1)one=true,++l;
	x=r-l+1;
	for(int y=x;y;y>>=1)++n;
	for(int i=n;--i;)F(j,i+1,n)adline(i,j,v(j));
	for(int i=n-2,j=1;j<=x;j<<=1,--i)if(x&j)adline(0,i,l-1),l+=j;
	if(one)adline(0,n-1,1);
	puts("YES");
	printf("%d %d\n",n,m);
	F(i,0,m)printf("%d %d %d\n",u[i]+1,v[i]+1,w[i]);
	return 0;
}