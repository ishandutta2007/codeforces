#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<vector>
#include<unordered_set>
#define abs(x) ((x)<0?-(x):(x))
#define int long long
using std::vector;
using std::unordered_set;
int n,m,k,p;
inline int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
inline int Rand(int l,int r)
{
	return rand()%(r-l+1)+l;
}
inline int add(int a,int b,int mod)
{
	if((a+=b)>=mod)
		a-=mod;
	return a;
}
inline int sub(int a,int b,int mod)
{
	if((a-=b)<0)
		a+=mod;
	return a;
}
inline int mul(int a,int b,int mod)
{
	return (a*b-(int)(((long double)a*b+0.5)/mod)*mod)%mod;
}
inline int qpow(int a,int b,int mod)
{
	int res=1;
	for(;b;a=mul(a,a,mod),b>>=1)
		if(b&1)
			res=mul(res,a,mod);
	return res;
}
inline bool miller_rabin(int x)
{
	int T=5,a,u=x-1,t=0;
	register int i;
	if(x==1||!(x&1))
		return x==2;
	while(!(u&1))
		u>>=1,t++;
	while(T--)
	{
		a=qpow(Rand(1,x-1),u,x);
		for(i=0;i<t;a=mul(a,a,x),i++)
			if(mul(a,a,x)==1&&a!=1&&a!=x-1)
				return 0;
		if(a!=1)
			return 0;
	}
	return 1;
}
vector<int> V,V2;
unordered_set<int> S;
inline void pollard_rho(int x)
{
	if(x==1)
		return;
	if(miller_rabin(x))
	{
		V.push_back(x);
		return;
	}
	int a,b,c,g,i,k;
	while(1)
	{
		a=b=Rand(1,x-1);c=Rand(0,x-1);i=0;k=1;
		while(1)
		{
			a=add(mul(a,a,x),c,x);
			if(a==b)
				break;
			if((g=gcd(abs(a-b),x))!=1)
			{
				pollard_rho(g);pollard_rho(x/g);
				return;
			}
			if(++i==k)
				b=a,i=0,k<<=1;
		}
	}
	return;
}
signed main()
{
	register int i;
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k==1||n*m*2%k!=0)
		return puts("NO"),0;
	p=n*m*2/k;
	pollard_rho(p);
	S.insert(1);
	for(auto x:V)
	{
		V2.clear();
		for(auto y:S)
			V2.push_back(x*y);
		for(auto y:V2)
			if(S.find(y)==S.end())
				S.insert(y);
	}
	for(auto x:S)
	{
		if(n>=x&&m>=p/x)
		{
			puts("YES");
			printf("0 0\n");
			printf("%lld 0\n",x);
			printf("0 %lld\n",p/x);
			return 0;
		}
	}
	puts("NO");
	return 0;
}