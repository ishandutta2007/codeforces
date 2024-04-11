// Problem: CF765F Souvenirs
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF765F
// Memory Limit: 500 MB
// Time Limit: 3000 ms
// 2022-03-16 21:09:53
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
#define mid (l+r>>1)
#define lowbit(x) (x&-x)
const int maxn=3e5+5,M=34005,inf=0x3f3f3f3f;
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
int n,m,a[maxn],l,r,ans[maxn],ls[maxn*32],rs[maxn*32],Max[maxn*32],Rt,c[maxn],tot=0;
vector<pi>q[maxn];
void add(int x,int num){for(int i=x;i;i-=lowbit(i))c[i]=min(c[i],num);}
int qry(int x){int res=inf;for(int i=x;i<=n;i+=lowbit(i))res=min(c[i],res);return res;}// [x,n] 
void change(int &rt,int l,int r,int pos,int num)
{
	if(l>pos||r<pos)return;
	if(!rt)rt=++tot;Max[rt]=max(Max[rt],num);//
	if(l==r)return;change(ls[rt],l,mid,pos,num);change(rs[rt],mid+1,r,pos,num);
}
int query(int rt,int l,int r,int L,int R)
{
	if(!rt)return 0;
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R)return Max[rt];
	return max(query(ls[rt],l,mid,L,R),query(rs[rt],mid+1,r,L,R));
}
void solve()
{
	memset(ls,0,sizeof ls);memset(rs,0,sizeof rs);Rt=0,tot=0;
	memset(Max,0,sizeof Max);memset(c,0x3f,sizeof c);
	for(int i=1;i<=n;i++)
	{
		int x=query(Rt,0,inf,a[i],inf);
		while(x)
		{
			add(x,a[x]-a[i]);if(a[x]-a[i]==0)break;
			x=query(Rt,0,inf,a[i],(a[i]+a[x])/2);
		}
		change(Rt,0,inf,a[i],i);
		for(auto j:q[i])ans[j.se]=min(ans[j.se],qry(j.fi));
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(ans,0x3f,sizeof ans);
	n=read();for(int i=1;i<=n;i++)a[i]=read();
	m=read();for(int i=1;i<=m;i++)l=read(),r=read(),q[r].pb(mp(l,i));
	solve();for(int i=1;i<=n;i++)a[i]=inf-a[i];solve();
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
 	return 0;
}