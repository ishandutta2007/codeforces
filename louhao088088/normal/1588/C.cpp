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
const int maxn=3e5+5,M=34005;
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
#define int long long
int n,m,a[maxn],sum[maxn],Min[maxn*4],Max[maxn*4],ans,b[maxn],c[maxn],T,tot;
map<int,int>s;
queue<int>q[maxn];
void build(int rt,int l,int r)
{
	if(l==r){Min[rt]=b[l];Max[rt]=c[l];return;}
	build(ls,l,mid),build(rs,mid+1,r);
	Min[rt]=min(Min[ls],Min[rs]);Max[rt]=max(Max[ls],Max[rs]);
}
int query1(int rt,int l,int r,int L,int R)
{
	if(L>r||R<l)return 1e18;
	if(l>=L&&r<=R)return Min[rt];
	return min(query1(ls,l,mid,L,R),query1(rs,mid+1,r,L,R));
}
int query2(int rt,int l,int r,int L,int R)
{
	if(L>r||R<l)return -1e18;
	if(l>=L&&r<=R)return Max[rt];
	return max(query2(ls,l,mid,L,R),query2(rs,mid+1,r,L,R));
}
void solve()
{
	n=read();tot=0;s.clear();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
		if(i&1)sum[i]=sum[i-1]+a[i];
		else sum[i]=sum[i-1]-a[i];
	for(int i=1;i<=n;i++)
		if(i&1)b[i]=sum[i],c[i]=-1e18;
		else c[i]=sum[i],b[i]=1e18;
//	for(int i=1;i<=n;i++)
	//	cout<<sum[i]<<" ";
	//cout<<endl;
	build(1,1,n);ans=0;
	for(int i=n;i>=0;i--)
	{
		if(!s[sum[i]])s[sum[i]]=++tot;
		int k=s[sum[i]];//cout<<k<<" "<<tot<<" "<<q[k].size()<<endl;
		while(!q[k].empty())
		{
			//cout<<query2(1,1,n,i+1,q[k].front())<<" "<<sum[i]<<endl;
			if(query1(1,1,n,i+1,q[k].front())<sum[i])q[k].pop();
			else if(query2(1,1,n,i+1,q[k].front())>sum[i])q[k].pop();
			else break;
		}//cout<<q[k].size()<<endl;
		ans+=q[k].size();q[k].push(i);
	}
	cout<<ans<<endl;
	for(int i=1;i<=tot;i++)while(!q[i].empty())q[i].pop();
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
	{
		solve();
	}
 	return 0;
}


/*********************************************************************
    :louhao088
    : 2021-11-14 15:09
*********************************************************************/