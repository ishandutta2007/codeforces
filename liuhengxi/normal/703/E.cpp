#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005,M=7000,INF=0x3fffffff;
const long long LLINF=0x3fffffffffffffffll;
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
int n,m,c,l[13],pre[M],f[N][M],e[N][M],g[M];
long long p[13],s[N][M];
void factor(long long k)
{
	for(long long i=2;i*i<=k;++i)if(k%i==0)
	{
		while(k%i==0)k/=i,++l[c];
		p[c++]=i;
	}
	if(k!=1)l[c]=1,p[c++]=k;
}
long long k,a[N],v[M];
int main()
{
	read(n,k);
	F(i,0,n)read(a[i]);
	if(k==1)
	{
		int ans=0;
		puts("1");
		F(i,0,n)if(a[i]<a[ans])ans=i;
		printf("%d\n",ans+1);
		return 0;
	}
	factor(k);
	m=1;v[0]=1;
	F(i,0,c)
	{
		F(j,m,m+m*l[i])v[j]=v[j-m]*p[i],pre[j]=j-m;
		m*=l[i]+1;
	}
	F(i,0,n+1)F(j,0,m)f[i][j]=INF,s[i][j]=LLINF;
	f[0][m-1]=0;s[0][m-1]=0;
	F(i,0,n)
	{
		F(j,0,m)
		{
			g[j]=j?g[pre[j]]+(a[i]%v[g[pre[j]]+j-pre[j]]?0:j-pre[j]):0;
			if(f[i+1][j-g[j]]>f[i][j]+1)f[i+1][j-g[j]]=f[i][j]+1;
			if(f[i+1][j]>f[i][j])f[i+1][j]=f[i][j];
		}
	}
	F(i,0,n)
	{
		F(j,0,m)
		{
			g[j]=j?g[pre[j]]+(a[i]%v[g[pre[j]]+j-pre[j]]?0:j-pre[j]):0;
			if(f[i+1][j-g[j]]==f[i][j]+1&&s[i+1][j-g[j]]>s[i][j]+a[i])s[i+1][j-g[j]]=s[i][j]+a[i],e[i+1][j-g[j]]=g[j];
			if(f[i+1][j]==f[i][j]&&s[i+1][j]>s[i][j])s[i+1][j]=s[i][j],e[i+1][j]=0;
		}
	}
	if(f[n][0]==INF)return puts("-1"),0;
	printf("%d\n",f[n][0]);
	for(int i=n,j=0;i;--i)
	{
		if(e[i][j])printf("%d ",i);
		j+=e[i][j];
	}
	puts("");
	return 0;
}