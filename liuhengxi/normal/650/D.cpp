#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=4e5+5,INF=0x3fffffff,MOD=1011011231;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
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
	void update(int x,T v){update(1,0,n,x,v);}
	T get(int x){return get(1,0,n,x);}
	T query(int x,int y){return query(1,0,n,x,y);}
#undef lc
#undef rc
};
struct maxcnt{int m,c;maxcnt(){}maxcnt(int a,int b){m=a,c=b;}};
struct query{int x,y,id,ans;friend bool operator<(query a,query b){return a.x<b.x;}}qy[N];
maxcnt f(maxcnt a,maxcnt b){return a.m==b.m?maxcnt(a.m,(a.c+b.c)%MOD):(a.m>b.m?a:b);}
maxcnt e(){return maxcnt(-INF,0);}
int n,m,k,a[N],v[3*N],x[N],y[N],ans[N];
maxcnt pre[N],suf[N],ori;
segtree<maxcnt,e,f,3*N> s1;
int main()
{
	read(n,m);
	F(i,0,n)read(a[i]),v[k++]=a[i]-1,v[k++]=a[i],v[k++]=a[i]+1;
	v[k++]=0;v[k++]=1e9+1;v[k++]=-1;v[k++]=1e9+2;
	sort(v,v+k);k=int(unique(v,v+k)-v);
	F(i,0,n)a[i]=int(lower_bound(v,v+k,a[i])-v);
	F(i,0,m)
	{
		read(x[i],y[i]);--x[i],y[i]=int(lower_bound(v,v+k,y[i])-v);
		qy[i].id=i;qy[i].x=x[i];qy[i].y=y[i];
	}
	sort(qy,qy+m);
	s1.build(k);
	s1.update(0,maxcnt(0,1));
	for(int i=0,j=0;i<n;++i)
	{
		for(;j<m&&qy[j].x==i;++j)ans[qy[j].id]+=s1.query(0,qy[j].y).m;
		pre[i]=s1.query(0,a[i]);
		maxcnt t=s1.get(a[i]);
		s1.update(a[i],f(maxcnt(pre[i].m+1,pre[i].c),t));
	}
	reverse(qy,qy+m);
	ori=s1.query(0,k);
	s1.build(k);
	s1.update(k-1,maxcnt(0,1));
	for(int i=n,j=0;~--i;)
	{
		for(;j<m&&qy[j].x==i;++j)ans[qy[j].id]+=s1.query(qy[j].y+1,k).m;
		suf[i]=s1.query(a[i]+1,k);
		maxcnt t=s1.get(a[i]);
		s1.update(a[i],f(maxcnt(suf[i].m+1,suf[i].c),t));
	}
	F(i,0,m)
	{
		ans[i]=max(ans[i]+1,ori.m-(pre[x[i]].m+suf[x[i]].m+1==ori.m&&(long long)pre[x[i]].c*suf[x[i]].c%MOD==ori.c));
		printf("%d\n",ans[i]);
	}
	return 0;
}