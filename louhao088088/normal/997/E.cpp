// Problem: CF526F Pudding Monsters
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF526F
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2022-03-11 21:26:49
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
int n,m,mx[maxn],mn[maxn],Min[maxn*4],sum[maxn*4],tag[maxn*4],s[maxn*4],a[maxn],x,y,ans,top1,top2,res[maxn],tag2[maxn*4];
vector<pi>e[maxn];
void pushx(int rt,int num){Min[rt]+=num;tag[rt]+=num;}
void pushy(int rt,int num){s[rt]+=num*sum[rt];tag2[rt]+=num;}
void push(int rt){if(tag[rt]){pushx(ls,tag[rt]),pushx(rs,tag[rt]);tag[rt]=0;}
if(tag2[rt]){if(Min[ls]==Min[rt])pushy(ls,tag2[rt]);if(Min[rs]==Min[rt])pushy(rs,tag2[rt]);tag2[rt]=0;}}
void pushup(int rt)
{
	Min[rt]=min(Min[ls],Min[rs]);s[rt]=s[ls]+s[rs];
	sum[rt]=((Min[ls]==Min[rt])?sum[ls]:0)+((Min[rs]==Min[rt])?sum[rs]:0);
}
void build(int rt,int l,int r)
{
	if(l==r){Min[rt]=l;sum[rt]=1;return;}
	build(ls,l,mid),build(rs,mid+1,r);pushup(rt);
}
void add(int rt,int l,int r,int L,int R,int num)
{
	if(l>R||r<L)return;
	if(l>=L&&r<=R){Min[rt]+=num;tag[rt]+=num;return;}
	push(rt);add(ls,l,mid,L,R,num);add(rs,mid+1,r,L,R,num);
	pushup(rt);
}
int query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R)return s[rt];push(rt);
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=read();//m=3;
	for(int i=1;i<=m;i++){x=read(),y=read(),e[y].pb(mp(x,i));}
	build(1,1,n);mn[1]=0,mx[1]=0;top1=top2=1;
	for(int i=1;i<=n;i++)
	{
		pushx(1,-1);
		while(top1>1&&a[mn[top1]]>a[i])add(1,1,n,mn[top1-1]+1,mn[top1],a[mn[top1]]),top1--;
		while(top2>1&&a[mx[top2]]<a[i])add(1,1,n,mx[top2-1]+1,mx[top2],-a[mx[top2]]),top2--;
		mn[++top1]=i,mx[++top2]=i;
		add(1,1,n,mn[top1-1]+1,mn[top1],-a[mn[top1]]);
		add(1,1,n,mx[top2-1]+1,mx[top2],a[mx[top2]]);
		pushy(1,1);
		/*cout<<"Min:";
		for(int i=1;i<=top1;i++)cout<<a[mn[i]]<<" ";cout<<endl;
		cout<<"Max:";
		for(int i=1;i<=top2;i++)cout<<a[mx[i]]<<" ";cout<<endl;
		cout<<s[1]<<" "<<sum[1]<<endl;*/
		for(auto j:e[i])res[j.se]=query(1,1,n,j.fi,i);
	}
	for(int i=1;i<=m;i++)printf("%lld\n",res[i]);
 	return 0;
}