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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

bool debug;

typedef struct LCT {
	typedef struct N {
		int p;
		int c[2];
		N() { p=c[0]=c[1]=-1; }
	} N;
	N nodes[1200010];

	bool isroot(int x) { return nodes[x].p==-1||nodes[nodes[x].p].c[0]!=x&&nodes[nodes[x].p].c[1]!=x; }

	int childindex(int x,int y) {
		assert(x!=-1&&y!=-1);
		if(nodes[x].c[0]==y&&nodes[y].p==x) return 0;
		if(nodes[x].c[1]==y&&nodes[y].p==x) return 1;
		assert(false); return -1;
	}

	void rotate(int x,int xi) {
		int y=nodes[x].c[xi];
		assert(x!=-1&&y!=-1); bool root=isroot(x);
		nodes[y].p=nodes[x].p; if(!root) nodes[nodes[y].p].c[childindex(nodes[y].p,x)]=y;
		nodes[x].c[xi]=nodes[y].c[1-xi]; if(nodes[x].c[xi]!=-1) nodes[nodes[x].c[xi]].p=x;
		nodes[y].c[1-xi]=x; nodes[x].p=y;
	}

	void splay(int x) {
		assert(x!=-1);
		while(!isroot(x)) {
			int y=nodes[x].p,yi=childindex(y,x);
			if(isroot(y)) { rotate(y,yi); continue; }
			int z=nodes[y].p,zi=childindex(z,y);
			if(yi==zi) { rotate(z,zi); rotate(y,yi); } else { rotate(y,yi); rotate(z,zi); }
		}
	}

	void expose(int x) {
		for(int y=x,z=-1;y!=-1;z=y,y=nodes[y].p) {
			splay(y);
			nodes[y].c[0]=z;
			z=y;
		}
		splay(x);
	}

	int disconnect(int x,int xi) {
		assert(x!=-1&&nodes[x].p==-1);
		int y=nodes[x].c[xi];
		if(y!=-1) {
			nodes[x].c[xi]=-1;
			nodes[y].p=-1;
		}
		return y;
	}

	void connect(int x,int xi,int y) {
		assert(x!=-1&&nodes[x].p==-1&&nodes[x].c[xi]==-1);
		if(y!=-1) {
			assert(nodes[y].p==-1);
			nodes[x].c[xi]=y;
			nodes[y].p=x;
		}
	}

	int getroot(int x) {
		expose(x);
		while(nodes[x].c[1]!=-1) x=nodes[x].c[1];
		splay(x);
		return x;
	}

	void rempar(int x) {
		//if(debug) printf("rempar(%d)\n",x);
		expose(x);
		disconnect(x,1);
	}

	void setpar(int x,int y) {
		//if(debug) printf("setpar(%d,%d)\n",x,y);
		expose(x); assert(nodes[x].c[1]==-1); nodes[x].p=y;
	}

	void printtree(int x) {
		printf("[");
		if(nodes[x].c[0]!=-1) printtree(nodes[x].c[0]); else printf("-");
		printf("%d",x);
		if(nodes[x].c[1]!=-1) printtree(nodes[x].c[1]); else printf("-");
		printf("]");
	}
	void print() {
		REP(i,18) printf("%d: par=%d, left=%d, right=%d\n",i,nodes[i].p,nodes[i].c[0],nodes[i].c[1]);
	}
} LCT;
LCT lct;

