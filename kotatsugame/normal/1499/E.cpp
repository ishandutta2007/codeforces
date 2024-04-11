#line 1 "a.cpp"
#include<iostream>
using namespace std;
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
#line 4 "a.cpp"
using mint=modint<998244353>;
string X,Y;
mint dp[1010][1010][27];
main()
{
	cin>>X>>Y;
	mint ans=0;
	for(int i=0;i<=X.size();i++)for(int j=0;j<=Y.size();j++)
	{
		dp[i][j][26]++;
		for(int k=0;k<=26;k++)
		{
			if(k<26)ans+=dp[i][j][k];
			if(i<X.size()&&X[i]-'a'!=k)dp[i+1][j][X[i]-'a']+=dp[i][j][k];
			if(j<Y.size()&&Y[j]-'a'!=k)dp[i][j+1][Y[j]-'a']+=dp[i][j][k];
		}
	}
	int cnt=0;
	for(int i=X.size()-1;i>=0;i--)
	{
		if(i+1<X.size()&&X[i]==X[i+1])cnt=0;
		cnt++;
		ans-=cnt*(Y.size()+1);
	}
	cnt=0;
	for(int i=Y.size()-1;i>=0;i--)
	{
		if(i+1<Y.size()&&Y[i]==Y[i+1])cnt=0;
		cnt++;
		ans-=cnt*(X.size()+1);
	}
	cout<<ans<<endl;
}