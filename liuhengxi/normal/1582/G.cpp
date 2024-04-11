#include<cstdio>
#include<algorithm>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,INF=0x3fffffff;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
template<typename T,T e(),T f(T,T),int N,T d()=e>struct segtree
{
#define lc (p<<1)
#define rc (p<<1|1)
private:
	int n;T seg[N<<2];
	void build(int p,int l,int r)
	{
		int mid=(l+r)>>1;
		if(r-l==1)return seg[p]=d(),void();
		build(lc,l,mid);build(rc,mid,r);
		seg[p]=f(seg[lc],seg[rc]);
	}
	void build(int p,int l,int r,T (*const &dd)(int))
	{
		int mid=(l+r)>>1;
		if(r-l==1)return seg[p]=dd(l),void();
		build(lc,l,mid,dd);build(rc,mid,r,dd);
		seg[p]=f(seg[lc],seg[rc]);
	}
	void update(int p,int l,int r,const int &x,const T &v)
	{
		int mid=(l+r)>>1;
		if(r-l==1)return seg[p]=v,void();
		if(x<mid)update(lc,l,mid,x,v);
		else update(rc,mid,r,x,v);
		seg[p]=f(seg[lc],seg[rc]);
	}
	T get(int p,int l,int r,const int &x)
	{
		int mid=(l+r)>>1;
		if(r-l==1)return seg[p];
		if(x<mid)return get(lc,l,mid,x);
		else return get(rc,mid,r,x);
	}
	T query(int p,int l,int r,const int &x,const int &y)
	{
		int mid=(l+r)>>1;
		if(y<=l||r<=x)return e();
		if(x<=l&&r<=y)return seg[p];
		return f(query(lc,l,mid,x,y),query(rc,mid,r,x,y));
	}
public:
	void build(int n_){build(1,0,n=n_);}
	void build(int n_,T dd(int)){build(1,0,n=n_,dd);}
	void update(int x,T v){update(1,0,n,x,v);}
	T get(int x){return get(1,0,n,x);}
	T query(int x,int y){return query(1,0,n,x,y);}
#undef lc
#undef rc
};
int mx(){return INF;}
int mn(int a,int b){return a<b?a:b;}
segtree<int,mx,mn,N> s;
vector<int> e[N];
int n,a[N],f[N];
long long ans;
char b[N];
int main()
{
	s.build(N);
	F(i,2,N)
	{
		for(int j=2;j*j<=i;++j)if(i%j==0){f[i]=j;break;}
		if(!f[i])f[i]=i;
	}
	read(n);
	F(i,0,n)read(a[i]);
	scanf("%s",b);
	for(int i=n;~--i;)
	{
		if(b[i]=='*')
		{
			for(int p=f[a[i]],t;a[i]!=1;p=f[a[i]])
			{
				for(t=0;a[i]%p==0;a[i]/=p,++t);
				F(_,0,t)if(!e[p].empty())e[p].pop_back();
				if(e[p].empty())s.update(p,n);
				else s.update(p,e[p].back());
			}
		}
		else
		{
			for(int p=f[a[i]],t;a[i]!=1;p=f[a[i]])
			{
				for(t=0;a[i]%p==0;a[i]/=p,++t);
				F(_,0,t)e[p].push_back(i);
				if(e[p].empty())s.update(p,n);
				else s.update(p,e[p].back());
			}
		}
		ans+=min(n,s.query(0,N))-i;
	}
	printf("%lld\n",ans);
	return 0;
}