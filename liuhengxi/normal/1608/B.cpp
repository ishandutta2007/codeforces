#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int tt,n,a,b,p[N];
int main()
{
	read(tt);
	while(tt--)
	{
		bool fsb=false;
		read(n,a,b);
		if(max(a,b)-min(a,b)>1)puts("-1");
		else
		{
			int c=-1,d=1;
			p[0]=0;
			if(a>b)
			{
				if(2*b+3>n)fsb=true;
				F(i,1,2*b+3)
				{
					if(i&1)p[i]=d++;
					else p[i]=c--;
				}
				F(i,2*b+3,n)
				{
					p[i]=c--;
				}
			}
			else if(a==b)
			{
				if(2*b+2>n)fsb=true;
				F(i,1,2*b+1)
				{
					if(i&1)p[i]=d++;
					else p[i]=c--;
				}
				F(i,2*b+1,n)
				{
					p[i]=d++;
				}
			}
			else if(a<b)
			{
				if(2*a+3>n)fsb=true;
				F(i,1,2*a+3)
				{
					if(i&1)p[i]=c--;
					else p[i]=d++;
				}
				F(i,2*a+3,n)
				{
					p[i]=d++;
				}
			}
			F(i,0,n)p[i]-=c;
			if(fsb)puts("-1");
			else
			{
				F(i,0,n)printf("%d ",p[i]);
				puts("");
			}
		}
	}
	return 0;
}