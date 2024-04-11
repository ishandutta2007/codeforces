#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=1e5+5,K=27;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,a[K][N<<2],t[K][N<<2],res[K];
char s[N];
void build(int *a,int *t,int p,int l,int r,int v)
{
	int mid=(l+r)>>1;t[p]=-1;
	if(r-l==1)return a[p]=s[l]=='a'+v,void();
	build(a,t,lc,l,mid,v),build(a,t,rc,mid,r,v);
	a[p]=a[lc]+a[rc];
}
void update(int *a,int *t,int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return t[p]=v,a[p]=v*(r-l),void();
	if(~t[p])
	{
		t[lc]=t[rc]=t[p];
		a[lc]=t[p]*(mid-l);
		a[rc]=t[p]*(r-mid);
		t[p]=-1;
	}
	update(a,t,lc,l,mid,x,y,v);update(a,t,rc,mid,r,x,y,v);
	a[p]=a[lc]+a[rc];
}
int query(int *a,int *t,int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return 0;
	if(x<=l&&r<=y)return a[p];
	if(~t[p])
	{
		t[lc]=t[rc]=t[p];
		a[lc]=t[p]*(mid-l);
		a[rc]=t[p]*(r-mid);
		t[p]=-1;
	}
	return query(a,t,lc,l,mid,x,y)+query(a,t,rc,mid,r,x,y);
}
void dfs(int *a,int *t,int p,int l,int r,int v)
{
	int mid=(l+r)>>1;
	if(r-l==1)
	{
		if(a[p])s[l]='a'+v;
		return;
	}
	if(~t[p])
	{
		t[lc]=t[rc]=t[p];
		a[lc]=t[p]*(mid-l);
		a[rc]=t[p]*(r-mid);
		t[p]=-1;
	}
	dfs(a,t,lc,l,mid,v);dfs(a,t,rc,mid,r,v);
}
int main()
{
#ifndef LOCAL
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
	read(n);read(m);
	scanf("%s",s);
	F(i,0,26)build(a[i],t[i],1,0,n,i);
	while(m--)
	{
		int l,r,cnt=0,sum=0;read(l);read(r);--l;
		F(i,0,26)if((res[i]=query(a[i],t[i],1,0,n,l,r))&1)++cnt;
		if(cnt>1)continue;
		F(i,0,26)if(res[i])update(a[i],t[i],1,0,n,l,r,0);
		F(i,0,26)if(res[i]&1)update(a[i],t[i],1,0,n,(l+r)>>1,(l+r+1)>>1,1);
		F(i,0,26)
		{
			res[i]>>=1;
			if(res[i])
			{
				update(a[i],t[i],1,0,n,l+sum,l+sum+res[i],1);
				update(a[i],t[i],1,0,n,r-sum-res[i],r-sum,1);
				sum+=res[i];
			}
		}
	}
	F(i,0,26)dfs(a[i],t[i],1,0,n,i);
	puts(s);
	return 0;
}