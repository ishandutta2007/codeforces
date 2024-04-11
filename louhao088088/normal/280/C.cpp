// LUOGU_RID: 90806009
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
const int maxn=2e5+5,M=2e5+5,mod=998244353,inf=1e10;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,x,y,d[maxn];double ans=0;vector<int>e[maxn];
void dfs(int x,int fa){
	d[x]=d[fa]+1;ans=ans+(1.0/d[x]);
	for(auto i:e[x])if(i^fa)dfs(i,x);
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<n;i++)x=read(),y=read(),e[x].pb(y),e[y].pb(x);
	dfs(1,0);printf("%.8lf",ans);
 	return 0;
}