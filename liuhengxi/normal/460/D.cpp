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
long long l,r,a,b,c;
int k;
bool find3()
{
	a=1;
	while(a<l)a<<=1,a|=1;
	b=(a<<1)^a^1^(a>>1);
	c=a^b;
	return c<=r;
}
int main()
{
	read(l);read(r);read(k);
	if(k==1)printf("%lld\n1\n%lld\n",l,l);
	else if(k==2)
	{
		if(!(l&1))printf("1\n2\n%lld %lld\n",l,l+1);
		else if(r-l!=1)printf("1\n2\n%lld %lld\n",l+1,l+2);
		else if((l^(l+1))<l)printf("%lld\n2\n%lld\n%lld\n",l^(l+1),l,l+1);
		else printf("%lld\n1\n%lld\n",l,l);
	}
	else if(k==3)
	{
		if(find3())printf("0\n3\n%lld %lld %lld\n",a,b,c);
		else if(!(l&1))printf("1\n2\n%lld %lld\n",l,l+1);
		else printf("1\n2\n%lld %lld\n",l+1,l+2);
	}
	else if(k>=4)
	{
		if(!(l&1))printf("0\n4\n%lld %lld %lld %lld\n",l,l+1,l+2,l+3);
		else if(r-l!=3)printf("0\n4\n%lld %lld %lld %lld\n",l+1,l+2,l+3,l+4);
		else if(find3())printf("0\n3\n%lld %lld %lld\n",a,b,c);
		else if(!(l&1))printf("1\n2\n%lld %lld\n",l,l+1);
		else printf("1\n2\n%lld %lld\n",l+1,l+2);
	}
	return 0;
}