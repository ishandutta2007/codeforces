#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5,F=(1<<20)-1;
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
struct dsu
{
	static const int N=::N<<1;
	int n,f[N],s[N],sz[N],t;
	void init(int n_){F(i,0,n=n_)f[i]=-1;}
	int find(int x){return f[x]&(1<<31)?x:find(f[x]);}
	void merge(int x,int y)
	{
		x=find(x),y=find(y);
		if(x!=y)
		{
			if(f[x]>f[y])swap(x,y);
			sz[t]=f[y];s[t++]=y;
			f[x]+=f[y];f[y]=x;
		}
	}
	void restore(){while(t)--t,f[f[s[t]]]-=sz[t],f[s[t]]=sz[t];}
}d;
struct edge
{
	long long group;
	int u,v;
	friend bool operator<(const edge &a,const edge &b){return a.group<b.group;}
}e[N];
int n,m,k,c[N],bc;
long long ans;
bool bad,b[N];
int main()
{
	read(n,m,k);d.init(n<<1);
	F(i,0,n)--read(c[i]);
	F(i,0,m)
	{
		int u,v;--read(u),--read(v);
		if(c[u]!=c[v])
		{
			if(c[u]>c[v])swap(u,v);
			e[i].group=(long long)c[u]<<20|c[v]|1ll<<40;
			e[i].u=u,e[i].v=v;
		}
		else d.merge(u+n,v),d.merge(u,v+n);
	}
	F(i,0,n)if(d.find(i)==d.find(i+n))bc+=!b[c[i]],b[c[i]]=true;
	ans=(k-bc)*(k-bc-1ll)>>1;
	d.t=0;
	sort(e,e+m);
	F(i,0,m)
	{
		if(e[i].group&1ll<<40&&!bad)
		{
			int &u=e[i].u,&v=e[i].v;
			d.merge(u,v+n);
			d.merge(u+n,v);
			if(d.find(u)==d.find(u+n))bad=true,--ans;
		}
		if(e[i].group!=e[i+1].group)d.restore(),bad=b[e[i+1].group&F]||b[e[i+1].group>>20&F];
	}
	printf("%lld\n",ans);
	return 0;
}