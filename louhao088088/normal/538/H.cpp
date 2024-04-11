#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
#define int long long
const int maxn=2e5+5,M=34005;
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
int n,m,l,r,t,T,c[maxn],x,y,a1,a2;pair<int,int>a[maxn];vector<int>e[maxn];
bool dfs(int x){
	for(auto i:e[x]){
		if(!c[i]){c[i]=3-c[x];if(!dfs(i))return 0;}
		if(c[i]==c[x])return 0;
	}
	return 1;
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	t=read(),T=read();n=read(),m=read();a1=0;a2=1e9;
	for(int i=1;i<=n;i++)x=read(),y=read(),a[i]=mp(x,y),
	a1=max(x,a1),a2=min(y,a2);
	if(a1+a2<t)a1=t-a2;
	else if(a1+a2>T)a2=T-a1;
	if(a1<0||a2<0)puts("IMPOSSIBLE"),exit(0);
	for(int i=1;i<=m;i++)
		x=read(),y=read(),e[x].pb(y),e[y].pb(x);
	for(int i=1;i<=n;i++){
		int u=0,v=0;
		if(a[i].fi<=a1&&a[i].se>=a1)u=1;
		if(a[i].fi<=a2&&a[i].se>=a2)v=1;
		if(!u&&!v){puts("IMPOSSIBLE"),exit(0);}
		if(u&&!v)c[i]=1;if(v&&!u)c[i]=2;
	}
	for(int i=1;i<=n;i++)if(c[i]){if(!dfs(i))puts("IMPOSSIBLE"),exit(0);}
	
	for(int i=1;i<=n;i++)
		if(!c[i]){
			c[i]=1;
			if(!dfs(i))puts("IMPOSSIBLE"),exit(0);
		}
	string b;
	for(int i=1;i<=n;i++)b+=(char)c[i]+'0';
	puts("POSSIBLE");
	cout<<a1<<" "<<a2<<endl;cout<<b<<endl;
 	return 0;
}