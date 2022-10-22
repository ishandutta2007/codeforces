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
int a,b,c,d;
long long ans;
int main()
{
	read(a);read(b);read(c);read(d);
	if(b-a>c-b)
	{
		F(i,a+b,b+c+1)
		{
			long long x,y;
			if(i<c+a)x=i-a-b+1;
			else if(i<b+b)x=c-b+1;
			else x=b+c-i+1;
			y=i-1<d?i-1:d;
			y=y-c+1;
			if(y>0)ans+=x*y;
		}
	}
	else
	{
		F(i,a+b,b+c+1)
		{
			long long x,y;
			if(i<b+b)x=i-a-b+1;
			else if(i<c+a)x=b-a+1;
			else x=b+c-i+1;
			y=i-1<d?i-1:d;
			y=y-c+1;
			if(y>0)ans+=x*y;
		}
	}
	printf("%lld\n",ans);
	return 0;
}