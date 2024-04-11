#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
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
#define maxn 100010
struct Store
{
	int x,y;
}	st[maxn];
bool cmp(Store a,Store b)
{
	return a.x>b.x;
}
int num[maxn],cnt;
int a[maxn];
int root[maxn];
struct Data
{
	int l,r;
	bool is;
	int num;
};
Data operator+(Data a,Data b)
{
	Data c;
	if (a.is && b.is)	c.is=true,c.l=a.l+b.l,c.r=a.r+b.r,c.num=a.num+b.num;else
	if (!a.is && b.is)	c.is=false,c.l=a.l,c.r=a.r+b.r,c.num=max(a.num,a.r+b.l);else
	if (a.is && !b.is)	c.is=false,c.l=a.l+b.l,c.r=b.r,c.num=max(b.num,a.r+b.l);else
	c.is=false,c.l=a.l,c.r=b.r,c.num=max(max(a.num,b.num),a.r+b.l);
	return c;
}
struct Seg
{
	Data num;
	int son[2];
}	seg[5000010];
int tot;
int insert(int pre,int l,int r,int pos)
{
	int now=++tot;
	seg[now].son[0]=seg[pre].son[0];
	seg[now].son[1]=seg[pre].son[1];
	if (l==r)
	{
		seg[now].num.l=seg[now].num.r=seg[now].num.num=1;
		seg[now].num.is=true;
		return now;
	}
	int mid=(l+r)>>1;
	if (pos<=mid)	seg[now].son[0]=insert(seg[pre].son[0],l,mid,pos);else
		seg[now].son[1]=insert(seg[pre].son[1],mid+1,r,pos);
	seg[now].num=seg[seg[now].son[0]].num+seg[seg[now].son[1]].num;
	return now;
}
Data query(int t,int l,int r,int ql,int qr)
{
	if (ql<=l && qr>=r)	return seg[t].num;
	int mid=(l+r)>>1;
	if (qr<=mid)	return query(seg[t].son[0],l,mid,ql,qr);
	if (ql>mid)	return query(seg[t].son[1],mid+1,r,ql,qr);
	return query(seg[t].son[0],l,mid,ql,mid)+query(seg[t].son[1],mid+1,r,mid+1,qr);
}
int n,m;
int main()
{
	read(n);
	for (int i=1;i<=n;i++)	read(a[i]);
	for (int i=1;i<=n;i++)
	{
		st[i].x=a[i];
		st[i].y=i;
		num[i]=a[i];
	}
	sort(st+1,st+n+1,cmp);
	sort(num+1,num+n+1);
	cnt=unique(num+1,num+n+1)-num-1;
	for (int i=1;i<=cnt;i++)
	if (cnt-i+1>i)	swap(num[i],num[cnt-i+1]);
	int pre=0,now=1;
	for (int i=1;i<=cnt;i++)
	{
		while (now<=n && st[now].x==num[i])	root[i]=insert(pre,1,n,st[now].y),pre=root[i],now++;
	}
	read(m);
	for (int i=1;i<=m;i++)
	{
		int x,y,w;
		read(x),read(y),read(w);
		int l=1,r=cnt;
		while (l<r)
		{
			int mid=(l+r)>>1;
			Data mjy=query(root[mid],1,n,x,y);
			if (mjy.num<w)	l=mid+1;else r=mid;
		}
		printf("%d\n",num[r]);
	}
	return 0;
}