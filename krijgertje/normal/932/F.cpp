#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int linecmpmethod=0; // 0=slope, 1=rx
struct Line { ll a,b; mutable ll rx; Line(ll a,ll b):a(a),b(b) {} Line(ll rx):rx(rx) {} }; // line is a*x+b, rightmost valid point for line is rx
bool operator<(const Line &u,const Line &v) {
	if(linecmpmethod==0) return u.a>v.a;
	if(linecmpmethod==1) return u.rx<v.rx;
	return false;
}
struct LowerEnvelop : multiset<Line> { // Lower envelop at integer points
	ll divdwn(ll num,ll den) { return num>=0?num/den:(num-den+1)/den; }
	void calcrx(iterator v,iterator w) {
		if(w==end()) v->rx=LLONG_MAX;
		else if(v->a==w->a) v->rx=v->b<w->b?LLONG_MAX:LLONG_MIN;
		else v->rx=divdwn(w->b-v->b,v->a-w->a);
	}
	void add(Line l) {
		auto v=insert(l);
		while(true) { auto w=next(v); calcrx(v,w); if(w==end()||v->rx<w->rx) break; w=erase(w); }
		if(v!=begin()) {
			auto u=prev(v); calcrx(u,v); if(!(u->rx<v->rx)) { v=erase(v); calcrx(u,v); }
			while(u!=begin()) { auto t=prev(u); if(t->rx<u->rx) break; erase(u); u=t; calcrx(u,v); }
		}
	}
	ll query(ll x) { assert(!empty()); linecmpmethod=1; Line l=*lower_bound(Line(x)); linecmpmethod=0; return l.a*x+l.b; }
};

const int MAXN=100000;

int n;
int a[MAXN];
int b[MAXN];
vector<int> adj[MAXN];
ll ans[MAXN];
LowerEnvelop env[MAXN];

int dfs(int at,int par) {
	int ret=at;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		int oth=dfs(to,at);
		if(SZ(env[ret])<SZ(env[oth])) swap(ret,oth);
		for(auto it=env[oth].begin();it!=env[oth].end();++it) env[ret].add(*it);
	}
	ans[at]=SZ(env[ret])==0?0:env[ret].query(a[at]);
	env[ret].add(Line(b[at],ans[at]));
	return ret;
}

void solve() {
	REP(i,n) env[i].clear();
	dfs(0,-1);
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]); REP(i,n) scanf("%d",&b[i]); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",ans[i]); } puts("");
}

ll bfans[MAXN];
ll bfdfs2(int at,int par,int rt) {
	ll ret=LLONG_MAX;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		ret=min(ret,(ll)a[rt]*b[to]+bfans[to]);
		ret=min(ret,bfdfs2(to,at,rt));
	}
	return ret;
}
void bfdfs(int at,int par) {
	bool leaf=true;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		leaf=false; bfdfs(to,at);
	}
	bfans[at]=leaf?0:bfdfs2(at,par,at);
}

void bfsolve() {
	bfdfs(0,-1);
}

void stress() {
	REP(rep,1000) {
		int mxval=100;
		n=10000; REP(i,n) a[i]=rand()%(2*mxval+1)-mxval,b[i]=rand()%(2*mxval+1)-mxval; REP(i,n) adj[i].clear(); FOR(y,1,n) { int x=rand()%y; adj[x].PB(y); adj[y].PB(x); }
		solve();
		bfsolve();
		bool ok=true; REP(i,n) if(ans[i]!=bfans[i]) ok=false;
		if(ok) { printf("."); continue; }
		printf("err\n");
		printf("have:"); REP(i,n) printf(" %lld",ans[i]); puts("");
		printf("want:"); REP(i,n) printf(" %lld",bfans[i]); puts("");
		printf("%d\n",n); REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts(""); REP(i,n) { if(i!=0) printf(" "); printf("%d",b[i]); } puts(""); REP(at,n) REPSZ(i,adj[at]) { int to=adj[at][i]; if(to<at) printf("%d %d\n",to+1,at+1); }
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}