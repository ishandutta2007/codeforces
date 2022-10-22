#include<cstdio>
#include<algorithm>
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
int tt,n,x,y;
int main()
{
	read(tt);
	while(tt--)
	{
		read(n,x,y);
		if(x>y)swap(x,y);
		if(x&&y)puts("-1");
		else if(x==0&&y==0)puts("-1");
		else if((n-1)%y)puts("-1");
		else
		{
			F(i,0,n-1)printf("%d ",i/y*y+2);
			puts("");
		}
	}
	return 0;
}