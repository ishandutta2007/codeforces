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
int t,n,ans;
int main()
{
	read(t);
	while(t--)
	{
		read(n);
		ans=(n+3)/4;
		F(i,0,n-ans)putchar('9');
		F(i,0,ans)putchar('8');
		putchar('\n');
	}
	return 0;
}