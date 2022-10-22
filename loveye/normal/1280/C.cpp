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

const int N = 1e6 + 5;
int n,t;
ll ans1,ans2;
int fir[N],to[N << 1],eds,nxt[N << 1],wei[N << 1];
void addedge(int u,int v,int w) {
	to[++eds] = v;
	wei[eds] = w;
	nxt[eds] = fir[u];
	fir[u] = eds;
}
int siz[N];
void dfs(int u,int fa) {
	//cerr << u << ' ' << fa << endl;
	int res;
	siz[u] = 1;
	foredge(i,u,v) if(v != fa) {
		dfs(v,u);
		siz[u] += siz[v];
	} else res = wei[i];
	ans2 += 1ll * min(siz[u],n*2-siz[u]) * res;
	ans1 += (siz[u] & 1) * res;
}
int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--) {
		cin >> n;
		eds = 0 ; fr(i,1,n*2) fir[i] = 0;
		for(int i = 1,u,v,w;i < n*2;++i) {
			cin >> u >> v >> w;
			addedge(u,v,w),addedge(v,u,w);
		}
		ans1 = 0,ans2 = 0;
		dfs(1,0);
		cout << ans1 << ' ' << ans2 << endl;
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}