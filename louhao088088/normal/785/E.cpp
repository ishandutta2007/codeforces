// Problem: CF785E Anton and Permutation
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF785E
// Memory Limit: 500 MB
// Time Limit: 4000 ms
// 2022-03-18 12:45:16
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
#define int long long
const int maxn=2e5+5,inf=1e6;
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
int n,m,x,y,ls[maxn*102],rs[maxn*102],sum[maxn*102],a[maxn],rt[maxn],tot=0,ans;
void change(int &rt,int l,int r,int pos,int num)
{
	if(l>pos||r<pos)return;
	if(!rt)rt=++tot;sum[rt]+=num;if(l==r)return;
	change(ls[rt],l,mid,pos,num),change(rs[rt],mid+1,r,pos,num);
}
int query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 0;if(!rt)return 0;
	if(l>=L&&r<=R)return sum[rt];
	return query(ls[rt],l,mid,L,R)+query(rs[rt],mid+1,r,L,R);
}
void add(int x,int num,int z){for(int i=x;i<=n;i+=lowbit(i))change(rt[i],0,inf,num,z);}
int qry(int x,int y)//1->x  y 
{if(y==0)return 0;int res=0;
for(int i=x;i;i-=lowbit(i))res+=query(rt[i],0,inf,0,y-1);return res;}
int query1(int l,int r,int x,int y)// l->r  [x,y] 
{
	if(l>r)return 0;
	int res=qry(r,y+1)-qry(l-1,y+1)-qry(r,x)+qry(l-1,x);
	return res;
} 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=i,add(i,a[i],1);
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read();if(x>y)swap(x,y);
		if(x==y){printf("%lld\n",ans);continue;}
		ans-=query1(x+1,y-1,a[y],inf);
		ans-=query1(x+1,y-1,0,a[x]);
		ans+=query1(x+1,y-1,0,a[y]);
		ans+=query1(x+1,y-1,a[x],inf);
		if(a[x]<a[y])ans++;
		else ans--;
		add(x,a[x],-1),add(y,a[y],-1);
		swap(a[x],a[y]);add(x,a[x],1),add(y,a[y],1);
		printf("%lld\n",ans);
	}
 	return 0;
}