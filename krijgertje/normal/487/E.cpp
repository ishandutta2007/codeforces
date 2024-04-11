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

typedef struct G {
	int n,m;
	int w[100000];
	int fst[100000];
	int nxt[200000];
	int to[200000];

	int stck[100000],nstck;
	int vis[100000],nvis;
	bool been[100000];
	int d[100000],mind[100000];
	int cur[100000];
	int par[100000];
	int comp[100000],ncomp;
	int cfst[100000],cnxt[100000];


	void tarjan() {
		nstck=nvis=ncomp=0;
		REP(i,n) been[i]=false;
		REP(i,n) par[i]=-1;
		REP(i,m) comp[i]=-1;
		stck[nstck++]=0; d[0]=0; par[0]=-2;
		while(nstck>0) {
			int at=stck[--nstck];
			if(!been[at]) {
				been[at]=true;
				cur[at]=fst[at];
				mind[at]=d[at];
			} else {
				int nat=to[cur[at]];
				if(mind[nat]>=d[at]) {
					//printf("Comp %d:",ncomp);
					cfst[ncomp]=-1;
					while(true) { 
						int now=vis[--nvis]; comp[now/2]=ncomp;
						cnxt[now/2]=cfst[ncomp]; cfst[ncomp]=now/2;
						//printf(" (%d-%d)",to[now],to[now^1]);
						if(now==cur[at]) break; 
					}
					//puts("");
					++ncomp;
				}
				if(mind[nat]<mind[at]) mind[at]=mind[nat];
				cur[at]=nxt[cur[at]];
			}
			while(cur[at]!=-1) {
				int nat=to[cur[at]];
				//printf("\tprocessing %d->%d\n",at,nat);
				if(been[nat]) {
					if(par[at]!=nat&&d[nat]<d[at]) {
						vis[nvis++]=cur[at]; //printf("\t\tbackedge\n");
						if(d[nat]<mind[at]) mind[at]=d[nat];
					}
					cur[at]=nxt[cur[at]];
				} else {
					stck[nstck++]=at;
					stck[nstck++]=nat;
					vis[nvis++]=cur[at]; //printf("\t\tdfsedge\n");
					par[nat]=at;
					d[nat]=d[at]+1;
					break;
				}
			}
		}
	}
} G;
G g;

