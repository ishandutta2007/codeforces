#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n;
long long sum,ans[N],tmp;
int main()
{
	read(n);
	F(i,0,n)
	{
		long long x;read(x);sum+=x;
	}
	F(i,1,n-1)sum-=i;
	tmp=sum/n;
	ans[0]=tmp;
	F(i,1,n)ans[i]=tmp+i-1;
	F(i,1,sum%n+1)++ans[i];
	F(i,0,n)printf("%lld ",ans[i]);
	puts("");
	return 0;
}