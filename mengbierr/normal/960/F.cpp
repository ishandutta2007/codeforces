#include<iostream>
#include<cstdio>
#include<cstring>
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
int ch[5000005][5],w[5000005];
int rt[100005],sz;
int n,m,ans;
struct data
{
	int l,r,w;
}q[100005];
int query(int p,int l,int r,int x,int y)
{
	if(y<x) return 0;
	if(!p) return 0;
	if(l==x&&r==y) return w[p];
	int mid=l+r>>1;
	if(y<=mid) return query(ch[p][0],l,mid,x,y);
	else if(x>mid) return query(ch[p][1],mid+1,r,x,y);
	else
	{
		return max(query(ch[p][0],l,mid,x,mid),query(ch[p][1],mid+1,r,mid+1,y));
	}
}
void modify(int &p,int l,int r,int x,int y)
{
	if(!p) p=++sz;
	int mid=l+r>>1;
	if(l==r)
	{
		w[p]=max(w[p],y);
		return;
	}
	if(x<=mid) modify(ch[p][0],l,mid,x,y);
	else modify(ch[p][1],mid+1,r,x,y);
	w[p]=max(w[ch[p][0]],w[ch[p][1]]);
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		q[i].l=read();q[i].r=read();q[i].w=read();
	}
	for(int i=m;i;i--)
	{
		int temp=query(rt[q[i].r],1,100000,q[i].w+1,100000);
		//cout<<temp+1<<" ";
		ans=max(ans,temp+1);
		modify(rt[q[i].l],1,100000,q[i].w,temp+1);
	}
	cout<<ans;
}