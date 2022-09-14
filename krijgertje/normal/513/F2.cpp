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

const int MAXSIDE=22;
const int MAXCELL=MAXSIDE*MAXSIDE;
const int MAXN=1+MAXCELL+2*MAXCELL+MAXCELL+1;
const int MAXM=2*(MAXCELL+MAXCELL*MAXCELL+MAXCELL+MAXCELL*MAXCELL+MAXCELL);

typedef struct MF {
	int n,m,s,t;
	int flow;
	int fst[MAXN]; // n->e
	int nxt[MAXM]; // e->e
	int to[MAXM]; // e->n
	int cap[MAXM]; // e->int

	int root[MAXN]; // n->n
	int back[MAXN]; // n->e

	int q[MAXN],qhead,qtail;

	void init() {
		REP(i,n) fst[i]=-1;
		REP(i,n) root[i]=back[i]=-1; root[s]=s; root[t]=t;
	}

	void addedge(int a,int b) {
		nxt[m]=fst[a]; fst[a]=m; to[m]=b; cap[m]=1; int ab=m++;
		nxt[m]=fst[b]; fst[b]=m; to[m]=a; cap[m]=0; int ba=m++;
		if(root[a]==s&&root[b]==t) { foundpath(ab); return; }
		if(root[a]==s&&root[b]!=s) {
			qhead=qtail=0; root[b]=s; back[b]=ba; q[qhead++]=b;
			while(qtail<qhead) {
				int at=q[qtail++];
				for(int x=fst[at];x!=-1;x=nxt[x]) if(cap[x]>0&&root[to[x]]!=s) {
					if(root[to[x]]==t) { foundpath(x); return; }
					root[to[x]]=s; back[to[x]]=x^1; q[qhead++]=to[x];
				}
			}
		}
		if(root[b]==t&&root[a]!=t) {
			qhead=qtail=0; root[a]=t; back[a]=ab; q[qhead++]=a;
			while(qtail<qhead) {
				int at=q[qtail++];
				for(int x=fst[at];x!=-1;x=nxt[x]) if(cap[x^1]>0&&root[to[x^1]]!=t) {
					if(root[to[x^1]]==s) { foundpath(x^1); return; }
					root[to[x^1]]=t; back[to[x^1]]=x^1; q[qhead++]=to[x^1];
				}
			}
		}
	}

	void foundpath(int x) {
		--cap[x]; ++cap[x^1]; ++flow;
		for(int at=to[x^1];at!=s;at=to[back[at]]) { ++cap[back[at]]; --cap[back[at]^1]; }
		for(int at=to[x];at!=t;at=to[back[at]]) { --cap[back[at]]; ++cap[back[at]^1]; }
		REP(i,n) root[i]=back[i]=-1;
		qhead=qtail=0; root[s]=s; q[qhead++]=s;
		while(qtail<qhead) {
			int at=q[qtail++]; assert(at!=t);
			for(int x=fst[at];x!=-1;x=nxt[x]) if(cap[x]>0&&root[to[x]]!=s) {
				assert(root[to[x]]!=t);
				root[to[x]]=s; back[to[x]]=x^1; q[qhead++]=to[x];
			}
		}
		qhead=qtail=0; root[t]=t; q[qhead++]=t;
		while(qtail<qhead) {
			int at=q[qtail++]; assert(at!=s);
			for(int x=fst[at];x!=-1;x=nxt[x]) if(cap[x^1]>0&&root[to[x^1]]!=t) {
				assert(root[to[x^1]]!=s);
				root[to[x^1]]=t; back[to[x^1]]=x^1; q[qhead++]=to[x^1];
			}
		}
	}
} G;
G g;

typedef struct Evnt { int a,b; ll t; } Evnt;
bool operator<(const Evnt &p,const Evnt &q) { return p.t<q.t; }
Evnt evnt[2*MAXCELL*MAXCELL]; int nevnt;

int h,w,na,nb,npair;
char m[MAXSIDE][MAXSIDE];
int ax[MAXCELL],ay[MAXCELL],at[MAXCELL];
int bx[MAXCELL],by[MAXCELL],bt[MAXCELL];

int c[MAXSIDE][MAXSIDE],ncell;
int d[MAXCELL][MAXCELL];
const int DX[]={-1,0,+1,0},DY[]={0,+1,0,-1};

void run() {
	scanf("%d%d%d%d",&h,&w,&na,&nb);
	REP(x,h) REP(y,w) scanf(" %c",&m[x][y]);
	if(na+1==nb) scanf("%d%d%d",&ax[na],&ay[na],&at[na]); else if(nb+1==na) scanf("%d%d%d",&bx[nb],&by[nb],&bt[nb]); else { printf("-1\n"); return; }
	REP(i,na) scanf("%d%d%d",&ax[i],&ay[i],&at[i]); REP(i,nb) scanf("%d%d%d",&bx[i],&by[i],&bt[i]);
	npair=max(na,nb);
	REP(i,npair) --ax[i],--ay[i],--bx[i],--by[i];

	ncell=0; REP(x,h) REP(y,w) if(m[x][y]=='#') c[x][y]=-1; else c[x][y]=ncell++;
	REP(i,ncell) REP(j,ncell) d[i][j]=i==j?0:INT_MAX;
	REP(x,h) REP(y,w) if(c[x][y]!=-1) REP(k,4) {
		int nx=x+DX[k],ny=y+DY[k];
		if(nx<0||nx>=h||ny<0||ny>=w||c[nx][ny]==-1) continue;
		d[c[x][y]][c[nx][ny]]=1;
	}
	REP(k,ncell) REP(i,ncell) REP(j,ncell) if(d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX&&d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];


	g.n=2*npair+2*ncell+2; g.m=0; g.s=g.n-2; g.t=g.n-1; g.flow=0;
	g.init();
	REP(i,npair) g.addedge(g.s,i); REP(i,npair) g.addedge(npair+i,g.t); REP(i,ncell) g.addedge(2*npair+2*i+0,2*npair+2*i+1);

	nevnt=0;
	REP(i,npair) { int ac=c[ax[i]][ay[i]]; assert(ac!=-1); REP(j,ncell) if(d[ac][j]!=INT_MAX) { evnt[nevnt].a=i; evnt[nevnt].b=2*npair+2*j+0; evnt[nevnt].t=(ll)at[i]*d[ac][j]; ++nevnt; } }
	REP(i,npair) { int bc=c[bx[i]][by[i]]; assert(bc!=-1); REP(j,ncell) if(d[bc][j]!=INT_MAX) { evnt[nevnt].a=2*npair+2*j+1; evnt[nevnt].b=npair+i; evnt[nevnt].t=(ll)bt[i]*d[bc][j]; ++nevnt; } }
	sort(evnt,evnt+nevnt);

	//REP(i,nevnt) printf("%lld: %d->%d\n",evnt[i].t,evnt[i].a,evnt[i].b);

	REP(i,nevnt) {
		g.addedge(evnt[i].a,evnt[i].b);
		if(g.flow==npair) { cout<<evnt[i].t<<endl; return; }
	}
	printf("-1\n");
}

int main() {
	run();
	return 0;
}