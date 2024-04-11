#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
const long long LLINF=0x3fffffffffffffff;
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
int tt,n,a[N];
long long ans;
int main()
{
	read(tt);
	while(tt--)
	{
		long long t=0,b=0;
		read(n);
		F(i,0,n)read(a[i]);
		sort(a,a+n);
		ans=-LLINF;
		F(i,1,n)t-=a[0]+a[i],b+=a[0]*(long long)a[i];
		if(t<0)ans=LLINF;
		else ans=max(ans,t*a[0]+b);
		F(i,1,n)
		{
			ans=max(ans,t*a[i-1]+b);
			ans=max(ans,t*a[i]+b);
			if(i!=n-1)
			{
				t+=a[0]-a[n-1];
				b+=(a[n-1]-a[0])*(long long)a[i];
			}
		}
		if(t>0)ans=LLINF;
		else ans=max(ans,t*a[n-1]+b);
		if(ans==LLINF)puts("INF");
		else printf("%lld\n",ans);
	}
	return 0;
}