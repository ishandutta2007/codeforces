#include<iostream>
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
using mint=modint<998244353>;
int D,N,M;
mint fact[20][20];
mint dp[1<<18];
int L[2<<17],P[18];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>D>>N>>M;
	for(int i=0;i<N;i++)cin>>L[i];
	for(int i=0;i<M;i++)cin>>P[i];
	sort(L,L+N);
	sort(P,P+M);
	{
		int li=0;
		for(int i=0;i<=M+1;i++)
		{
			int l=i==0?-D:i==M+1?2*D:P[i-1];
			while(li<N&&L[li]<l)li++;
			for(int j=i+1;j<=M+1;j++)
			{
				int r=j==0?-D:j==M+1?2*D:P[j-1];
				fact[i][j]=1;
				for(int k=li;k<N&&L[k]<r;k++)
				{
					fact[i][j]*=min(min(L[k]-l,r-L[k]),D+1);
				}
			}
		}
	}
	for(int i=0;i<1<<M;i++)
	{
		dp[i]=1;
		int l=0;
		for(int k=0;k<M;k++)if(!(i>>k&1))
		{
			dp[i]*=fact[l][k+1];
			l=k+1;
		}
		dp[i]*=fact[l][M+1];
	}
	for(int i=0;i<M;i++)for(int j=0;j<1<<M;j++)if(j>>i&1)dp[j]-=dp[j^1<<i];
	for(int i=0;i<M;i++)for(int j=0;j<1<<M;j++)if(j>>i&1)dp[j^1<<i]+=dp[j];
	int Q;cin>>Q;
	vector<pair<int,int> >need(M);
	for(;Q--;)
	{
		int f;cin>>f;
		for(int i=0;i<M;i++)need[i]=make_pair(abs(f-P[i]),i);
		sort(need.begin(),need.end());
		int dl=0,msk=0;
		mint ans=0;
		for(int i=0;i<M;)
		{
			int dr=need[i].first;
			ans+=dp[(1<<M)-1^msk]*(dr-dl);
			while(i<M&&need[i].first==dr)
			{
				msk|=1<<need[i].second;
				i++;
			}
			dl=dr;
		}
		ans+=dp[(1<<M)-1^msk]*(D+1-dl);
		cout<<ans<<"\n";
	}
}