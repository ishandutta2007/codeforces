#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t;
int main()
{
	read(t);
	while(t--)
	{
		int n,k,l1,r1,l2,r2,ak,a,b;
		long long now=0,ans=LLINF,c=0;
		read(n);read(k);read(l1);read(r1);read(l2);read(r2);
		if(l1>l2)
		{
			l1^=l2^=l1^=l2;
			r1^=r2^=r1^=r2;
		}
		if(r1<l2)ak=0,a=l2-r1,b=r2-l1;
		else if(r1<r2)ak=r1-l2,a=0,b=r2-r1+l2-l1;
		else ak=r2-l2,a=0,b=r1-r2+l2-l1;
		c=(long long)ak*n;
		if(c>k)ans=0;
		else
		F(i,0,n)
		{
			now+=a;
			if(k-c<b)
			{
				if(now+k-c<ans)ans=now+k-c;
			}
			else
			{
				c+=b;now+=b;
				if(c>k)c=k;
				if(now+2*(k-c)<ans)ans=now+2*(k-c);
				if(c==k)break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}