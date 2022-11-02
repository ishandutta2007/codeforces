// Problem: CF527E Data Center Drama
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF527E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2022-04-07 19:07:32
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
const int maxn=1e6+5,M=34005;
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
int n,m,head[maxn],cnt=1,to[maxn],vis[maxn],nex[maxn],in[maxn],las,x,y;
void add(int x,int y){to[++cnt]=y,nex[cnt]=head[x];head[x]=cnt;}
void Add(int x,int y,int id){in[x]++,in[y]++;add(x,y),add(y,x);}
void dfs(int x)
{
	for(int i=head[x];i;i=nex[i])
	{	head[x]=nex[i];
		if(vis[i])continue;//cout<<i<<" "<<cnt<<endl;
		vis[i]=vis[i^1]=1;
		dfs(to[i]);m--;
		if(m&1)printf("%d %d\n",x,to[i]);
		else printf("%d %d\n",to[i],x);i=head[x];
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)x=read(),y=read(),Add(x,y,i);las=0;
	for(int i=1;i<=n;i++)if(in[i]&1&&!las)las=i;else if(in[i]&1)Add(i,las,++m),las=0;
	if(m&1)Add(1,1,++m);
	cout<<m<<endl;dfs(1);
 	return 0;
}