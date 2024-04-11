#line 1 "a.cpp"
#include<cstdio>
#include<vector>
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
using mint=modint<998244353>;
int N;
vector<int>G[3<<17];
pair<pair<mint,mint>,mint>dfs(int u,int p)
{
	vector<pair<mint,mint> >ch;
	mint one=1;
	for(int v:G[u])if(v!=p)
	{
		pair<pair<mint,mint>,mint>q=dfs(v,u);
		one*=q.first.first+q.second;
		ch.push_back(make_pair(q.first.first*2+q.second,q.first.second+q.second));
	}
	vector<mint>R(ch.size()+1);
	R[ch.size()]=1;
	for(int i=ch.size();i--;)
	{
		R[i]=R[i+1]*ch[i].first;
	}
	mint L=1;
	mint black=0;
	for(int i=0;i<ch.size();i++)
	{
		black+=L*ch[i].second*R[i+1];
		L*=ch[i].first;
	}
	//printf("%d : %d, %d, %d\n",u,black.val(),(L-one).val(),one.val());
	return make_pair(make_pair(black,L-one),one);
}
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int a,b;scanf("%d%d",&a,&b);a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	pair<pair<mint,mint>,mint>q=dfs(0,-1);
	printf("%d\n",(q.first.first+q.second).val());
}