#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=100;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int k,n;
long long p,ans[N];
int main()
{
	read(p);read(k);
	ans[0]=p;
	for(;ans[n];++n)
	{
		long long tmp;
		if(ans[n]>0)tmp=ans[n]/k;
		else tmp=-(-ans[n]+k-1)/k;
		ans[n]-=k*tmp;
		ans[n+1]-=tmp;
	}
	printf("%d\n",n);
	F(i,0,n)printf("%lld ",ans[i]);
	puts("");
	return 0;
}