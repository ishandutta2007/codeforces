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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=501000;
int sz[N];
int n,u,v,_,c122;
VI e[N];
char s[N];
void dfs1(int u,int f) {
	VI ss;
	sz[u]=1;
	for (auto v:e[u]) if (v!=f) {
		dfs1(v,u);
		sz[u]+=sz[v];
		ss.pb(sz[v]);
	}
	if (sz[u]!=n) ss.pb(n-sz[u]);
	if (SZ(ss)==3) {
		sort(all(ss));
		if (ss[2]>=2&&ss[1]>=2) {
			c122=1;
		}
	}
}

map<pair<vector<PII>,string>,int> hs[2];

VI pe[100];
int cc[100];
int checkwin(vector<PII> ee,string col) {
	int n=SZ(ee)+1;
	rep(i,1,n+1) pe[i].clear();
	for (auto p:ee) {
		int u=p.fi,v=p.se;
		pe[u].pb(v);
		pe[v].pb(u);
	}
	rep(i,1,n+1) {
		cc[i]=0;
		if (col[i-1]!='N') {
			cc[i]=col[i-1]=='B'?-1:1;
		}
	}
	rep(i,1,n+1) if (cc[i]!=0) {
		int nb=0;
		for (auto v:pe[i]) if (cc[v]==cc[i]) nb++;
		if (nb>=2) return cc[i];
	}
	return 0;
}

int bf(vector<PII> ee,string col,int op) {
	pair<vector<PII>,string> st(ee,col);
	if (hs[op].count(st)) {
		return hs[op][st];
	}
	int s=checkwin(ee,col);
	if (s!=0) return hs[op][st]=s;
	if (op==0) {
		int z=-100;
		rep(i,0,n) if (col[i]=='N') {
			auto ncol=col;
			ncol[i]='W';
			z=max(z,bf(ee,ncol,1));
		}
		return hs[op][st]=(z==-100?0:z);
	} else {
		int z=100;
		rep(i,0,n) if (col[i]=='N') {
			auto ncol=col;
			ncol[i]='B';
			z=min(z,bf(ee,ncol,0));
		}
		return hs[op][st]=(z==100?0:z);
	}
}
bool solve() {
	scanf("%d",&n);
	rep(i,1,n+1) e[i].clear();
	vector<PII> E;
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		if (u>v) swap(u,v);
		e[u].pb(v);
		e[v].pb(u);
		E.pb(mp(u,v));
	}
	scanf("%s",s+1);
	if (n<=5) {
		int w=bf(E,string(s+1,s+n+1),0);
		assert(w>=0);
		return w;
	}
	rep(i,1,n+1) if (SZ(e[i])>=4) return 1;
	c122=0;
	dfs1(1,0);
	if (c122) return 1;
	bool an=1;
	rep(i,1,n+1) an&=(s[i]=='N');
	if (an) {
		int c3=0;
		rep(i,1,n+1) c3+=SZ(e[i])==3;
		if (c3>=3) return 1;
		if (c3==2) return n%2;
		return 0;
	}
	rep(i,1,n+1) if (s[i]=='W'&&SZ(e[i])>=2) {
		return 1;
	}
	rep(i,1,n+1) if (s[i]=='W'&&SZ(e[i])==1) {
		int v=e[i][0];
		if (SZ(e[v])>=3) return 1;
	}
	bool ch=1;
	rep(i,1,n+1) ch&=(SZ(e[i])<=2);
	if (ch) {
		int cw=0;
		rep(i,1,n+1) cw+=s[i]=='W';
		if (cw<=1) return 0;
		else return n%2;
	}
	int cw=0;
	rep(i,1,n+1) cw+=s[i]=='W';
	if (cw>=2) return 1;
	return 1-n%2;
//	return 1;
}

int main() {
	for (scanf("%d",&_);_;_--) {
		puts(solve()?"White":"Draw");
	}
}