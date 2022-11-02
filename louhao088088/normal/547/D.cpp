// Problem: CF547D Mike and Fish
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF547D
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 2021-12-13 12:45:58
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
int n,m,a[maxn],b[maxn],lx[maxn],ly[maxn],col[maxn];
vector<int>e[maxn];
void dfs(int x,int c)
{
	col[x]=c;
	for(auto i:e[x])
		if(!col[i])dfs(i,c^1);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read();
		if(lx[a[i]])e[lx[a[i]]].pb(i),e[i].pb(lx[a[i]]),lx[a[i]]=0;else lx[a[i]]=i;
		if(ly[b[i]])e[ly[b[i]]].pb(i),e[i].pb(ly[b[i]]),ly[b[i]]=0;else ly[b[i]]=i;
	}
	for(int i=1;i<=n;i++)if(!col[i])dfs(i,3);
	for(int i=1;i<=n;i++)if(col[i]==3)putchar('b');else putchar('r');
 	return 0;
}