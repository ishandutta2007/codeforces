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
#include <chrono>
#include <random>
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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int STALPH = 26;

struct STNode {
	char *s; int len;
	int childs[STALPH];
	int suffix;
	STNode(char *s, int len) :s(s), len(len) { memset(childs, -1, sizeof(childs)); suffix = -1; }
};
struct SuffixTree {
	int root;
	vector<STNode> nodes;

	int addnode(char *s, int len) { nodes.PB(STNode(s, len)); return SZ(nodes) - 1; }
	vector<int> build(char *s) {
		nodes.clear(); root = addnode(NULL, 0);
		int n = strlen(s), atnode = root, atedge = 0, atlen = 0, pint = -1, pleaf = -1; // atedge+atlen==i
		REPE(i, n) {
			while (true) {
				int tonode = atedge == n ? -1 : nodes[atnode].childs[s[atedge] - 'a'];
				if (tonode != -1 && atlen >= nodes[tonode].len) {
					atedge += nodes[tonode].len;
					atlen -= nodes[tonode].len;
					atnode = tonode;
					continue;
				}
				if (tonode == -1) { // atlen should be 0, atedge should be i
					if (i != n) {
						int leaf = addnode(s + i, n - i);
						nodes[atnode].childs[nodes[leaf].s[0] - 'a'] = leaf;
						if (pleaf != -1) nodes[pleaf].suffix = leaf; pleaf = leaf;
					} else {
						if (pleaf != -1) nodes[pleaf].suffix = atnode; pleaf = -1;
					}
					if (pint != -1) nodes[pint].suffix = atnode; pint = -1;
				} else if (i == n || nodes[tonode].s[atlen] != s[i]) {
					int branch = addnode(nodes[tonode].s, atlen);
					nodes[tonode].s += atlen, nodes[tonode].len -= atlen;
					nodes[atnode].childs[nodes[branch].s[0] - 'a'] = branch;
					nodes[branch].childs[nodes[tonode].s[0] - 'a'] = tonode;
					if (i != n) {
						int leaf = addnode(s + i, n - i);
						nodes[branch].childs[nodes[leaf].s[0] - 'a'] = leaf;
						if (pleaf != -1) nodes[pleaf].suffix = leaf; pleaf = leaf;
					} else {
						if (pleaf != -1) nodes[pleaf].suffix = branch; pleaf = -1;
					}
					if (pint != -1) nodes[pint].suffix = branch; pint = branch;
				} else {
					if (pint != -1) assert(atlen == 0), nodes[pint].suffix = atnode; pint = -1;
					++atlen;
					break;
				}
				if (atnode == root) {
					atedge++;
					if (atlen == 0) { assert(pint == -1); break; } else --atlen;
				} else {
					atnode = nodes[atnode].suffix;
				}
			}
		}
		vector<int> ret(n+1,-1); for(int at=1,len=n;at!=-1;at=nodes[at].suffix,--len) ret[len]=at; return ret;
	}

	void print(int at, int depth = 0) {
		REP(i, depth) printf("  "); if (nodes[at].s == NULL) printf("<root>"); else printf("'%.*s'", nodes[at].len, nodes[at].s);
		printf(": id=%d",at); if(nodes[at].suffix!=-1) printf(" suffix=%d",nodes[at].suffix); puts("");
		REP(i, STALPH) if (nodes[at].childs[i] != -1) print(nodes[at].childs[i], depth + 1);
	}
};

struct TNode {
	vector<int> ch; int parlen;
	int sz,heavy,par,pathid,pathidx,rootlen;
};
struct Tree {
	int root;
	vector<TNode> nodes;
};

struct HLPath {
	vector<int> nodes;
};
struct HeavyLight {
	Tree *t;
	vector<int> prelst;
	vector<HLPath> paths;
	
