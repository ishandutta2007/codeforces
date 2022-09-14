#line 1 "a.cpp"
#include<iostream>
#include<algorithm>
#include<vector>
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
#line 6 "a.cpp"
using mint=modint<(int)1e9+7>;
int T,N,K;
vector<int>G[100];
mint dp[100][101];
int cnt[100];
void dfs(int u,int p,int c)
{
	cnt[c]++;
	for(int v:G[u])if(v!=p)dfs(v,u,c+1);
}
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<N;i++)G[i].clear();
		for(int i=1;i<N;i++)
		{
			int u,v;cin>>u>>v;
			u--,v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(K==2)
		{
			cout<<N*(N-1)/2<<endl;
			continue;
		}
		mint ans=0;
		for(int i=0;i<N;i++)
		{
			for(int c=0;c<N;c++)
			{
				for(int k=0;k<=K;k++)dp[c][k]=0;
				dp[c][0]=1;
			}
			for(int u:G[i])
			{
				for(int c=0;c<N;c++)cnt[c]=0;
				dfs(u,i,0);
				for(int c=0;c<N;c++)if(cnt[c]>0)
				{
					for(int k=K-1;k>=0;k--)dp[c][k+1]+=dp[c][k]*cnt[c];
				}
			}
			for(int c=0;c<N;c++)ans+=dp[c][K];
		}
		cout<<ans<<endl;
	}
}