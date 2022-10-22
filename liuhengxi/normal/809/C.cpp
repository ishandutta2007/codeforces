#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define ctz(x) (x?__builtin_ctz(x):32)
#define lg2(x) (31-__builtin_clz(x))
using namespace std;
const int N=65,MOD=1000000007;
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
int q,a[N],b[N],la[N],lb[N],n,m;
int main()
{
	read(q);
	while(q--)
	{
		int xl,yl,xr,yr,k,ans=0;
		read(xl,yl,xr,yr,k);
		--xl,--yl;
		for(a[n=0]=xl;xl<xr;a[++n]=xl)xl+=1<<min(ctz(xl),lg2(xr-xl));
		for(b[m=0]=yl;yl<yr;b[++m]=yl)yl+=1<<min(ctz(yl),lg2(yr-yl));
		F(i,0,n)la[i]=a[i+1]-a[i];
		F(i,0,m)lb[i]=b[i+1]-b[i];
		F(i,0,n)F(j,0,m)
		{
			int cnt=min(la[i],lb[j]),len=max(la[i],lb[j]);
			int bas=(a[i]^b[j])&-len;
			len=min(len,max(k-bas,0));
			if(len)ans=(int)((ans+(len*(1ll+bas+bas+len)>>1)%MOD*cnt)%MOD);
		}
		printf("%d\n",ans);
	}
	return 0;
}