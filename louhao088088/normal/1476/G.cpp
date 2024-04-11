// Problem: CF1476G Minimum Difference
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1476G
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 2021-12-25 14:13:48
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
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
const int maxn=2e5+5,M=34005;
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
int a[maxn],n,m,op,l,r,b[maxn],c[maxn],tot,tot2,t,ans[maxn];
int id[maxn],s[maxn],nex[maxn],lst[maxn],s2[maxn],tmp[maxn];
struct node
{
	int l,r,x,k,id;
}q[maxn];
bool cmp(node a,node b){if(id[a.l]!=id[b.l])return a.l<b.l;
	if(id[a.r]!=id[b.r])return a.r<b.r;return a.x<b.x;}
void add(int x){s2[s[a[x]]]--;s[a[x]]++;s2[s[a[x]]]++;int o=s[a[x]];
if(s2[o]==1)lst[o]=o-1,nex[o]=nex[o-1],lst[nex[o]]=o,nex[o-1]=o;
if(s2[o-1]==0)lst[o]=lst[o-1],nex[lst[o-1]]=o;}
void cut(int x){s2[s[a[x]]]--;s[a[x]]--;s2[s[a[x]]]++;int o=s[a[x]];//cout<<"CUT:"<<o<<" "<<a[x]<<endl;
if(s2[o]==1)nex[o]=o+1,lst[o]=lst[o+1],nex[lst[o+1]]=o,lst[o+1]=o;
if(s2[o+1]==0)nex[o]=nex[o+1],lst[nex[o+1]]=o;}
int getans(int z)
{
	int x=q[z].k;
	int ans=1e9,sum=0;int u=0;
	for(int i=nex[0];i;i=nex[i])tmp[++u]=i;
	if(u>t)return 0;
	for(int i=1,j=0;i<=u;i++)
	{
		while(sum<x&&j<u)j++,sum+=s2[tmp[j]];
		if(sum<x)break;
		//cout<<tmp[j]<<" "<<tmp[i]<<" "<<sum<<endl;
		ans=min(ans,tmp[j]-tmp[i]);sum-=s2[tmp[i]];
	}
	if(ans==1e9)return -1;
	return ans;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();t=pow(n,0.66666)+1;s2[0]=1e6;
	for(int i=1;i<=n;i++)a[i]=read(),id[i]=(i-1)/t+1;
	for(int i=1;i<=m;i++)
	{
		op=read();
		if(op==1)q[++tot].l=read(),q[tot].r=read(),q[tot].k=read(),q[tot].x=tot2,q[tot].id=tot;
		else b[++tot2]=read(),c[tot2]=read();
	}
	sort(q+1,q+tot+1,cmp);int l=1,r=0,g=0;
	for(int i=1;i<=tot;i++)
	{
		while(g<q[i].x){g++;if(l<=b[g]&&r>=b[g])cut(b[g]);swap(a[b[g]],c[g]);if(l<=b[g]&&r>=b[g])add(b[g]);}
		while(g>q[i].x){if(l<=b[g]&&r>=b[g])cut(b[g]);swap(a[b[g]],c[g]);if(l<=b[g]&&r>=b[g])add(b[g]);g--;}
		while(l>q[i].l)l--,add(l);
		while(r<q[i].r)r++,add(r);
		while(l<q[i].l)cut(l),l++;
		while(r>q[i].r)cut(r),r--;
		ans[q[i].id]=getans(i);
	}
	for(int i=1;i<=tot;i++)printf("%d\n",ans[i]);
 	return 0;
}