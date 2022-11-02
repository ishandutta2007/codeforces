// Problem: CF235C Cyclical Quest
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF235C
// Memory Limit: 500 MB
// Time Limit: 3000 ms
// 2022-04-01 21:23:46
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
const int maxn=2e6+5,M=34005;
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
int n,m;
char a[maxn],b[maxn];
struct Sam
{
	int ch[maxn][26],fa[maxn],len[maxn],tot=1,las=1,vis[maxn],sz[maxn];vector<int>e[maxn];
	void ins(int x)
	{
		int p=las,t=++tot;len[t]=len[p]+1;sz[t]=1;las=t;
		for(;p&&!ch[p][x];p=fa[p])ch[p][x]=t;
		if(!p){fa[t]=1;return ;}int q=ch[p][x];
		if(len[q]==len[p]+1){fa[t]=q;return;}
		len[++tot]=len[p]+1;fa[tot]=fa[q];fa[t]=fa[q]=tot;
		memcpy(ch[tot],ch[q],sizeof ch[q]);
		for(int i=p;ch[i][x]==q;i=fa[i])ch[i][x]=tot;
	}
	void dfs(int x)
	{
		for(auto i:e[x])
			dfs(i),sz[x]+=sz[i];
	//	cout<<x<<" "<<fa[x]<<" "<<sz[x]<<endl;
	}
	void build()
	{
		for(int i=2;i<=tot;i++)e[fa[i]].pb(i);
		dfs(1);
	}
	void work(int n,int id)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
			b[i+n]=b[i]-'a',b[i]-='a';int now=1,l=0;
		for(int i=1;i<n*2;i++)
		{
			while(!ch[now][b[i]]&&now)now=fa[now],l=len[now];
			if(!now)l=0,now=1;
			else l++,now=ch[now][b[i]];
			if(l>=n)
			{
				//cout<<now<<" "<<len[fa[now]]<<endl;
				while(len[fa[now]]>=n)now=fa[now];
				if(vis[now]!=id)ans+=sz[now],vis[now]=id;
				l=n;
			}
		}
		printf("%d\n",ans);
		//exit(0);
	}
}sam;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s",a+1);n=strlen(a+1);
	for(int i=1;i<=n;i++)sam.ins(a[i]-'a');
	sam.build();
	n=read();
	for(int i=1;i<=n;i++)scanf("%s",b+1),sam.work(strlen(b+1),i);
 	return 0;
}