typedef struct T {
	int onlycomp[100000];
	int lastcomp[100000];

	int n,m;
	int cutid[100000];
	int fst[200000];
	int nxt[400000];
	int to[400000];

	void create() {
		REP(i,g.n) {
			onlycomp[i]=-1;
			for(int x=g.fst[i];x!=-1;x=g.nxt[x]) {
				int now=g.comp[x/2];
				if(onlycomp[i]==-1) onlycomp[i]=now; else if(onlycomp[i]!=now) onlycomp[i]=-2;
			}
		}
		n=g.ncomp,m=0;
		REP(i,g.n) if(onlycomp[i]!=-2) cutid[i]=-1; else cutid[i]=n++;
		REP(i,g.n) lastcomp[i]=-1;
		REP(i,n) fst[i]=-1;
		REP(i,g.ncomp) for(int x=g.cfst[i];x!=-1;x=g.cnxt[x]) REP(j,2) {
			int at=g.to[2*x+j];
			if(cutid[at]==-1||lastcomp[at]==i) continue;
			lastcomp[at]=i;
			nxt[2*m+0]=fst[i]; fst[i]=2*m+0; to[2*m+0]=cutid[at];
			nxt[2*m+1]=fst[cutid[at]]; fst[cutid[at]]=2*m+1; to[2*m+1]=i;
			++m;
		}
	}

	int par[200000];
	int d[200000];
	int q[200000],qhead,qtail;
	int sz[200000];
	int heavy[200000];

	int id[200000],nid;
	int off[200000];
	int start[200000];
	int cnt[200000];
	int at[200000];

	int val[200000];
	int sval[1<<19];

	void init() {
		REP(i,n) par[i]=-1;
		qhead=qtail=0; q[qhead++]=0; par[0]=-2; d[0]=0;
		while(qtail<qhead) {
			int at=q[qtail++];
			for(int x=fst[at];x!=-1;x=nxt[x]) {
				if(par[to[x]]!=-1) continue;
				par[to[x]]=at; d[to[x]]=d[at]+1; q[qhead++]=to[x];
			}
		}
		for(int i=qhead-1;i>=0;--i) {
			int at=q[i]; sz[at]=1;
			for(int x=fst[at];x!=-1;x=nxt[x]) if(par[to[x]]==at) sz[at]+=sz[to[x]];
			heavy[at]=-1; for(int x=fst[at];x!=-1;x=nxt[x]) if(par[to[x]]==at&&2*sz[to[x]]>=sz[at]) heavy[at]=to[x];
		}
		nid=0;
		REP(i,n) if(par[i]==-2||heavy[par[i]]!=i) {
			start[nid]=nid==0?0:start[nid-1]+cnt[nid-1]; cnt[nid]=0;
			for(int x=i;x!=-1;x=heavy[x]) { id[x]=nid,off[x]=cnt[nid]++; at[start[nid]+off[x]]=x; }
			++nid;
		}
	}

	void up1(int &a,int &ret) {
		int cur=val[start[id[a]]+off[a]]; if(cur<ret) ret=cur;
		a=par[a];
	}

	void upmany(int &a,int cnt,int &ret) {
		int cur=sgetmin(0,0,n-1,start[id[a]]+off[a]-cnt+1,start[id[a]]+off[a]); if(cur<ret) ret=cur;
		a=at[start[id[a]]+off[a]-cnt];
	}

	int solve(int a,int b) {
		int ret=INT_MAX;
		if(d[a]<d[b]) swap(a,b);
		//printf("solving(%d,%d)\n",a,b);
		while(d[a]!=d[b]) {
			if(heavy[par[a]]!=a) {
				up1(a,ret);
			} else {
				upmany(a,min(off[a],d[a]-d[b]),ret);
			}
		}
		while(a!=b) {
			if(heavy[par[a]]!=a||heavy[par[b]]!=b) {
				up1(a,ret); up1(b,ret);
			} else {
				int cnt=min(off[a],off[b]); upmany(a,cnt,ret); upmany(b,cnt,ret);
			}
		}
		up1(a,ret);
		if(a>=g.ncomp) up1(a,ret);
		return ret;
	}

	int sgetmin(int x,int l,int r,int L,int R) {
		if(L<=l&&r<=R) return sval[x];
		int m=l+(r-l)/2;
		if(R<=m) return sgetmin(2*x+1,l,m,L,R);
		if(m+1<=L) return sgetmin(2*x+2,m+1,r,L,R);
		return min(sgetmin(2*x+1,l,m,L,R),sgetmin(2*x+2,m+1,r,L,R));
	}

	void supdate(int x,int l,int r,int KEY) {
		if(l==r) { sval[x]=val[l]; return; }
		int m=l+(r-l)/2;
		if(KEY<=m) supdate(2*x+1,l,m,KEY);
		if(m+1<=KEY) supdate(2*x+2,m+1,r,KEY);
		sval[x]=min(sval[2*x+1],sval[2*x+2]);
	}

	void sinit(int x,int l,int r) {
		if(l==r) { sval[x]=val[l]; return; }
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		sval[x]=min(sval[2*x+1],sval[2*x+2]);
	}

	void setval(int at,int nval) {
		//printf("setting %d to %d\n",at,nval);
		val[start[id[at]]+off[at]]=nval;
		//REP(i,n) printf(" %d",val[i]); puts("");
		supdate(0,0,n-1,start[id[at]]+off[at]);
	}

	void print() {
		REP(i,g.n) if(cutid[i]!=-1) printf("%d: cut %d\n",i,cutid[i]); else printf("%d: comp %d\n",i,onlycomp[i]);
		//REP(i,n) { printf("%d:",i); for(int x=fst[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }
		printrec(0,0);
	}
	void printrec(int at,int d) {
		REP(i,d) printf("  "); printf("%d %c (%d,%d)\n",at,par[at]!=-2&&heavy[par[at]]==at?'H':'.',id[at],off[at]);
		for(int x=fst[at];x!=-1;x=nxt[x]) if(par[to[x]]==at) printrec(to[x],d+1);
	}
} T;
T t;

