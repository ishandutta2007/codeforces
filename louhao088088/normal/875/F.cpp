// Problem: CF875F Royal Questions
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF875F
// Memory Limit: 500 MB
// Time Limit: 1500 ms
// 2022-04-21 20:00:36
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
#define lowbit(x) (x&-x)
const int maxn=1e6+5,M=34005;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,x,y,z,tag[maxn],fa[maxn],ans=0;
int find(int x){if(x==fa[x])return x;return fa[x]=find(fa[x]);}
struct node{int x,y,z;}a[maxn];
bool cmp(node a,node b){return a.z>b.z;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)x=read(),y=read(),z=read(),a[i]={x,y,z};
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=find(a[i].x),v=find(a[i].y);
		if(tag[u]&&tag[v])continue;
		if(u==v&&!tag[u])tag[u]=1;
		else fa[u]=v,tag[v]|=tag[u];
		ans+=a[i].z;
	}cout<<ans<<endl;
 	return 0;
}