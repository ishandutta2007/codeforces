// Problem: CF464E The Classic Problem
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF464E
// Memory Limit: 750 MB
// Time Limit: 5000 ms
// 2022-03-10 19:24:03
// Author : louhao088
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
const int maxn=1e5+105,M=34005,mod=1e9+7,mod2=1396716913;
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
int n,m,x,y,z,S,T,rt[maxn],las[maxn],ans[maxn],g,ls[maxn*200],rs[maxn*200],sum[maxn*200],tot=0;
bool vis[maxn];
vector<pi>e[maxn];
struct Hash
{
	int x,y;
	Hash operator +(const Hash &k)const{return{(x+k.x)%mod,(y+k.y)%mod2};}
	Hash operator -(const Hash &k)const{return{(x-k.x+mod)%mod,(y-k.y+mod2)%mod2};}
	Hash operator *(const Hash &k)const{return{1ll*x*k.x%mod,1ll*y*k.y%mod2};}
	bool operator ==(const Hash &k)const{return x==k.x&&y==k.y;}
}base,fac[maxn],s[maxn*200];
bool cmp(int rt,int rt1,int l,int r)//x<y return 1;
{
	if(l==r){return sum[rt]<sum[rt1];}
	if(s[rs[rt]]==s[rs[rt1]])return cmp(ls[rt],ls[rt1],l,mid);
	else return cmp(rs[rt],rs[rt1],mid+1,r);
}
int query(int rt,int l,int r,int L,int R)
{
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R)return sum[rt];
	return query(ls[rt],l,mid,L,R)+query(rs[rt],mid+1,r,L,R);
}
void build(int &rt,int l,int r)
{
	rt=++tot;s[rt]={0,0};sum[rt]=0;
	if(l==r)return;build(ls[rt],l,mid);build(rs[rt],mid+1,r);
}
int find(int rt,int l,int r,int pos)
{
	if(l==r)return l;
	if(mid<pos)return find(rs[rt],mid+1,r,pos);
	else if(query(rt,l,r,pos,mid)==mid-pos+1)return find(rs[rt],mid+1,r,mid+1);
	else return find(ls[rt],l,mid,pos);
}
void add(int &rt,int rt1,int l,int r,int pos)
{
	if(l>pos||r<pos)return;rt=++tot;
	ls[rt]=ls[rt1],rs[rt]=rs[rt1];s[rt]=s[rt1];sum[rt]=sum[rt1];
	if(l==r){s[rt]={1,1};sum[rt]=1;return;}
	add(ls[rt],ls[rt1],l,mid,pos);add(rs[rt],rs[rt1],mid+1,r,pos);
	s[rt]=s[rs[rt]]*fac[mid-l+1]+s[ls[rt]];sum[rt]=sum[ls[rt]]+sum[rs[rt]];
}
void change(int &rt,int rt1,int rt2,int l,int r,int L,int R)
{
	if(l>R||r<L)return;rt=++tot;
	ls[rt]=ls[rt1],rs[rt]=rs[rt1];s[rt]=s[rt1];sum[rt]=sum[rt1];
	if(l>=L&&r<=R){ls[rt]=ls[rt2],rs[rt]=rs[rt2];s[rt]=s[rt2];sum[rt]=sum[rt2];return;}
	change(ls[rt],ls[rt1],ls[rt2],l,mid,L,R);change(rs[rt],rs[rt1],rs[rt2],mid+1,r,L,R);
	s[rt]=s[rs[rt]]*fac[mid-l+1]+s[ls[rt]];sum[rt]=sum[ls[rt]]+sum[rs[rt]];
}
void upd(int &Rt,int rt1,int pos)
{
	int x=find(rt1,0,n,pos);
	add(Rt,rt1,0,n,x);
	if(pos<x)change(Rt,Rt,rt[S],0,n,pos,x-1);
}
struct node{int x,rt;bool operator < (const node &a)const{return cmp(a.rt,rt,0,n);}};
void dij(int S)
{
	priority_queue<node>q;q.push({S,rt[S]});
	while(!q.empty())
	{
		int x=q.top().x;q.pop();
		if(vis[x])continue;vis[x]=1;
		if(x==T)break;
		for(auto i:e[x])
		{
			if(vis[i.fi])continue;
			int Rt;upd(Rt,rt[x],i.se);
			if(!rt[i.fi]||cmp(Rt,rt[i.fi],0,n))rt[i.fi]=Rt,q.push({i.fi,Rt}),las[i.fi]=x;
		}
	}
	if(!vis[T])puts("-1"),exit(0);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	g=read(),m=read();
	for(int i=1;i<=m;i++)
		x=read(),y=read(),z=read(),e[x].pb(mp(y,z)),e[y].pb(mp(x,z));
	n=1e5+50;base={2,17};fac[0]={1,1};
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*base;
	S=read(),T=read();build(rt[S],0,n);dij(S);
	cout<<s[rt[T]].x<<endl;int cnt=0;
	for(int i=T;i;i=las[i])ans[++cnt]=i;cout<<cnt<<endl;
	for(int i=cnt;i>=1;i--)printf("%d ",ans[i]);
 	return 0;
}