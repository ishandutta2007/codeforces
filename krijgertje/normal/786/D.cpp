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

const int MAXN=20000;
const int MAXQ=20000;

const int MAXGN=MAXN;
const int MAXGM=MAXGN-1;
typedef void (*decompose_callback)(int); 
typedef struct G {
	int n,m;
	int ghead[MAXGN],gnxt[2*MAXGM],gto[2*MAXGM]; char gc[MAXGM];
	void init(int _n) { n=_n,m=0; REP(i,n) ghead[i]=-1; }
	void addedge(int a,int b,char c) { gnxt[2*m+0]=ghead[a],ghead[a]=2*m+0,gto[2*m+0]=b; gnxt[2*m+1]=ghead[b],ghead[b]=2*m+1,gto[2*m+1]=a; gc[m]=c; ++m; }

	bool wascentroid[MAXGN];
	int csz[MAXGN];
	void decompose(int root,decompose_callback cb) {
		REP(i,n) wascentroid[i]=false;
		_decompose(root,cb);
	}
	void _decompose(int at,decompose_callback cb) {
		dfscentroidsz(at,-1);
		at=dfscentroid(at,-1,csz[at]);
		cb(at);
		wascentroid[at]=true;
		for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(wascentroid[to]) continue; _decompose(to,cb); }
	}
	void dfscentroidsz(int at,int par) { csz[at]=1; for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(wascentroid[to]||to==par) continue; dfscentroidsz(to,at); csz[at]+=csz[to]; } }
	int dfscentroid(int at,int par,int cn) { for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(wascentroid[to]||to==par) continue; if(2*csz[to]>cn) return dfscentroid(to,at,cn); } return at; }
} G;
G g;

