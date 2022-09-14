#line 1 "a.cpp"
#include<cstdio>
#include<string>
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
#line 1 "/home/kotatsugame/library/string/Zalgo.cpp"
//Longest Common Prefix(s,s.substr(i)) O(|s|)
#include<vector>
#line 4 "/home/kotatsugame/library/string/Zalgo.cpp"
vector<int>Zalgo(const string&s)
{
	vector<int>ret(s.size());
	if(s.empty())return ret;
	ret[0]=s.size();
	int i=1,j=0;
	while(i<s.size())
	{
		while(i+j<s.size()&&s[j]==s[i+j])j++;
		ret[i]=j;
		if(j==0)
		{
			i++;
			continue;
		}
		int k=1;
		while(i+k<s.size()&&k+ret[k]<j)ret[i+k]=ret[k],k++;
		i+=k;j-=k;
	}
	return ret;
}
#line 6 "a.cpp"
using mint=modint<(int)1e9+7>;
int M;
mint L[3030][3030];
main()
{
	scanf("%d",&M);
	mint sum=0;
	L[0][0]=1;
	string S="";
	for(int j=1;j<=M;j++)
	{
		int a;scanf("%d",&a);
		S=(char)(a+'0')+S;
		vector<int>za=Zalgo(S);
		int mx=0;
		for(int i=1;i<j;i++)if(mx<za[i])mx=za[i];
		for(int i=0;i<j;i++)
		{
			L[i][j]=L[i][j-1];
			if(j-2>=i)L[i][j]+=L[i][j-2];
			if(j-3>=i)L[i][j]+=L[i][j-3];
			if(j-4>=i)
			{
				string t=S.substr(0,4);
				if(t!="1100"&&t!="1010"&&t!="0111"&&t!="1111")L[i][j]+=L[i][j-4];
			}
			if(mx<j-i)sum+=L[i][j];
		}
		L[j][j]=1;
		printf("%d\n",(int)sum.val());
	}
}