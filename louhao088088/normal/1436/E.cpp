#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=((x<<1)+(x<<3)+(ch^48));
	if(f==1)x=-x;return x;
}
int m,n,a[maxn],s[maxn],f[maxn],tot=0,id[maxn],t,ss[maxn],ans[maxn],p;
struct node
{
	int l,r,num;
}b[maxn];
bool cmp(node a,node b)
{
	if(id[a.l]==id[b.l])return a.r<b.r;
	return a.l<b.l;
}
void add(int x){s[x]++;if(s[x]==1)ss[id[x]]++;}
void cut(int x){s[x]--;if(s[x]==0)ss[id[x]]--;}
int getmex()
{
	int k=1;
	for(int i=1;i<=t+1;i++)
		if(ss[i]<t)break;
		else k++;	
	for(int i=(k-1)*t+1;i<=k*t;i++)
		if(s[i]==0)return i;
}
bool check(int num)
{
	int sum=getmex();if(sum<num)return true;return false;
}
int main()
{
	n=read();int F=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),s[a[i]]++;
		if(a[i]!=1)F=1;
	}
	for(int i=1;i<=n+1;i++)
		if(s[i]==0){p=i+1;break;}
	t=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		id[i]=(i-1)/t+1;
		if(!f[a[i]])
		{
			f[a[i]]=i;if(i!=1)b[++tot].l=1,b[tot].r=i-1,b[tot].num=a[i];
		}
		else
		{
			if(i!=f[a[i]]+1)b[++tot].l=f[a[i]]+1,b[tot].r=i-1,b[tot].num=a[i];f[a[i]]=i;
		}
		//cout<<b[tot].l<<" "<<b[tot].r<<" "<<b[tot].num<<" "<<tot<<endl;
		//;
	}memset(s,0,sizeof s);
	for(int i=1;i<=n;i++)if(f[i]&&f[i]!=n)b[++tot].l=f[i]+1,b[tot].r=n,b[tot].num=i;
	sort(b+1,b+tot+1,cmp);int l=b[1].l,r=b[1].r;for(int i=l;i<=r;i++)add(a[i]);if(!check(b[1].num))ans[b[1].num]=1;
	for(int i=2;i<=tot;i++)
	{
		while(l<b[i].l)cut(a[l]),l++;
		while(l>b[i].l)l--,add(a[l]);
		while(r<b[i].r)r++,add(a[r]);
		while(r>b[i].r)cut(a[r]),r--;
		if(!check(b[i].num))ans[b[i].num]=1;
		
	}
	for(int i=1;i<p-1;i++)if(!ans[i])cout<<i<<endl,exit(0);
	cout<<p<<endl;
	return 0;
}