const int MAXTN=MAXN;
typedef struct T {
	int n;
	int root,chead[MAXTN],cnxt[MAXTN],par[MAXTN]; char cpar[MAXTN];
	void init(const G &g,int rt) { n=g.n,root=rt; REP(i,n) chead[i]=-1; par[rt]=-1,cpar[rt]='-'; dfsinit(g,rt); }
	void dfsinit(const G &g,int at) { for(int x=g.ghead[at];x!=-1;x=g.gnxt[x]) { int to=g.gto[x]; if(to==par[at]) continue; par[to]=at,cpar[to]=g.gc[x>>1]; dfsinit(g,to); cnxt[to]=chead[at]; chead[at]=to; } }

	typedef struct LadderSeg { int id,s,t; LadderSeg(int id,int s,int t):id(id),s(s),t(t) {} } LadderSeg;
	int d[MAXTN],h[MAXTN],longpath[MAXTN],nladders,ladderoff[MAXTN+1],laddernodes[2*MAXTN],ladderid[MAXTN];
	void calcladders() {
		d[root]=0; dfslongpaths(root); nladders=ladderoff[0]=0;
		REP(i,n) if(par[i]==-1||longpath[par[i]]!=i) {
			int id=nladders++; ladderoff[id+1]=ladderoff[id];
			for(int at=par[i],j=0;at!=-1&&j<h[i];at=par[at],++j) laddernodes[ladderoff[id+1]++]=at;
			reverse(laddernodes+ladderoff[id],laddernodes+ladderoff[id+1]);
			for(int at=i;at!=-1;at=longpath[at]) ladderid[at]=id,laddernodes[ladderoff[id+1]++]=at;
		}
		//REP(i,nladders) { printf("ladder%d:",i); FOR(j,ladderoff[i],ladderoff[i+1]) printf(" %d",laddernodes[j]); puts(""); }
	}
	void dfslongpaths(int at) { h[at]=1,longpath[at]=-1; for(int to=chead[at];to!=-1;to=cnxt[to]) { d[to]=d[at]+1; dfslongpaths(to); if(h[to]+1>h[at]) h[at]=h[to]+1,longpath[at]=to; } }
	int lca(int u,int v) {
		while(true) {
			if(u==v) return u;
			int uid=ladderid[u],uoff=ladderoff[uid],dutop=d[laddernodes[uoff]];
			int vid=ladderid[v],voff=ladderoff[vid],dvtop=d[laddernodes[voff]];
			int dmn=max(dutop,dvtop);
			if(d[u]<=dmn) { v=laddernodes[voff]; continue; } if(d[v]<=dmn) { u=laddernodes[uoff]; continue; }
			int nu=laddernodes[uoff+dmn-dutop],nv=laddernodes[voff+dmn-dvtop];
			//printf("u=%d du=%d uid=%d uoff=%d dutop=%d, v=%d dv=%d vid=%d voff=%d dvtop=%d, dmn=%d nu=%d nv=%d\n",u,d[u],uid,uoff,dutop,v,d[v],vid,voff,dvtop,dmn,nu,nv);
			if(nu!=nv) { u=nu; v=nv; continue; }
			int k=0; while(dmn+(1<<k)<d[u]&&dmn+(1<<k)<d[v]) ++k; for(--k;k>=0;--k) if(dmn+(1<<k)<d[u]&&dmn+(1<<k)<d[v]&&laddernodes[uoff+dmn+(1<<k)-dutop]==laddernodes[voff+dmn+(1<<k)-dvtop]) dmn+=1<<k;
			if(laddernodes[uoff+dmn+1-dutop]==laddernodes[voff+dmn+1-dvtop]) return laddernodes[uoff+dmn+1-dutop]; else return laddernodes[uoff+dmn-dutop];
		}
	}
	vector<LadderSeg> ladderpath(int u,int v) {
		vector<LadderSeg> ret;
		int w=lca(u,v);
		while(u!=w) {
			int id=ladderid[u],off=ladderoff[id],dtop=d[laddernodes[off]]; 
			if(dtop>=d[w]) { ret.PB(LadderSeg(id,d[u]-dtop,0)); u=laddernodes[off]; continue; }
			ret.PB(LadderSeg(id,d[u]-dtop,d[w]-dtop)); u=laddernodes[off+d[w]-dtop];
		}
		int revoff=SZ(ret);
		while(v!=w) {
			int id=ladderid[v],off=ladderoff[id],dtop=d[laddernodes[off]]; 
			if(dtop>=d[w]) { ret.PB(LadderSeg(id,0,d[v]-dtop)); v=laddernodes[off]; continue; }
			ret.PB(LadderSeg(id,d[w]-dtop,d[v]-dtop)); v=laddernodes[off+d[w]-dtop];
		}
		reverse(ret.begin()+revoff,ret.end());
		//printf("ladderpath(%d,%d) [%d]\n",u,v,w); REPSZ(i,ret) printf("on %d from %d to %d\n",ret[i].id,ret[i].s,ret[i].t);
		return ret;
	}
} T;
T t;

