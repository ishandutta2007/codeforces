#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m;
int main()
{
	int t=0,ans=0;
	read(n);read(m);
	if(n>m)ans=n-m;
	else
	{
		while(n<m)n<<=1,++t;
		n-=m;
		F(i,0,ans=t)
		{
			ans+=(n&1);
			n>>=1;
		}
		ans+=n;
	}
	printf("%d\n",ans);
	return 0;
}