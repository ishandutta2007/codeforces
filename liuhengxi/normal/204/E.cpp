#include<cstdio>
#include<algorithm>
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
constexpr int N=2e5+5;
int m;
namespace suffixarray
{
	int &n=::m,m=1.5e5,rk[2*N],nrk[N],cnt[N],id[N],sa[N],nsa[N],height[N];
	int s[N];
	void getsa()
	{
		int p;
		F(i,0,n)rk[i]=s[i];
		F(i,0,n)++cnt[rk[i]];
		F(i,1,m)cnt[i]+=cnt[i-1];
		F(i,0,n)sa[--cnt[rk[i]]]=i;
		for(int k=1;;k<<=1,m=p+1)
		{
			int last1=0,last2=0;
			F(i,n,n+k)rk[i]=-1;
			p=-1;F(i,n-k,n)id[++p]=i;F(i,0,n)if(sa[i]>=k)id[++p]=sa[i]-k;
			F(i,0,m)cnt[i]=0;
			F(i,0,n)++cnt[rk[i]];
			F(i,1,m)cnt[i]+=cnt[i-1];
			for(int i=n-1;~i;--i)nsa[--cnt[rk[id[i]]]]=id[i];
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
using suffixarray::sa;
using suffixarray::rk;
using suffixarray::height;
struct modify
{
	int l,r,x;
	friend bool operator<(modify a,modify b){return a.x>b.x;}
}d[N<<1];
int n,k,len[N],pos[N],q[N],qf,qr,last[N],bl[N],c[N],f,nxt[N],ans[N];
int find(int x){return nxt[x]==x?x:nxt[x]=find(nxt[x]);}
void solve()
{
	int l=0,cnt=0;
	F(i,0,n)last[i]=-1;
	F(i,0,m-n)
	{
		cnt-=last[bl[sa[i]]]>=l;
		++cnt;
		if(~last[bl[sa[i]]])c[last[bl[sa[i]]]]=0;
		c[last[bl[sa[i]]]=i]=1;
		while(qf<qr&&height[q[qr-1]]>=height[i])--qr;
		q[qr++]=i;
		while(cnt>=k)
		{
			if(l)d[f++]={l-1,i+1,height[q[qf]]};
			cnt-=c[l++];
			while(qf<qr&&q[qf]<l)++qf;
		}
		if(l)d[f++]={l-1,i+1,height[q[qf]]};
	}
	sort(d,d+f);
	F(i,0,m+1)nxt[i]=i;
	F(i,0,f)for(int j=find(d[i].l);j<d[i].r;j=find(j))ans[j]=d[i].x,nxt[j]=j+1;
}
char s[N];
int main()
{
	read(n,k);
	F(i,0,n)
	{
		scanf("%s",s);
		pos[i]=m;
		while(s[len[i]])++len[i];
		F(j,0,len[i])bl[m]=i,suffixarray::s[m++]=s[j]-'a';
		bl[m]=-1;suffixarray::s[m++]=128+i;
	}
	if(k>n){F(i,0,n)printf("0 ");puts("");return 0;}
	if(k==1){F(i,0,n)printf("%lld ",len[i]*(len[i]+1ll)>>1);puts("");return 0;}
	suffixarray::getsa();
	suffixarray::getheight();
	solve();
	F(i,0,n)
	{
		long long realans=0;
		F(j,pos[i],pos[i]+len[i])realans+=ans[rk[j]];
		printf("%lld ",realans);
	}
	puts("");
	return 0;
}