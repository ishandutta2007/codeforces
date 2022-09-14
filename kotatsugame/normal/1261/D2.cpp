#line 1 "a.cpp"
#include<cstdio>
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
#line 4 "a.cpp"
using mint=modint<998244353>;
int N,K;
int H[2<<17];
mint fac[2<<17],inv[2<<17];
mint comb(int a,int b){return fac[a]*inv[b]*inv[a-b];}
main()
{
	scanf("%d%d",&N,&K);
	fac[0]=1;
	for(int i=1;i<=N;i++)fac[i]=fac[i-1]*i;
	inv[N]=1/fac[N];
	for(int i=N;i--;)inv[i]=inv[i+1]*(i+1);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&H[i]);
	}
	if(K==1)
	{
		puts("0");
		return 0;
	}
	int cnt=0;
	for(int i=0;i<N;i++)cnt+=H[i]!=H[(i+1)%N];
	mint ans=0;
	for(int i=1;i<=cnt;i++)
	{
		mint now;
		if(i%2==0)
		{
			now=(mint(2).pow(i)-comb(i,i/2))/2;
		}
		else
		{
			now=mint(2).pow(i-1);
		}
		now*=comb(cnt,i);
		if(i<cnt)now*=mint(K-2).pow(cnt-i);
		ans+=now;
	}
	ans*=mint(K).pow(N-cnt);
	printf("%d\n",(int)ans.val());
}