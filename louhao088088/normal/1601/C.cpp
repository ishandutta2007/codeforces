#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define lowbit(x) (x)&(-x)
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
const int maxn=2e6+5,M=34005;
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
int n,m,c[2*maxn],a[maxn],b[maxn],sum[maxn*2],sum2[maxn*2],ans[maxn*2],d[maxn],T,tot=0,s[maxn*2];
long long Ans=0;
void add(int x,int y){for(int i=x;i<=tot;i+=lowbit(i))c[i]+=y;}
int query(int x){int res=0;for(int i=x;i;i-=lowbit(i))res+=c[i];return res;}
void build(int rt,int l,int r)
{
	sum[rt]=sum2[rt]=ans[rt]=0;
	if(l==r){return;}
	build(ls,l,mid),build(rs,mid+1,r);
}
void pushup(int rt)
{
	sum[rt]=sum[ls]+sum[rs];sum2[rt]=sum2[ls]+sum2[rs];
	ans[rt]=min(sum[ls]+sum2[rs],min(ans[ls]+sum2[rs],sum[ls]+ans[rs]));
}
void change(int rt,int l,int r,int pos,int val)
{
	if(l>pos||r<pos)return;
	if(l==r)
	{
		sum[rt]=sum2[rt]=ans[rt]=0;
		if(val==1)sum[rt]=1;
		if(val==-1)sum2[rt]=1;
		return;
	}
	change(ls,l,mid,pos,val);change(rs,mid+1,r,pos,val);
	pushup(rt);
}
vector<int>id[maxn];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		n=read(),m=read();tot=0;Ans=0;
		for(int i=1;i<=n;i++)a[i]=d[++tot]=read();
		for(int i=1;i<=m;i++)b[i]=d[++tot]=read();
		sort(b+1,b+m+1);sort(d+1,d+tot+1);
		for(int i=1;i<=n;i++)a[i]=lower_bound(d+1,d+tot+1,a[i])-d;
		for(int i=1;i<=m;i++)b[i]=lower_bound(d+1,d+tot+1,b[i])-d;
		for(int i=1;i<=n;i++)
		{
			add(a[i],1);Ans+=i-query(a[i]);
		}
		for(int i=1;i<=n;i++)id[a[i]].pb(i);
		for(int i=1;i<=m;i++)s[b[i]]++;
		build(1,1,n);
		for(int i=1;i<=n;i++)change(1,1,n,i,1);
		for(int i=1;i<=tot;i++)
		{
			for(auto x:id[i])change(1,1,n,x,0);
			Ans+=1ll*s[i]*min(min(sum[1],sum2[1]),ans[1]);
			//cout<<sum[1]<<" "<<sum2[1]<<" "<<ans[1]<<" "<<s[i]<<endl;
			for(auto x:id[i])change(1,1,n,x,-1);
		}
		for(int i=1;i<=tot;i++)c[i]=0,s[i]=0;
		for(int i=1;i<=n;i++)id[a[i]].clear();
		cout<<Ans<<endl;
	}
 	return 0;
}