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

const int MAXN=300000;
const int MAXM=300000;

int n,m;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],deg[MAXN];

bool done[MAXN];
bool dead[MAXN];
int prv[MAXN];
int q[MAXN],qhead,qtail;

int path[MAXN],npath;
int id[MAXN];
int cnt[MAXN];

bool solve() {
	int s=-1,t=-1;
	//REP(i,n) { printf("%d:",i+1); for(int x=ghead[i];x!=-1;x=gnxt[x]) printf(" %d",gto[x]+1); puts(""); }
	REP(i,n) {
		REP(j,n) done[j]=false;
		for(int x=ghead[i];x!=-1;x=gnxt[x]) done[gto[x]]=true;
		REP(j,n) if(i!=j&&!done[j]) { t=j; break; }
		if(t!=-1) { s=i; break; }
	}
	if(s==-1&&t==-1) { REP(i,n) id[i]=0; return true; }
	//printf("s=%d t=%d\n",s,t);
	REP(j,n) done[j]=false,prv[j]=-2; qhead=qtail=0; done[s]=true,prv[s]=-1,q[qhead++]=s;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(!done[to]) done[to]=true,prv[to]=at,q[qhead++]=to; }
	}
	//printf("init path:"); for(int at=t;at!=-1;at=prv[at]) printf(" %d",at+1); puts("");
	assert(done[t]);
	REP(j,n) done[j]=false; for(int at=t;at!=-1;at=prv[at]) done[at]=true;
	REP(j,n) dead[j]=false; for(int at=prv[t];at!=s;at=prv[at]) for(int x=ghead[at];x!=-1;x=gnxt[x]) dead[gto[x]]=true;
	while(true) {
		int to=-1; for(int x=ghead[s];x!=-1;x=gnxt[x]) if(!done[gto[x]]&&!dead[gto[x]]) { to=gto[x]; break; } if(to==-1) break;
		for(int x=ghead[s];x!=-1;x=gnxt[x]) dead[gto[x]]=true;
		done[to]=true,prv[s]=to,prv[to]=-1,s=to;
	}
	while(true) {
		int to=-1; for(int x=ghead[t];x!=-1;x=gnxt[x]) if(!done[gto[x]]&&!dead[gto[x]]) { to=gto[x]; break; } if(to==-1) break;
		for(int x=ghead[t];x!=-1;x=gnxt[x]) dead[gto[x]]=true;
		done[to]=true,prv[to]=t,t=to;
	}
	npath=0; for(int at=t;at!=-1;at=prv[at]) path[npath++]=at; reverse(path,path+npath);
	//printf("final path:"); for(int at=t;at!=-1;at=prv[at]) printf(" %d",at+1); puts("");
	REP(i,n) id[i]=-1; REP(i,npath) id[path[i]]=i;
	REP(at,n) if(id[at]==-1) {
		int mn=-1,mx=-1; bool any=false;
		for(int x=ghead[at];x!=-1;x=gnxt[x]) if(id[gto[x]]!=-1) {
			if(!any) { mn=mx=id[gto[x]]; any=true; continue; }
			if(id[gto[x]]<mn) mn=id[gto[x]]; if(id[gto[x]]>mx) mx=id[gto[x]];
		}
		//printf("%d:",at+1); if(!any) printf(" none\n"); else printf(" %d..%d\n",mn+1,mx+1);
		if(!any) return false;
		if(mx-mn==2) id[at]=mn+1; else if(mx-mn==1&&mn==0) id[at]=mn; else if(mx-mn==1&&mx==npath-1) id[at]=mx; else return false;
	}
	REP(at,n) for(int x=ghead[at];x!=-1;x=gnxt[x]) if(abs(id[at]-id[gto[x]])>1) return false;
	REP(i,npath) cnt[i]=0; REP(at,n) cnt[id[at]]++;
	REP(at,n) { int want=-1; FORE(d,-1,+1) { int nid=id[at]+d; if(nid<0||nid>=npath) continue; want+=cnt[nid]; } if(want!=deg[at]) return false; }
	return true;
}

void run() {
	scanf("%d%d",&n,&m); REP(i,n) ghead[i]=-1,deg[i]=0;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b,++deg[a];
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a,++deg[b];
	}
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%d",id[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}