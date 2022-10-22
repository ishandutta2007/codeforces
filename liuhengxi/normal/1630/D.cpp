#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,INF=0x3fffffff;
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
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int tt,n,a[N],m,b[N],s[N],mn[N];
int main()
{
	read(tt);
	while(tt--)
	{
		int g=0;
		long long ans1=0,ans2=0,sum=0,ans;
		read(n,m);
		F(i,0,n)read(a[i]),sum+=max(a[i],-a[i]);
		F(i,0,m)read(b[i]),g=gcd(g,b[i]);
		F(i,0,g)s[i]=1,mn[i]=INF;
		F(i,0,n)mn[i%g]=min(mn[i%g],max(a[i],-a[i])),a[i]<0&&(s[i%g]*=-1);
		F(i,0,g)if(s[i]==-1)ans1+=mn[i]<<1;
		F(i,0,g)s[i]*=-1;
		F(i,0,g)if(s[i]==-1)ans2+=mn[i]<<1;
		ans=sum-min(ans1,ans2);
		printf("%lld\n",ans);
	}
	return 0;
}