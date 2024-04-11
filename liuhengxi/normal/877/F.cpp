#include<cstdio>
#include<cmath>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct query
{
	int l,r,id;
}qu[N];
int n,k,a[N],b,q,s[N+1],t[N+1],cnt1[2*N+2],cnt2[2*N+2],L,R;
long long ss[N+1],tt[N+1],v[2*N+2],now,ans[N];
bool cmp(query x,query y){return x.l/b!=y.l/b?x.l<y.l:x.r<y.r;}
int hash1(long long x)
{
	int l=0,r=2*n+2;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(x<v[mid])r=mid;
		else l=mid;
	}
	return l;
}
int main()
{
	read(n);read(k);
	b=sqrt(n);
	if(b<1)b=1;if(b>n)b=n;
	F(i,0,n)
	{
		int t;read(t);
		a[i]=3-t*2;
	}
	F(i,0,n)
	{
		int t;read(t);
		a[i]*=t;
	}
	F(i,0,n)ss[i+1]=ss[i]+a[i];
	F(i,0,n+1)tt[i]=ss[i]-k;
	F(i,0,n+1)v[2*i]=ss[i],v[2*i+1]=tt[i];
	sort(v,v+2*n+2);
	F(i,0,n+1)s[i]=hash1(ss[i]),t[i]=hash1(tt[i]);
	read(q);
	F(i,0,q)read(qu[i].l),read(qu[i].r),qu[i].id=i,--qu[i].l;
	sort(qu,qu+q,cmp);
	cnt1[s[0]]=1;cnt2[t[0]]=1;
	F(i,0,q)
	{
		int l=qu[i].l,r=qu[i].r;
		while(R<r)
		{
			++R;
			now+=cnt1[t[R]];
			++cnt1[s[R]],++cnt2[t[R]];
		}
		while(L>l)
		{
			--L;
			now+=cnt2[s[L]];
			++cnt1[s[L]],++cnt2[t[L]];
		}
		while(R>r)
		{
			--cnt1[s[R]],--cnt2[t[R]];
			now-=cnt1[t[R]];
			--R;
		}
		while(L<l)
		{
			--cnt1[s[L]],--cnt2[t[L]];
			now-=cnt2[s[L]];
			++L;
		}
		ans[qu[i].id]=now;
	}
	F(i,0,q)printf("%lld\n",ans[i]);
	return 0;
}