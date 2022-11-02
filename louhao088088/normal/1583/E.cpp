#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
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
int n,m,x,y,f[maxn],q,d[maxn],a[maxn],b[maxn],c[maxn],fa[maxn],sum[maxn],g[maxn],st[maxn],h[maxn],ans=0,ff[maxn];
int getf(int x){if(f[x]==x)return x;return f[x]=getf(f[x]);}
vector<int>e[maxn];
void dfs(int x)
{
//	cout<<x<<endl;
	d[x]=d[fa[x]]+1;
	for(auto i:e[x])
		if(i^fa[x])
			fa[i]=x,dfs(i);
}
void dfs1(int x)
{
	int l=0;
	for(auto i:e[x])
		if(i^fa[x])
		{
			dfs1(i);ff[x]+=ff[i];
			if(!a[i]&&h[i])ff[x]++;
			else if(a[i])l++;
		}
	ff[x]+=l/2;h[x]=l%2;//cout<<ff[x]<<" "<<x<<endl;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read();if(getf(x)==getf(y))continue;
		f[getf(x)]=getf(y);//cout<<x<<" "<<y<<endl;
		e[x].push_back(y);e[y].push_back(x);
	}
	dfs(1);q=read();
	for(int i=1;i<=q;i++)
	{
		x=read(),y=read();b[i]=x,c[i]=y;
		if(d[x]<d[y])swap(x,y);
		while(d[x]>d[y])a[x]^=1,x=fa[x],sum[i]++;
		while(x!=y)a[x]^=1,a[y]^=1,x=fa[x],y=fa[y],sum[i]+=2;
		g[i]=x;
	}
	int F=0;
	for(int i=1;i<=n;i++)
		if(a[i])F=1;
	if(F==1)
	{
		puts("NO");
		dfs1(1);
		cout<<ff[1]+h[1]<<endl;
	}
	else
	{
		puts("YES");
		for(int i=1;i<=q;i++)
		{
			printf("%d\n",sum[i]+1);int tot=0;
			while(b[i]!=g[i])printf("%d ",b[i]),b[i]=fa[b[i]];printf("%d ",g[i]);
			while(c[i]!=g[i])st[++tot]=c[i],c[i]=fa[c[i]];
			for(int i=tot;i;i--)printf("%d ",st[i]);cout<<endl;
		}
	}
 	return 0;
}