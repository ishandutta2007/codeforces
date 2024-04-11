#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

namespace SAT2 {
	const int N=410;
	VI e[N];
	int n,cnt,dfn[N],low[N],st[N],bel[N],top,ind;
	bool ins[N],g[N][N];
	void init(int ct) {
		n=ct;
		cnt=0;top=0;ind=0;
		rep(i,0,n) e[i].clear();
		rep(i,0,n) rep(j,0,n) g[i][j]=0;
	}  
	void add(int u,int v) { if (g[u][v]) return; e[u].pb(v); g[u][v]=1;}
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
	void solve() {
		rep(i,0,n) dfn[i]=0;
		rep(i,0,n) if (!dfn[i]) tarjan(i);
	}
}

int n,m,l,p1,p2,av,ac;
PII e[201000];
char p[30],ch1[30],ch2[30],a[1010],ret[1010];
bool check(int len) {
	SAT2::init(n*2);
	rep(i,0,m) {
		SAT2::add(e[i].fi,e[i].se);
		SAT2::add(e[i].se^1,e[i].fi^1);
	}
	rep(i,0,len) {
		if (p[ret[i]-'a']=='V') SAT2::add(2*i,2*i+1);
		else SAT2::add(2*i+1,2*i);
	}
	rep(i,0,n) {
		if (av) SAT2::add(2*i,2*i+1);
		if (ac) SAT2::add(2*i+1,2*i); 
	}
	SAT2::solve();
	rep(i,0,n) if (SAT2::bel[2*i]==SAT2::bel[2*i+1]) return 0;
	return 1;
}
void dfs(int d,int fg) {
	if (d==n) {
		puts(ret);
		throw 0;
	} else {
		int v=0,c=0;
		rep(i,fg?0:a[d]-'a',l) {
			ret[d]=i+'a';
			if (p[i]=='V') {
				if (v>=2) continue;
				v++;
			}
			if (p[i]=='C') {
				if (c>=2) continue;
				c++;
			}
			if (check(d+1)) {
				dfs(d+1,fg|(i!=a[d]-'a'));
			}
		}
	}
}
int main() {
	scanf("%s",p); l=strlen(p);
	av=1; ac=1;
	rep(i,0,l) av&=(p[i]=='V'),ac&=(p[i]=='C');
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%s%d%s",&p1,ch1,&p2,ch2); --p1;--p2;
		int s1=ch1[0]=='V',s2=ch2[0]=='V';
		e[i]=mp(p1*2+s1,p2*2+s2);
	}
	scanf("%s",a);
	try {
		dfs(0,0);
	} catch(int e) {
		return 0;
	}
	puts("-1");
}