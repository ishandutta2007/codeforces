#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,MOD=998244353;
template<typename T>T& read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
	return x;
}
int n,p[N],c[N],ans;
void add(int x,int y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
int sum(int x){int ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
inline int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		b>>=1;(a*=a)%=MOD;
	}
	return (int)c;
}
inline int inv(int x){return pow(x,MOD-2);}
int main()
{
	int cnt=0,all,invall;
	read(n);
	F(i,0,n)if(~read(p[i]))--p[i];
	for(int i=n-1;~i;--i)if(~p[i])add(p[i],1),(ans+=sum(p[i]))%=MOD;else ++cnt;
	(ans+=cnt*(cnt-1ll)%MOD*inv(4)%MOD)%=MOD;
	invall=inv(all=n-sum(n));
	F(i,0,n)if(~p[i])
	{
		(ans+=(p[i]-sum(p[i]))*(long long)cnt%MOD*invall%MOD)%=MOD;
		(ans+=(all-p[i]+sum(p[i]))*(long long)(all-cnt)%MOD*invall%MOD)%=MOD;
	}
	else --cnt;
	printf("%d\n",ans);
	return 0;
}