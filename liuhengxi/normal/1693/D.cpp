#include<cstdio>
#include<algorithm>
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
int n,p[N],f[N],g[N];
long long ans;
int main()
{
	read(n);
	F(i,0,n)--read(p[i]);
	for(int i=n,k=n-1;~--i;)
	{
		f[i]=n;g[i]=-1;
		for(int j=i+1;j<n;++j)
		{
			int lf=f[j],lg=g[j];
			f[j]=-1;g[j]=n;
			if(p[j]>p[j-1])f[j]=max(f[j],f[j-1]);
			if(j==i+1||(f[j-2]>p[j-1]&&p[j-2]<p[j])||(g[j-2]<p[j]&&p[j-2]>p[j-1]))f[j]=max(f[j],p[j-1]);
			if(p[j]<p[j-1])g[j]=min(g[j],g[j-1]);
			if(j==i+1||(g[j-2]<p[j-1]&&p[j-2]>p[j])||(f[j-2]>p[j]&&p[j-2]<p[j-1]))g[j]=min(g[j],p[j-1]);
			if(f[j]==lf&&g[j]==lg)break;
		}
		while(f[k]==-1&&g[k]==n)--k;
		ans+=k-i+1;
	}
	printf("%lld\n",ans);
	return 0;
}