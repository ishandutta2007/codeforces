#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define inline  __attribute__((always_inline))
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int n,tot,m;
ll sum[200005],bb[200005],b[200005],a[200005],k;
ll pur[200005],c[200005],cnt[200005],d[200005];
ll ans[200005],nowans;
struct query
{
	int l;
	int r;
	int block;
	int id;
}q[100005];

int find(ll x)
{
	int l=1,r=tot,pla=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(b[mid]<=x)
		{
			pla=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return pla;
}
bool cmp(const query &x,const query &y)
{
	if(x.block!=y.block)
	return x.block<y.block;
	return x.l<y.l;
}
void add1(int x)
{
	
	nowans+=cnt[c[x]];cnt[a[x]]++;
	//cout<<"+"<<nowans<<" "<<x<<endl;
}
void add2(int x)
{
	
	nowans+=cnt[d[x]];cnt[a[x]]++;
	//cout<<"+"<<nowans<<" "<<x<<endl;
}
void del1(int x)
{
	cnt[a[x]]--;
	nowans-=cnt[c[x]];
	
	//cout<<"-"<<nowans<<" "<<x<<endl;
}
void del2(int x)
{
	//cout<<d[x]<<' ';
	cnt[a[x]]--;
	nowans-=cnt[d[x]];
	
	//cout<<"-"<<nowans<<" "<<x<<endl;
}
int main()
{
	n=read();k=read();
	for(int i=1;i<=n;i++) a[i]=read()==2?-1:1;
	for(int i=1;i<=n;i++) a[i]*=read();
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++) bb[i]=sum[i];
	sort(bb,bb+n+1);
	for(int i=0;i<=n;i++)
	{
		if(i==0||bb[i]!=bb[i-1])
		{
			b[++tot]=bb[i];
		}
	}
	b[0]=9000000000000000000LL;
	for(int i=0;i<=n;i++)
	{
		int tmp=find(sum[i]-k);
		if(sum[i]-k==b[tmp])
		{
			c[i]=tmp;
		}
		else c[i]=n+2;
	}
	for(int i=0;i<=n;i++)
	{
		int tmp=find(sum[i]+k);
		if(sum[i]+k==b[tmp])
		{
			d[i]=tmp;
		}
		else d[i]=n+2;
	}
	for(int i=0;i<=n;i++) a[i]=find(sum[i]);
	//for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	int block=sqrt(n);
	m=read();
	for(int i=1;i<=m;i++)
	{
		q[i].l=read()-1;q[i].r=read();q[i].block=(q[i].r-1)/block+1;
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	int l=0,r=-1;
	for(int i=1;i<=m;i++)
	{
		while(r<q[i].r) add1(++r);
		while(l>q[i].l) add2(--l);
		while(r>q[i].r) del1(r--);
		while(l<q[i].l) del2(l++);
		ans[q[i].id]=nowans;
	}
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
}
/*
8 0
1 1 2 1 1 1 2 2
2 1 3 2 1 1 2 3
5
1 4
2 8
2 4
6 7
4 6
*/