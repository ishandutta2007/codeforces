#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5,MOD=1000000007;
template<typename T>T& read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
	return x;
}
struct BITb
{
	int n;long long c[N];
	void init(int n_){n=n_;}
	void add(int x,long long y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
	long long sum(int x){long long ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
};
int n,a[N],v[N],r[N];long long ans;
BITb b;
void solve()
{
	F(i,0,n+1)b.c[i]=0;
	F(i,0,n)
	{
		b.add(r[i],i+1);
		ans+=b.sum(r[i])%MOD*a[i]%MOD*(n-i)%MOD;
	}
}
int main()
{
	F(i,0,read(n))v[i]=read(a[i]);
	sort(v,v+n);
	F(i,0,n)r[i]=lower_bound(v,v+n,a[i])-v;
	b.init(n);
	F(i,0,n)ans+=(i+1ll)*(n-i)%MOD*a[i]%MOD;
	solve();
	F(i,0,n/2)swap(a[i],a[n-1-i]),swap(r[i],r[n-1-i]);
	solve();
	printf("%lld\n",ans%MOD);
	return 0;
}