#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct node
{
	int id;
	int x;
}arr[200005];
int root[2000005];
int lson[4000005],rson[4000005],sum[4000005],tot=1;
int n,q,x1,x2,yy1,y2;
void ins(int rt,int &now,int l,int r,int pos,int num)
{
	if(!now)
	{
		now=++tot;
		sum[now]=lson[now]=rson[now]=0;
	}
	if(l==r)
	{
		sum[now]+=num;
		return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) 
	{
		ins(lson[rt],lson[now],l,mid,pos,num);
		rson[now]=rson[rt];
	}
	else
	{
		ins(rson[rt],rson[now],mid+1,r,pos,num);
		lson[now]=lson[rt];
	}
	sum[now]=sum[lson[now]]+sum[rson[now]];
	return;
}
int query(int rt,int l,int r,int L,int R)
{
	if(rt==0) return 0;
	if(L>R) return 0;
	if(rt==0) return 0;
	if(L<=l&&r<=R) return sum[rt];
	int mid=l+r>>1;
	int sum=0;
	if(L<=mid) sum+=query(lson[rt],l,mid,L,R);
	if(R>=mid+1) sum+=query(rson[rt],mid+1,r,L,R);
	return sum;
}
long long calc(long long t)
{
	return (t-1)*t/2;
}
int main()
{
	n=read(),q=read();
	root[0]=1;
	for(int i=1;i<=n;i++)
	{
		arr[i].x=read();
		arr[i].id=i;
		ins(root[i-1],root[i],1,n,arr[i].x,1);
	}
	while(q--)
	{
		x1=read(),yy1=read(),x2=read(),y2=read();
		long long t1=0,t2=0,t3=0,t4=0;
		t1=max(0,x1-1);
		t2=query(root[n],1,n,1,yy1-1);
		t3=max(0,n-x2);
		t4=query(root[n],1,n,y2+1,n);
		long long sum=calc(n);
		sum-=calc(t1)+calc(t2)+calc(t3)+calc(t4);
		t1=query(root[x1-1],1,n,1,yy1-1);
		t2=query(root[x1-1],1,n,y2+1,n);
		t3=query(root[n],1,n,1,yy1-1)-query(root[x2],1,n,1,yy1-1);
		t4=query(root[n],1,n,y2+1,n)-query(root[x2],1,n,y2+1,n);
		sum+=calc(t1)+calc(t2)+calc(t3)+calc(t4);
		printf("%lld\n",sum);
	}
}