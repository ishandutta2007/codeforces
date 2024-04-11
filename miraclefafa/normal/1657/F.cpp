#include <bits/stdc++.h>
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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=401000;
VI nch[N],npre[N],nsuf[N],e[N];
vector<char> pch[N];
set<int> ch[N];
string st[N];
VI p[N];
int n,q,dep[N],par[N];
char s[N],ans[N];

void dfs(int u,int f) {
	dep[u]=dep[f]+1;
	par[u]=f;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
	}
}

namespace SAT2 {
	const int N=6200000;
	VI e[N];
	int n,cnt,dfn[N],low[N],st[N],bel[N],top,ind;
	bool ins[N];
	void init(int ct) {
		n=ct;
		cnt=0;top=0;ind=0;
		//rep(i,0,n) e[i].clear();
	}  
	void add(int u,int v) { e[u].pb(v);}
	void padd(int u,int v) {
		//printf("padd %d %d\n",u,v);
		e[u].pb(v);
		e[v^1].pb(u^1);
	}
	void tarjan(int u) {
		dfn[u]=low[u]=++ind;
		ins[u]=1;
		st[++top]=u;
		rep(i,0,SZ(e[u])) {
			int v=e[u][i];
			if (!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
			else if (ins[v]) low[u]=min(low[u],low[v]);
		} 
		if (dfn[u]==low[u]) {
			++cnt;
			while (1) {
				bel[st[top]]=cnt;
				ins[st[top]]=0;
				if (st[top--]==u) break;
			}
		}
	}
	bool solve() {
		rep(i,0,n) dfn[i]=0;
		rep(i,0,n) if (!dfn[i]) tarjan(i);
		rep(i,0,n/2) if (bel[2*i]==bel[2*i+1]) return 0;
		return 1;
		// bel i>=bel i' ->i'
	}
}

int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n) {
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,0);
	rep(i,0,q) {
		int u,v;
		scanf("%d%d%s",&u,&v,s);
		int m=strlen(s);
		// not sure
		int pu=(dep[u]-dep[v]+m)/2,pv=(dep[v]-dep[u]+m)/2;
		VI pt,pt2;
		rep(j,0,pu) {
			pt.pb(u); u=par[u];
		}
		rep(j,0,pv) {
			pt2.pb(v); v=par[v];
		}
		assert(u==v);
		reverse(all(pt2));
		pt.pb(u);
		for (auto v:pt2) pt.pb(v);
		p[i]=pt; st[i]=s;
		rep(i,0,m) {
			ch[pt[i]].insert(s[i]);
			ch[pt[i]].insert(s[m-i-1]);
		}
	}
	int id=q;
	rep(i,1,n+1) {
		for (auto p:ch[i]) {
			pch[i].pb(p);
		}
		int m=SZ(pch[i]);
		npre[i].resize(m);
		nsuf[i].resize(m);
		nch[i].resize(m);
		//rep(j,0,m) printf("zz %d %c\n",i,pch[i][j]);
		rep(j,0,m) {
			npre[i][j]=id++;
			nsuf[i][j]=id++;
			nch[i][j]=id++;
		}
		rep(j,1,m) {
			SAT2::padd(npre[i][j]*2,npre[i][j-1]*2);
			SAT2::padd(nsuf[i][j-1]*2,nsuf[i][j]*2);
		}
		rep(j,0,m) {
			SAT2::padd(npre[i][j]*2,nch[i][j]*2);
			SAT2::padd(nsuf[i][j]*2,nch[i][j]*2);
			if (j>0) SAT2::padd(nch[i][j]*2+1,npre[i][j-1]*2);
			if (j+1<m) SAT2::padd(nch[i][j]*2+1,nsuf[i][j+1]*2);
		}
	}
	rep(i,0,q) {
		int m=SZ(p[i]);
		rep(j,0,m) {
			char s=st[i][j];
			int u=p[i][j];
			int id=lower_bound(all(pch[u]),s)-pch[u].begin();
			//printf("fff %d %d %d\n",i,u,id);
			SAT2::padd(i*2,nch[u][id]*2+1);
		}
		rep(j,0,m) {
			char s=st[i][m-1-j];
			int u=p[i][j];
			int id=lower_bound(all(pch[u]),s)-pch[u].begin();
			//printf("ggg %d %d %d\n",i,u,id);
			SAT2::padd(i*2+1,nch[u][id]*2+1);
		}
	}
	SAT2::n=2*id;
	//printf("qq %d\n",SAT2::n);
	if (!SAT2::solve()) {
		puts("NO");
		return 0;
	}
	rep(i,1,n+1) ans[i]='a';
	rep(i,0,q) {
		//printf("zz %d %d\n",SAT2::bel[2*i],SAT2::bel[2*i+1]);
		if (SAT2::bel[2*i]>SAT2::bel[2*i+1]) {
			reverse(all(p[i]));
		}
		int m=SZ(p[i]);
		rep(j,0,m) ans[p[i][j]]=st[i][j];
	}
	puts("YES");
	puts(ans+1);
}