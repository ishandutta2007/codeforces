#include<bits/stdc++.h>
using namespace std;

#define int long long
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

const int N = 2e5 + 5;
int n;
int fir[N],to[N << 1],nxt[N << 1],cnt;
I addedge(int u,int v) {
	to[++cnt] = v;
	nxt[cnt] = fir[u];
	fir[u] = cnt;
}
int f[N][21],dep[N],siz[N];
void dfs(int u,int fa) {
	fr(i,1,20) f[u][i] = f[f[u][i-1]][i-1];
	dep[u] = dep[fa] + 1;
	siz[u] = 1;
	foredge(i,u,v) if(v != fa) {
		f[v][0] = u;
		dfs(v,u);
		siz[u] += siz[v];
	}
}
inline int LCA(int u,int v) {
	if(dep[u] < dep[v]) swap(u,v);
	rf(i,20,0) if(dep[f[u][i]] >= dep[v]) u = f[u][i];
	if(u == v) return u;
	rf(i,20,0) if(f[u][i] != f[v][i])
		u = f[u][i],v = f[v][i];
	return f[u][0];
}
inline int dis(int u,int v) {
	return dep[u] + dep[v] - (dep[LCA(u,v)] << 1);
}
LL ans[N];
inline LL calc(int u,int v) {
	if(LCA(u,v) != u) return siz[u];
	rf(i,20,0) if(dep[f[v][i]] > dep[u]) v = f[v][i];
	return n - siz[v];
}
signed main() {
	ios::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		cin >> n;
		cnt = 0;
		fr(i,1,n) fir[i] = 0;
		for(int i = 1,u,v;i < n;++i) {
			cin >> u >> v;
			++u,++v;
			addedge(u,v);
			addedge(v,u);
		}
		dfs(1,0);
		fr(i,0,n) ans[i] = 0;
		LL sum = 0;
		foredge(i,1,u) {
			ans[0] += 1ll * siz[u] * (siz[u]-1) / 2;
			if(LCA(u,2) == u) ans[1] -= (siz[u]-siz[2]) * (siz[u]-siz[2]),sum += siz[u]-siz[2];
			else ans[1] -= siz[u] * siz[u],sum += siz[u];
		}
		ans[1] += sum * sum;
		ans[1] /= 2;
		ans[1] += n - siz[2] - 1;
		int A = 1,B = 2;
		fr(i,2,n) {
			if(i == n) {
				ans[n] = 1;
				break;
			}
			int dia = dis(i+1,A),dib = dis(i+1,B),dab = dis(A,B);
			if(dia + dib == dab) ans[i] = 0;
			else if(dia + dab == dib) {
				ans[i] = (calc(A,B)-calc(i+1,A)) * calc(B,A);
				A = i+1;
			} else if(dib + dab == dia) {
				ans[i] = calc(A,B) * (calc(B,A)-calc(i+1,B));
				B = i+1;
			} else {
				ans[i] = calc(A,B) * calc(B,A);
				break;
			}
		}
		fr(i,0,n) cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}