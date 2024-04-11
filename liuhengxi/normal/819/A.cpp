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
int a,b,l,r,ans;
int main()
{
	read(a);read(b);read(l);read(r);--l;
	if(r-l>=2*(a+b))
	{
		if(a>b)ans=2*a-b;
		else ans=a+1;
	}
	else if(r-l>=a+b)
	{
		int len1=a+b-l%(a+b),len2=r%(a+b);
		if(r/(a+b)-l/(a+b)==1)
		{
			if(len1<=b)ans=len2+1;
			else
			{
				if(a>b)
				{
					ans=len1-b+(len2<b?len2:b);
					ans=ans<a?ans:a;
					if(len2>b)ans+=(len2<a?len2:a)-b;
				}
				else ans=a;
			}
		}
		else
		{
			if(a>b)
			{
				if(len1<=b)len1=a+1;
				else if(len1<=a)len1=a+len1-b;
				else len1=2*a-b;
				if(len2<=b)len2=a;
				else if(len2<=a)len2=len2-b+a;
				else len2=2*a-b;
				ans=len1>len2?len1:len2;
			}
			else ans=a+1;
		}
	}
	else
	{
		if(l%(a+b)<a)
		{
			if(r%(a+b)>=a)ans=a-l%(a+b);
			else if(r/(a+b)==l/(a+b))ans=r-l;
			else ans=r-l-b;
		}
		else
		{
			if(r/(a+b)==l/(a+b))ans=1;
			else if(r%(a+b)<a)ans=r%(a+b)+1;
			else ans=a+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}