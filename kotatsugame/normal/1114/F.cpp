#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
#include<vector>
#include<functional>
template<typename T>
struct lazysegtree{
	function<T(T,T)>calcfn,lazycalcfn;
	function<T(T,T,unsigned int)>updatefn;
	int n;
	T defvalue,lazydefvalue;
	vector<T>dat,lazy;
	vector<bool>lazyflag;
	lazysegtree(int n_=0,T defvalue_=0,
		function<T(T,T)>calcfn_=[](T a,T b){return a+b;},
		function<T(T,T)>lazycalcfn_=[](T a,T b){return a+b;},
		function<T(T,T,unsigned int)>updatefn_=[](T a,T b,unsigned int width){return a+b*width;},
		T lazydefvalue_=0
	):defvalue(defvalue_),lazydefvalue(lazydefvalue_),
		calcfn(calcfn_),lazycalcfn(lazycalcfn_),updatefn(updatefn_)
	{
		n=1;
		while(n<n_)n<<=1;
		dat.assign(2*n-1,defvalue);
		lazy.assign(2*n-1,lazydefvalue);
		lazyflag.assign(2*n-1,false);
	}
	void copy(const vector<T>&v)
	{
		for(int i=0;i<v.size();i++)dat[i+n-1]=v[i];
		for(int i=n-2;i>=0;i--)dat[i]=calcfn(dat[2*i+1],dat[2*i+2]);
	}
	void eval(int i,int l,int r)
	{
		if(lazyflag[i])
		{
			dat[i]=updatefn(dat[i],lazy[i],r-l);
			if(r-l>1)
			{
				lazy[2*i+1]=lazycalcfn(lazy[2*i+1],lazy[i]);
				lazy[2*i+2]=lazycalcfn(lazy[2*i+2],lazy[i]);
				lazyflag[2*i+1]=lazyflag[2*i+2]=true;
			}
			lazy[i]=lazydefvalue;
			lazyflag[i]=false;
		}
	}
	void update(int a,int b,T x,int k=0,int l=0,int r=-1)//[a,b)
	{
		if(r<0)r=n;
		eval(k,l,r);
		if(b<=l||r<=a)return;
		else if(a<=l&&r<=b)
		{
			lazy[k]=lazycalcfn(lazy[k],x);
			lazyflag[k]=true;
			eval(k,l,r);
		}
		else
		{
			update(a,b,x,2*k+1,l,(l+r)/2);
			update(a,b,x,2*k+2,(l+r)/2,r);
			dat[k]=calcfn(dat[2*k+1],dat[2*k+2]);
		}
	}
	T query(int a,int b,int k=0,int l=0,int r=-1)//[a,b)
	{
		if(r<0)r=n;
		eval(k,l,r);
		if(b<=l||r<=a)return defvalue;
		else if(a<=l&&r<=b)return dat[k];
		else return calcfn(
			query(a,b,2*k+1,l,(l+r)/2),
			query(a,b,2*k+2,(l+r)/2,r)
		);
	}
};
long long mod=1e9+7;
long long power(long long a,long long b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}
int prime[62]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293};
long long inv[62];
int n,q;
struct A
{
	long long v,b;
};
main()
{
	scanf("%d%d",&n,&q);
	lazysegtree<A>P(n,(A){1,0},[](A a,A b){return (A){a.v*b.v%mod,a.b|b.b};},[](A a,A b){return (A){a.v*b.v%mod,a.b|b.b};},
		[](A a,A b,unsigned int w){return (A){a.v*power(b.v,w)%mod,a.b|b.b};},(A){1,0});
	vector<A>a;
	for(int i=0;i<62;i++)inv[i]=(mod+1-power(prime[i],mod-2))%mod;
	for(int i=0;i<n;i++)
	{
		long long x;scanf("%lld",&x);
		long long b=0;
		for(int j=0;j<62;j++)
		{
			if(x%prime[j]==0)
			{
				b|=1LL<<j;
			}
		}
		a.push_back((A){x,b});
	}
	P.copy(a);
	for(;q--;)
	{
		string s;cin>>s;
		if(s=="MULTIPLY")
		{
			int l,r;long long x;
			scanf("%d%d%lld",&l,&r,&x);
			long long b=0;
			for(int i=0;i<62;i++)
			{
				if(x%prime[i]==0)
				{
					b|=1LL<<i;
				}
			}
			P.update(l-1,r,(A){x,b});
		}
		else
		{
			int l,r;scanf("%d%d",&l,&r);
			A it=P.query(l-1,r);
			long long ans=it.v;
			for(int i=0;i<62;i++)
			{
				if(it.b>>i&1)
				{
					ans=ans*inv[i]%mod;
				}
			}
			printf("%lld\n",ans);
		}
	}
}