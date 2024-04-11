#line 1 "a.cpp"
#include<cstdio>
#include<set>
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
#line 1 "/home/kotatsugame/library/datastructure/DST.cpp"
//Disjoint Sparse Table
#include<vector>
#include<functional>
template<typename T>
struct DST{
	function<T(T,T)>calcfn;
	int n;
	vector<vector<T> >dat;
	DST(const vector<T>&v={},
		function<T(T,T)>calcfn_=[](T a,T b){return a<b?a:b;}
	):calcfn(calcfn_)
	{
		n=v.size();
		dat.push_back(v);
		for(int i=2;i<n;i<<=1)
		{
			dat.push_back(vector<T>(n));
			for(int j=i;j<n;j+=i<<1)
			{
				dat.back()[j-1]=dat[0][j-1];
				for(int k=2;k<=i;k++)
				{
					dat.back()[j-k]=calcfn(dat[0][j-k],dat.back()[j-k+1]);
				}
				dat.back()[j]=dat[0][j];
				for(int k=2;k<=i&&j+k<=n;k++)
				{
					dat.back()[j+k-1]=calcfn(dat.back()[j+k-2],dat[0][j+k-1]);
				}
			}
		}
	}
	T query(int l,int r)const//[l,r)
	{
		if(l<0)l=0;
		if(r>n)r=n;
		r--;
		if(l==r)return dat[0][l];
		int k=31-__builtin_clz(l^r);
		return calcfn(dat[k][l],dat[k][r]);
	}
};
#line 6 "a.cpp"
using mint=modint<998244353>;
int N,Q;
mint P[2<<17];
main()
{
	scanf("%d%d",&N,&Q);
	const mint inv100=1/mint(100);
	vector<mint>Mi(N);
	vector<pair<mint,mint> >Fi(N);
	for(int i=0;i<N;i++)
	{
		int p;
		scanf("%d",&p);
		P[i]=p*inv100;
		Mi[i]=P[i];
		Fi[i]=make_pair(P[i],1);
	}
	DST<mint>M(Mi,[](mint a,mint b){return a*b;});
	DST<pair<mint,mint> >F(Fi,[](pair<mint,mint>a,pair<mint,mint>b)
	{
		return make_pair(a.first*b.first,a.first*b.second+a.second);
	});
	auto calc=[&M,&F](int l,int r)
	{
		mint V=M.query(l,r);
		mint U;
		if(l+1==r)U=1;
		else
		{
			pair<mint,mint>p=F.query(l,r-1);
			U=p.first+p.second;
		}
		return U/V;
	};
	set<int>S;
	S.insert(0);
	S.insert(N);
	mint now=calc(0,N);
	for(int c=0;c<Q;c++)
	{
		int u;scanf("%d",&u);u--;
		if(S.find(u)==S.end())
		{
			auto it=S.lower_bound(u);
			int r=*it;
			it--;
			int l=*it;
			now-=calc(l,r);
			now+=calc(l,u);
			now+=calc(u,r);
			S.insert(u);
		}
		else
		{
			auto it=S.lower_bound(u);
			it++;
			int r=*it;
			it--;
			it--;
			int l=*it;
			it++;
			S.erase(it);
			now-=calc(l,u);
			now-=calc(u,r);
			now+=calc(l,r);
		}
		printf("%d\n",(int)now.val());
	}
}