#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 30;
int n,k;
int v[N*N],tot;
bool vis[N][N];
void dfs(int u) {
	fr(i,1,k) if(!vis[u][i]) {
		vis[u][i] = 1;
		dfs(i);
	}
	v[tot++] = u;
}
int main() {
	cin >> n >> k;
	dfs(1);
//	fo(i,0,tot) cout << v[i] << ' '; cout << endl;
	if(tot) --tot;
	fo(i,0,n) cout << char('a'-1 + v[i % tot]);
	return 0;
}