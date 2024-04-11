//This is meng meng da mjy>_<
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000007
typedef long long ll;
using namespace std;

void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 150010
int b[maxn];
int num[maxn];
int cnt[maxn];
int pos[maxn];
int a[maxn];
int d[maxn];
int n,m,h,r,mjy;
struct Seg
{
	int minx;
	int tag;
}	seg[maxn<<2];
inline void update(int t)
{
	seg[t].minx=min(seg[t<<1].minx,seg[t<<1|1].minx);
}
void insert(int t,int l,int r,int pos,int val)
{
	if (l==r)
	{
		seg[t].minx=val;
		return;
	}
	int mid=(l+r)>>1;
	if (pos<=mid)	insert(t<<1,l,mid,pos,val);else insert(t<<1|1,mid+1,r,pos,val);
	update(t);
}
void addtag(int t,int val)
{
	seg[t].tag+=val;
	seg[t].minx+=val;
}
void pushdown(int t)
{
	if (seg[t].tag)
	{
		addtag(t<<1,seg[t].tag);
		addtag(t<<1|1,seg[t].tag);
		seg[t].tag=0;
	}
}
void add(int t,int l,int r,int ql,int qr,int val)
{
	if (l==ql && r==qr)
	{
		addtag(t,val);
		return;
	}
	pushdown(t);
	int mid=(l+r)>>1;
	if (qr<=mid)	add(t<<1,l,mid,ql,qr,val);else
	if (ql>mid)	add(t<<1|1,mid+1,r,ql,qr,val);else
	add(t<<1,l,mid,ql,mid,val),add(t<<1|1,mid+1,r,mid+1,qr,val);
	update(t);
}
inline int query()
{
	return seg[1].minx;
}
int main()
{
	read(n),read(m),read(h);
	for (int i=1;i<=m;i++)	read(b[i]),num[i]=b[i];
	for (int i=1;i<=n;i++)	read(a[i]);
	sort(num+1,num+m+1);
	r=unique(num+1,num+m+1)-num-1;
	for (int i=1;i<=m;i++)	cnt[lower_bound(num+1,num+r+1,b[i])-num]++;
	for (int i=1;i<=m;i++)
	{
		pos[i]=lower_bound(num+1,num+r+1,h-a[i])-num;
		d[pos[i]]++;
	}
	int now=0;
	for (int i=1;i<=r;i++)
	{
		now+=d[i];
		now-=cnt[i];
		insert(1,1,r,i,now);
	}
	mjy=(query()>=0);
	for (int i=m+1;i<=n;i++)
	{
		pos[i]=lower_bound(num+1,num+r+1,h-a[i])-num;
		int l=pos[i-m];
		if (pos[i]>l)	add(1,1,r,l,pos[i]-1,-1);
		if (pos[i]<l)	add(1,1,r,pos[i],l-1,1);
		mjy+=(query()>=0);
	}
	printf("%d\n",mjy);
	return 0;
}