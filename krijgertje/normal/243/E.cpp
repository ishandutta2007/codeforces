#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <cassert>
#include <iostream>
#include <string>
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


const int INVALID=-1;
const int UNMARKED=0;
const int MARKED=1;
const int PENDING=2; // has a black descendant, but not yet told to parent
const int QUEUED=3;
const int FULL=4;
const int PARTIAL=5;
const int TOP=6;
const int LEAFNODE=0;
const int PNODE=1;
const int QNODE=2;

struct PQTreeNode {
	// structural fields
	int kind;
	int parent; // not necessarily set for children of qnodes
	int extremechilds[2];
	int siblings[2];
	int othersibling(int x) { REP(k,2) if(siblings[k]==x) return siblings[1-k]; assert(false); return -1; }
	void replaceextremechild(int a,int b) { REP(k,2) if(extremechilds[k]==a) { extremechilds[k]=b; return; } assert(false); }
	void replacesibling(int a,int b) { REP(k,2) if(siblings[k]==a) { siblings[k]=b; return; } assert(false); }
	bool isextreme() { return siblings[0]==-1||siblings[1]==-1; }
	void init(int _kind) {
		kind=_kind; parent=-1; extremechilds[0]=extremechilds[1]=siblings[0]=siblings[1]=-1;
		state=UNMARKED,nmarkedchilds=0,nblackdescendants=0,fullhead=fullnxt=-1,fullcnt=0,partialhead=partialnxt=-1,partialcnt=0;
	}
	
	// fields used during processing
	int state,nmarkedchilds,nblackdescendants;
	int fullhead,fullnxt,fullcnt;
	int partialhead,partialnxt,partialcnt;
};
struct PQTree {

	// structural fields
	bool failed;
	vector<PQTreeNode> nodes;
	queue<int> pool;

	// fields used during processing
	vector<int> markednodes;
	queue<int> q;
	int virtualtop;

	int createnode(int kind) {
		int ret; if(!pool.empty()) { ret=pool.front(); pool.pop(); } else { ret=SZ(nodes); nodes.PB(PQTreeNode()); }
		nodes[ret].init(kind); return ret;
	}
	void releasenode(int at) {
		nodes[at].kind=INVALID; pool.push(at);
	}
	void fixparent(int at) {
		int par=nodes[at].parent;
		if(par!=-1&&nodes[par].kind==QNODE&&!nodes[at].isextreme()) nodes[at].parent=-1;
	}
	void removenode(int at) {
		if(at==-1) return;
		int par=nodes[at].parent;
		REP(k,2) { int to=nodes[at].siblings[k],oth=nodes[at].siblings[1-k]; if(to==-1) nodes[par].replaceextremechild(at,oth); else nodes[to].replacesibling(at,oth); }
		nodes[at].parent=nodes[at].siblings[0]=nodes[at].siblings[1]=-1;
	}
	void appendnode(int at,int par) {
		if(at==-1) return;
		int prv=nodes[par].extremechilds[1];
		nodes[at].parent=par,nodes[at].siblings[0]=prv,nodes[at].siblings[1]=-1;
		if(prv==-1) nodes[par].extremechilds[0]=at; else { nodes[prv].replacesibling(-1,at); fixparent(prv); }
		nodes[par].extremechilds[1]=at;
	}
	void appendall(int at,int par) {
		if(at==-1) return;
		int prv=nodes[par].extremechilds[1],fst=nodes[at].extremechilds[0],lst=nodes[at].extremechilds[1];
		nodes[fst].parent=par,nodes[fst].replacesibling(-1,prv),nodes[lst].parent=par;
		if(prv==-1) nodes[par].extremechilds[0]=fst; else { nodes[prv].replacesibling(-1,fst); fixparent(prv),fixparent(fst); }
		nodes[par].extremechilds[1]=lst;
		releasenode(at);
	}
	void replacenode(int at,int by) {
		int par=nodes[at].parent,prv=nodes[at].siblings[0],nxt=nodes[at].siblings[1];
		//printf("replacenode at=%d by=%d par=%d\n",at,by,par);
		nodes[by].parent=par,nodes[by].siblings[0]=prv,nodes[by].siblings[1]=nxt;
		if(prv==-1) { if(par!=-1) nodes[par].replaceextremechild(at,by); } else nodes[prv].replacesibling(at,by);
		if(nxt==-1) { if(par!=-1) nodes[par].replaceextremechild(at,by); } else nodes[nxt].replacesibling(at,by);
		nodes[at].parent=nodes[at].siblings[0]=nodes[at].siblings[1]=-1;
	}
	void expandnode(int at) {
		int par=nodes[at].parent,prv=nodes[at].siblings[0],nxt=nodes[at].siblings[1],fst=nodes[at].extremechilds[0],lst=nodes[at].extremechilds[1];
		nodes[fst].parent=nodes[lst].parent=par,nodes[fst].replacesibling(-1,prv),nodes[lst].replacesibling(-1,nxt);
		if(prv==-1) nodes[par].replaceextremechild(at,fst); else { nodes[prv].replacesibling(at,fst); fixparent(fst); }
		if(nxt==-1) nodes[par].replaceextremechild(at,lst); else { nodes[nxt].replacesibling(at,lst); fixparent(lst); }
		releasenode(at);
	}
	void reducenode(int &at) {
		if(nodes[at].extremechilds[0]==-1&&nodes[at].extremechilds[1]==-1) { releasenode(at); at=-1; return; }
		if(nodes[at].extremechilds[0]==nodes[at].extremechilds[1]) { int old=at; at=nodes[at].extremechilds[0]; nodes[at].parent=-1; releasenode(old); return; }
	}
	void reversenode(int at) {
		if(at==-1) return;
		swap(nodes[at].extremechilds[0],nodes[at].extremechilds[1]);
	}