	void dfspre(int at) {
		prelst.PB(at);
		REPSZ(i,t->nodes[at].ch) dfspre(t->nodes[at].ch[i]);
	}
	void build(Tree *_t) {
		t=_t; prelst.clear(); dfspre(t->root);
		for(int i=SZ(prelst)-1;i>=0;--i) {
			int at=prelst[i]; t->nodes[at].sz=1,t->nodes[at].heavy=-1,t->nodes[at].par=-1;
			REPSZ(j,t->nodes[at].ch) { int to=t->nodes[at].ch[j]; t->nodes[to].par=at; t->nodes[at].sz+=t->nodes[to].sz; if(t->nodes[at].heavy==-1||t->nodes[to].sz>t->nodes[t->nodes[at].heavy].sz) t->nodes[at].heavy=to; }
		}
		paths.clear();
		REPSZ(i,prelst) {
			int at=prelst[i]; t->nodes[at].rootlen=t->nodes[at].par==-1?0:t->nodes[t->nodes[at].par].rootlen+t->nodes[at].parlen;
			if(t->nodes[at].par!=-1&&t->nodes[t->nodes[at].par].heavy==at) continue;
			HLPath path; for(int x=at;x!=-1;x=t->nodes[x].heavy) t->nodes[x].pathid=SZ(paths),t->nodes[x].pathidx=SZ(path.nodes),path.nodes.PB(x); paths.PB(path);
		}
	}
	vector<pair<int,int>> decomposepathtoroot(int at) {
		vector<pair<int,int>> ret;
		while(at!=-1) { ret.PB(MP(t->nodes[at].pathid,t->nodes[at].pathidx)); at=t->nodes[paths[t->nodes[at].pathid].nodes[0]].par; }
		reverse(ret.begin(),ret.end()); return ret;
	}
	void print() {
		REPSZ(i,paths) { printf("path%d:",i); REPSZ(j,paths[i].nodes) printf(" %d",paths[i].nodes[j]); puts(""); }
	}
};



const int MAXLEN=200000;
const int MAXQ=200000;
const int MAXLG=20;
//const int MAXE=(MAXLEN+MAXQ)*MAXLG;
//const int MAXCURP=MAXLEN*MAXLG;
//const int MAXCURQ=MAXQ*MAXLG;

char s[MAXLEN+1]; int slen;
int nq;
int ql[MAXQ],qr[MAXQ]; ll qans[MAXQ];

SuffixTree sufftree;
vector<int> suffixids;
Tree t;
HeavyLight heavylight;

struct BIT {
	int n; pair<int,ll> all; vector<pair<int,ll>> bit;
	BIT() {} BIT(int _n) { n=_n; all=MP(0,0LL); bit=vector<pair<int,ll>>(n+1,MP(0,0LL)); }
	void mod(int idx,int a,ll b) { /*printf("\tmod(%d,%d,%lld)\n",idx,a,b);*/ all.first+=a; all.second+=b; ++idx; while(idx<=n) { bit[idx].first+=a; bit[idx].second+=b; idx+=idx&-idx; } }
	pair<int,ll> get(int idx) { pair<int,ll> ret=MP(0,0LL); ++idx; while(idx>0) { ret.first+=bit[idx].first; ret.second+=bit[idx].second; idx-=idx&-idx; } return ret; }
	void reset(int _n) { n=_n; all=MP(0,0LL); FORE(i,1,n) bit[i]=MP(0,0LL); }
};

struct P { int id,pathidx,len; P(int id,int pathidx,int len):id(id),pathidx(pathidx),len(len) {} P() {} };
struct Q { int id,pathidx,len; Q(int id,int pathidx,int len):id(id),pathidx(pathidx),len(len) {} Q() {} };
struct E { int kind,id,pathidx,key,val; E(int kind,int id,int pathidx,int key,int val):kind(kind),id(id),pathidx(pathidx),key(key),val(val) {}  E() {} };
bool operator<(const E &a,const E &b) { if(2*a.key+a.kind!=2*b.key+b.kind) return 2*a.key+a.kind<2*b.key+b.kind; return a.id<b.id; }

//P curp[MAXCURP]; int ncurp;
//Q curq[MAXCURQ]; int ncurq;
//E e[MAXE]; int ne;
BIT bit(2*MAXLEN);

vector<vector<P>> plst1;
vector<vector<P>> plst2;
vector<vector<Q>> qlst1;
vector<vector<Q>> qlst2;
vector<vector<Q>> qlst3;

