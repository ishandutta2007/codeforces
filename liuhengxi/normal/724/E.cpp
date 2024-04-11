#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e4+5;
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
int n,c,a[N],b[N];
long long f[N],g[N],ans=0x3f3f3f3f3f3f3f3f;
int main()
{
	memset(f,0x3f,sizeof f);
	read(n,c);
	F(i,0,n)read(a[i]);
	F(i,0,n)read(b[i]);
	f[0]=0;
	F(i,0,n)
	{
		memset(g,0x3f,sizeof g);
		F(j,0,i+1)
		{
			g[j]=min(g[j],f[j]+a[i]+(long long)j*c);
			g[j+1]=min(g[j+1],f[j]+b[i]);
		}
		memcpy(f,g,sizeof f);
	}
	F(i,0,n+1)ans=min(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}