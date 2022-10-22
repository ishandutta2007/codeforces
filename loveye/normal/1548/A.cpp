#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 2e5 + 5;
int n,m;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
struct Node {
	int t; pii e;
	inline bool operator < (const Node &o) const {
		return e < o.e;
	}
};
int ans[N];
vector<pii> buc[N << 2];
#define lc (k << 1)
#define rc (lc | 1)
#define left lc,l,mid
#define right rc,mid+1,r
void change(int k,int l,int r,int x,int y,pii v) {
	if(x <= l && r <= y) return buc[k].push_back(v);
	int mid = l + r >> 1;
	if(x <= mid) change(left,x,y,v);
	if(y > mid) change(right,x,y,v);
}
int nowans; bool vis[N];
void dfs(int k,int l,int r) {
	vector<int> tmp;
	for(auto x : buc[k]) if(vis[x.fi]) {
		vis[x.fi] = 0;
		--nowans;
		tmp.push_back(x.fi);
	}
	if(l == r) {
		if(ans[l]) printf("%d\n",nowans);
		for(auto x : tmp) vis[x] = 1,++nowans;
		return;
	}
	int mid = l + r >> 1;
	dfs(left),dfs(right);
	for(auto x : tmp) vis[x] = 1,++nowans;
}
set<Node> s;
int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1,u,v;i <= m;++i) {
		scanf("%d%d",&u,&v);
		if(u > v) swap(u,v);
		s.insert((Node){1,mp(u,v)});
	}
	int q; scanf("%d",&q);
	fr(kas,1,q) {
		static int u,v,op;
		scanf("%d",&op);
		if(op == 3) ans[kas] = 1;
		else {
			scanf("%d%d",&u,&v);
			if(u > v) swap(u,v);
			if(op == 1) s.insert((Node){kas,mp(u,v)});
			else {
				auto it = s.find((Node){kas,mp(u,v)});
				change(1,1,q,it->t,kas,mp(u,v));
				s.erase(it);
			}
		}
	}
	for(auto it : s) change(1,1,q,it.t,q,it.e);
	nowans = n;
	fr(i,1,n) vis[i] = 1;
	dfs(1,1,q);
	return 0;
}