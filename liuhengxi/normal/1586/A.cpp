#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=105;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int tt,n,a[N],m,b[N];
bool isprime(int x)
{
	if(x<2)return false;
	for(int i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,0,n)read(a[i]);
		m=0;
		if(n<=5)
		{
			F(i,1,1<<n)
			{
				int sum=0,cnt=0;
				F(j,0,n)if(i>>j&1)sum+=a[j],++cnt;
				if(!isprime(sum)&&cnt>m)
				{
					m=0;
					F(j,0,n)if(i>>j&1)b[m++]=j+1;
				}
			}
		}
		else
		{
			int sum=0;
			F(i,0,n)sum+=a[i];
			if(!isprime(sum))
			{
				m=n;
				F(i,0,n)b[i]=i+1;
			}
			else
			{
				F(i,0,n)if(!isprime(sum-a[i]))
				{
					m=0;
					F(j,0,i)b[m++]=j+1;
					F(j,i+1,n)b[m++]=j+1;
				}
			}
		}
		printf("%d\n",m);
		F(i,0,m)printf("%d ",b[i]);
		puts("");
	}
	return 0;
}