	void setmarked(int at) { int par=nodes[at].parent; nodes[at].state=MARKED; if(par!=-1) ++nodes[par].nmarkedchilds; }
	bool mark(const vector<int> &ids) {
		//printf("mark: (qsz=%d)",SZ(q)); print();
		REPSZ(i,ids) { int at=ids[i]; assert(nodes[at].state==UNMARKED); nodes[at].state=QUEUED; markednodes.PB(at),q.push(at); }
		int npendingblocks=0; bool markedroot=false;
		while(SZ(q)+npendingblocks+(markedroot?1:0)>1) {
			if(q.empty()) return false;
			int at=q.front(),par=nodes[at].parent; q.pop(); assert(nodes[at].state==QUEUED);
			if(par==-1&&nodes[at].siblings[0]==-1&&nodes[at].siblings[1]==-1) { setmarked(at); assert(!markedroot); markedroot=true; continue; }
			if(par==-1) REP(k,2) { int to=nodes[at].siblings[k]; assert(to!=-1); if(nodes[to].state==MARKED) { par=nodes[at].parent=nodes[to].parent; break; } }
			if(par!=-1) {
				setmarked(at);
				if(nodes[par].state==UNMARKED) { nodes[par].state=QUEUED; markednodes.PB(par),q.push(par); }
				REP(k,2) {
					int prv=at,to=nodes[at].siblings[k]; if(to==-1||nodes[to].state!=PENDING) continue; --npendingblocks;
					while(to!=-1&&nodes[to].state==PENDING) { nodes[to].parent=par; setmarked(to); tie(prv,to)=MP(to,nodes[to].othersibling(prv)); }
				}
			} else {
				nodes[at].state=PENDING; ++npendingblocks;
				REP(k,2) { int to=nodes[at].siblings[k]; assert(to!=-1); if(nodes[to].state!=PENDING) continue; --npendingblocks; }
			}
		}
		while(!q.empty()) { int at=q.front(); q.pop(); nodes[at].state=MARKED; }
		if(npendingblocks==1) {
			int l=-1,r=-1,cnt=0; REPSZ(i,markednodes) { int at=markednodes[i]; if(nodes[at].state!=PENDING) continue; ++cnt; if(l==-1&&r==-1) l=r=at; } assert(l!=-1&&r!=-1);
			if(cnt>=2) {
				virtualtop=createnode(QNODE); markednodes.PB(virtualtop); nodes[virtualtop].state=MARKED; nodes[l].parent=virtualtop,setmarked(l); //printf("virtualtop=%d\n",virtualtop);
				{ int nl=nodes[l].siblings[0]; while(nl!=-1&&nodes[nl].state!=UNMARKED) tie(nl,l)=MP(nodes[nl].othersibling(l),nl),nodes[l].parent=virtualtop,setmarked(l); }
				{ int nr=nodes[r].siblings[1]; while(nr!=-1&&nodes[nr].state!=UNMARKED) tie(nr,r)=MP(nodes[nr].othersibling(r),nr),nodes[r].parent=virtualtop,setmarked(r); }
				nodes[l].parent=nodes[r].parent=virtualtop; nodes[virtualtop].extremechilds[0]=l,nodes[virtualtop].extremechilds[1]=r;
			}
		}
		return true;
	}

