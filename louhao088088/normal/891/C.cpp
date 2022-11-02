// Problem: CF891C Envy
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF891C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2022-01-20 21:20:29
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
const int maxn=5e5+5,M=34005;
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
int n,m,g[maxn],f[maxn],x,k,q,y;
struct node
{
	int u,v,w,id,tx,ty;
}line[maxn],b[maxn];
bool cmp(node a,node b){return a.w<b.w;}
bool cnp(node a,node b){return a.id<b.id;}
int getf(int x){if(f[x]==x)return x;return f[x]=getf(f[x]);}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)line[i].u=read(),line[i].v=read(),line[i].w=read(),line[i].id=i;
	sort(line+1,line+m+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;)
	{
		int j=i;g[line[i].id]=i;
		while(line[j].w==line[i].w&&j<=m)line[j].tx=getf(line[j].u),line[j].ty=getf(line[j].v),j++;
		while(i<j){f[getf(line[i].u)]=getf(line[i].v);i++;}
	}
	sort(line+1,line+m+1,cnp);
	q=read();
	for(int i=1;i<=n;i++)f[i]=i;
	for(int _=1;_<=q;_++)
	{
		k=read();
		for(int j=1;j<=k;j++)x=read(),b[j]=line[x];
		sort(b+1,b+k+1,cmp);int F=1;
		//cout<<k<<endl;
		for(int i=1;i<=k;)
		{
			int j=i;
			while(b[j].w==b[i].w&&j<=k)
			{
				if(getf(b[j].tx)==getf(b[j].ty))F=0;
				else f[getf(b[j].tx)]=getf(b[j].ty);
				j++;
			}
			while(i<j)f[b[i].tx]=b[i].tx,f[b[i].ty]=b[i].ty,i++;//,cout<<i<<endl;
		}
		if(F)puts("YES");
		else puts("NO");
	}
 	return 0;
}