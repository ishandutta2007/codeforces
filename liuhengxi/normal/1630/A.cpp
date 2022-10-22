#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=(1<<16)+5;
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
int tt,n,k;
int main()
{
	read(tt);
	while(tt--)
	{
		int all;
		read(n,k);
		all=n-1;
		if(k==0)
		{
			F(i,0,n>>1)printf("%d %d\n",i,i^all);
		}
		else if(k<n-1)
		{
			F(i,0,n)
			{
				int j;
				if(i==k)j=all;
				else if(i==all)j=k;
				else if(i==0)j=k^all;
				else if(i==(k^all))j=0;
				else j=i^all;
				if(i<j)printf("%d %d\n",i,j);
			}
		}
		else if(n==4)puts("-1");
		else
		{
			printf("%d %d\n",1,3);
			printf("%d %d\n",n-2,n-1);
			F(i,0,n>>1)
			{
				int j=0;
				if(i!=1&&i!=3)
				{
					if(i==0)j=n-4;
					else if(i==2)j=n-3;
					else j=i^all;
					printf("%d %d\n",i,j);
				}
			}
		}
	}
	return 0;
}