typedef struct PQ {
	int id[100000];
	int off[100000];
	int at[100000];
	int start[100000];
	int cnt[100000];

	void init() {
		REP(i,g.ncomp) cnt[i]=0;
		REP(i,g.n) {
			int cid=t.cutid[i]==-1?t.onlycomp[i]:t.par[t.cutid[i]];
			id[i]=cid; off[i]=cnt[cid]++;
		}
		REP(i,g.ncomp) start[i]=i==0?0:start[i-1]+cnt[i-1];
		//REP(i,g.n) printf("%d: %d %d\n",i,id[i],off[i]);
		//REP(i,g.ncomp) printf("%d: %d %d\n",i,start[i],cnt[i]);
		REP(i,g.n) { at[start[id[i]]+off[i]]=i; up(i); }
		//REP(i,g.n) printf("%d: %d (%d,%d) -> %d\n",i,at[i],id[at[i]],off[at[i]],g.w[at[i]]);
		REP(i,g.ncomp) t.val[t.start[t.id[i]]+t.off[i]]=g.w[at[start[i]+0]];
		REP(i,g.n) { int j=t.cutid[i]; if(j!=-1) t.val[t.start[t.id[j]]+t.off[j]]=g.w[i]; }
		t.sinit(0,0,t.n-1);
	}

	void up(int x) {
		int cid=id[x],base=start[cid],len=cnt[cid];
		while(true) {
			int coff=off[x],noff=(coff-1)/2,y=at[base+noff];
			if(g.w[y]<=g.w[x]) break;
			change(x,y);
		}
	}

	void down(int x) {
		int cid=id[x],base=start[cid],len=cnt[cid];
		while(true) {
			int coff=off[x],y=x,noff1=2*coff+1,noff2=2*coff+2;
			if(noff1<len) { int z=at[base+noff1]; if(g.w[z]<g.w[y]) y=z; }
			if(noff2<len) { int z=at[base+noff2]; if(g.w[z]<g.w[y]) y=z; }
			if(x==y) break;
			change(x,y);
		}
	}

	void update(int x) {
		up(x); down(x);
	}

	void change(int x,int y) {
		assert(id[x]==id[y]);
		int px=start[id[x]]+off[x],py=start[id[y]]+off[y]; assert(at[px]==x&&at[py]==y);
		swap(at[px],at[py]); swap(off[x],off[y]);
	}

	int minval(int x) {
		int y=at[start[id[x]]+0]; return g.w[y];
	}
} PQ;
PQ pq;

typedef struct IN {
	int n,m,nq;
	int w[100000];
	int a[100000],b[100000];
	char type[100000]; int x[100000],y[100000];

	
	void gen() {
		int seed=time(NULL); printf("seed=%d\n",seed); srand(seed);
		n=20000; m=n-1; nq=100000; int LIM=100000;
		REP(i,n) w[i]=rand()%LIM+1;
		FOR(i,1,n) a[i-1]=1/*+rand()%i*/,b[i-1]=1+i;
		FOR(i,n-1,m) do { a[i]=1+rand()%n,b[i]=1+rand()%n; } while(a[i]==b[i]);
		REP(i,nq) type[i]=rand()%2==0?'A':'C'; REP(i,nq) { x[i]=1+rand()%n; y[i]=1+rand()%(type[i]=='A'?n:LIM); }
	}
} IN;
IN in;


void input() {
	scanf("%d%d%d",&in.n,&in.m,&in.nq);
	REP(i,in.n) scanf("%d",&in.w[i]);
	REP(i,in.m) scanf("%d%d",&in.a[i],&in.b[i]);
	REP(qi,in.nq) scanf(" %c%d%d",&in.type[qi],&in.x[qi],&in.y[qi]);
}



void run() {
/*	printf("%d %d\n",in.n,in.m);
	REP(i,in.n) printf("%d ",in.w[i]); puts("");
	REP(i,in.m) printf("(%d,%d)",in.a[i],in.b[i]); puts("");
	REP(i,in.nq) printf("(%c %d %d)",in.type[i],in.x[i],in.y[i]); puts(""); */
	g.n=in.n; g.m=in.m;
	REP(i,g.n) g.w[i]=in.w[i];
	REP(i,g.n) g.fst[i]=-1;
	REP(i,g.m) {
		int a=in.a[i],b=in.b[i]; --a,--b;
		g.nxt[2*i+0]=g.fst[a]; g.fst[a]=2*i+0; g.to[2*i+0]=b;
		g.nxt[2*i+1]=g.fst[b]; g.fst[b]=2*i+1; g.to[2*i+1]=a;
	}
	g.tarjan();
	t.create();
	t.init();
	//t.print();
	pq.init();
	REP(qi,in.nq) {
		char type=in.type[qi];
		if(type=='A') {
			int a=in.x[qi],b=in.y[qi]; --a,--b; int oa=a,ob=b;
			int ret=-1;
			if(a==b) { 
				ret=g.w[a];
			} else {
				a=t.cutid[a]==-1?t.onlycomp[a]:t.cutid[a];
				b=t.cutid[b]==-1?t.onlycomp[b]:t.cutid[b];
				ret=t.solve(a,b);
			}
			printf("%d\n",ret);
		} else if(type=='C') {
			int a=in.x[qi],w=in.y[qi]; --a;
			g.w[a]=w;
			int b;
			if(t.cutid[a]!=-1) {
				t.setval(t.cutid[a],w);
				b=t.par[t.cutid[a]];
			} else {
				b=t.onlycomp[a];
			}
			pq.update(a);
			int bw=pq.minval(a);
			t.setval(b,bw);
		}
	}
}

int main() {
	input();
	run();
	return 0;
}