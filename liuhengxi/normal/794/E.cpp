#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=3e5+5;
int n,a[N],f[N];
int main()
{
	F(i,0,read(n))read(a[i]);
	F(i,0,n-1)
	{
		int k=max(i,n-2-i)-min(i,n-2-i);
		f[k]=max(f[k],max(a[i],a[i+1]));
	}
	F(i,1,n-1)
	{
		int k=max(i,n-1-i)-min(i,n-1-i);
		f[k]=max(f[k],min(a[i],max(a[i-1],a[i+1])));
	}
	F(i,0,n)f[n-1]=max(f[n-1],a[i]);
	F(i,0,n)
	{
		if(i>=2)f[i]=max(f[i],f[i-2]);
		printf("%d ",f[i]);
	}
	puts("");
	return 0;
}