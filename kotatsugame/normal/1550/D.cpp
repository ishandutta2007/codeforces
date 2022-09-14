#line 1 "a.cpp"
#include<cstdio>
#include<algorithm>
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
combination<mint>C;
mint C1(int M,int L,int R)
{
	//printf("C1 : %d %d %d\n",M,L,R);
	//fflush(stdout);
	if(M==0)return 0;
	if(L<R)return 0;
	return ((R-M-1<0?mint(0):C.C(L-M-1,R-M-1))*(M-L)+C.C(L-1,R-1)*L)/(L-R+1);
}
mint C2(int M,int L,int R)
{
	//printf("C2 : %d %d %d\n",M,L,R);
	//fflush(stdout);
	if(M==0)return 0;
	if(L<R)return 0;
	return (C.C(L-1,R-1)*L*(L+1)-(R-M-1<0?mint(0):C.C(L-M-1,R-M-1))*(L-M)*(mint(L)*M+L-mint(M)*R+M+1))/mint(mint(L-R+1)*(L-R+2));
}
int T,N,L,R;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&L,&R);
		mint ans=0;
		if(N%2==0)
		{
			int nr=min(N/2+1-L,R-N/2);
			if(nr>0)ans+=nr;
		}
		else
		{
			{
				int nr=min((N+1)/2-L,R-(N-1)/2);
				if(nr>0)ans+=nr;
			}
			{
				int nr=min((N+3)/2-L,R-(N+1)/2);
				if(nr>0)ans+=nr;
			}
		}
		for(int r=1;r<=N;r++)
		{
			if(N%2==0)
			{
				{
					int nr=min({r-1,N/2,R+L-r});
					if(nr>0)
					{
						ans+=C2(nr,r-1,N/2);
						ans-=C1(nr,r-1,N/2)*L;
					}
				}
				{
					int nr=min(r-1,N/2);
					int nl=max(1,R+L-r+1);
					if(nl<=nr)
					{
						ans+=(C1(nr,r-1,N/2)-C1(nl-1,r-1,N/2))*(R-r);
					}
				}
			}
			else
			{
				{
					{
						int nr=min({r-1,(N-1)/2,R+L-r});
						if(nr>0)
						{
							ans+=C2(nr,r-1,(N-1)/2);
							ans-=C1(nr,r-1,(N-1)/2)*L;
						}
					}
					{
						int nr=min({r-1,(N+1)/2,R+L-r});
						if(nr>0)
						{
							ans+=C2(nr,r-1,(N+1)/2);
							ans-=C1(nr,r-1,(N+1)/2)*L;
						}
					}
				}
				{
					{
						int nr=min(r-1,(N-1)/2);
						int nl=max(1,R+L-r+1);
						if(nl<=nr)
						{
							ans+=(C1(nr,r-1,(N-1)/2)-C1(nl-1,r-1,(N-1)/2))*(R-r);
						}
					}
					{
						int nr=min(r-1,(N+1)/2);
						int nl=max(1,R+L-r+1);
						if(nl<=nr)
						{
							ans+=(C1(nr,r-1,(N+1)/2)-C1(nl-1,r-1,(N+1)/2))*(R-r);
						}
					}
				}
			}
		}
		printf("%d\n",ans.val());
	}
}