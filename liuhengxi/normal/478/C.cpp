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
int a,b,c,ans;
void sort()
{
	if(a<b)a^=b^=a^=b;
	if(b<c)b^=c^=b^=c;
	if(a<b)a^=b^=a^=b;
}
int main()
{
	int tmp;
	read(a);read(b);read(c);
	sort();
	tmp=a-b<b-c?a-b:b-c;
	a-=2*tmp;b-=tmp;ans+=tmp;
	sort();
	if(b==c)
	{
		tmp=(a-c)/3<c?(a-c)/3:c;
		a-=4*tmp;
		b-=tmp;
		c-=tmp;
		ans+=2*tmp;
		if(a-c==2&&c)a-=2,--c,++ans;
	}
	else
	{
		tmp=(a-c)/3;
		ans+=2*tmp;
		a-=3*tmp;b-=3*tmp;
		if(a-c==2)--a,b-=2,++ans;
	}
	ans+=c;
	printf("%d\n",ans);
	return 0;
}