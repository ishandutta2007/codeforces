#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

#include <stack>
const int N=301000;
struct node {
	map<int,node*> g;
}pool[310000*10],*cur=pool,*rt[N];
stack<node*> tras;
int sz[N],c[N],diff[N],n,u,v;
VI son[N],e[N];
char s[N];
node *newnode() {
	if (tras.empty()) {
		node *p=cur++;
		return p;
	} else {
		node *p=tras.top(); p->g.clear();
		tras.pop();
		return p;
	}
}
bool cmp(int a,int b) { return sz[a]>sz[b];}
void dfs2(node *a,node *b,int &sz) {
	for (auto p:b->g) {
		if (!a->g.count(p.fi)) {
			a->g[p.fi]=newnode(); sz++;
		}
		dfs2(a->g[p.fi],p.se,sz);
	}
}
void dfs(int u,int f) {
	sz[u]=1;
	for (auto v:e[u]) {
		if (v==f) continue;
		dfs(v,u);
		son[u].pb(v);
		sz[u]+=sz[v];
	}
	if (sz[u]==1) {
		rt[u]=newnode(); diff[u]=1;
		rt[u]->g[s[u]-'a']=newnode();
		return;
	}
	sort(all(son[u]),cmp);
	rt[u]=rt[son[u][0]]; diff[u]=diff[son[u][0]];
	rep(j,1,SZ(son[u])) {
		int v=son[u][j];
		dfs2(rt[u],rt[v],diff[u]);
	}
	node *p=newnode(); diff[u]++; p->g[s[u]-'a']=rt[u];
	rt[u]=p;
//	printf("%d %d\n",u,diff[u]);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",c+i);
	scanf("%s",s+1);
	rep(i,1,n) scanf("%d%d",&u,&v),e[u].pb(v),e[v].pb(u);
	dfs(1,0);
	int mv=0,st=0;
	rep(i,1,n+1) mv=max(mv,diff[i]+c[i]);
	rep(i,1,n+1) if (diff[i]+c[i]==mv) st++;
	printf("%d %d\n",mv,st);
}