#line 1 "a.cpp"
#include<cstdio>
#include<cstring>
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
#line 5 "a.cpp"
using mint=modint<(int)1e9+7>;
int N,M;
char S[222];
int fail[222];
mint dp[2][201][101];
main()
{
	scanf("%d%s",&N,S);
	M=strlen(S);
	for(int i=0;i<M;i++)
	{
		for(int j=i;j>=0;j--)
		{
			bool ok=S[j]!=S[i];
			for(int k=0;k<j;k++)ok=ok&&S[k]==S[i-(j-k)];
			if(ok)
			{
				fail[i]=j+1;
				break;
			}
		}
	}
	int now=0;
	dp[now][0][0]=1;
	for(int i=0;i<2*N;i++)
	{
		int nxt=1-now;
		for(int j=0;j<=M;j++)for(int k=0;k<=N;k++)dp[nxt][j][k]=0;
		for(int j=0;j<=M;j++)for(int k=0;k<=N;k++)
		{
			if(k<N)
			{
				if(j==M)dp[nxt][j][k+1]+=dp[now][j][k];
				else if(S[j]=='(')dp[nxt][j+1][k+1]+=dp[now][j][k];
				else dp[nxt][fail[j]][k+1]+=dp[now][j][k];
			}
			if(k>0)
			{
				if(j==M)dp[nxt][j][k-1]+=dp[now][j][k];
				else if(S[j]==')')dp[nxt][j+1][k-1]+=dp[now][j][k];
				else dp[nxt][fail[j]][k-1]+=dp[now][j][k];
			}
		}
		now=nxt;
	}
	printf("%d\n",dp[now][M][0].val());
}