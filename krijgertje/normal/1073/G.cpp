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

const int ALPH=27;

typedef struct Node {
	int start,end;
	int childs[ALPH];
	int suffix;
	Node(int start,int end):start(start),end(end) { memset(childs,-1,sizeof(childs)); suffix=-1; }
} Node;

vector<Node> nodes;
int addnode(int start,int end) {
	nodes.push_back(Node(start,end));
	return SZ(nodes)-1;
}

int create(char *s) {
	int n=strlen(s);
	int root=addnode(0,0);
	int atnode=root,atedge=0,atlen=0,rem=0,prev=-1;
	for(int i=0;i<n;++i) {
		++rem; prev=-1;
		while(rem>0) {
			int tonode=nodes[atnode].childs[s[atedge]-'a'];
			int tostart=tonode==-1?-1:nodes[tonode].start;
			if(tonode!=-1&&nodes[tonode].start+atlen>=nodes[tonode].end) {
				atedge+=nodes[tonode].end-nodes[tonode].start;
				atlen-=nodes[tonode].end-nodes[tonode].start;
				atnode=tonode;
				continue;
			}
			if(tonode==-1) { //atlen should be 0
				int leaf=addnode(i,n);
				nodes[atnode].childs[s[atedge]-'a']=leaf;
				if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
			} else if(s[tostart+atlen]==s[i]) {
				++atlen;
				if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
				break;
			} else {
				int branch=addnode(tostart,tostart+atlen);
				nodes[tonode].start+=atlen;
				int leaf=addnode(i,n);
				nodes[atnode].childs[s[atedge]-'a']=branch;
				nodes[branch].childs[s[tostart+atlen]-'a']=tonode;
				nodes[branch].childs[s[i]-'a']=leaf;
				if(prev!=-1) nodes[prev].suffix=branch; prev=branch;
			}
			--rem;
			if(atnode==root) {
				if(atlen>0) --atlen;
				atedge++;
			} else {
				atnode=nodes[atnode].suffix;
			}
		}
	}
	return root;
}

const int MAXLEN=200000+1;
const int MAXQ=200000;
const int MAXNODES=2*MAXLEN+1;
const int MAXLG=18;

int slen,nq;
char s[MAXLEN+1];

vector<int> qa[MAXQ];
vector<int> qb[MAXQ];
ll qans[MAXQ];

void print(int node,int depth) {
	for(int i=0;i<depth;++i) printf("  ");
	printf("'"); for(int i=nodes[node].start;i<nodes[node].end;++i) printf("%c",s[i]); printf("'(%d)",node);
	if(nodes[node].end!=slen) printf(" -> %d",node); if(nodes[node].suffix!=-1) printf(" [%d]",nodes[node].suffix); puts("");
	for(int i=0;i<ALPH;++i) if(nodes[node].childs[i]!=-1) print(nodes[node].childs[i],depth+1);
}


int par[MAXNODES];
int dep[MAXNODES];
int len[MAXNODES];
int up[MAXNODES][MAXLG+1];
int id[MAXLEN];
int pre[MAXNODES],preidx[MAXNODES],npre;

void dfsinit(int at) {
	pre[npre]=at,preidx[at]=npre,++npre;
	dep[at]=par[at]==-1?0:dep[par[at]]+1;
	len[at]=(par[at]==-1?0:len[par[at]])+nodes[at].end-nodes[at].start;
	up[at][0]=par[at]==-1?at:par[at]; REP(k,MAXLG) up[at][k+1]=up[up[at][k]][k];
	if(nodes[at].end==slen) id[slen-len[at]]=at,--len[at];
	REP(i,ALPH) {
		int to=nodes[at].childs[i]; if(to==-1) continue;
		par[to]=at; dfsinit(to);
	}
}
int lca(int a,int b) {
	if(dep[a]<dep[b]) swap(a,b);
	for(int k=MAXLG;k>=0;--k) if(dep[a]-(1<<k)>=dep[b]) a=up[a][k];
	for(int k=MAXLG;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
	return a==b?a:up[a][0];
}

pair<int,int> spec[2*MAXLEN+1]; int nspec;
int stack[MAXNODES],nstack;
vector<int> ch[MAXNODES];
int lst[MAXNODES],nlst;
int colcnt[MAXNODES][2];


void maketree() {
	//printf("spec:"); REP(i,nspec) printf(" %d",spec[i].second); puts("");
	nstack=nlst=0;
	REP(i,nspec) {
		int at=spec[i].second;
		if(nstack==0) { assert(dep[at]==0); stack[nstack++]=at,lst[nlst++]=at; continue; }
		int x=lca(at,stack[nstack-1]);
		while(nstack>=2&&dep[x]<=dep[stack[nstack-2]]) {
			int a=stack[--nstack]; int b=stack[nstack-1];
			ch[b].PB(a);
		}
		if(dep[x]<dep[stack[nstack-1]]) {
			int a=stack[--nstack];
			ch[x].PB(a);
		}
		if(x!=stack[nstack-1]) stack[nstack++]=x,lst[nlst++]=x;
		if(x!=at) stack[nstack++]=at,lst[nlst++]=at;
	}
	while(nstack>=2) { int a=stack[--nstack]; int b=stack[nstack-1]; ch[b].PB(a); }
	REP(i,nlst) { int at=lst[i]; colcnt[at][0]=colcnt[at][1]=0; }
}
void cleartree() {
	REP(i,nlst) { int at=lst[i]; ch[at].clear(); }
}
ll dfsans(int at,int prv) {
	ll ret=0;
	REPSZ(i,ch[at]) {
		int to=ch[at][i];
		ret+=dfsans(to,at);
		REP(j,2) colcnt[at][j]+=colcnt[to][j];
	}
	if(prv!=-1) {
		ret+=(ll)colcnt[at][0]*colcnt[at][1]*(len[at]-len[prv]);
		//printf("dfsans(%d): %d %d (%d-%d)\n",at,colcnt[at][0],colcnt[at][1],len[at],len[prv]);
	}
	return ret;
}


void solve() {
	s[slen++]='z'+1; s[slen]='\0';
	nodes.clear();
	int root=create(s);
	//print(root,0);

	npre=0; par[root]=-1; REP(i,slen) id[i]=-1;
	dfsinit(root);
	//REP(i,slen) printf("%s: %d\n",s+i,id[i]);

	REP(i,nq) {
		nspec=0; spec[nspec++]=MP(preidx[root],root);
		REPSZ(j,qa[i]) { int x=id[qa[i][j]]; spec[nspec++]=MP(preidx[x],x); }
		REPSZ(j,qb[i]) { int x=id[qb[i][j]]; spec[nspec++]=MP(preidx[x],x); }
		sort(spec,spec+nspec); nspec=unique(spec,spec+nspec)-spec;
		maketree();
		REPSZ(j,qa[i]) { int x=id[qa[i][j]]; ++colcnt[x][0]; }
		REPSZ(j,qb[i]) { int x=id[qb[i][j]]; ++colcnt[x][1]; }
		qans[i]=dfsans(root,-1);
		cleartree();
	}
}

void run() {
	scanf("%d%d",&slen,&nq); scanf("%s",s);
	REP(i,nq) { int na,nb; scanf("%d%d",&na,&nb); REP(j,na) { int x; scanf("%d",&x); --x; qa[i].PB(x); } REP(j,nb) { int x; scanf("%d",&x); --x; qb[i].PB(x); } }
	solve();
	REP(i,nq) printf("%lld\n",qans[i]);
}

int main() {
	run();
	return 0;
}