typedef struct IN {
	int h,w,nq;
	char g[100000][10];
	char type[100000]; int x[100000],y[100000]; char z[100000];
	void read() {
		scanf("%d%d%d",&h,&w,&nq);
		REP(i,h) REP(j,w) scanf(" %c",&g[i][j]);
		REP(qi,nq) { scanf(" %c%d%d",&type[qi],&x[qi],&y[qi]); --x[qi],--y[qi]; if(type[qi]=='C') scanf(" %c",&z[qi]); }
	}
	void gen() {
		int seed=1417298426; printf("%d\n",seed); srand(seed);
		h=99422,w=10,nq=99289; char pos[3]={'<','>','^'};
		REP(i,h) REP(j,w) g[i][j]=pos[rand()%3];
		REP(i,nq) { type[i]=rand()%2==0?'A':'C'; x[i]=rand()%h; y[i]=rand()%w; z[i]=pos[rand()%3]; }
		//REP(i,h) { REP(j,3) printf("%c",g[i][j]); puts(""); }
		//REP(qi,min(nq,10)) printf("%c %d %d %c\n",type[qi],x[qi],y[qi],type[qi]=='C'?'-':z[qi]);
	}
} IN;
IN in;

typedef struct S {
	char g[100000][10];
	int x[1200010],y[1200010];
	int id[100001][12],nid;
	void init() {
		REP(i,in.h) REP(j,in.w) g[i][j]=in.g[i][j];
		memset(id,-1,sizeof(id));
		nid=0; FOR(i,-1,in.h) FOR(j,-1,in.w+1) {
			if(i==-1&&(j==-1||j==in.w)) continue;
			id[i+1][j+1]=nid; x[nid]=i; y[nid]=j; ++nid;
		}
	}
	int getid(int x,int y) { return id[x+1][y+1]; }
	void print() { REP(i,in.h) { REP(j,in.w) printf("%c",g[i][j]); puts(""); } }
} S;
S s;

void run() {
	in.read();
	//in.gen();
	s.init();
	//printf("%d\n",s.nid);
	REP(x,in.h) REP(y,in.w) {
		int id=s.getid(x,y),lid=s.getid(x,y-1),rid=s.getid(x,y+1),uid=s.getid(x-1,y);
		if(s.g[x][y]=='<'&&!(y-1>=0&&s.g[x][y-1]=='>')) lct.setpar(id,lid);
		if(s.g[x][y]=='>'&&!(y+1<in.w&&s.g[x][y+1]=='<')) lct.setpar(id,rid);
		if(s.g[x][y]=='^') lct.setpar(id,uid);
	}

	REP(qi,in.nq) {
		//printf("qi=%d %c %d %d %c\n",qi,in.type[qi],in.x[qi],in.y[qi],in.type[qi]!='C'?'-':in.z[qi]);
		//if(debug) { s.print(); lct.print(); }
		//lct.print();
		//REP(i,s.nid) { lct.expose(i); printf("%d: ",i); lct.printtree(i); puts(""); }

		int x=in.x[qi],y=in.y[qi],id=s.getid(x,y),lid=s.getid(x,y-1),rid=s.getid(x,y+1),uid=s.getid(x-1,y);
		if(in.type[qi]=='C') {
			lct.rempar(id);
			if(s.g[x][y]=='<'&&y-1>=0&&s.g[x][y-1]=='>') lct.setpar(lid,id);
			if(s.g[x][y]=='>'&&y+1<in.w&&s.g[x][y+1]=='<') lct.setpar(rid,id);
			s.g[x][y]=in.z[qi];
			if(s.g[x][y]=='<') { if(y-1>=0&&s.g[x][y-1]=='>') lct.rempar(lid); else lct.setpar(id,lid); }
			if(s.g[x][y]=='>') { if(y+1<in.w&&s.g[x][y+1]=='<') lct.rempar(rid); else lct.setpar(id,rid); }
			if(s.g[x][y]=='^') lct.setpar(id,uid);
		} else {
			int tid=lct.getroot(id);
			int tx=s.x[tid],ty=s.y[tid];
			//printf("\t%d %d %d\n",tid,tx,ty);
			if(0<=tx&&tx<in.h&&0<=ty&&ty<in.w) tx=ty=-1; else ++tx,++ty;
			printf("%d %d\n",tx,ty);
		}
	}

}

int main() {
	run();
	return 0;
}