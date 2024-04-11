#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 4005;
int n,m,st[N],top,ch[N][2],siz[N];
ll dp[N][N],a[N];
void dfs(int u) {
	if(!u) return;
	int lc = ch[u][0],rc = ch[u][1];
	dfs(lc); dfs(rc);
	siz[u] = siz[lc] + siz[rc] + 1;
	fr(i,0,siz[lc]) fr(j,0,siz[rc]) {
		dp[u][i+j] = max(dp[u][i+j],dp[lc][i] + dp[rc][j] - 2ll * i * j * a[u]);
		dp[u][i+j+1] = max(dp[u][i+j+1],dp[lc][i] + dp[rc][j] + m * a[u] - 2ll * i * j * a[u] - (i+j) * a[u] * 2 - a[u]);
	}
}
int main() {
	cin >> n >> m;
	fr(i,1,n) cin >> a[i];
	fr(i,1,n) {
		while(top && a[st[top]] > a[i])
			ch[i][0] = st[top--];
		if(top) ch[st[top]][1] = i;
		st[++top] = i;
	}
	dfs(st[1]);
	cout << dp[st[1]][m] << endl;
	return 0;
}