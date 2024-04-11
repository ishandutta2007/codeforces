#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2005,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,h,a[N],ans=1;
int main()
{
	read(n);read(h);
	F(i,1,n+1)
	{
		read(a[i]);a[i]=h-a[i];
		if(a[i]<0)return puts("0"),0;
	}
	F(i,1,n+1)
	{
		int dif=a[i]-a[i-1];
		if(dif==-1)ans=(long long)ans*a[i-1]%MOD;
		if(dif==0)ans=(long long)ans*(a[i-1]+1)%MOD;
		if(dif<-1||dif>1)ans=0;
	}
	printf("%d\n",ans*(int)(a[n]<2));
	return 0;
}