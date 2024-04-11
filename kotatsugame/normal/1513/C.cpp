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
using mint=modint<(int)1e9+7>;
#line 1 "/home/kotatsugame/library/math/squarematrix.cpp"
#include<array>
template<typename T,unsigned int N>
struct Matrix{
	array<array<T,N>,N>dat;
	array<T,N>&operator[](int i){return dat[i];}
	const array<T,N>&operator[](int i)const{return dat[i];}
	static Matrix eye(){
		Matrix res;
		for(int i=0;i<N;i++)res[i][i]=1;
		return res;
	}
	Matrix operator+(const Matrix&A)const{
		Matrix res;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)
			res[i][j]=dat[i][j]+A[i][j];
		return res;
	}
	Matrix operator*(const Matrix&A)const{
		Matrix res;
		for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=0;k<N;k++)
			res[i][j]+=dat[i][k]*A[k][j];
		return res;
	}
	Matrix pow(long long n)const{
		Matrix a=*this,res=eye();
		for(;n;a=a*a,n>>=1)if(n&1)res=res*a;
		return res;
	}
};
#line 6 "a.cpp"
using mat=Matrix<mint,10>;
int T,N,M;
mint cnt[10];
mat X[2<<17];
main()
{
	scanf("%d",&T);
	mat A;
	for(int i=0;i<9;i++)A[i+1][i]=1;
	A[0][9]=A[1][9]=1;
	mat E=mat::eye();
	for(int i=1;i<2<<17;i++)X[i]=E=E*A;
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<10;i++)cnt[i]=0;
		while(N)cnt[N%10]++,N/=10;
		mint ans=0;
		for(int i=0;i<10;i++)for(int j=0;j<10;j++)
		{
			ans+=X[M][i][j]*cnt[j];
		}
		printf("%d\n",ans.val());
	}
}