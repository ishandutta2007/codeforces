#line 1 "a.cpp"
#include<cstdio>
#include<map>
using namespace std;
#line 2 "/home/kotatsugame/library/math/modint.cpp"
#include<iostream>
#include<utility>
template<int m>
struct modint{
	unsigned int x;
	constexpr modint()noexcept:x(){}
	template<typename T>
	constexpr modint(T x_)noexcept:x((x_%=m)<0?x_+m:x_){}
	constexpr unsigned int val()const noexcept{return x;}
	constexpr modint&operator++()noexcept{if(++x==m)x=0;return*this;}
	constexpr modint&operator--()noexcept{if(x==0)x=m;--x;return*this;}
	constexpr modint operator++(int)noexcept{modint res=*this;++*this;return res;}
	constexpr modint operator--(int)noexcept{modint res=*this;--*this;return res;}
	constexpr modint&operator+=(const modint&a)noexcept{x+=a.x;if(x>=m)x-=m;return*this;}
	constexpr modint&operator-=(const modint&a)noexcept{if(x<a.x)x+=m;x-=a.x;return*this;}
	constexpr modint&operator*=(const modint&a)noexcept{x=(unsigned long long)x*a.x%m;return*this;}
	constexpr modint&operator/=(const modint&a)noexcept{return*this*=a.inv();}
	constexpr modint operator+()const noexcept{return*this;}
	constexpr modint operator-()const noexcept{return modint()-*this;}
	constexpr modint pow(long long n)const noexcept
	{
		if(n<0)return pow(-n).inv();
		modint x=*this,r=1;
		for(;n;x*=x,n>>=1)if(n&1)r*=x;
		return r;
	}
	constexpr modint inv()const noexcept
	{
		int s=x,t=m,x=1,u=0;
		while(t)
		{
			int k=s/t;
			s-=k*t;
			swap(s,t);
			x-=k*u;
			swap(x,u);
		}
		return modint(x);
	}
	friend constexpr modint operator+(const modint&a,const modint&b){return modint(a)+=b;}
	friend constexpr modint operator-(const modint&a,const modint&b){return modint(a)-=b;}
	friend constexpr modint operator*(const modint&a,const modint&b){return modint(a)*=b;}
	friend constexpr modint operator/(const modint&a,const modint&b){return modint(a)/=b;}
	friend constexpr bool operator==(const modint&a,const modint&b){return a.x==b.x;}
	friend constexpr bool operator!=(const modint&a,const modint&b){return a.x!=b.x;}
	friend ostream&operator<<(ostream&os,const modint&a){return os<<a.x;}
	friend istream&operator>>(istream&is,modint&a){long long v;is>>v;a=modint(v);return is;}
};
#line 1 "/home/kotatsugame/library/math/combination.cpp"
#include<vector>
template<typename T>
struct combination{
	vector<T>fac,invfac;
	combination(size_t N=0):fac(1,1),invfac(1,1)
	{
		make_table(N);
	}
	void make_table(size_t N)
	{
		if(fac.size()>N)return;
		size_t now=fac.size();
		N=max(N,now*2);
		fac.resize(N+1);
		invfac.resize(N+1);
		for(size_t i=now;i<=N;i++)fac[i]=fac[i-1]*i;
		invfac[N]=1/fac[N];
		for(size_t i=N;i-->now;)invfac[i]=invfac[i+1]*(i+1);
	}
	T factorial(size_t n)
	{
		make_table(n);
		return fac[n];
	}
	T P(size_t n,size_t k)
	{
		if(n<k)return 0;
		make_table(n);
		return fac[n]*invfac[n-k];
	}
	T C(size_t n,size_t k)
	{
		if(n<k)return 0;
		make_table(n);
		return fac[n]*invfac[n-k]*invfac[k];
	}
	T H(size_t n,size_t k)
	{
		if(n==0)return k==0?1:0;
		return C(n-1+k,k);
	}
};
#line 6 "a.cpp"
using mint=modint<(int)1e9+7>;
int N;
int A[1<<17];
main()
{
	scanf("%d",&N);
	long long sum=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		sum+=A[i];
	}
	if(sum%N!=0)
	{
		puts("0");
		return 0;
	}
	sum/=N;
	map<int,int>mp;
	int nL=0,M=0,nR=0;
	for(int i=0;i<N;i++)
	{
		if(sum>A[i])
		{
			nL++;
			mp[A[i]]++;
		}
		else if(sum==A[i])M++;
		else
		{
			nR++;
			mp[A[i]]++;
		}
	}
	combination<mint>C;
	mint ans=1;
	for(pair<int,int>p:mp)ans*=C.factorial(p.second);
	ans=1/ans;
	if(nL>=2&&nR>=2)
	{
		ans*=C.factorial(nL)*C.factorial(nR)*2;
	}
	else ans*=C.factorial(nL+nR);
	ans*=C.H(N-M+1,M);
	printf("%lld\n",ans.val());
}