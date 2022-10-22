#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 2e5 + 5,MOD = 1e9 + 7;
int n,f[N],t,s[N],ans,id[N],g[N];
int vis[N << 1];
struct Node {
	int l,r;
} p[N];
struct BIT {
	int c[N << 1]; void add(int x,int v) {for(;x;x &= x-1) (c[x] += v) %= MOD;}
	int ask(int x) {int res = 0; for(;x <= n*2;x += x & -x) (res += c[x]) %= MOD; return res;}
} t1,t2;
int c[N << 1]; void add(int x,int v) {for(;x;x &= x-1) c[x] = max(c[x],v);}
int ask(int x) {int res = 0; for(;x <= n*2;x += x & -x) res = max(res,c[x]); return res;}
int main() {
	scanf("%d",&n);
	fr(i,1,n) scanf("%d%d",&p[i].l,&p[i].r),id[i] = i;
	scanf("%d",&t);
	int mx = 0;
	fr(i,1,t) {
		scanf("%d",s+i);
		vis[p[s[i]].r] = 1;
		mx = max(mx,p[s[i]].r);
	}
	sort(p+1,p+n+1,[](const Node &a,const Node &b) {
		return a.r < b.r;
	});
	fr(i,1,n) {
		f[i] = (t2.ask(p[i].l) + t1.ask(p[i].l)) % MOD;
		g[i] = ask(p[i].l);
		t1.add(p[i].l,1);
		t2.add(p[i].l,f[i]);
		if(vis[p[i].r]) add(p[i].l,p[i].r);
	}
	sort(id+1,id+n+1,[] (const int &i,const int &j) {
		return p[i].l < p[j].l;
	});
	fr(i,1,n) {
		if(p[id[i]].r > mx) continue;
		if(p[id[i]].r < mx) (ans += f[id[i]] + 1) %= MOD;
		else {
			(ans += f[id[i]] + 1) %= MOD;
			mx = g[id[i]];
		}
	}
	printf("%d\n",ans);
	return 0;
}