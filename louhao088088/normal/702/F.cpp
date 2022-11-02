// Problem: CF702F T-Shirts
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF702F
// Memory Limit: 1000 MB
// Time Limit: 4000 ms
// 2022-02-24 20:12:53
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
#define lowbit (x&-x)
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
int n,m,tot=0,ls[maxn],rs[maxn],sum[maxn],tag[maxn],c[maxn],ans[maxn],tag2[maxn],id[maxn],Rt,w[maxn];
struct node {int x,y;}a[maxn],b[maxn];
mt19937 rnd(time(0));
bool cmp(node a,node b){if(a.x==b.x)return a.y<b.y;return a.x>b.x;}
int ins(int x,int y){int rt=++tot;w[rt]=rnd();ls[rt]=rs[rt]=0;c[rt]=x,sum[rt]=0;tag[rt]=0,tag2[rt]=0;id[rt]=y;return rt;}
void pushx(int rt,int x,int y){if(!rt)return;tag[rt]+=x;tag2[rt]+=y;c[rt]-=x;sum[rt]+=y;}
void push(int rt){pushx(ls[rt],tag[rt],tag2[rt]),pushx(rs[rt],tag[rt],tag2[rt]);tag[rt]=0;tag2[rt]=0;}
int merge(int a,int b)
{
	if(!a||!b)return a+b;push(a);push(b);
	if(w[a]>w[b]){ls[b]=merge(a,ls[b]);return b;}
	rs[a]=merge(rs[a],b);return a;
}
void split(int rt,int &a,int &b,int val)
{
	//cout<<rt<<" "<<a<<" "<<b<<" "<<c[rt]<<" "<<ls[rt]<<" "<<rs[rt]<<" "<<val<<endl;
	if(!rt){a=0,b=0;return;}push(rt);
	if(c[rt]>=val)b=rt,split(ls[b],a,ls[b],val);
	else a=rt,split(rs[a],rs[a],b,val);
}
void dfs(int rt,int x)
{
	if(!rt)return;push(rt);
	dfs(ls[rt],x),dfs(rs[rt],x);ls[rt]=rs[rt]=0;
	int a,b;c[rt]-=x;sum[rt]++;tag[rt]=0,tag2[rt]=0;
	//cout<<id[rt]<<" "<<c[rt]<<" "<<sum[rt]<<endl;
	split(Rt,a,b,c[rt]);Rt=merge(a,merge(rt,b));
}
void solve(int x,int y)
{
	int a,b,d;
	split(Rt,a,b,y);
	split(b,b,d,y*2);
	pushx(d,y,1);Rt=a;
	dfs(b,y);Rt=merge(Rt,d);
}
void dfs1(int x)
{
	if(!x)return ;push(x);
	dfs1(ls[x]),dfs1(rs[x]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i].y=read(),a[i].x=read();
	m=read();sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)
		b[i].x=read(),b[i].y=i;
	sort(b+1,b+m+1,cmp);
	for(int i=m;i>=1;i--)Rt=merge(Rt,ins(b[i].x,b[i].y));
	for(int i=1;i<=n;i++)
		solve(a[i].x,a[i].y);//cout<<tot<<endl;
	dfs1(Rt);
	for(int i=1;i<=m;i++)ans[id[i]]=sum[i];
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
 	return 0;
}