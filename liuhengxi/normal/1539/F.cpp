#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
	void build(int p,int l,int r,const T &dd)
	{
		int mid=(l+r)>>1;
		if(r-l==1)return seg[p]=dd,void();
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
	void build(int n_,T dd=d()){build(1,0,n=n_,dd);}
	void update(int x,T v){update(1,0,n,x,v);}
	T get(int x){return get(1,0,n,x);}
	T query(int x,int y){return query(1,0,n,x,y);}
#undef lc
#undef rc
};
struct ps{int pre,suf,sum;ps(){}ps(int a,int b,int c){pre=a,suf=b,sum=c;}};
ps psadd(ps a,ps b){return ps(max(a.pre,a.sum+b.pre),max(b.suf,a.suf+b.sum),a.sum+b.sum);}
ps e_(){return ps(0,0,0);}
int n,a[N],id[N],ans[N];
segtree<ps,e_,psadd,N> seg;
bool cmp(int u,int v){return a[u]<a[v];}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),id[i]=i;
	sort(id,id+n,cmp);
	seg.build(n,ps(1,1,1));
	for(int l=0,r=0;r<n;l=r)
	{
		while(a[id[r]]==a[id[l]])++r;
		F(i,l,r)ans[id[i]]=seg.query(0,id[i]).suf+seg.query(id[i]+1,n).pre+1;
		F(i,l,r)seg.update(id[i],ps(0,0,-1));
	}
	reverse(id,id+n);
	seg.build(n,ps(1,1,1));
	for(int l=0,r=0;r<n;l=r)
	{
		while(a[id[r]]==a[id[l]])++r;
		F(i,l,r)ans[id[i]]=max(ans[id[i]],seg.query(0,id[i]).suf+seg.query(id[i]+1,n).pre);
		F(i,l,r)seg.update(id[i],ps(0,0,-1));
	}
	F(i,0,n)printf("%d ",ans[i]>>1);
	puts("");
	return 0;
}