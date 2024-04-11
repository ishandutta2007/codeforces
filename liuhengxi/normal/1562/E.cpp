#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005;
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
struct st
{
	const static int N=5005,LogN=14;
	int n,a[LogN][N],log[N];
	void build(int *b,int n_)
	{
		n=n_;
		F(i,2,n+1)log[i]=log[i-1]+((i&-i)==i);
		F(i,0,n)a[0][i]=b[i];
		F(i,0,log[n])
		{
			int k=1<<i;
			F(j,0,n-(k<<1)+1)a[i+1][j]=min(a[i][j],a[i][j+k]);
		}
	}
	int query(int l,int r)
	{
		int k=log[r-l];
		return min(a[k][l],a[k][r-(1<<k)]);
	}
}t;
int n;
namespace suffixarray
{
	int m,rk[2*N],nrk[N],cnt[N],id[N],sa[N],nsa[N],height[N];
	char s[N];
	void clear()
	{
		#define c(x) memset(x,0,sizeof x)
		c(rk);c(nrk);c(cnt);c(id);c(sa);m=26;
	}
	void getsa()
	{
		int p;
		F(i,0,n)rk[i]=s[i]-'a';
		F(i,0,n)++cnt[rk[i]];
		F(i,1,m)cnt[i]+=cnt[i-1];
		F(i,0,n)sa[--cnt[rk[i]]]=i;
		for(int k=1;;k<<=1,m=p+1)
		{
			register int last1=0,last2=0;
			F(i,n,n+k)rk[i]=-1;
			p=-1;F(i,n-k,n)id[++p]=i;F(i,0,n)if(sa[i]>=k)id[++p]=sa[i]-k;
			F(i,0,m)cnt[i]=0;
			F(i,0,n)++cnt[rk[i]];
			F(i,1,m)cnt[i]+=cnt[i-1];
			for(register int i=n-1;~i;--i)nsa[--cnt[rk[id[i]]]]=id[i];
			F(i,0,n)sa[i]=nsa[i];
			nrk[sa[0]]=p=0;
			last1=rk[sa[0]];last2=rk[sa[0]+k];
			F(i,1,n)
			{
				nrk[sa[i]]=rk[sa[i]]==last1&&rk[sa[i]+k]==last2?p:++p;
				last1=rk[sa[i]];last2=rk[sa[i]+k];
			}
			F(i,0,n)rk[i]=nrk[i];
			if(p==n-1)break;
		}
	}
	void getheight()
	{
		int k=0;
		F(i,0,n)if(rk[i])
		{
			if(k)--k;
			while(s[i+k]==s[sa[rk[i]-1]+k])++k;
			height[rk[i]]=k;
		}else k=0;
	}
}
using suffixarray::s;
using suffixarray::rk;
int tt,f[N];
int main()
{
	read(tt);
	while(tt--)
	{
		int ans=0;
		suffixarray::clear();
		read(n);
		scanf("%s",s);
		suffixarray::getsa();
		suffixarray::getheight();
		t.build(suffixarray::height,n);
		F(i,0,n)
		{
			int len=n-i,lcp;
			f[i]=len;
			for(int j=i;~--j;)
			{
				lcp=t.query(min(rk[j],rk[i])+1,max(rk[j],rk[i])+1);
				if(rk[j]<rk[i])f[i]=max(f[i],f[j]+len-lcp);
			}
			ans=max(ans,f[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}