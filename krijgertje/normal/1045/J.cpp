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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXQ=100000;
const int MAXLEN=100;
const int ALPH=26;
const int MAXLG=16;
const int BATCHSIZE=2000;

int n;
vector<pair<int,char>> e[MAXN];
int nq;
int qa[MAXQ],qb[MAXQ]; char qs[MAXQ][MAXLEN+1]; int qlen[MAXQ],qans[MAXQ];

struct AhoNode { int fail,head;  AhoNode():fail(-1),head(-1) {} };
struct AhoEdge { int nxt; char c; int to; AhoEdge() {} AhoEdge(int nxt,char c,int to):nxt(nxt),c(c),to(to) {} };
struct Aho {
    AhoNode nodes[BATCHSIZE*MAXLEN+1]; int nnodes;
    AhoEdge edges[BATCHSIZE*MAXLEN]; int nedges;
	int root;
	int addnode() { int ret=nnodes; nodes[nnodes++]=AhoNode(); return ret; }
	void addedge(int at,char c,int to) { edges[nedges++]=AhoEdge(nodes[at].head,c,to); nodes[at].head=nedges-1; }
	int getnxt(int at,char c) { for(int x=nodes[at].head;x!=-1;x=edges[x].nxt) if(edges[x].c==c) return edges[x].to; return -1; }
	void init() { nnodes=nedges=0; root=addnode(); }
	int add(char *s) { int at=root; for(int i=0;s[i]!='\0';++i) { int to=getnxt(at,s[i]); if(to==-1) { to=addnode(); addedge(at,s[i],to); } at=to; } return at; }
	vector<int> bfs;
	void build() {
		bfs=vector<int>(1,root); REPSZ(i,bfs) { int at=bfs[i]; for(int x=nodes[at].head;x!=-1;x=edges[x].nxt) { int to=edges[x].to; bfs.PB(to); } } assert(SZ(bfs)==nnodes);
		nodes[root].fail=root; REPSZ(i,bfs) { int at=bfs[i]; for(int x=nodes[at].head;x!=-1;x=edges[x].nxt) { char c=edges[x].c; int to=nodes[at].fail; while(to!=root&&getnxt(to,c)==-1) to=nodes[to].fail; to=getnxt(to,c); if(at==root||to==-1) to=root; nodes[edges[x].to].fail=to; } }
		//REPSZ(at,nodes) { printf("%d: fail=%d nxt:",at,nodes[at].fail); for(int x=nodes[at].head;x!=-1;x=edges[x].nxt) printf(" %c=%d",edges[x].c,edges[x].to); puts(""); }
	}
};

struct Kmp {
	vector<int> nxt; char *s; int slen;
	void init(char *_s) { s=_s,slen=strlen(s); nxt=vector<int>(slen+1); nxt[0]=nxt[1]=0; FORE(i,2,slen) { int at=nxt[i-1]; while(at!=0&&s[i-1]!=s[at]) at=nxt[at]; if(s[i-1]==s[at]) ++at; nxt[i]=at; } }
	int count(char *t) { int ret=0,at=0,tlen=strlen(t); REP(i,tlen) { while(at!=0&&t[i]!=s[at]) at=nxt[at]; if(t[i]==s[at]) ++at; if(at==slen) ++ret,at=nxt[at]; } return ret; }
};

int par[MAXN],up[MAXN][MAXLG+1],sz[MAXN],dep[MAXN],heavy[MAXN]; char parc[MAXN];
int hroot[MAXN],hlen[MAXN],hdn[MAXN],hup[MAXN];
char s[2*MAXN+1]; int slen;

void dfsinit(int at) {
	dep[at]=par[at]==-1?0:dep[par[at]]+1,sz[at]=1,heavy[at]=-1; up[at][0]=par[at]==-1?at:par[at]; REP(k,MAXLG) up[at][k+1]=up[up[at][k]][k];
	REPSZ(i,e[at]) {
		int to=e[at][i].first; if(to==par[at]) continue;
		par[to]=at,parc[to]=e[at][i].second; dfsinit(to); sz[at]+=sz[to];
		if(heavy[at]==-1||sz[to]>sz[heavy[at]]) heavy[at]=to;
	}
	//printf("%d: par=%d dep=%d sz=%d heavy=%d up=",at+1,par[at]+1,dep[at],sz[at],heavy[at]+1); REPE(k,MAXLG) printf("%d ",up[at][k]+1); puts("");
}
int lca(int a,int b) { if(dep[a]<dep[b]) swap(a,b); for(int k=MAXLG;k>=0;--k) if(dep[a]-(1<<k)>=dep[b]) a=up[a][k]; for(int k=MAXLG;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k]; return a==b?a:up[a][0]; }
vector<pair<int,int>> getpath(int a,int b) {
	int c=lca(a,b); vector<pair<int,int>> retup,retdn;
	//printf("%d to %d -> lca=%d\n",a+1,b+1,c+1);
	while(hroot[a]!=hroot[c]) { int x=hroot[a],off=dep[a]-dep[x]; retup.PB(MP(hup[x]+hlen[x]-off-1,hup[x]+hlen[x]-1)); a=par[hroot[a]]; }
	if(a!=c) { int x=hroot[a],off1=dep[a]-dep[x],off2=dep[c]-dep[x]+1; retup.PB(MP(hup[x]+hlen[x]-off1-1,hup[x]+hlen[x]-off2-1)); a=c; }
	while(hroot[b]!=hroot[c]) { int x=hroot[b],off=dep[b]-dep[x]; retdn.PB(MP(hdn[x],hdn[x]+off)); b=par[hroot[b]]; }
	if(b!=c) { int x=hroot[b],off1=dep[b]-dep[x],off2=dep[c]-dep[x]+1; retdn.PB(MP(hdn[x]+off2,hdn[x]+off1)); b=c; }
	//printf("retup:"); REPSZ(i,retup) printf(" %d..%d",retup[i].first,retup[i].second); puts("");
	//printf("retdn:"); REPSZ(i,retdn) printf(" %d..%d",retdn[i].first,retdn[i].second); puts("");
	reverse(retdn.begin(),retdn.end()); vector<pair<int,int>> ret=retup; REPSZ(i,retdn) ret.PB(retdn[i]); return ret;
}