const int MAXSTLEN=4*MAXN+1;
const int MAXLGSTLEN=16;
typedef struct SuffTree {
	typedef struct Node {
		int start,end;
		int childs[27];
		int suffix;
		Node() {}
		Node(int start,int end):start(start),end(end) { memset(childs,-1,sizeof(childs)); suffix=-1; }
	} Node;

	char s[MAXSTLEN+1]; int slen;
	Node nodes[2*MAXSTLEN-1]; int nnodes,root;

	int addnode(int start,int end) {
		int ret=nnodes++;
		nodes[ret]=Node(start,end);
		return ret;
	}

	void build() {
		nnodes=0;
		root=addnode(0,0);
		int atnode=root,atedge=0,atlen=0,rem=0,prev=-1;
		for(int i=0;i<slen;++i) {
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
					int leaf=addnode(i,slen);
					nodes[atnode].childs[s[atedge]-'a']=leaf;
					if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
				} else if(s[tostart+atlen]==s[i]) {
					++atlen;
					if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
					break;
				} else {
					int branch=addnode(tostart,tostart+atlen);
					nodes[tonode].start+=atlen;
					int leaf=addnode(i,slen);
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
	}
	int sa[MAXSTLEN],lcp[MAXSTLEN]; int nsa;
	int rmqjump[MAXSTLEN][MAXLGSTLEN+1];
	int lg[MAXSTLEN+1];
	void createsa() {
		nsa=0; dfscreatesa(root,0,-1);
		FOR(i,1,nsa) rmqjump[i][0]=lcp[i];
		for(int k=1;(1<<k)<=nsa;++k) REPE(i,nsa-(1<<k)) rmqjump[i][k]=min(rmqjump[i][k-1],rmqjump[i+(1<<(k-1))][k-1]);
		lg[1]=0; FORE(i,2,nsa) { lg[i]=lg[i-1]; while((2<<lg[i])<=i) ++lg[i]; }
		//FORE(i,1,nsa) printf("%d: %d\n",i,lg[i]); REP(i,nsa) { printf("%d:",i); for(int k=0;i+(1<<k)<=nsa;++k) printf(" %d",rmqjump[i][k]); puts(""); }
	}
	void dfscreatesa(int node,int depth,int clcp) {
		if(nodes[node].end==slen) { int idx=nodes[node].start-depth; lcp[nsa]=clcp; sa[idx]=nsa++; }
		for(int i=0;i<27;++i) if(nodes[node].childs[i]!=-1) { dfscreatesa(nodes[node].childs[i],depth+nodes[node].end-nodes[node].start,clcp); clcp=depth+nodes[node].end-nodes[node].start; }
	}
	int rmq(int a,int b) {
		//int ret=lcp[a]; FORE(i,a+1,b) if(lcp[i]<ret) ret=lcp[i]; return ret;
		int k=lg[b+1-a]; return min(rmqjump[a][k],rmqjump[b+1-(1<<k)][k]);
	}
	void dfsprint(int node,int depth) {
		for(int i=0;i<depth;++i) printf("  ");
		printf("'"); for(int i=nodes[node].start;i<nodes[node].end;++i) printf("%c",s[i]); printf("'");
		if(nodes[node].end!=slen) printf(" -> %d",node); if(nodes[node].suffix!=-1) printf(" [%d]",nodes[node].suffix); puts("");
		for(int i=0;i<27;++i) if(nodes[node].childs[i]!=-1) dfsprint(nodes[node].childs[i],depth+1);
	}
	void print() {
		printf("%s\n",s);
		dfsprint(root,0);
		REP(i,slen) printf("%d ",sa[i]); puts("");
		REP(i,slen) printf("%d ",lcp[i]); puts("");
	}
} SuffTree;
SuffTree st;

int n,nq;
vector<pair<int,int> > q[MAXN];
int ans[MAXQ];

int	dnoff[MAXN],upoff[MAXN];
void createstr() {
	st.slen=0;
	REP(id,t.nladders) {
		int len=t.ladderoff[id+1]-t.ladderoff[id];
		dnoff[id]=st.slen; REP(j,len-1) st.s[st.slen++]=t.cpar[t.laddernodes[t.ladderoff[id]+j+1]];
		upoff[id]=st.slen; REP(j,len-1) st.s[st.slen++]=t.cpar[t.laddernodes[t.ladderoff[id]+len-j-1]];
	}
	st.s[st.slen++]='{'; st.s[st.slen]='\0';
	st.build();
	st.createsa();
	//st.print();
}
void printpath(const vector<pair<int,int> > &path) { REPSZ(i,path) { if(i!=0) printf(" "); FOR(j,path[i].first,path[i].second) printf("%c",st.s[j]); } }
vector<pair<int,int> > pathstrs(int u,int v) {
	vector<T::LadderSeg> res=t.ladderpath(u,v); vector<pair<int,int> > ret;
	REPSZ(i,res) {
		int len=t.ladderoff[res[i].id+1]-t.ladderoff[res[i].id];
		if(res[i].s<res[i].t) ret.PB(MP(dnoff[res[i].id]+res[i].s,dnoff[res[i].id]+res[i].t));
		if(res[i].s>res[i].t) ret.PB(MP(upoff[res[i].id]+len-res[i].s-1,upoff[res[i].id]+len-res[i].t-1));
	}
	//printf("\t\tpathstrings(%d,%d): ",u,v); printpath(ret); puts("");
	return ret;
}
int scmp(int a,int b,int len) {
	//REP(i,len) if(st.s[a+i]!=st.s[b+i]) return st.s[a+i]<st.s[b+i]?-1:+1; return 0;
	a=st.sa[a],b=st.sa[b]; if(a==b) return 0; bool inv=false; if(a>b) swap(a,b),inv=true; if(st.rmq(a+1,b)>=len) return 0; return !inv?-1:+1;
}
int _pathcmp(const vector<pair<int,int> > &a,const vector<pair<int,int> > &b) {
	int ai=0,bi=0,aoff=0,boff=0;
	while(ai<SZ(a)&&bi<SZ(b)) {
		int alen=a[ai].second-a[ai].first-aoff,blen=b[bi].second-b[bi].first-boff,len=min(alen,blen);
		int cmp=scmp(a[ai].first+aoff,b[bi].first+boff,len); if(cmp!=0) return cmp;
		aoff+=len; if(a[ai].first+aoff>=a[ai].second) ++ai,aoff=0;
		boff+=len; if(b[bi].first+boff>=b[bi].second) ++bi,boff=0;
	}
	bool adone=ai>=SZ(a),bdone=bi>=SZ(b); if(adone!=bdone) return adone?-1:+1; return 0;
}
int pathcmp(const vector<pair<int,int> > &a,const vector<pair<int,int> > &b) { int ret=_pathcmp(a,b); /*printf("\t\t\tpathcmp("); printpath(a); printf(","); printpath(b); printf(")=%d\n",ret);*/ return ret; }

int ntrie;
int trienxt[MAXN][26];
int trienodehead[MAXN],trienodenxt[MAXN];
vector<pair<int,int> > triepaths[MAXN]; int ntriepaths; int triepathidx[MAXN];
int createtrienode() { int ret=ntrie++; REP(i,26) trienxt[ret][i]=-1; trienodehead[ret]=-1; return ret; }
void dfscreatetrie(int at,int par,int z) {
	trienodenxt[at]=trienodehead[z],trienodehead[z]=at;
	for(int x=g.ghead[at];x!=-1;x=g.gnxt[x]) { int to=g.gto[x]; if(to==par||g.wascentroid[to]) continue; char c=g.gc[x>>1]; if(trienxt[z][c-'a']==-1) trienxt[z][c-'a']=createtrienode(); dfscreatetrie(to,at,trienxt[z][c-'a']); }
}
void dfscreatetriepaths(int z,int c) {
	for(int x=trienodehead[z];x!=-1;x=trienodenxt[x]) triepathidx[x]=ntriepaths++,triepaths[triepathidx[x]]=pathstrs(c,x);
	REP(i,26) if(trienxt[z][i]!=-1) dfscreatetriepaths(trienxt[z][i],c);
}
int bit[MAXN+1];
void bitmod(int idx,int by) { ++idx; while(idx<=ntriepaths) { bit[idx]+=by; idx+=idx&-idx; } }
int bitget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
void dfsbitmod(int at,int par,int by) { bitmod(triepathidx[at],by); for(int x=g.ghead[at];x!=-1;x=g.gnxt[x]) { int to=g.gto[x]; if(to==par||g.wascentroid[to]) continue; dfsbitmod(to,at,by); } }
int calcpathsthroughcentroid(int c,int u,int v) {
	//printf("\tcalcpathsthroughcentroid(%d,%d,%d)\n",c,u,v);
	vector<pair<int,int> > qpath=pathstrs(u,v);
	vector<pair<int,int> > uppath=pathstrs(u,c);
	int uplen=0; REPSZ(i,uppath) uplen+=uppath[i].second-uppath[i].first;
	vector<pair<int,int> > qpath1,qpath2; int rem=uplen;
	REPSZ(i,qpath) { int curlen=qpath[i].second-qpath[i].first; if(rem>=curlen) { qpath1.PB(qpath[i]); rem-=curlen; } else if(rem>0) { qpath1.PB(MP(qpath[i].first,qpath[i].first+rem)); qpath2.PB(MP(qpath[i].first+rem,qpath[i].second)); rem=0; } else qpath2.PB(qpath[i]); }

	int cmp1=pathcmp(qpath1,uppath);
	if(cmp1>0) return bitget(ntriepaths-1); if(cmp1<0) return 0;
	//printf("\t\tremaining: "); printpath(qpath2); puts("");
	int l=-1,h=ntriepaths; while(l+1<h) { int m=l+(h-l)/2; if(pathcmp(triepaths[m],qpath2)<0) l=m; else h=m; }
	//printf("\t\t->idx=%d, cnt=%d\n",l,bitget(l));
	return bitget(l);
}
void dfscalcpathsthroughcentroid(int at,int par,int c) {
	REPSZ(i,q[at]) { int u=at,v=q[at][i].first,idx=q[at][i].second; ans[idx]+=calcpathsthroughcentroid(c,u,v); }
	for(int x=g.ghead[at];x!=-1;x=g.gnxt[x]) { int to=g.gto[x]; if(to==par||g.wascentroid[to]) continue; dfscalcpathsthroughcentroid(to,at,c); }
}
void calccentroid(int c) {
	//printf("centroid=%d\n",c);
	// create trie
	ntrie=0; int trieroot=createtrienode(); dfscreatetrie(c,-1,trieroot);
	// create ordered list of all pathstrs + let each node know its index in the list + create a bit (initially all ones)
	ntriepaths=0; dfscreatetriepaths(trieroot,c);
	memset(bit,0,sizeof(bit)); REP(i,ntriepaths) bitmod(i,+1);
	// process all queries at c
	REPSZ(i,q[c]) { int u=c,v=q[c][i].first,idx=q[c][i].second; ans[idx]+=calcpathsthroughcentroid(c,u,v); }
	// for each subtree: disable subtree in bit, process al queries in it through c, reenable subtree in bit
	for(int x=g.ghead[c];x!=-1;x=g.gnxt[x]) {
		int to=g.gto[x]; if(g.wascentroid[to]) continue;
		dfsbitmod(to,c,-1);
		dfscalcpathsthroughcentroid(to,c,c);
		dfsbitmod(to,c,+1);
	}
	//exit(0);
}



void run() {
	scanf("%d%d",&n,&nq);
	g.init(n);
	REP(i,n-1) { int a,b; char c; scanf("%d%d %c",&a,&b,&c); --a,--b; g.addedge(a,b,c); }
	REP(i,n) q[i].clear();
	REP(i,nq) {
		int u,v; scanf("%d%d",&u,&v); --u,--v;
		q[u].PB(MP(v,i));
	}

	//n=MAXN,nq=MAXQ; g.init(n); REP(i,n-1) { int a=rand()%(i+1),b=i+1; char c='a'+rand()%26; g.addedge(a,b,c); } REP(i,n) q[i].clear(); REP(i,nq) while(true) { int x=rand()%n,y=rand()%n; if(x==y) continue; q[x].PB(MP(y,i)); break; }

	t.init(g,0);
	t.calcladders();
	createstr();
	memset(ans,-1,sizeof(ans));
	g.decompose(0,calccentroid);
	REP(i,nq) printf("%d\n",ans[i]);
}

int main() {
	run();
	return 0;
}