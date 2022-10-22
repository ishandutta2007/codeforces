#include<cstdio>
#include<cmath>
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
int tt,R,r,k;
double a,b,d,mid;
int main()
{
	read(tt);
	while(tt--)
	{
		read(R,r,k);
		a=1.0/R,b=1.0/r;d=(b-a)/2.0;
		mid=sqrt(((a+b)/2.0)*((a+b)/2.0)+((b-a)*k)*((b-a)*k));
		printf("%.8lf\n",1.0/(mid-d)-1.0/(mid+d));
	}
	return 0;
}