int qid[MAXQ];
Aho aho;
Kmp kmp;
char t[2*(MAXLEN-1)+1]; int tlen;
vector<vector<int>> pos;

void solve() {
	//return;
	//printf("qid:"); REP(i,nq) printf(" %d",qid[i]); puts("");
	par[0]=-1,parc[0]='-'; dfsinit(0);
	REP(i,n) if(par[i]!=-1&&heavy[par[i]]==i) hlen[i]=-1; else { hlen[i]=0; for(int at=i;at!=-1;at=heavy[at]) hroot[at]=i,++hlen[i]; }
	slen=0; REP(i,n) if(hlen[i]==-1) hdn[i]=hup[i]=-1; else { hdn[i]=slen; slen+=hlen[i]; hup[i]=slen; slen+=hlen[i]; for(int at=i,j=0;at!=-1;at=heavy[at],++j) s[hdn[i]+j]=s[hup[i]+hlen[i]-j-1]=parc[at]; } s[slen]='\0';
	//printf("s: %s\n",s);
	for(int bs=0;bs<nq;bs+=BATCHSIZE) {
	    int be=min(bs+BATCHSIZE,nq);
    	aho.init();
	    FOR(i,bs,be) qid[i]=aho.add(qs[i]);
	    aho.build();
    	{ pos=vector<vector<int>>(aho.nnodes); int at=aho.root; REP(i,slen) { while(at!=aho.root&&aho.getnxt(at,s[i])==-1) at=aho.nodes[at].fail; at=aho.getnxt(at,s[i]); if(at==-1) at=aho.root; for(int to=at;to!=aho.root;to=aho.nodes[to].fail) pos[to].PB(i); } }
	    
    	FOR(i,bs,be) {
    		vector<pair<int,int>> path=getpath(qa[i],qb[i]);
    		kmp.init(qs[i]);
    		//printf("%d->%d %s:",qa[i]+1,qb[i]+1,qs[i]); REPSZ(j,path) { printf(" "); FORE(k,path[j].first,path[j].second) printf("%c",s[k]); } puts("");
    		//printf("nxt:"); REPSZ(j,kmp.nxt) printf(" %d",kmp.nxt[j]); puts("");
    		//printf("pos:"); REPSZ(j,pos[qid[i]]) printf(" %d",pos[qid[i]][j]); puts("");
    		qans[i]=0;
    		REPSZ(j,path) {
    			int plen=path[j].second-path[j].first+1,nfst=min(qlen[i]-1,plen);
    			tlen=0; REP(k,nfst) t[tlen++]=s[path[j].second+1-nfst+k]; for(int jj=j+1;jj<SZ(path)&&tlen<nfst+qlen[i]-1;++jj) for(int k=path[jj].first;k<=path[jj].second&&tlen<nfst+qlen[i]-1;++k) t[tlen++]=s[k]; t[tlen]='\0';
    			//printf("\t%s\n",t);
    			qans[i]+=kmp.count(t);
    			if(plen>=qlen[i]) {
    				int l=lower_bound(pos[qid[i]].begin(),pos[qid[i]].end(),path[j].first+qlen[i]-1)-pos[qid[i]].begin();
    				int r=lower_bound(pos[qid[i]].begin(),pos[qid[i]].end(),path[j].second+1)-pos[qid[i]].begin();
    				qans[i]+=r-l;
    				//printf("\t[%d..%d)\n",l,r);
    			}
    		}
    	}
	}


}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; char c; scanf("%d%d %c",&a,&b,&c); --a,--b; e[a].PB(MP(b,c)); e[b].PB(MP(a,c)); }
	scanf("%d",&nq);
	REP(i,nq) { scanf("%d%d%s",&qa[i],&qb[i],qs[i]); --qa[i],--qb[i],qlen[i]=strlen(qs[i]); }

	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int myrand() { return rand()%1000*1000+rand()%1000; }
void stress() {
	n=MAXN; REP(i,n-1) { int a=i+1,b=myrand()%(i+1); char c='a'+rand()%26; e[a].PB(MP(b,c)); e[b].PB(MP(a,c)); }
	nq=MAXQ; REP(i,nq) { qa[i]=myrand()%n,qb[i]=myrand()%n; REP(j,MAXLEN) qs[i][j]='a'+rand()%26; qs[i][MAXLEN]='\0'; qlen[i]=MAXLEN; }
	solve();
}

int main() {
	run();
	//stress();
	return 0;
}