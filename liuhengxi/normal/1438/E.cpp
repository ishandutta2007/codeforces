#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,a[N],ans;
int main()
{
	F(i,0,read(n))read(a[i]);
	F(i,0,n-2)
	{
		int sum=0,lim=a[i];
		lim|=lim>>1;lim|=lim>>2;lim|=lim>>4;lim|=lim>>8;lim|=lim>>16;
		F(j,i+1,n-1)
		{
			sum+=a[j];
			if(sum==(a[i]^a[j+1])&&a[i]>a[j+1])++ans;
			if(sum>lim)break;
		}
	}
	for(int i=n;i>=2;--i)
	{
		int sum=0,lim=a[i];
		lim|=lim>>1;lim|=lim>>2;lim|=lim>>4;lim|=lim>>8;lim|=lim>>16;
		for(int j=i;--j;)
		{
			sum+=a[j];
			if(sum==(a[i]^a[j-1])&&a[i]>a[j-1])++ans;
			if(sum>lim)break;
		}
	}
	printf("%d\n",ans);
	return 0;
}