#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define mid (l+r>>1)
#define lowbit (x&-x)
const int maxn=1e5+5,M=2e5,mod=1e9+7;
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
int n,m,Rt[maxn],sum[maxn*400],tot,inv[M+5],f[M+5],s[M+5],x,ans=0,l,r;
int ls[maxn*400],rs[maxn*400];
int merge(int pre,int l,int r,int x,int num)
{
	if(l>x||r<x)return pre;
	int rt=++tot;
	if(l==r){sum[rt]=1ll*sum[pre]*num%mod;return rt;}
	ls[rt]=merge(ls[pre],l,mid,x,num),rs[rt]=merge(rs[pre],mid+1,r,x,num);
	sum[rt]=1ll*sum[ls[rt]]*sum[rs[rt]]%mod;return rt;
}
int query(int rt,int l,int r,int x)
{
	if(l>=x)return sum[rt];
	if(r<x)return 1;
	return 1ll*query(ls[rt],l,mid,x)*query(rs[rt],mid+1,r,x)%mod;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();inv[1]=1,sum[0]=1;
	for(int i=2;i<=M;i++)
	{
		inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
		if(!f[i]){for(int k=i;k<=M;k+=i)f[k]=i;}
	}
	for(int i=1;i<=n;i++)
	{
		x=read();Rt[i]=Rt[i-1];
		while(f[x])
		{
			int k=f[x],t=1;
			while(x%k==0)
			{
				t=t*k;x=x/k;
				if(s[t])Rt[i]=merge(Rt[i],1,n,s[t],inv[k]);
				s[t]=i;
			}Rt[i]=merge(Rt[i],1,n,i,t);
		}
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		l=read(),r=read();l=(l+ans)%n+1,r=(r+ans)%n+1;
		if(l>r)swap(l,r);
		ans=query(Rt[r],1,n,l);printf("%d\n",ans);
	}
 	return 0;
}