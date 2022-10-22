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
int n,m,c,a[N],p,cnt;
int main()
{
	read(n);read(m);read(c);
	while(cnt<n)
	{
		read(p);
		if(p<=c/2)
		{
			F(i,0,n)
			{
				if(!a[i])
				{
					++cnt;
					a[i]=p;
					printf("%d\n",i+1);
					break;
				}
				if(p<a[i])
				{
					a[i]=p;
					printf("%d\n",i+1);
					break;
				}
			}
		}
		else
		{
			for(int i=n-1;~i;--i)
			{
				if(!a[i])
				{
					++cnt;
					a[i]=p;
					printf("%d\n",i+1);
					break;
				}
				if(p>a[i])
				{
					a[i]=p;
					printf("%d\n",i+1);
					break;
				}
			}
		}
		fflush(stdout);
	}
	return 0;
}