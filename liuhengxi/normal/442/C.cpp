#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5;
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
int n,a[N],m;
long long ans;
int main()
{
	read(n);
	for(int i=0,j=0;i<n;++i,m=++j)
	{
		read(a[j]);
		for(;j>=2&&a[j-2]>=a[j-1]&&a[j-1]<=a[j];a[j-1]=a[j],--j)ans+=min(a[j-2],a[j]);
	}
	sort(a,a+m);
	F(i,0,m-2)ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}