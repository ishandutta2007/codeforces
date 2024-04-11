#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct BITb
{
	int n;long long c[N];
	void init(int n_){n=n_;}
	void add(int x,long long y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
	long long sum(int x){long long ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
	int binary(int x)
	{
		int ans=0;
		for(int delta=1<<(31-__builtin_clz(n));delta;delta>>=1)
			if(ans+delta<=n&&c[ans+delta]<=x)x-=c[ans+=delta];
		return ans;
	}
};
struct BITa
{
	int n;
	BITb c1,c2;
	void init(int n_){n=n_;c1.init(n);c2.init(n);}
	void add(int x,int v){c1.add(x,(long long)x*v);c2.add(n-x,v);}
	long long sum(int x){return c1.sum(x)+c2.sum(n-x+1)*x;}
	void add(int x,int y,int v){add(x,-v);add(y,v);}
	long long sum(int x,int y){return sum(y)-sum(x);}
};
int n,p[N],q[N];
long long ans;
BITa a,b;
BITb c;
int main()
{
	read(n);
	F(i,0,n)read(p[i]),q[--p[i]]=i;
	a.init(n);b.init(n);c.init(n);
	F(i,0,n)
	{
		int mid=0,l=(i+1)/2,r=i+1-l;
		long long tmp=ans+=i-c.sum(q[i]);
		c.add(q[i],1);
		a.add(q[i],n,1);
		b.add(0,q[i]+1,1);
		mid=c.binary((i+1)>>1);
		tmp+=a.sum(0,mid)+b.sum(mid,n);
		tmp-=l*(l+1ll)/2+r*(r+1ll)/2;
		printf("%lld\n",tmp);
	}
	return 0;
}