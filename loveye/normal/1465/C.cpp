#include<bits/stdc++.h>
using namespace std;

int read();
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

const int N = 1e5 + 5;
int n,m,x[N],y[N],p[N];
bool vis[N];
int main() {
	ios::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		cin >> n >> m;
		fr(i,1,n) p[i] = vis[i] = 0;
		int ans = m;
		fr(i,1,m) {
			cin >> x[i] >> y[i];
			if(x[i] == y[i]) --ans;
			else p[x[i]] = y[i];
		}
		fr(i,1,n) if(p[i] && !vis[i]) {
			int cur = p[i];
			while(cur && !vis[cur]) vis[cur] = 1,cur = p[cur];
			if(vis[i]) ++ans;
			else vis[i] = 1;
		}
		cout << ans << endl;
	}
	return 0;
}