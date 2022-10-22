#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=4e5+5,M=2e5+5;
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
struct segtree
{
	#define lc (p<<1)
	#define rc (p<<1|1)
	int n;
	int tot[N<<2];long long sum[N<<2],sumw[N<<2];
	void update(int p,int l,int r,int x,long long v)
	{
		if(r-l==1)return tot[p]=!!v,sum[p]=v,void();
		int mid=(l+r)>>1;
		if(x<mid)update(lc,l,mid,x,v);
		else update(rc,mid,r,x,v);
		tot[p]=tot[lc]+tot[rc];
		sum[p]=sum[lc]+sum[rc];
		sumw[p]=sumw[lc]+sumw[rc]+sum[rc]*tot[lc];
	}
	void update(int x,long long v){update(1,0,n,x,v);}
	void query(int p,int l,int r,int x,int y,int &ac,long long &as,long long &aw)
	{
		if(y<=l||r<=x)return as=aw=ac=0,void();
		if(x<=l&&r<=y)return ac=tot[p],as=sum[p],aw=sumw[p],void();
		int mid=(l+r)>>1;
		int lac,rac;long long las,law,ras,raw;
		query(lc,l,mid,x,y,lac,las,law);
		query(rc,mid,r,x,y,rac,ras,raw);
		ac=lac+rac;as=las+ras;aw=law+raw+ras*lac;
	}
	void query(int x,int y,int &ac,long long &as,long long &aw){query(1,0,n,x,y,ac,as,aw);}
	long long binary(int p,int l,int r,int x)
	{
		if(r-l==1)return x*sum[p];
		int mid=(l+r)>>1;
		if(x<tot[lc])return binary(lc,l,mid,x);
		return sum[lc]+binary(rc,mid,r,x-tot[lc]);
	}
	long long binary(int x){return binary(1,0,n,x);}
	int binaryp(int p,int l,int r,int x)
	{
		if(r-l==1)return l+x;
		int mid=(l+r)>>1;
		if(x<tot[lc])return binaryp(lc,l,mid,x);
		return binaryp(rc,mid,r,x-tot[lc]);
	}
	int binaryp(int x){return binaryp(1,0,n,x);}
	#undef lc
	#undef rc
}seg;
int n,k,m,siz,t[M];
long long s[M],a[M],v[N],sum;
long long query()
{
	int half=(siz+1)>>1,l=0,r=half+1;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		(seg.binary(mid)>sum-seg.binary(siz-mid+1)?l:r)=mid;
	}
	long long ans=sum,le,ri;
	int ac;long long as,aw;
	seg.query(0,seg.binaryp(l),ac,as,aw);
	le=as*ac-aw;
	seg.query(seg.binaryp(siz-l),n,ac,as,aw);
	ri=aw;
	ans-=2*(le-ri);
	if((siz&1)&&l==half)ans+=seg.binary(half)*2-sum;
	return ans;
}
int main()
{
	read(k,m);
	F(i,0,k)v[i]=read(s[i]);
	F(i,0,m)read(t[i],a[i]),v[i+k]=a[i];
	sort(v,v+k+m);n=(int)(unique(v,v+k+m)-v);
	seg.n=n;
	F(i,0,k)seg.update((int)(lower_bound(v,v+n,s[i])-v),s[i]),sum+=s[i];
	siz=k;
	printf("%lld\n",query());
	F(i,0,m)
	{
		if(t[i]==1)seg.update((int)(lower_bound(v,v+n,a[i])-v),a[i]),sum+=a[i],++siz;
		else seg.update((int)(lower_bound(v,v+n,a[i])-v),0),sum-=a[i],--siz;
		printf("%lld\n",query());
	}
	return 0;
}