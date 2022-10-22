#include<cstdio>
#include<algorithm>
#include<functional>
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
constexpr int N=1e5+5;
int tt,n,m1,m2,a[N],b[N],a1[N],a2[N];
long long ans;
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		m1=m2=0;
		F(i,0,n)read(a[i]);
		F(i,0,n)read(b[i]);
		F(i,0,n)
		{
			if(a[i])a1[m1++]=b[i];
			else a2[m2++]=b[i];
		}
		sort(a1,a1+m1,greater<int>());
		sort(a2,a2+m2,greater<int>());
		ans=0;
		if(m1==m2)
		{
			F(i,0,m1)ans+=2ll*a1[i]+2ll*a2[i];
			ans-=min(a1[m1-1],a2[m1-1]);
		}
		else
		{
			F(i,0,n)ans+=b[i];
			F(i,0,min(m1,m2))ans+=a1[i]+a2[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}