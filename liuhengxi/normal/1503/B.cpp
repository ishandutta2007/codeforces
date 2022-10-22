#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=110;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,xa[N*N/2],ya[N*N/2],xb[N*N/2],yb[N*N/2],cnt1,cnt2;
int main()
{
	read(n);
	F(i,0,n)F(j,0,n)
		if((i^j)&1)xa[cnt1]=i+1,ya[cnt1++]=j+1;
		else xb[cnt2]=i+1,yb[cnt2++]=j+1;
	F(i,0,n*n)
	{
		int a;
		read(a);
		if(a==1)
		{
			if(cnt1)
			{
				--cnt1;
				printf("3 %d %d\n",xa[cnt1],ya[cnt1]);
			}
			else
			{
				--cnt2;
				printf("2 %d %d\n",xb[cnt2],yb[cnt2]);
			}
		}
		else
		{
			if(cnt2)
			{
				--cnt2;
				printf("1 %d %d\n",xb[cnt2],yb[cnt2]);
			}
			else
			{
				--cnt1;
				printf("%d %d %d\n",5-a,xa[cnt1],ya[cnt1]);
			}
		}
		fflush(stdout);
	}
	return 0;
}