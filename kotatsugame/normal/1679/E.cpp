#include<iostream>
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
int N;
string S;
mint tb[18][1<<17];
int cL[1001],cR[1001];
mint pw[18][1001];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>S;
	for(int i=0;i<N;i++)cL[i+1]=cL[i]+(S[i]=='?');
	for(int i=N;i--;)cR[i]=cR[i+1]+(S[i]=='?');
	for(int c=1;c<=17;c++)
	{
		mint p=1,cc=c;
		for(int j=0;j<=N;j++)
		{
			pw[c][j]=p;
			p*=cc;
		}
	}
	for(int t=0;t<2;t++)
	{
		for(int i=0;i<N;i++)
		{
			int cnt=0,now=0;
			for(int j=0;;j++)
			{
				int l=i-j,r=i+t+j;
				if(l<0||r>=N)break;
				if(S[l]=='?'||S[r]=='?')
				{
					if(S[l]=='?'&&S[r]=='?')cnt++;
					else if(S[l]=='?')now|=1<<S[r]-'a';
					else now|=1<<S[l]-'a';
				}
				else if(S[l]!=S[r])break;
				for(int c=1;c<=17;c++)tb[c][now]+=pw[c][cnt+cL[l]+cR[r+1]];
			}
		}
	}
	for(int c=1;c<=17;c++)
	{
		for(int i=0;i<17;i++)
		{
			for(int j=0;j<1<<17;j++)if(j>>i&1)tb[c][j]+=tb[c][j^1<<i];
		}
	}
	int Q;cin>>Q;
	for(;Q--;)
	{
		string t;cin>>t;
		int now=0;
		for(char c:t)now|=1<<c-'a';
		cout<<tb[t.size()][now]<<"\n";
	}
}