void precalc() {
	auto tstart = std::chrono::system_clock::now();
	// for each path, its nodes sorted by id		(want:pathidx+id+len)
	// for each path, its nodes sorted by id+len	(want:pathidx+id+len)
	// for each path, its queries sorted by L		(want:pathidx+id+len)
	// for each path, its queries sorted by R		(want:pathidx+id+len)
	// for each path, its queries sorted by R-len	(want:pathidx+id+len)
	plst1=vector<vector<P>>(SZ(heavylight.paths));
	plst2=vector<vector<P>>(SZ(heavylight.paths)); vector<vector<pair<int,P>>> ptmp2(2*slen);
	REP(id,slen) {
		int at=suffixids[slen-id];
		while(at!=-1) {
			int pathid=t.nodes[at].pathid,pathidx=t.nodes[at].pathidx,len=t.nodes[at].rootlen;
			plst1[pathid].PB(P(id,pathidx,len));
			ptmp2[id+len].PB(MP(pathid,P(id,pathidx,len)));
			at=t.nodes[heavylight.paths[pathid].nodes[0]].par;
		}
	}
	REPSZ(i,ptmp2) REPSZ(j,ptmp2[i]) { auto cur=ptmp2[i][j]; plst2[cur.first].PB(cur.second); }
	fprintf(stderr,"\t%lld\n",(ll)((std::chrono::system_clock::now()-tstart).count()));
	qlst1=vector<vector<Q>>(SZ(heavylight.paths)); vector<vector<pair<int,Q>>> qtmp1(slen);
	qlst2=vector<vector<Q>>(SZ(heavylight.paths)); vector<vector<pair<int,Q>>> qtmp2(slen);
	qlst3=vector<vector<Q>>(SZ(heavylight.paths)); vector<vector<pair<int,Q>>> qtmp3(2*slen);
	REP(id,nq) {
		int at=suffixids[slen-ql[id]];
		while(at!=-1) {
			int pathid=t.nodes[at].pathid,pathidx=t.nodes[at].pathidx,len=t.nodes[at].rootlen,firstnode=heavylight.paths[pathid].nodes[0],h=t.nodes[firstnode].rootlen-t.nodes[firstnode].parlen;
			if(h<qr[id]-ql[id]+1) {
				{ int lo=0,hi=pathidx+1; while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(t.nodes[heavylight.paths[pathid].nodes[mi-1]].rootlen>=qr[id]-ql[id]+1) hi=mi; else lo=mi; } pathidx=lo; }
				len=min(t.nodes[heavylight.paths[pathid].nodes[pathidx]].rootlen,qr[id]-ql[id]+1);
				qtmp1[ql[id]].PB(MP(pathid,Q(id,pathidx,len)));
				qtmp2[qr[id]].PB(MP(pathid,Q(id,pathidx,len)));
				qtmp3[qr[id]-len+slen].PB(MP(pathid,Q(id,pathidx,len)));
			}
			at=t.nodes[firstnode].par;
		}
	}
	REPSZ(i,qtmp1) REPSZ(j,qtmp1[i]) { auto cur=qtmp1[i][j]; qlst1[cur.first].PB(cur.second); }
	REPSZ(i,qtmp2) REPSZ(j,qtmp2[i]) { auto cur=qtmp2[i][j]; qlst2[cur.first].PB(cur.second); }
	REPSZ(i,qtmp3) REPSZ(j,qtmp3[i]) { auto cur=qtmp3[i][j]; qlst3[cur.first].PB(cur.second); }
	fprintf(stderr,"\t%lld\n",(ll)((std::chrono::system_clock::now()-tstart).count()));
}



