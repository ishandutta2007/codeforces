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
const int maxn=2e5+5,M=2e5+5,mod=1e9+7;
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
int n,m,a[maxn],x,f[maxn],vis[maxn],Rt;
char s[maxn];vector<int>e[maxn],ans;
void dfs1(int x,int fa){
	ans.pb(x);vis[x]=1;
	for(auto i:e[x])if(i!=fa&&!vis[i])dfs1(i,x);
}
void dfs(int x,int fa){
	int s=0;
	for(auto i:e[x])if(i^fa){
		dfs(i,x);
		if(!vis[i])s++;
	}
	if(x!=Rt)s++;
	if(s%2==0)dfs1(x,fa);
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		x=read();if(!x)Rt=i;else e[x].pb(i);
	}dfs(Rt,0);
	if(!vis[Rt])puts("NO");
	else {
		puts("YES");
		for(int i=0;i<n;i++)printf("%d\n",ans[i]);
	}
 	return 0;
}