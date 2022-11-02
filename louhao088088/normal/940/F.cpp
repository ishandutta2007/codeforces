#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=200005;
struct node
{
	int l,r,id,pre;
}b[maxn];
int m,n,x,y,a[maxn],t,id[maxn],ans[maxn],sum=0,k,l,r,num=0,s[maxn],si[maxn],now,d[maxn];
int opt,tot=0,c[maxn],c2[maxn],qnum=0,cnt=0;
bool cmp(node a,node b)
{
	if(id[a.l]!=id[b.l])return id[a.l]<id[b.l];
	else if(id[a.r]!=id[b.r])return id[a.r]<id[b.r];
	return a.pre<b.pre;
}
int add(int x){si[s[x]]--,s[x]++,si[s[x]]++;}
int cut(int x){si[s[x]]--,s[x]--,si[s[x]]++;}
int change(int x,int l,int r)
{
	if(c[x]>=l&&c[x]<=r)
	{
		si[s[a[c[x]]]]--,s[a[c[x]]]--,si[s[a[c[x]]]]++;
		si[s[c2[x]]]--,s[c2[x]]++,si[s[c2[x]]]++;
	}swap(c2[x],a[c[x]]);
}
int getans(){for(int i=1;i<=n;i++)if(!si[i])return i;}
signed main()
{
	n=read();t=pow(n,0.6666666);m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=d[++cnt]=read(),id[i]=(i-1)/t+1;
	}
	for(int i=1;i<=m;i++)
	{
		opt=read();
		if(opt==1)b[++qnum].l=read(),b[qnum].r=read(),b[qnum].id=qnum,b[qnum].pre=tot;
		else if(opt==2)c[++tot]=read(),c2[tot]=d[++cnt]=read();
	}
	sort(d+1,d+cnt+1);
	int un=unique(d+1,d+1+cnt)-d-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(d+1,d+1+un,a[i])-d;
	for(int i=1;i<=tot;i++) c2[i]=lower_bound(d+1,d+1+un,c2[i])-d;
	sort(b+1,b+qnum+1,cmp);l=b[1].l,r=b[1].r;now=0;
	for(int i=b[1].l;i<=b[1].r;i++)add(a[i]);
	while(now<b[1].pre)change(++now,b[1].l,b[1].r);ans[b[1].id]=getans();//cout<<b[1].id<<endl;
	for(int i=2;i<=qnum;i++)
	{
		while(l<b[i].l)cut(a[l++]);
		while(l>b[i].l)add(a[--l]);//cout<<si[1]<<endl;
		while(r<b[i].r)add(a[++r]);
		while(r>b[i].r)cut(a[r--]);//cout<<si[1]<<" "<<b[i].id<<" "<<r+1<<" "<<s[2]<<" "<<s[3]<<" "<<s[1]<<endl;//cout<<now<<" "<<b[i].id<<endl;
		while(now>b[i].pre)change(now--,b[i].l,b[i].r);
		while(now<b[i].pre)change(++now,b[i].l,b[i].r);
		ans[b[i].id]=getans();
	}
	for(int i=1;i<=qnum;i++)printf("%d\n",ans[i]);
	return 0;
}