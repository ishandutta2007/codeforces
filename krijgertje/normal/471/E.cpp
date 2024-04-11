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

int pcnt[100];

typedef struct IN {
	int n;
	int x1[200000],y1[200000],x2[200000],y2[200000];
	void read() {
		scanf("%d",&n);
		REP(i,n) scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	void gen() {
		int each=100000; n=2*each;
		REP(i,each) x1[i]=x2[i]=i,y1[i]=rand()%each,y2[i]=y1[i]+1+rand()%each;
		REP(i,each) x1[each+i]=rand()%each,x2[each+i]=x1[each+i]+1+rand()%each,y1[each+i]=y2[each+i]=i;
	}
	void print() {
		printf("%d\n",n);
		REP(i,n) printf("%d %d %d %d\n",x1[i],y1[i],x2[i],y2[i]);
	}
} IN;
IN in;

typedef struct UF {
	int par[200000];
	int rnk[200000];
	ll len[200000];

	int q[200000],nq;

	void create(int a,int nlen) {
		par[a]=a; rnk[a]=0; len[a]=nlen; 
	}
	int find(int a) {
		//if(debug) printf("find(%d): %d/%lld\n",a,par[a],len[a]);
		nq=0;
		while(par[a]!=a) {
			q[nq++]=a;
			a=par[a];
		}
		REP(i,nq) par[q[i]]=a;
		return a;
	}
	void unite(int a,int b) {
		++pcnt[1];
		a=find(a); b=find(b);
		if(a==b) { 
			//printf("decreasing\n");
			--len[a]; return;
		}
		if(rnk[a]<rnk[b]) swap(a,b);
		par[b]=a; len[a]+=len[b];
	}
	void reduce(int a,int by) {
		if(by==0) return;
		//printf("reducing by %d\n",by);
		++pcnt[2];
		a=find(a); len[a]-=by;
	}
} UF;
UF uf;

typedef struct Y {
	int val,cnt;
	int p; int c[2];
} Y;

typedef struct YT {
	Y y[200000]; int ny;
	void init() { ny=0; }
	void calc(int a) {
		y[a].cnt=1+(y[a].c[0]!=-1?y[y[a].c[0]].cnt:0)+(y[a].c[1]!=-1?y[y[a].c[1]].cnt:0);
	}
	int childindex(int a,int b) {
		assert(a!=-1);
		assert(b!=-1);
		if(y[a].c[0]==b) return 0;
		if(y[a].c[1]==b) return 1;
		assert(false);
		return -1;
	}
	void rotate(int a,int ai) {
		++pcnt[3];
		int b=y[a].c[ai];
		assert(a!=-1);
		assert(b!=-1);
		y[b].p=y[a].p; if(y[b].p!=-1) { y[y[b].p].c[childindex(y[b].p,a)]=b; }
		y[a].c[ai]=y[b].c[1-ai]; if(y[a].c[ai]!=-1) y[y[a].c[ai]].p=a;
		y[b].c[1-ai]=a; y[a].p=b;
		calc(a); calc(b);
	}
	int splay(int a) {
		++pcnt[4];
		assert(a!=-1);
		while(y[a].p!=-1) {
			++pcnt[5];
			int b=y[a].p,bi=childindex(b,a);
			if(y[b].p==-1) { rotate(b,bi); continue; }
			int c=y[b].p,ci=childindex(c,b);
			if(bi==ci) { rotate(c,ci); rotate(b,bi); }
			else { rotate(b,bi); rotate(c,ci); }
		}
		return a;
	}
	int connect(int lyid,int ryid) {
		if(ryid==-1) return lyid;
		if(lyid==-1) return ryid;
		lyid=getlast(lyid); ryid=splay(ryid);
		y[lyid].c[1]=ryid; y[ryid].p=lyid; calc(lyid);
		return lyid;
	}
	int connect(int lyid,int myid,int ryid) {
		return connect(connect(lyid,myid),ryid);
	}
	void disconnect(int lyid,int &ryid) {
		lyid=splay(lyid);
		ryid=y[lyid].c[1];
		if(ryid!=-1) {
			y[lyid].c[1]=y[ryid].p=-1;
			calc(lyid);
		}
	}
	void split(int yid,int &lyid,int &hyid,int val) {
		if(yid==-1) { lyid=hyid=-1; return; }
		yid=splay(yid);
		lyid=-1; int pyid=yid;
		for(int cyid=yid;cyid!=-1;) {
			++pcnt[15]; pyid=cyid;
			if(y[cyid].val<val) {
				lyid=cyid;
				cyid=y[cyid].c[1];
			} else {
				cyid=y[cyid].c[0];
			}
		}
		if(pyid!=-1) yid=splay(pyid);
		if(lyid!=-1) disconnect(lyid,hyid); else hyid=yid;
	}

	void split(int yid,int &lyid,int &myid,int &hyid,int val) {
		split(yid,lyid,yid,val);
		split(yid,myid,hyid,val+1);
	}
	int removerange(int &yid,int lval,int hval) {
		int lyid,hyid,ryid=yid;
		split(ryid,lyid,ryid,lval);
		split(ryid,ryid,hyid,hval+1);
		yid=connect(lyid,hyid);
		return ryid;
	}
	int getfirst(int yid) {
		assert(yid!=-1);
		yid=splay(yid);
		while(y[yid].c[0]!=-1) {
			++pcnt[6];
			yid=y[yid].c[0];
		}
		return splay(yid);
	}
	int getlast(int yid) {
		assert(yid!=-1);
		yid=splay(yid);
		while(y[yid].c[1]!=-1) {
			++pcnt[7];
			yid=y[yid].c[1];
		}
		return splay(yid);
	}
	bool check(int yid,int &py) {
		if(y[yid].c[0]!=-1&&!check(y[yid].c[0],py)) return false;
		if(y[yid].val<=py) { printf("yerror: not strictly increasing at %d (prev=%d mine=%d)\n",yid,py,y[yid].val); return false; }
		if(y[yid].c[1]!=-1&&!check(y[yid].c[1],py)) return false;
		return true;
	}
	void print(int yid) {
		if(yid==-1) { printf("-"); return; }
		printf("["); print(y[yid].c[0]); printf("%d",y[yid].val); print(y[yid].c[1]); printf("]"); 
	}
} YT;
YT yt;

typedef struct B {
	int ly,hy,yid,ufid;
	int p; int c[2];
} B;

typedef struct BT {
	B b[200000]; int nb;
	int bid;
	void init() { nb=0; bid=-1; }
	int childindex(int x,int y) {
		assert(x!=-1);
		assert(y!=-1);
		if(b[x].c[0]==y) return 0;
		if(b[x].c[1]==y) return 1;
		assert(false);
		return -1;
	}
	void rotate(int x,int xi) {
			++pcnt[8];
		int y=b[x].c[xi];
		assert(x!=-1);
		assert(y!=-1);
		b[y].p=b[x].p; if(b[y].p!=-1) { b[b[y].p].c[childindex(b[y].p,x)]=y; }
		b[x].c[xi]=b[y].c[1-xi]; if(b[x].c[xi]!=-1) b[b[x].c[xi]].p=x;
		b[y].c[1-xi]=x; b[x].p=y;
	}
	int splay(int x) {
			++pcnt[9];
		assert(x!=-1);
		while(b[x].p!=-1) {
			++pcnt[10];
			int y=b[x].p,yi=childindex(y,x);
			if(b[y].p==-1) { rotate(y,yi); continue; }
			int z=b[y].p,zi=childindex(z,y);
			if(yi==zi) { rotate(z,zi); rotate(y,yi); }
			else { rotate(y,yi); rotate(z,zi); }
		}
		return x;
	}
	void disconnect(int lbid,int &rbid) {
		lbid=splay(lbid);
		rbid=b[lbid].c[1];
		if(rbid!=-1) b[lbid].c[1]=b[rbid].p=-1;
	}
	int connect(int lbid,int rbid) {
		if(rbid==-1) return lbid;
		if(lbid==-1) return rbid;
		lbid=getlast(lbid); rbid=splay(rbid);
		b[lbid].c[1]=rbid; b[rbid].p=lbid; return lbid;
	}
	void splitly(int bid,int &lbid,int &hbid,int val) {
		if(bid==-1) { lbid=hbid=-1; return; }
		bid=splay(bid);
		lbid=-1; int pbid=bid;
		for(int cbid=bid;cbid!=-1;) {
			++pcnt[16]; pbid=cbid;
			if(b[cbid].ly<val) {
				lbid=cbid;
				cbid=b[cbid].c[1];
			} else {
				cbid=b[cbid].c[0];
			}
		}
		if(pbid!=-1) bid=splay(pbid);
		if(lbid!=-1) disconnect(lbid,hbid); else hbid=bid;
	}
	void splithy(int bid,int &lbid,int &hbid,int val) {
		if(bid==-1) { lbid=hbid=-1; return; }
		bid=splay(bid);
		lbid=-1; int pbid=bid;
		for(int cbid=bid;cbid!=-1;) {
			++pcnt[17]; pbid=cbid;
			if(b[cbid].hy<val) {
				lbid=cbid;
				cbid=b[cbid].c[1];
			} else {
				cbid=b[cbid].c[0];
			}
		}
		if(pbid!=-1) bid=splay(pbid);
		if(lbid!=-1) disconnect(lbid,hbid); else hbid=bid;
	}


	int removerange(int ly,int hy) {
		int lbid,hbid,rbid=bid;
		splithy(rbid,lbid,rbid,ly); // all b with b.hy < ly
		splitly(rbid,rbid,hbid,hy+1); // all b with b.ly <= hy
		bid=connect(lbid,hbid);
		return rbid;
	}
	void insert(int nbid) {
		//printf("inserting %d\n",nbid);
		//printroot();
		int lbid,hbid;
		splitly(bid,lbid,hbid,b[nbid].ly);
		//printf("%d %d\n",lbid,hbid);
		bid=connect(connect(lbid,nbid),hbid);
		//printf("->\n");
		//printroot();
	}
	int getfirst(int bid) {
		assert(bid!=-1);
		bid=splay(bid);
		while(b[bid].c[0]!=-1) {
			++pcnt[11];
			bid=b[bid].c[0];
		}
		return splay(bid);
	}
	int getlast(int bid) {
		assert(bid!=-1);
		bid=splay(bid);
		while(b[bid].c[1]!=-1) {
			++pcnt[12];
			bid=b[bid].c[1];
		}
		return splay(bid);
	}
	bool checkroot() {
		if(bid==-1) return true;
		bid=splay(bid);
		int py=INT_MIN; return check(bid,py);
	}
	bool check(int bid,int &py) {
		if(b[bid].c[0]!=-1&&!check(b[bid].c[0],py)) return false;
		if(b[bid].ly<=py) { printf("error: ranges overlap. bid=%d, ly=%d, py=%d\n",bid,b[bid].ly,py); return false; }
		py=b[bid].hy;
		int npy=INT_MIN; if(!yt.check(yt.splay(b[bid].yid),npy)) return false;
		int ly=yt.y[yt.getfirst(b[bid].yid)].val,hy=yt.y[yt.getlast(b[bid].yid)].val;
		if(b[bid].ly!=ly) { printf("error: minimum not same at bid=%d (have %d want %d)\n",bid,b[bid].ly,ly); return false; }
		if(b[bid].hy!=hy) { printf("error: maximum not same at bid=%d (have %d want %d)\n",bid,b[bid].hy,hy); return false; }
		if(b[bid].c[1]!=-1&&!check(b[bid].c[1],py)) return false;
		return true;
	}
	void printroot() {
		if(bid==-1) { printf("empty\n"); return; }
		bid=splay(bid);
		print(bid,0);
	}
	void print(int bid,int d) {
		if(bid==-1) return;
		print(b[bid].c[0],d+1);
		REP(i,d) printf("  "); printf("%d: [%d..%d] cnt=%d uf=%d ",bid,b[bid].ly,b[bid].hy,yt.y[yt.splay(b[bid].yid)].cnt,b[bid].ufid); yt.print(b[bid].yid); puts("");
		print(b[bid].c[1],d+1);
	}
} BT;
BT bt;

typedef struct E {
	int type; // 0=shor,1=vrt,2=thor
	int id;
} E;
bool operator<(const E &a,const E &b) {
	int ax=a.type==1?in.x1[a.id]:a.type==0?in.x1[a.id]:in.x2[a.id];
	int bx=b.type==1?in.x1[b.id]:b.type==0?in.x1[b.id]:in.x2[b.id];
	if(ax!=bx) return ax<bx;
	if(a.type!=b.type) return a.type<b.type;
	return in.y1[a.id]<in.y1[b.id];
}

typedef struct ELST {
	E e[400000]; int ne;
	void init() {
		ne=0;
		REP(i,in.n) if(in.x1[i]==in.x2[i]) {
			e[ne].type=1; e[ne].id=i; ++ne;
		} else if(in.y1[i]==in.y2[i]) {
			e[ne].type=0; e[ne].id=i; ++ne;
			e[ne].type=2; e[ne].id=i; ++ne;
		} else {
			assert(false);
		}
		sort(e,e+ne);
	}
	void process() {
		REP(i,in.n) uf.create(i,in.x2[i]-in.x1[i]+in.y2[i]-in.y1[i]);
		REP(ei,ne) {
			++pcnt[13];
			int id=e[ei].id;
			//if(!bt.checkroot()) { bt.printroot(); exit(0); }
			//bt.printroot();
			//printf("processing %d (type=%d)\n",id,e[ei].type);
			if(e[ei].type==0) {
				// create a new block
				// insert block into BT (possibly splitting existing block)
				int yid=yt.ny++;
				Y &y=yt.y[yid];
				y.p=-1,y.c[0]=-1,y.c[1]=-1,y.val=in.y1[id],y.cnt=1;
				int bid=bt.nb++;
				B &b=bt.b[bid];
				b.p=-1,b.c[0]=-1,b.c[1]=-1,b.ly=y.val,b.hy=y.val,b.ufid=id,b.yid=yid;
				int obid=bt.removerange(y.val,y.val);
				if(obid==-1) {
					bt.insert(bid);
				} else {
					B &ob=bt.b[obid];
					assert(ob.p==-1&&ob.c[0]==-1&&ob.c[1]==-1);
					int loyid,moyid,hoyid;
					yt.split(ob.yid,loyid,moyid,hoyid,y.val);
					assert(loyid!=-1&&moyid==-1&&hoyid!=-1);
					int nbid=bt.nb++;
					B &nb=bt.b[nbid];
					nb.p=-1,nb.c[0]=-1,nb.c[1]=-1,nb.ly=yt.y[yt.getfirst(hoyid)].val,nb.hy=ob.hy,nb.ufid=ob.ufid,nb.yid=hoyid;
					ob.hy=yt.y[yt.getlast(loyid)].val,ob.yid=loyid;
					bt.insert(obid); bt.insert(bid); bt.insert(nbid);
				}
			} else if(e[ei].type==2) {
				// find block
				// remove from block
				// if block is empty, remove from BT
				int bid=bt.removerange(in.y1[id],in.y2[id]);
				assert(bid!=-1);
				B &b=bt.b[bid];
				assert(b.p==-1&&b.c[0]==-1&&b.c[1]==-1);
				int yid=yt.removerange(b.yid,in.y1[id],in.y2[id]);
				//printf("remove yid(%d,%d,%d) [%d]: ",b.yid,in.y1[id],in.y2[id],b.yid); yt.print(yid); printf("\n");
				assert(yid!=-1);
				Y &y=yt.y[yid];
				assert(y.p==-1&&y.c[0]==-1&&y.c[1]==-1);
				if(b.yid!=-1) {
					b.ly=yt.y[yt.getfirst(b.yid)].val;
					b.hy=yt.y[yt.getlast(b.yid)].val;
					bt.insert(bid);
				}
			} else if(e[ei].type==1) {
				// find blocks and merge them:
				// o merge B
				// o merge YT
				// o remove one from BT
				// o merge in UF
				int bid=bt.removerange(in.y1[id],in.y2[id]);
				//printf("removed:\n"); bt.print(bt.splay(bid),0);
				//printf("remaining:\n"); bt.printroot();
				if(bid==-1) continue;
				bid=bt.getfirst(bid);
				if(reduceinblock(bid,in.y1[id],in.y2[id]))
					uf.unite(id,bt.b[bid].ufid);
				//printf("united\n");
				while(true) {
					++pcnt[14];
					//printf("first=%d\n",bid);
					B &b=bt.b[bid];
					int nbid=b.c[1];
					if(nbid==-1) break;
					while(bt.b[nbid].c[0]!=-1) nbid=bt.b[nbid].c[0];
					nbid=bt.splay(nbid);
					assert(bt.b[nbid].c[0]==bid&&bt.b[bid].c[0]==-1&&bt.b[bid].c[1]==-1);
					reduceinblock(nbid,in.y1[id],in.y2[id]);
					B &nb=bt.b[nbid];
					nb.c[0]=b.p=-1;
					//printf("merging %d and %d\n",bid,nbid);
					nb.ly=b.ly; 
					int yid=yt.splay(b.yid),nyid=yt.getfirst(nb.yid);
					Y &ny=yt.y[nyid];
					Y &y=yt.y[yid];
					ny.c[0]=yid; y.p=nyid; yt.calc(nyid);
					int ufid=b.ufid,nufid=nb.ufid;
					uf.unite(ufid,nufid);
					bid=nbid;
				}
				bt.insert(bid);
			}
		}
	}

	bool reduceinblock(int bid,int y1,int y2) {
		B &b=bt.b[bid];
		int lyid,hyid,ryid=b.yid;
		yt.split(ryid,lyid,ryid,y1);
		yt.split(ryid,ryid,hyid,y2+1);
		/*printf("bid=%d\n",bid);
		printf("l: "); if(lyid==-1) printf("-"); else yt.print(yt.splay(lyid)); puts("");
		printf("m: "); if(ryid==-1) printf("-"); else yt.print(yt.splay(ryid)); puts("");
		printf("h: "); if(hyid==-1) printf("-"); else yt.print(yt.splay(hyid)); puts(""); */
		if(ryid!=-1) {
			int cnt=yt.y[yt.splay(ryid)].cnt;
			uf.reduce(b.ufid,cnt-1);
		}
		b.yid=yt.connect(lyid,ryid,hyid);
		return ryid!=-1;
	}
} ELST;
ELST elst;

void run() {
	yt.init(); bt.init(); elst.init();
	elst.process();
	ll ret=0;
	REP(i,in.n) {
		if(uf.find(i)==i) {
			ll cur=uf.len[i];
			if(cur>ret) ret=cur;
		}
	}
	cout<<ret<<endl;
/*	REP(i,18) fprintf(stderr,"p%d: %d\n",i,pcnt[i]);
	fprintf(stderr,"n: %d\n",in.n);
	fprintf(stderr,"ny: %d\n",yt.ny);
	fprintf(stderr,"nb: %d\n",bt.nb);
	fprintf(stderr,"ne: %d\n",elst.ne); */
}

int main() {
	in.read(); run(); return 0;
}