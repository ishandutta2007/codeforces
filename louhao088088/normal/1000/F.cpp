#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=1000005;
struct node
{
	int l,r,id;
}b[maxn];
int n,m,a[maxn],t,t2,id[maxn],s[maxn],ans[maxn],sum=0,k,st[maxn],top=0,pos[maxn];
bool cmp(node a,node b)
{
	if(id[a.l]!=id[b.l])return a.l<b.l;
	if(id[a.l]&1)return a.r<b.r;return a.r>b.r;
}
inline void add(int x)
{
	s[x]++;if(s[x]==1)st[++top]=x,pos[x]=top;
	else if(s[x]==2)st[pos[x]]=st[top],pos[st[pos[x]]]=pos[x],st[top]=pos[x]=0,top--;
}
inline void cut(int x)
{
	s[x]--;if(s[x]==1)st[++top]=x,pos[x]=top;
	else if(s[x]==0)st[pos[x]]=st[top],pos[st[pos[x]]]=pos[x],st[top]=pos[x]=0,top--;
}
signed main()
{
	n=read(),t=sqrt(n);
	for(register int i=1;i<=n;i++)a[i]=read(),id[i]=(i-1)/t+1;m=read();
	for(register int i=1;i<=m;i++)b[i].l=read(),b[i].r=read(),b[i].id=i;
	sort(b+1,b+m+1,cmp);int l=b[1].l,r=b[1].r;
	for(register int i=b[1].l;i<=b[1].r;i++)add(a[i]);ans[b[1].id]=st[top];
	for(register int i=2;i<=m;i++)
	{
		while(l<b[i].l)cut(a[l++]);
		while(l>b[i].l)add(a[--l]);
		while(r<b[i].r)add(a[++r]);
		while(r>b[i].r)cut(a[r--]);
		ans[b[i].id]=st[top];
	}
	for(register int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}