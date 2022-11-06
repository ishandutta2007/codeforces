#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct xxx{bool ok;int l,r,sum,len,ls,rs;}t[401000];
struct data{int val,id;}a[100100];
int n;
xxx pushup(xxx a,xxx b,int l,int r)
{
	xxx c;c.l=l;c.r=r;
	if(a.ok==1||b.ok==1){c.ok=1;return c;} 
	if(a.sum>0&&b.sum>0&&a.len!=b.len){c.ok=1;return c;}
	c.ls=a.ls;c.rs=b.rs;c.ok=0;
	if(a.ls==a.r-a.l+1)c.ls=a.ls+b.ls;
	if(b.rs==b.r-b.l+1)c.rs=b.rs+a.rs;
	if(c.ls==c.r-c.l+1){c.sum=0;c.len=0;return c;}
	if(a.ls==a.r-a.l+1){c.sum=b.sum;c.len=b.len;return c;}
	if(b.ls==b.r-b.l+1){c.sum=b.sum;c.len=a.len;return c;}
	int len;
	if(a.sum==0&&b.sum!=0)len=b.len;
	if(a.sum!=0&&b.sum==0)len=a.len;
	if(a.sum!=0&&b.sum!=0)len=a.len;
	if(a.sum==0&&b.sum==0)len=-1;
	if(a.rs==0&&b.ls==0){c.sum=a.sum+b.sum;c.len=len;return c;}
	if(a.rs!=0&&b.ls!=0)
	{
		if(len==-1){c.len=a.rs+b.ls;c.sum=1;return c;}
		else if(a.rs+b.ls==len){c.len=len;c.sum=a.sum+b.sum+1;return c;}
		else {c.ok=1;return c;}
	}
	if(a.rs==0&&b.ls!=0)
	{
		if(len==-1){c.len=b.ls;c.sum=1;return c;}
		else if(b.ls==len){c.len=len;c.sum=a.sum+b.sum+1;return c;}
		else {c.ok=1;return c;}
	}
	if(a.rs!=0&&b.ls==0)
	{
		if(len==-1){c.ok=0;c.len=a.rs;c.sum=1;return c;}
		else if(a.rs==len){c.len=len;c.sum=a.sum+b.sum+1;return c;}
		else {c.ok=1;return c;}
	}
}
void build(int x,int l,int r)
{
	t[x].l=l;t[x].r=r;if(l==r)return;int mid=l+r>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
}
void modify(int x,int k)
{
	if(t[x].l==k&&t[x].r==k){t[x].sum=t[x].len=0;t[x].ls=t[x].rs=1;t[x].ok=0;return;}
	int mid=t[x].l+t[x].r>>1;
	if(k<=mid)modify(x<<1,k);
	else modify(x<<1|1,k);
	if(t[x<<1].l==0)t[x]=t[x<<1|1];
	else if(t[x<<1|1].l==0)t[x]=t[x<<1];
	else t[x]=pushup(t[x<<1],t[x<<1|1],t[x].l,t[x].r);
}
bool cmp(data a,data b){return a.val<b.val;}
int main()
{
	scanf("%d",&n);build(1,1,n); 
	for(int i=1;i<=n;i++)scanf("%d",&a[i].val),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	int Max=0,ans;
	for(int i=1;i<=n;)
	{
		int k=a[i].val;
		while(a[i].val==k)
		{
			modify(1,a[i].id);
			i++;
		}
		xxx a;a.ok=a.ls=a.rs=a.sum=a.len=0;a.l=a.r=1;
		xxx b=a;
		xxx c=pushup(a,t[1],1,n+1);
		xxx d=pushup(c,b,0,0);
		if(d.ok==0)
		{
			if(d.sum>Max)Max=d.sum,ans=k+1;
		 } 
	}
	printf("%d",ans);return 0;
 }