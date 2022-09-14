#line 1 "a.cpp"
using namespace std;
#include<vector>
template<typename T>
T lagrange_interpolation(const vector<T>&y,T x)
{
	int N=y.size();
	if(N==0)return T(0);
	vector<T>fac(N),invfac(N);
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i;
	invfac[N-1]=1/fac[N-1];
	for(int i=N-1;i--;)invfac[i]=invfac[i+1]*(i+1);
	vector<T>L(N),R(N);
	L[0]=1;
	for(int i=1;i<N;i++)L[i]=L[i-1]*(x-(i-1));
	R[N-1]=1;
	for(int i=N-1;i--;)R[i]=R[i+1]*(x-(i+1));
	T ret=0;
	for(int i=0;i<N;i++)
	{
		T now=L[i]*R[i]*invfac[i]*invfac[N-i-1]*y[i];
		if(N-i&1)ret+=now;
		else ret-=now;
	}
	return ret;
}
#include<iostream>
#line 3 "/home/kotatsugame/library/math/modint.cpp"
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
#line 29 "a.cpp"
using mint=modint<(int)1e9+7>;
int N,K;
main()
{
	cin>>N>>K;
	vector<mint>y(K+2);
	y[0]=0;
	for(int i=1;i<=K+1;i++)
	{
		y[i]=y[i-1]+mint(i).pow(K);
	}
	cout<<lagrange_interpolation(y,(mint)N)<<endl;
}