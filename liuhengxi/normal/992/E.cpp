#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=2e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,q,a[N];
long long s[N<<2];
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return s[p]=a[l],void();
	build(lc,l,mid);build(rc,mid,r);
	s[p]=s[lc]+s[rc];
}
void update(int p,int l,int r,int x,int v)
{
	int mid=(l+r)>>1;
	if(r-l==1)return s[p]=a[l]=v,void();
	if(x<mid)update(lc,l,mid,x,v);
	else update(rc,mid,r,x,v);
	s[p]=s[lc]+s[rc];
}
int query(int p,int l,int r,long long pre)
{
	int mid=(l+r)>>1,ans;
	if(r-l==1)return s[p]==pre?l:-1;
	if(pre>s[p]||!s[p])return -1;
	ans=query(lc,l,mid,pre);
	if(~ans)return ans;
	return query(rc,mid,r,pre+s[lc]);
}
int main()
{
	read(n,q);
	F(i,0,n)read(a[i]);
	build(1,0,n);
	while(q--)
	{
		int p,x;read(p,x);--p;
		update(1,0,n,p,x);
		if(a[0]==0)puts("1");
		else
		{
			int ans=query(1,0,n,0);
			if(~ans)++ans;
			printf("%d\n",ans);
		}
	}
	return 0;
}