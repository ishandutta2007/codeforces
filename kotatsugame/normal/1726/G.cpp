#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
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
#include<vector>
template<typename T>
struct combination{
	vector<T>fac,ifac;
	combination(size_t N=0):fac(1,1),ifac(1,1)
	{
		make_table(N);
	}
	void make_table(size_t N)
	{
		if(fac.size()>N)return;
		size_t now=fac.size();
		N=max(N,now*2);
		fac.resize(N+1);
		ifac.resize(N+1);
		for(size_t i=now;i<=N;i++)fac[i]=fac[i-1]*i;
		ifac[N]=1/fac[N];
		for(size_t i=N;i-->now;)ifac[i]=ifac[i+1]*(i+1);
	}
	T factorial(size_t n)
	{
		make_table(n);
		return fac[n];
	}
	T invfac(size_t n)
	{
		make_table(n);
		return ifac[n];
	}
	T P(size_t n,size_t k)
	{
		if(n<k)return 0;
		make_table(n);
		return fac[n]*ifac[n-k];
	}
	T C(size_t n,size_t k)
	{
		if(n<k)return 0;
		make_table(n);
		return fac[n]*ifac[n-k]*ifac[k];
	}
	T H(size_t n,size_t k)
	{
		if(n==0)return k==0?1:0;
		return C(n-1+k,k);
	}
};
using mint=modint<998244353>;
combination<mint>C;
int N;
int Ai[2<<17],Bi[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;i++)cin>>Ai[i];
	for(int i=0;i<N;i++)cin>>Bi[i];
	vector<pair<int,int> >A(N);
	for(int i=0;i<N;i++)
	{
		A[i]=make_pair(Ai[i],Bi[i]);
	}
	sort(A.begin(),A.end());
	vector<pair<int,pair<int,int> > >B;
	for(pair<int,int>ab:A)
	{
		if(B.empty()||B.back().first<ab.first)B.push_back(make_pair(ab.first,make_pair(0,0)));
		if(ab.second==0)B.back().second.first++;
		else B.back().second.second++;
	}
	if(B.size()==1)
	{
		cout<<C.factorial(N)<<endl;
		return 0;
	}
	if(B[0].second!=make_pair(0,1))
	{
		cout<<0<<endl;
		return 0;
	}
	int TO=B[0].first+N-1;
	mint ans=1;
	int l=1,r=N-1;
	for(int i=1;i<B.size();i++)
	{
		int m=B[i].second.first+B[i].second.second;
		r-=m;
		if(TO==B[i].first)
		{
			ans*=C.factorial(B[i].second.first);
			ans*=C.C(N,l+B[i].second.first)*C.factorial(B[i].second.second);
			l+=m;
			continue;
		}
		if(B[i].second.second>1)
		{
			cout<<0<<endl;
			return 0;
		}
		if(B[i].second.first>0)
		{
			if(B[i].first<=TO&&TO<=B[i].first+l)
			{
				ans*=C.factorial(B[i].second.first);
			}
			else
			{
				cout<<0<<endl;
				return 0;
			}
		}
		if(B[i].second.second==1)
		{
			if(B[i].first+r<=TO&&TO<=B[i].first+N-1)
			{
			}
			else
			{
				cout<<0<<endl;
				return 0;
			}
		}
		l+=m;
	}
	cout<<ans<<endl;
}