#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
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
template<typename T>struct BITb
{
	int n;T c[N];
	void init(int n_){n=n_;}
	void add(int x,T y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
	T sum(int x){T ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
	int binary(int x)
	{
		int ans=0;
		if(x<0)return -1;
		for(int delta=1<<(31-__builtin_clz(n));delta;delta>>=1)
			if(ans+delta<=n&&c[ans+delta]<=x)x-=c[ans+=delta];
		return ans;
	}
};
BITb<int> c;
struct BITa
{
	int n;
	BITb<long long> c1;
	BITb<int> c2;
	void init(int n_){n=n_;c1.init(n);c2.init(n);}
	void add(int x,int v){c1.add(x,(long long)x*v);c2.add(n-x,v);}
	long long sum(int x){return c1.sum(x)+c2.sum(n-x+1)*(long long)x;}
	void add(int x,int y,int v){add(x,-v);add(y,v);}
	long long sum(int x,int y){return sum(y)-sum(x);}
}d;
struct query
{
	int x,id,c;
	bool operator<(query b){return x<b.x;}
}qy[N<<1];
int n,q,p[N],ip[N],l[N],r[N],x[N],y[N];
long long ans[N];
int main()
{
	read(n,q);
	F(i,0,n)ip[--read(p[i])]=i;
	F(i,0,q)--read(l[i]);
	F(i,0,q)read(r[i]);
	c.init(n);
	for(int i=n;~--i;)
	{
		int t=c.sum(ip[i]);
		c.add(ip[i],1);
		x[ip[i]]=c.binary(t-1)+1;
		y[ip[i]]=c.binary(t+1);
	}
	F(i,0,q)
	{
		qy[i<<1|0].x=l[i],qy[i<<1|0].id=i,qy[i<<1|0].c=-1;
		qy[i<<1|1].x=r[i],qy[i<<1|1].id=i,qy[i<<1|1].c=1;
	}
	sort(qy,qy+(q<<1));
	d.init(n);
	for(int i=0,i_end=q<<1,j=0;i<i_end;++i)
	{
		while(j<qy[i].x)d.add(x[j],y[j],1),++j;
		ans[qy[i].id]+=qy[i].c*d.sum(l[qy[i].id],r[qy[i].id]);
	}
	F(i,0,q)printf("%lld ",ans[i]);
	puts("");
	return 0;
}