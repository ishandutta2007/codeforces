#include<cstdio>
#include<algorithm>
#include<functional>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,MOD=1e9+7;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int T,n,p,k[N];
int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		b>>=1;(a*=a)%=MOD;
	}
	return (int)c;
}
int main()
{
	read(T);
	while(T--)
	{
		int a=0,b=0;/*(a*p^b)*/
		read(n);read(p);
		F(i,0,n)read(k[i]);
		if(p==1)
		{
			printf("%d\n",n&1);
			continue;
		}
		sort(k,k+n,greater<int>());
		F(i,0,n)
		{
			if(~b)
			{
				if(a)
				{
					while(b>k[i])
					{
						if(a*(long long)p>n)
						{
							a=a*(long long)pow(p,b)%MOD;
							b=-1;
							break;
						}
						a*=p;
						--b;
					}
					if(~b)--a;
				}
				else
				{
					a=1;b=k[i];
				}
			}
			if(!~b)(a+=MOD-pow(p,k[i]))%=MOD;
		}
		if(~b)a=a*(long long)pow(p,b)%MOD;
		printf("%d\n",a);
	}
	return 0;
}