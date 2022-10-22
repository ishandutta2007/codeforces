#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v,T) for(int i = T.fir[u],v;v = T.to[i],i;i = T.nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 3e5 + 5;
int n;
struct Tree {
	int fir[N],to[N << 1],nxt[N << 1],cnt;
	I addedge(int u,int v) {
		to[++cnt] = v;
		nxt[cnt] = fir[u];
		fir[u] = cnt;
	}
} T1,T2;
int dfn[N],dfc,siz[N],f[N][21];
struct Saver {
	struct Node {int *p,v;} st[N * 20];
	int top;
	I save(int &x) {st[++top] = {&x,x};}
	I pop() {*(st[top].p) = st[top].v;--top;}
} s;
int BIT[N];
I add(int x,int v) {
	for(;x <= n;x += x & -x) {
		s.save(BIT[x]);
		BIT[x] += v;
	}
}
inline int ask(int x) {
	int res = 0;
	for(;x;x -= x & -x) res += BIT[x];
	return res;
}
void dfs(int u) {
	dfn[u] = ++dfc;
	siz[u] = 1;
	fr(i,1,20) f[u][i] = f[f[u][i-1]][i-1];
	foredge(i,u,v,T2) {
		f[v][0] = u;
		dfs(v);
		siz[u] += siz[v];
	}
}
int ans,now;
I insert(int u) {
	if(ask(dfn[u]+siz[u]-1)-ask(dfn[u]-1)) return;
	int cur = u;
	rf(i,20,0) {
		int nxt = f[cur][i];
		if(!nxt) continue;
		if(ask(dfn[nxt])-ask(dfn[nxt]-1) == 1) {
			cur = nxt;
			break;
		}
		if(ask(dfn[nxt]+siz[nxt]-1)-ask(dfn[nxt]-1) == 0)
			cur = nxt;
	}
	if(ask(dfn[cur])-ask(dfn[cur]-1) == 1) add(dfn[cur],-1),--now;
	add(dfn[u],1),++now;
}
void getans(int u) {
	int res = s.top;
	s.save(now);
	insert(u);
	if(!T1.fir[u]) ans = max(ans,now);
	else foredge(i,u,v,T1) getans(v);
	while(s.top != res) s.pop();
}
int main() {
	int t; cin >> t;
	while(t--) {
		cin >> n; int x;
		fr(i,1,n) T1.fir[i] = T2.fir[i] = 0;
		T1.cnt = T2.cnt = 0; dfc = 0;
//		cerr << n << endl;
		fr(i,2,n) cin >> x,T1.addedge(x,i);
		fr(i,2,n) cin >> x,T2.addedge(x,i);
		dfs(1);
		ans = 0;
		getans(1);
		cout << ans << endl;
	}
	return 0;
}