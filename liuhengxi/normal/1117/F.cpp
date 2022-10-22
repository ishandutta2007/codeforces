#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,K=17;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,p,a[N],g[K][K],nxt[K],tmp[K],sum[1<<K],ans,c[K],b[1<<K];
bool f[1<<K];
char s[N];
int main()
{
	read(n,p);
	scanf("%s",s);
	F(i,0,n)++c[a[i]=s[i]-'a'];
	F(i,0,p)F(j,0,p)read(g[i][j]);
	F(i,0,p)nxt[i]=n;
	for(int i=n;~--i;)
	{
		int mask=0;
		F(j,0,p)tmp[j]=nxt[j];
		sort(tmp,tmp+p);
		F(j,0,p)if(tmp[j]<n)
		{
			if(!g[a[i]][a[tmp[j]]])
			{
				++b[mask];
				--b[mask|(1<<a[i])];
				--b[mask|(1<<a[tmp[j]])];
				++b[mask|(1<<a[i])|(1<<a[tmp[j]])];
			}
			mask=mask|(1<<a[tmp[j]]);
		}
		nxt[a[i]]=i;
	}
	for(int j=1<<(p-1);j;j>>=1)F(i,0,1<<p)if(!(i&j))b[i|j]+=b[i];
	f[0]=true;
	F(i,0,1<<p)if(!b[i])F(j,0,p)f[i]=f[i]||f[i&~(1<<j)];
	F(i,1,1<<p)
	{
		sum[i]=sum[i^(i&-i)]+c[__builtin_ctz(i)];
		if(f[i]&&sum[i]>ans)ans=sum[i];
	}
	printf("%d\n",n-ans);
	return 0;
}