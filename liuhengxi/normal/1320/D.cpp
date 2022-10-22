#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,MOD=1232022251,A0=202201,A1=202219,B=20220127;
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
struct pow
{
	int P[N];
	pow(){F(i,P[0]=1,N)P[i]=int(P[i-1]*(long long)B%MOD);}
}pw;
struct hash
{
	int val,ival,len;
	hash(){}
	hash(int a,int b,int c){val=a,ival=b,len=c;}
}a00(A0,A1,1),a01(A1,A0,1),a1(0,0,0);
int n,q;
char s[N];
hash e(){return hash(0,0,0);}
hash f(hash a,hash b)
{
	hash ans;
	ans.len=a.len+b.len;
	ans.val=int((a.val*(long long)pw.P[b.len]+b.val)%MOD);
	ans.ival=int((a.ival*(long long)pw.P[b.len]+b.ival)%MOD);
	return ans;
}
hash init(int x){return s[x]=='0'?((x&1)?a01:a00):a1;}
segtree<hash,e,f,N> seg;
int main()
{
	read(n);
	scanf("%s",s);
	seg.build(n,init);
	for(read(q);q--;)
	{
		int l1,l2,len,r1,r2;--read(l1),--read(l2);read(len);
		r1=l1+len;r2=l2+len;
		hash res1=seg.query(l1,r1),res2=seg.query(l2,r2);
		puts((l1&1?res1.val:res1.ival)==(l2&1?res2.val:res2.ival)?"Yes":"No");
	}
	return 0;
}