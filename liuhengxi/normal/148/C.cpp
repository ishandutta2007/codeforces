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
int n,a,b,ans[N];
int main()
{
	read(n);read(a);read(b);
	if(n!=1&&a==n-1)return puts("-1"),0;
	if(b==0)
	{
		F(i,0,n-a-1)ans[i]=100;
		F(i,n-a-1,n)ans[i]=101+i-n+a;
	}
	else
	{
		F(i,0,b+1)ans[i]=1<<i;
		F(i,b+1,a+b+1)ans[i]=ans[i-1]+1;
		F(i,a+b+1,n)ans[i]=1;
	}
	F(i,0,n)printf("%d ",ans[i]);
	puts("");
	return 0;
}