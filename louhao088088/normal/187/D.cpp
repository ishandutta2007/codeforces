#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
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
int n,m,a[maxn],T,b[maxn],tot=0,Min[maxn*4],s[maxn],d[maxn],f[maxn],t2,t1,l[maxn],q,x,ans;
void pushup(int rt){Min[rt]=min(Min[ls],Min[rs]);}
void build(int rt,int l,int r)
{
	if(l==r){Min[rt]=1e9;return;}
	build(ls,l,mid),build(rs,mid+1,r);pushup(rt);
}
void change(int rt,int l,int r,int x,int num)
{
	if(l>x||r<x)return;
	if(l==r){Min[rt]=num;return;}
	change(ls,l,mid,x,num),change(rs,mid+1,r,x,num),pushup(rt);
}
int query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 1e9;
	if(l>=L&&r<=R)return Min[rt];
	return min(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));	
}
int get(int l,int r)
{
	int x=lower_bound(b+1,b+n+1,l)-b;
	int y=lower_bound(b+1,b+n+1,r)-b;
	if(b[y]>r)y--;if(y==n+1)y--;
	if(x>y)return 1e9;
	return query(1,1,n,x,y); 
}
int find(int s)
{
	int res=1e9,l,r;if(s==0)s=T;
	if(s<=t1)
	{
		l=t1-s,r=T-s-1;res=min(res,get(l,r));
	}
	else
	{
		l=0,r=T-s-1;res=min(res,get(l,r));
		l=t1-s+T,r=T-1;res=min(res,get(l,r));
	}
	if(res>n)return -1;
	return res;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),t1=read(),t2=read();T=t1+t2;
	for(int i=1;i<=n;i++)
	{
		l[i]=read(),s[i]=s[i-1]+l[i];b[i]=(s[i])%T;
	}l[n+1]=read();s[n+1]=s[n]+l[n+1];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		int u=lower_bound(b+1,b+n+1,s[i]%T)-b;
		d[i]=u;
	}
	build(1,1,n);f[n]=l[n+1];change(1,1,n,d[n],n);
	for(int i=n-1;i>=1;i--)
	{
		int x=find(T-b[d[i]]);
		if(x==-1)
		{
			f[i]=s[n+1]-s[i];
		}
		else
		{
			int k=(s[x]-s[i]-1)/T+1;
			f[i]=f[x]+k*T;
		}
		change(1,1,n,d[i],i);
	}
	q=read();
	for(int i=1;i<=q;i++)
	{
		x=read();
		int y=find(x%T);
		if(y==-1)
		{
			ans=x+s[n+1];
		}
		else
		{
			ans=f[y];int k=s[y]+x;k=(k-1)/T+1;
			ans=ans+k*T;
		}
		printf("%lld\n",ans);
	}
 	return 0;
}