	bool reduce(const vector<int> &ids) {
		//printf("reducing:"); print();
		REPSZ(i,ids) { int at=ids[i]; ++nodes[at].nblackdescendants; q.push(at); }
		while(!q.empty()) {
			int at=q.front(),par=nodes[at].parent,curblackdescendants=nodes[at].nblackdescendants; q.pop();
			bool islast=curblackdescendants==SZ(ids);
			//printf("reducing %d (nblack=%d,fullcnt=%d,islast=%s)\n",at,curblackdescendants,nodes[at].fullcnt,islast?"yes":"no");
			if(nodes[at].partialcnt>=3||!islast&&nodes[at].partialcnt>=2) return false;
			bool allfull=at!=virtualtop; if(allfull) for(int x=nodes[at].extremechilds[0],y=-1;x!=-1;tie(x,y)=MP(nodes[x].othersibling(y),x)) if(nodes[x].state!=FULL) { allfull=false; break; }
			if(nodes[at].kind==LEAFNODE||allfull) {
				nodes[at].state=islast?TOP:FULL;
				for(int x=nodes[at].fullhead;x!=-1;x=nodes[x].fullnxt) fixparent(x);
			} else if(nodes[at].kind==PNODE) {
				int partial1=nodes[at].partialhead,partial2=partial1!=-1?nodes[partial1].partialnxt:-1;
				removenode(partial1); removenode(partial2); reversenode(partial2);
				int full=createnode(PNODE); markednodes.PB(full); for(int x=nodes[at].fullhead;x!=-1;x=nodes[x].fullnxt) { removenode(x); appendnode(x,full); } reducenode(full);
				//printf("here (full=%d):",full); print();
				int empty=at; at=createnode(QNODE); markednodes.PB(at); replacenode(empty,at);
				if(!islast) {
					reducenode(empty); appendnode(empty,at); appendall(partial1,at); appendnode(full,at);
					nodes[at].state=PARTIAL;
				} else {
					appendall(partial1,at); appendnode(full,at); appendall(partial2,at);
					if(nodes[empty].extremechilds[0]==-1&&nodes[empty].extremechilds[1]==-1) reducenode(empty); else { replacenode(at,empty); /*printf("x:"); print();*/ reducenode(at); /*printf("y:"); print();*/ appendnode(at,empty); /*printf("z:"); print();*/ }
					nodes[at].state=TOP;
				}
				//printf("after:"); print();
			} else if(nodes[at].kind==QNODE) {
				//printf("here:");
				int tmp=nodes[at].fullcnt>=1?nodes[at].fullhead:nodes[at].partialcnt>=1?nodes[at].partialhead:-1,l=tmp,r=tmp;
				{ int nl=nodes[l].siblings[0]; while(nl!=-1&&nodes[nl].state!=UNMARKED) tie(nl,l)=MP(nodes[nl].othersibling(l),nl); if(nodes[l].siblings[0]!=nl) reversenode(l); }
				{ int nr=nodes[r].siblings[1]; while(nr!=-1&&nodes[nr].state!=UNMARKED) tie(nr,r)=MP(nodes[nr].othersibling(r),nr); if(nodes[r].siblings[1]!=nr) reversenode(r); }
				if(at!=virtualtop&&nodes[nodes[at].extremechilds[0]].state==FULL&&nodes[nodes[at].extremechilds[1]].state==FULL) return false;
				//printf("l=%d r=%d fullcnt=%d partialcnt=%d\n",l,r,nodes[at].fullcnt,nodes[at].partialcnt);
				for(int x=nodes[at].fullhead;x!=-1;x=nodes[x].fullnxt) if(x!=l&&x!=r) fixparent(x);
				int partial1=nodes[at].partialhead,partial2=partial1!=-1?nodes[partial1].partialnxt:-1;
				//printf("partial1=%d partial2=%d\n",partial1,partial2);
				if(partial1!=-1&&partial1!=l&&partial1!=r||partial2!=-1&&partial2!=l&&partial2!=r) return false;
				if(!islast) {
					if(nodes[l].isextreme()&&nodes[l].state!=PARTIAL) { swap(l,r); if(nodes[l].state==PARTIAL) reversenode(l); }
					if(!nodes[r].isextreme()||l!=r&&nodes[r].state==PARTIAL) return false;
					if(r!=nodes[at].extremechilds[1]) reversenode(at);
					if(nodes[l].state==PARTIAL) expandnode(l); else fixparent(l);
					nodes[at].state=PARTIAL;
				} else {
					if(nodes[l].state==PARTIAL) expandnode(l); else fixparent(l);
					if(nodes[r].state==PARTIAL) reversenode(r),expandnode(r); else fixparent(r);
					nodes[at].state=TOP;
				}
				//printf("after:"); print();
			} else assert(false);
			if(par!=-1&&!islast) {
				if(nodes[at].state==FULL) { nodes[at].fullnxt=nodes[par].fullhead; nodes[par].fullhead=at; ++nodes[par].fullcnt; }
				if(nodes[at].state==PARTIAL) { nodes[at].partialnxt=nodes[par].partialhead; nodes[par].partialhead=at; ++nodes[par].partialcnt; }
				nodes[par].nblackdescendants+=curblackdescendants;
				--nodes[par].nmarkedchilds; if(nodes[par].nmarkedchilds==0) q.push(par); 
				//printf("par=%d nmarkedchilds=%d\n",par,nodes[par].nmarkedchilds);
			}
		}
		if(virtualtop!=-1) { for(int x=nodes[virtualtop].fullhead;x!=-1;x=nodes[x].fullnxt) fixparent(x); for(int x=nodes[virtualtop].partialhead;x!=-1;x=nodes[x].partialnxt) fixparent(x); }
		return true;
	}

