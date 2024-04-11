#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int n;
namespace suffixarray
{
	int m=26,rk[2*N],nrk[N],cnt[N],id[N],sa[N],nsa[N],height[N];
	char s[N];
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
using suffixarray::getsa;
using suffixarray::getheight;
using suffixarray::sa;
using suffixarray::rk;
using suffixarray::height;
struct st
{
	const static int N=2e5+5,LogN=20;
	int n,a[LogN][N],log[N];
	void build(int *b,int n)
	{
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
int q,sqrtn,id[N],f[N<<1],val[N<<1],ind,fa[N<<1],k,l,a[N],b[N],c[N<<1],d[N<<1];
long long ans;
bool cmp(int u,int v){return height[u]>height[v];}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int query(int x,int y)
{
	if(x==y)return n-x;
	x=rk[x],y=rk[y];
	if(x<y)return t.query(x,y);
	return t.query(y,x);
}
void buildtree()
{
	F(i,1,n)id[i]=i;
	sort(id+1,id+n,cmp);
	F(i,0,n<<1)f[i]=i;
	F(i,0,n)val[i]=n-i;
	ind=n;
	F(i,1,n)
	{
		fa[find(sa[id[i]-1])]=fa[find(sa[id[i]])]=ind;
		f[find(sa[id[i]-1])]=f[find(sa[id[i]])]=ind;
		val[ind++]=height[id[i]];
	}
}
int main()
{
	read(n,q);
	while(sqrtn*sqrtn<n)++sqrtn;
	scanf("%s",s);
	getsa();getheight();buildtree();
	fa[ind-1]=ind;
	t.build(height+1,n);
	while(q--)
	{
		ans=0;
		read(k,l);
		F(i,0,k)--read(a[i]);
		F(i,0,l)--read(b[i]);
		if(k<sqrtn&&l<sqrtn)
		{
			F(i,0,k)F(j,0,l)ans+=query(a[i],b[j]);
		}
		else
		{
			F(i,0,n<<1)c[i]=d[i]=0;
			F(i,0,k)++c[a[i]];
			F(i,0,l)++d[b[i]];
			F(i,0,ind)
			{
				c[fa[i]]+=c[i];
				d[fa[i]]+=d[i];
				ans+=(long long)c[i]*d[i]*(val[i]-val[fa[i]]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}