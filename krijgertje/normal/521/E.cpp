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

const int MAXN=200000;
const int MAXM=200000;

int n,m;
int fst[MAXN];
int nxt[2*MAXM];
int to[2*MAXM];

bool been[MAXN];
int order[MAXN],norder;
int stck[MAXN],cur[MAXN],nstck;
int par[MAXN];
int d[MAXN];

int nc;
int cstart[MAXN];
int clen[MAXN];
int cidx[MAXN];
int cpos[MAXN];
int cnode[2*MAXN],ncnode;
bool visit[MAXN];

int npath;
int path[MAXN+1];

int ret[3][MAXN]; int nret[3];
void printsol() {
	printf("YES\n");
	assert(cidx[path[npath-1]]!=-1); int c=cidx[path[npath-1]],b=cpos[path[npath-1]];
	int a; if(path[0]==cnode[cstart[c]]) a=0; else { assert(cidx[path[0]]==c); a=cpos[path[0]]; }
	{ nret[0]=0; int at=a; while(true) { ret[0][nret[0]++]=cnode[cstart[c]+at]; if(at==b) break; at=(at+1)%clen[c]; } }
	{ nret[1]=0; int at=a; while(true) { ret[1][nret[1]++]=cnode[cstart[c]+at]; if(at==b) break; at=(at-1+clen[c])%clen[c]; } }
	{ nret[2]=npath; REP(i,npath) ret[2][i]=path[i]; }
	REP(i,3) { printf("%d",nret[i]); REP(j,nret[i]) printf(" %d",ret[i][j]+1); puts(""); }
}


void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) fst[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}
	//REP(i,n) { printf("%d:",i); for(int x=fst[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }

	REP(i,n) been[i]=visit[i]=false,cur[i]=fst[i],par[i]=-2,cidx[i]=cpos[i]=-1,d[i]=-1;
	REP(i,n) if(!been[i]) {
		norder=nstck=nc=ncnode=0;
		been[i]=true; order[norder++]=i; stck[nstck++]=i; par[i]=-1; d[i]=0;
		while(nstck>0) {
			int at=stck[nstck-1];
			while(cur[at]!=-1&&been[to[cur[at]]]) cur[at]=nxt[cur[at]];
			if(cur[at]!=-1) {
				int nat=to[cur[at]]; assert(!been[nat]);
				been[nat]=true; order[norder++]=nat; stck[nstck++]=nat; par[nat]=at; d[nat]=d[at]+1;
			} else {
				--nstck;
			}
		}
		//printf("order:"); REP(j,norder) printf(" %d",order[j]); puts("");
		REP(j,norder) {
			int at=order[j];
			for(int x=fst[at];x!=-1;x=nxt[x]) {
				if(to[x]==par[at]||par[to[x]]==at||d[to[x]]<d[at]) continue;
				npath=0;
				path[npath++]=at; visit[at]=true;
				int now=to[x];
				while(true) { path[npath++]=now; if(visit[now]) break; visit[now]=true; now=par[now]; }
				if(path[0]==path[npath-1]) {
					cstart[nc]=ncnode; clen[nc]=npath-1; ncnode+=clen[nc];
					cnode[cstart[nc]]=path[0]; FOR(i,1,npath-1) cnode[cstart[nc]+i]=path[i],cidx[path[i]]=nc,cpos[path[i]]=i;
					//printf("found cycle:"); REP(k,clen[nc]) printf(" %d",cnode[cstart[nc]+k]); puts("");
					nc++;
				} else {
					printsol();
					return;
				}
			}
		}
	}
	printf("NO\n");
}

int main() {
	run();
	return 0;
}