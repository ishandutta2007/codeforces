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
int tt,n,m;
int main()
{
	read(tt);
	while(tt--)
	{
		read(n,m);
		if(m<n)
		{
			puts("No");
			continue;
		}
		if(n&1)
		{
			puts("Yes");
			F(i,0,n-1)printf("%d ",1);
			printf("%d\n",m-n+1);
		}
		else
		{
			if(m&1)
			{
				puts("No");
			}
			else
			{
				puts("Yes");
				F(i,0,n-2)printf("%d ",1);
				int a=(m-n+2)>>1;
				printf("%d %d\n",a,a);
			}
		}
	}
	return 0;
}