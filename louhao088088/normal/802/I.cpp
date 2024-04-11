// Problem: CF802I Fake News (hard)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF802I
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 2022-04-01 19:42:03
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
#define int long long
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
int n,m;char a[maxn];
struct Sam
{
	int ch[maxn][26],las,tot,fa[maxn],len[maxn],s[maxn],ans;
	vector<int>e[maxn];
	void clear(){memset(ch,0,sizeof ch);memset(s,0,sizeof s);
	for(int i=1;i<=tot;i++)e[i].clear();tot=1;las=1;ans=0;}
	void ins(int x)
	{
		int p=las,t=++tot;len[t]=len[p]+1;s[t]=1;las=t;
		for(;!ch[p][x];p=fa[p])ch[p][x]=t;
		if(!p){fa[t]=1;return ;}int q=ch[p][x];
		if(len[q]==len[p]+1){fa[t]=q;return;}
		len[++tot]=len[p]+1;fa[tot]=fa[q];fa[t]=fa[q]=tot;
		memcpy(ch[tot],ch[q],sizeof ch[q]);
		for(int i=p;ch[i][x]==q;i=fa[i])ch[i][x]=tot;
	}
	void dfs(int x)
	{
		for(auto i:e[x])
			dfs(i),s[x]+=s[i];
		ans+=s[x]*s[x]*(len[x]-len[fa[x]]);
		//cout<<x<<" "<<s[x]<<" "<<len[x]<<" "<<len[fa[x]]<<" "<<fa[x]<<endl;
	}
	void work()
	{
		clear();scanf("%s",a+1);
		int len=strlen(a+1);
		for(int i=1;i<=len;i++)ins(a[i]-'a');
		for(int i=2;i<=tot;i++)e[fa[i]].pb(i);//cout<<tot<<endl;
		dfs(1);cout<<ans<<endl;
	}
}sam;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)sam.work();
 	return 0;
}