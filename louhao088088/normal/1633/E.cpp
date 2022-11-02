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
#define int long long
const int maxn=1e4+5,M=34005;
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
int n,m,p[maxn],fa[maxn],s,g[maxn],k,b,q,x,cnt=0,ans,a1,a2,a3,h;
signed d[maxn*1000];
struct node{int x,y,w;}e[maxn];
int find(int x){if(fa[x]==x)return x;return fa[x]=find(fa[x]);}
bool cmp(node a,node b){return a.w<b.w;}
bool cmp1(int a,int b){return e[a].w+e[p[a]].w<e[b].w+e[p[b]].w;}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++)e[i].x=read(),e[i].y=read(),e[i].w=read();
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int s=0;
		for(int j=1;j<=n;j++)fa[j]=j;
		for(int j=i-1;j>0;j--){
			fa[find(e[j].x)]=find(e[j].y);
			if(find(e[i].x)==find(e[i].y)){s=j;break;}
		}
		if(s)g[++cnt]=i,p[i]=s;
		else k--,b+=e[i].w;
	}
	sort(g+1,g+cnt+1,cmp1);h=read(),q=read();a1=read(),a2=read(),a3=read();
	for(int i=1;i<=h;i++)d[i]=read();
	for(int i=h+1;i<=q;i++)d[i]=(d[i-1]*a1+a2)%a3;
	sort(d+1,d+q+1);int s1=1,s2=1;
	for(int i=1;i<=q;i++){
		x=d[i];
		while(s1<=m&&e[s1].w<x)k+=2,b-=2*e[s1].w,s1++;
		while(s2<=cnt&&e[g[s2]].w+e[p[g[s2]]].w<2*x)k-=2,b+=e[g[s2]].w+e[p[g[s2]]].w,s2++;
		ans=ans^(k*x+b);
	}cout<<ans<<endl;
 	return 0;
}