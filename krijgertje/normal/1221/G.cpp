#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }


const int MAXN=40;

int n,m;
vector<int> adj[MAXN];

int col[MAXN];
bool been[MAXN];

bool dfscol(int at,int c) { if(col[at]!=-1) return col[at]==c; else col[at]=c; REPSZ(i,adj[at]) { int to=adj[at][i]; if(!dfscol(to,1-c)) return false; } return true; }
void dfsbeen(int at) { if(been[at]) return; else been[at]=true; REPSZ(i,adj[at]) { int to=adj[at][i]; dfsbeen(to); } }


ll calcany() { return 1LL<<n; }
ll calcindep() {
	int n1=n/2,n2=n-n1;
	vector<ll> adjmask(n,0LL); REP(at,n) REPSZ(i,adj[at]) { int to=adj[at][i]; adjmask[at]|=1LL<<to; }
	vector<int> ways(1<<n2,0);
	REP(mask,1<<n1) {
		bool ok=true; int othmask=0;
		REP(i,n1) if((mask&(1<<i))!=0) {
			if((adjmask[i]&mask)!=0) ok=false;
			othmask|=adjmask[i]>>n1;
		}
		if(!ok) continue;
		assert(othmask>=0&&othmask<(1<<n2));
		//printf("%x -> %x -> %x\n",mask,othmask,(1<<n2)-1-othmask);
		++ways[(1<<n2)-1-othmask];
	}
	//REP(mask,1<<n1) if(ways[mask]!=0) printf("before %x: %d\n",mask,ways[mask]);
	REP(bit,n2) REP(mask,1<<n2) if((mask&(1<<bit))!=0) ways[mask^(1<<bit)]+=ways[mask];
	//REP(mask,1<<n1) if(ways[mask]!=0) printf("after %x: %d\n",mask,ways[mask]);
	ll ret=0;
	REP(mask,1<<n2) {
		bool ok=true;
		REP(i,n2) if((mask&(1<<i))!=0) {
			if((adjmask[n1+i]&(((ll)mask)<<n1))!=0) ok=false;
		}
		if(!ok) continue;
		//printf("%x -> %d\n",mask,ways[mask]);
		ret+=ways[mask];
	}
	//printf("indep=%lld\n",ret);
	return ret;
}
ll calcmono() { REP(i,n) been[i]=false; ll ret=1; REP(i,n) if(!been[i]) dfsbeen(i),ret*=2; return ret; }
ll calcbipartite() { REP(i,n) col[i]=-1; ll ret=1; REP(i,n) if(col[i]==-1) if(!dfscol(i,0)) return 0; else ret*=2; return ret; }
ll calcsingle() { ll ret=1; REP(i,n) if(SZ(adj[i])==0) ret*=2; return ret; }
ll calcnone() { ll ret=1; REP(i,n) if(SZ(adj[i])>0) return 0; else ret*=2; return ret; }

ll solve() {
	ll ret=0;
	ret+=calcany();
	ret-=2*calcindep();
	ret-=calcmono();
	ret+=calcbipartite();
	ret+=2*calcsingle();
	ret-=calcnone();
	return ret;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}