void solve() {
	// build suffix tree
	suffixids=sufftree.build(s);
	//sufftree.print(sufftree.root); printf("suffixids:"); REPSZ(i,suffixids) printf(" %d",suffixids[i]); puts("");
	
	// calculate heavy-light decomposition
	t.nodes.clear(); t.root=sufftree.root; REPSZ(i,sufftree.nodes) { TNode tnode; tnode.parlen=sufftree.nodes[i].len; REP(j,STALPH) if(sufftree.nodes[i].childs[j]!=-1) tnode.ch.PB(sufftree.nodes[i].childs[j]); t.nodes.PB(tnode); }
	heavylight.build(&t);
	//heavylight.print();
	
	precalc();
	
	REPSZ(pathid,heavylight.paths) {
		//sum of max(0,min(R-z+1-h,min(dep[px],dep[qx])-h)) for all L<=z<=R for all heavy paths
		int firstnode=heavylight.paths[pathid].nodes[0],h=t.nodes[firstnode].rootlen-t.nodes[firstnode].parlen,pathlen=SZ(heavylight.paths[pathid].nodes);
		vector<P> &cplst1=plst1[pathid]; vector<P> &cplst2=plst2[pathid]; vector<Q> &cqlst1=qlst1[pathid]; vector<Q> &cqlst2=qlst2[pathid]; vector<Q> &cqlst3=qlst3[pathid];
		// p.id<=R and dep[px]<dep[qx]: max(0,min(R-z+1-h,dep[px]-h))	-> p.pathidx< q.pathidx, B iff p.id+dep[px]<=R+1, otherwise A iff p.id<=R+1-h, p.id<=R implied
		// p.id<=R and dep[px]>=dep[qx]: max(0,min(R-z+1-h,dep[qx]-h))	-> p.pathidx>=q.pathidx, B iff p.id<=R+1-dep[qx], otherwise A iff p.id<=R+1-h, p.id<=R implied
		// p.id<=L-1 and dep[px]<dep[qx]: max(0,min(R-z+1-h,dep[px]-h))	-> p.pathidx< q.pathidx, always B
		// p.id<=L-1 and dep[px]>=dep[qx]: max(0,min(R-z+1-h,dep[qx]-h))-> p.pathidx>=q.pathidx, always B
		{ // p.id+h<=R+1		-> (R+1)-(z+h) everywhere
			int pidx=0;
			pair<int,ll> all=MP(0,0LL);
			REPSZ(qidx,cqlst2) {
				while(pidx<SZ(cplst1)&&cplst1[pidx].id+h<=qr[cqlst2[qidx].id]+1) all.first+=1,all.second-=cplst1[pidx].id+h,++pidx;
				qans[cqlst2[qidx].id]+=(ll)(qr[cqlst2[qidx].id]+1)*all.first+all.second;
			}
		}
		{ // p.id+dep[px]<=R+1	-> (dep[px]+z)-(R+1) on the left
			int pidx=0;
			bit.reset(pathlen);
			REPSZ(qidx,cqlst2) {
				while(pidx<SZ(cplst2)&&cplst2[pidx].id+cplst2[pidx].len<=qr[cqlst2[qidx].id]+1) bit.mod(cplst2[pidx].pathidx,+1,cplst2[pidx].id+cplst2[pidx].len),++pidx;
				pair<int,ll> pref=bit.get(cqlst2[qidx].pathidx-1),all=bit.all; qans[cqlst2[qidx].id]+=(ll)-(qr[cqlst2[qidx].id]+1)*pref.first+pref.second;
			}
		}
		{ // p.id<=R+1-dep[qx]	-> (z)-(R+1-dep[qx]) on the right
			int pidx=0;
			bit.reset(pathlen);
			REPSZ(qidx,cqlst3) {
				while(pidx<SZ(cplst1)&&cplst1[pidx].id<=qr[cqlst3[qidx].id]+1-cqlst3[qidx].len) bit.mod(cplst1[pidx].pathidx,+1,cplst1[pidx].id),++pidx;
				pair<int,ll> pref=bit.get(cqlst3[qidx].pathidx-1),all=bit.all; qans[cqlst3[qidx].id]+=(ll)-(qr[cqlst3[qidx].id]+1-cqlst3[qidx].len)*(all.first-pref.first)+(all.second-pref.second);
			}
		}
		{ // p.id<=L-1			-> dep[px]-h on the left and dep[qx]-h on the right	-> dep[qx]-h everywhere and dep[px]-dep[qx] on the left
			int pidx=0;
			bit.reset(pathlen);
			REPSZ(qidx,cqlst1) {
				while(pidx<SZ(cplst1)&&cplst1[pidx].id<=ql[cqlst1[qidx].id]-1) bit.mod(cplst1[pidx].pathidx,+1,cplst1[pidx].len),++pidx;
				pair<int,ll> pref=bit.get(cqlst1[qidx].pathidx-1),all=bit.all; qans[cqlst1[qidx].id]-=(ll)-(cqlst1[qidx].len)*pref.first+pref.second+(ll)(cqlst1[qidx].len-h)*all.first;
			}
		}
	}
}

void run() {
	scanf("%s",s); slen=strlen(s);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i];
	solve();
	REP(i,nq) printf("%lld\n",qans[i]);
}

void stress() {
	//std::mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
	std::mt19937 rng(231789);
	REP(rep,10) {
		slen=MAXLEN; REP(i,slen) s[i]='a'+rng()%2; s[slen]='\0';
		nq=MAXQ; REP(i,nq) { ql[i]=rng()%slen,qr[i]=rng()%slen; if(ql[i]>qr[i]) swap(ql[i],qr[i]); }
		auto tstart = std::chrono::system_clock::now();
		solve();
		ll chk=0; REP(i,nq) chk^=qans[i];
		auto tend = std::chrono::system_clock::now();
		auto duration = (ll)((tend-tstart).count());
		printf("duration: %lld (chk=%lld)\n",duration,chk);
	}
}

int main() {
	run();
	//stress();
	return 0;
}