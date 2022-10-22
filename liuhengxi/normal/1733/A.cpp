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
constexpr int N=105;
int tt,n,k,a[N];
int main()
{
	read(tt);
	while(tt--)
	{
		long long ans=0;
		read(n,k);
		F(i,0,k)read(a[i]);
		F(i,k,n)
		{
			int x;read(x);
			a[i%k]=max(a[i%k],x);
		}
		F(i,0,k)ans+=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}