	void cleanup() {
		REPSZ(i,markednodes) {
			int at=markednodes[i];
			nodes[at].state=UNMARKED; nodes[at].nmarkedchilds=0; nodes[at].nblackdescendants=0;
			nodes[at].fullhead=-1,nodes[at].fullnxt=-1,nodes[at].fullcnt=0,nodes[at].partialhead=-1,nodes[at].partialnxt=-1,nodes[at].partialcnt=0;
		}
		if(virtualtop!=-1) { releasenode(virtualtop); virtualtop=-1; }
		markednodes.clear(); q=queue<int>();
	}

	void print(int at) {
		if(nodes[at].kind==PNODE) printf("{"); else if(nodes[at].kind==QNODE) printf("["); else if(nodes[at].kind==LEAFNODE) printf("%c",'A'+at); else printf("?");
		for(int x=nodes[at].extremechilds[0],y=-1;x!=-1;tie(x,y)=MP(nodes[x].othersibling(y),x)) { if(y!=-1) printf(","); print(x); }
		if(nodes[at].kind==PNODE) printf("}"); else if(nodes[at].kind==QNODE) printf("]");
	}
	void print() {
		//REPSZ(at,nodes) if(nodes[at].kind!=INVALID) printf("%d: kind=%d parent=%d extremechilds=%d,%d siblings=%d,%d nblack=%d\n",at,nodes[at].kind,nodes[at].parent,nodes[at].extremechilds[0],nodes[at].extremechilds[1],nodes[at].siblings[0],nodes[at].siblings[1],nodes[at].nblackdescendants);
		REPSZ(at,nodes) if(nodes[at].kind!=INVALID&&nodes[at].parent==-1&&nodes[at].siblings[0]==-1&&nodes[at].siblings[1]==-1&&at!=virtualtop) { print(at); puts(""); }
	}

	void init(int n) {
		failed=false; pool=queue<int>(); nodes.clear();
		REP(i,n) createnode(LEAFNODE); int root=createnode(PNODE); REP(i,n) appendnode(i,root);
		markednodes.clear(); q=queue<int>(); virtualtop=-1;
	}
	bool update(const vector<int> &ids) {
		//printf("update:" ); REPSZ(i,ids) printf("%c",'A'+ids[i]); puts("");
		if(failed) return false;
		if(!mark(ids)) { failed=true; return false; }
		if(!reduce(ids)) { failed=true; return false; }
		cleanup();
		//printf("done:"); print();
		return true;
	}
	void buildfrontier(vector<int> &frontier,int at) { if(nodes[at].kind==LEAFNODE) frontier.PB(at); else for(int x=nodes[at].extremechilds[0],y=-1;x!=-1;tie(x,y)=MP(nodes[x].othersibling(y),x)) buildfrontier(frontier,x); }
	vector<int> frontier() {
		REPSZ(at,nodes) if(nodes[at].kind!=INVALID&&nodes[at].parent==-1&&nodes[at].siblings[0]==-1&&nodes[at].siblings[1]==-1&&at!=virtualtop) { vector<int> ret; buildfrontier(ret,at); return ret; }
		assert(false); return vector<int>();
	}
};

const int MAXN=500;

int n;
char g[MAXN][MAXN+1];

PQTree tree;
vector<int> ord;

bool solve() {
	tree.init(n);
	REP(x,n) {
		vector<int> cur; REP(y,n) if(g[x][y]=='1') cur.PB(y);
		if(!tree.update(cur)) return false;
	}
	ord=tree.frontier(); assert(SZ(ord)==n);
	return true;
}

void run() {
	scanf("%d",&n);
	REP(x,n) scanf("%s",g[x]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(x,n) { REP(y,n) printf("%c",g[x][ord[y]]); puts(""); }
}

int main() {
	run();
	return 0;
}