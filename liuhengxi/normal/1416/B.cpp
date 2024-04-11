#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e4+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int T,n,a[N],sum;
int main()
{
	read(T);
	while(T--)
	{
		read(n);
		sum=0;
		F(i,0,n)read(a[i]),sum+=a[i];
		if(sum%n)puts("-1");
		else
		{
			printf("%d\n",3*n-3);
			F(i,1,n)
			{
				printf("%d %d %d\n",1,i+1,(i+1-a[i]%(i+1))%(i+1));
				printf("%d %d %d\n",i+1,1,(a[i]+i)/(i+1));
			}
			F(i,1,n)printf("%d %d %d\n",1,i+1,sum/n);
		}
	}
	return 0;
}