#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 1000009
using namespace std;

int n,c[N][2],f[N],ans[N]; bool bo[N]; char ch[N][10];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int dfs(int x){
	if (bo[x]) return f[x]=c[x][0];
	if (ch[x][0]=='N') f[x]=dfs(c[x][0])^1;
	else if (ch[x][0]=='A') f[x]=dfs(c[x][0])&dfs(c[x][1]);
	else if (ch[x][0]=='O') f[x]=dfs(c[x][0])|dfs(c[x][1]);
	else if (ch[x][0]=='X') f[x]=dfs(c[x][0])^dfs(c[x][1]);
	return f[x];
}
void dfs2(int x){
	if (bo[x]){ ans[x]=1; return; }
	if (ch[x][0]=='N') dfs2(c[x][0]); else
	if (ch[x][0]=='X'){ dfs2(c[x][0]); dfs2(c[x][1]); } else
	if (ch[x][0]=='A'){
		if (f[c[x][0]]) dfs2(c[x][1]); if (f[c[x][1]]) dfs2(c[x][0]);
	} else{
		if (!f[c[x][0]]) dfs2(c[x][1]); if (!f[c[x][1]]) dfs2(c[x][0]);	
	}
}
int main(){
	scanf("%d",&n);
	int i;
	for (i=1; i<=n; i++){
		scanf("%s",ch[i]);
		if (ch[i][0]=='I'){
			bo[i]=1; scanf("%d",&c[i][0]);
		} else if (ch[i][0]=='N') scanf("%d",&c[i][0]);
		else scanf("%d%d",&c[i][0],&c[i][1]);
	}
	dfs(1); dfs2(1);
	for (i=1; i<=n; i++) if (bo[i]) printf("%d",f[1]^ans[i]); puts("");
	return 0;
}