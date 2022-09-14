#line 1 "a.cpp"
#include<cstdio>
#include<vector>
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
#line 6 "a.cpp"
using mint=modint<998244353>;
int N,K;
vector<int>G[5000];
mint dp[5000][5001];
void dfs(int u,int p)
{
	vector<vector<mint> >R(1,vector<mint>(K/2+1,mint(1)));
	R.reserve(G[u].size()+1);
	for(int v:G[u])if(v!=p)
	{
		dfs(v,u);
		mint sum=dp[v][K];
		for(int i=K;i--;)
		{
			dp[v][i+1]=dp[v][i];
			sum+=dp[v][i];
		}
		dp[v][0]=sum;
		vector<mint>tmp=R.back();
		sum=0;
		for(int i=0;i<=K/2;i++)tmp[i]*=sum+=dp[v][i];
		R.push_back(vector<mint>());
		R.back().swap(tmp);
	}
	for(int i=0;i<=K/2;i++)
	{
		mint now=R.back()[i];
		if(i>0)now-=R.back()[i-1];
		dp[u][i]+=now;
	}
	vector<mint>L(K/2+1,mint(1));
	reverse(G[u].begin(),G[u].end());
	for(int v:G[u])if(v!=p)
	{
		R.pop_back();
		for(int i=K;i>K/2;i--)dp[u][i]+=dp[v][i]*R.back()[K-i]*L[K-i];
		mint sum=0;
		for(int i=0;i<=K/2;i++)L[i]*=sum+=dp[v][i];
	}
}
main()
{
	scanf("%d%d",&N,&K);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1);
	mint ans=0;
	for(int i=0;i<=K;i++)ans+=dp[0][i];
	printf("%d\n",ans.val());
}