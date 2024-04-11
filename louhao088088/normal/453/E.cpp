// Problem: CF453E Little Pony and Lord Tirek
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF453E
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 2022-02-17 21:20:11
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
#define int long long
const int maxn=1e5+5,M=34005;
const double eps=1e-12;
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
int n,m,ls[maxn*60],rs[maxn*60],rt[maxn],id[maxn],a[maxn],b[maxn],tot=0,x,t,l,r;
struct node{int x,y;node operator +(const node &p)const{return {x+p.x,y+p.y};}}val[maxn*60],res;
void pushup(int rt){val[rt]=val[ls[rt]]+val[rs[rt]];}
void build(int &rt,int l,int r)
{
	rt=++tot;if(l==r){val[rt]={b[l],0};return;}
	build(ls[rt],l,mid),build(rs[rt],mid+1,r);pushup(rt);
}
void updata(int &rt,int rt1,int l,int r,int x)
{
	if(l>x||r<x)return;rt=++tot;ls[rt]=ls[rt1],rs[rt]=rs[rt1],val[rt]=val[rt1];
	if(l==r){val[rt]={0,a[l]};return;}updata(ls[rt],ls[rt1],l,mid,x),updata(rs[rt],rs[rt1],mid+1,r,x);pushup(rt);
}
node query(int rt,int l,int r,int L,int R)
{
	if(!rt)return (node){0,0};if(l>R||r<L)return (node){0,0};
	if(l>=L&&r<=R)return val[rt];return query(ls[rt],l,mid,L,R)+query(rs[rt],mid+1,r,L,R);
}
struct ODT{int l,r;mutable double v;char operator<(ODT b) const {return l<b.l;}};
set<ODT>s;set<pi>s2;
auto split(int x) //ODT
{
	if(x>n) return s.end();
	auto it=--s.upper_bound((ODT){x,0,0});
	if (it->l==x)return it;int l=it->l,r=it->r,v=it->v;
	s.erase(it);s.insert((ODT){l,x-1,v});
	return s.insert((ODT){x,r,v}).fi;
}
node getans(int L,int R,double t)//
{
	int l=1,r=n,res=0;
	while(l<=r)
	{
		if(a[id[mid]]<=b[id[mid]]*t)res=mid,l=mid+1;
		else r=mid-1;
	}
	return query(rt[res],1,n,L,R);
}
bool cmp(int x,int y){return a[x]*b[y]<a[y]*b[x];}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		x=read(),a[i]=read(),b[i]=read();
		if(!a[i]&&!b[i])a[i]=1;id[i]=i;
		if(b[i])s.insert((ODT){i,i,1.0*-x/b[i]});
		else s.insert((ODT){i,i,0}),s2.insert(mp(i,x));
	}sort(id+1,id+n+1,cmp);build(rt[0],1,n);s2.insert(mp(n+1,0));
	for(int i=1;i<=n;i++)updata(rt[i],rt[i-1],1,n,id[i]);m=read();
	for(int i=1;i<=m;i++)
	{
		t=read();l=read();r=read();set<pi>::iterator it;int ans=0;
		while(s2.size()>1&&(it=s2.lower_bound(mp(l,0)))->fi<=r)ans+=it->se,s2.erase(it);
		auto tr=split(r+1),tl=split(l);
		for(auto i=tl;i!=tr;i++)
			res=getans(i->l,i->r,t-i->v),ans+=res.y+(int)(res.x*(t-i->v)+0.5);
		s.erase(tl,tr),s.insert({l,r,1.0*t});printf("%lld\n",ans);
	}
 	return 0;
}