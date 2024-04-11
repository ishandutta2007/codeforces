// Problem: CF438D The Child and Sequence
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF438D
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 2022-02-19 07:38:16
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
#define int long long
const int maxn=4e5+5,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,a[maxn],sum[maxn],Max[maxn],l,r,x,op;
void pushup(int rt){sum[rt]=sum[ls]+sum[rs],Max[rt]=max(Max[ls],Max[rs]);}
void build(int rt,int l,int r)
{
	if(l==r){Max[rt]=sum[rt]=a[l];return;}
	build(ls,l,mid),build(rs,mid+1,r);pushup(rt);
}
void updata(int rt,int l,int r,int x,int num)
{
	if(l>x||r<x)return ;
	if(l==r){Max[rt]=sum[rt]=num;return;}
	updata(ls,l,mid,x,num),updata(rs,mid+1,r,x,num);pushup(rt);
}
void updata2(int rt,int l,int r,int L,int R,int x)
{
	if(l>R||r<L)return ;if(Max[rt]<x)return ;
	if(l==r){sum[rt]%=x,Max[rt]%=x;return;}
	updata2(ls,l,mid,L,R,x),updata2(rs,mid+1,r,L,R,x);pushup(rt);
}
int query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R)return sum[rt];
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		op=read();
		if(op==1)l=read(),r=read(),printf("%lld\n",query(1,1,n,l,r));
		else if(op==2)l=read(),r=read(),x=read(),updata2(1,1,n,l,r,x);
		else l=read(),x=read(),updata(1,1,n,l,x);
	}
 	return 0;
}