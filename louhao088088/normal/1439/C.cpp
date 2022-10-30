#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls rt<<1
#define rs rt<<1|1
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=5e5+5;
int n,m,ans,a[maxn*4],sum[maxn*4],Min[maxn*4],Max[maxn*4],tag[maxn*4],x,y,opt,M;
inline void push(int rt,int l,int r)
{
	if(tag[rt])
	{
		tag[ls]=tag[rt],tag[rs]=tag[rt];int mid=l+r>>1;sum[ls]=tag[rt]*(mid-l+1);
		sum[rs]=tag[rt]*(r-mid);Min[ls]=Min[rs]=Max[ls]=Max[rs]=tag[rt];tag[rt]=0;
	}
}
inline void build(int rt,int l,int r)
{
	if(l==r){Min[rt]=a[l],Max[rt]=a[l],sum[rt]=a[l];return;}
	int mid=l+r>>1;build(ls,l,mid),build(rs,mid+1,r);
	sum[rt]=sum[ls]+sum[rs],Min[rt]=min(Min[ls],Min[rs]);Max[rt]=max(Max[ls],Max[rs]);
}
inline void change(int rt,int l,int r,int L,int R,int num)
{
	if(l>R||r<L)return;
	if(l>=L&&r<=R){Max[rt]=Min[rt]=num,sum[rt]=(r-l+1)*num;tag[rt]=num;return;}push(rt,l,r);
	int mid=l+r>>1;change(ls,l,mid,L,R,num),change(rs,mid+1,r,L,R,num);
	sum[rt]=sum[ls]+sum[rs],Min[rt]=min(Min[ls],Min[rs]);Max[rt]=max(Max[ls],Max[rs]);
}
inline int query(int rt,int l,int r,int num)
{
	if(Min[rt]>num)return 10000000;
	if(Max[rt]<=num)return l;
	if(l==r)return l;int mid=l+r>>1;push(rt,l,r);
	return min(query(ls,l,mid,num),query(rs,mid+1,r,num));
}
inline int query2(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 0;if(l>=L&&r<=R){return sum[rt];}
	push(rt,l,r);int mid=l+r>>1;
	return query2(ls,l,mid,L,R)+query2(rs,mid+1,r,L,R);
}
inline int query1(int rt,int l,int r,int num)
{
	if(sum[rt]<=num){M=max(M,r);return sum[rt];}
	if(l==r)return 0;push(rt,l,r);int mid=l+r>>1;
	if(sum[ls]<=num)
	{
		M=max(M,mid);
		return sum[ls]+query1(rs,mid+1,r,num-sum[ls]);
	}
	else return query1(ls,l,mid,num);
}
signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		opt=read(),x=read(),y=read();
		if(opt==1)
		{
			int k=query(1,1,n,y);if(k>x)continue;
			else change(1,1,n,k,x,y);
		}
		else
		{
			int k2=query(1,1,n,y);ans=0;M=x;
			while(k2<=n)
			{
				k2=max(k2,M);
				int k=query2(1,1,n,1,k2-1);M=0;
				y=y-query1(1,1,n,y+k)+k;ans+=M-k2+1;
				if(M==n)break;
				k2=query(1,1,n,y);
			}printf("%d\n",ans);
		}
	}
	return 0;
}