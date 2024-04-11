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
const int MAXM=MAXN-1;
const int MAXLGN=18;
const int MAXNALL=(MAXLGN+1)*MAXN;

int allnodes[MAXNALL],allnxt[MAXNALL],allnxtidx[MAXNALL],allprvidx[MAXNALL]; ll allcdst[MAXNALL],allcpdst[MAXNALL],nall;
int nnodes[MAXN]; // nnodes[i] = # nodes in TREE(i)
int* nodes[MAXN]; // nodes[i][j] = node in position j in TREE(i)
int* nxt[MAXN]; // nxt[i][j] = next centroid for node in position j in TREE(i)
int* nxtidx[MAXN]; // nxtidx[i][j] = position in next centroid for node in position j in TREE(i)
ll* cdst[MAXN]; // cdst[i][j] = sum of distances of nodes in positions [0..j] in TREE(i) to i
ll* cpdst[MAXN]; // cpdst[i][j] = sum of distances of nodes in positions [0..j] in TREE(i) to par[i]
int *prvidx[MAXN]; // prvidx[i][j] = position in previous centroid for node in position j in TREE(i)

int findge(int u,int x) { int l=-1,h=nnodes[u]; while(l+1<h) { int m=l+(h-l)/2; if(prvidx[u][m]>=x) h=m; else l=m; } return h; }
int findle(int u,int x) { int l=-1,h=nnodes[u]; while(l+1<h) { int m=l+(h-l)/2; if(prvidx[u][m]<=x) l=m; else h=m; } return l; }
ll query(int u,int qidx,int a,int b) {
	ll qdst=cdst[u][qidx]-(qidx==0?0:cdst[u][qidx-1]);
	ll ret=cdst[u][b]-(a==0?0:cdst[u][a-1])+(b-a+1)*qdst;
	int v=nxt[u][qidx];
	//printf("qdst=%lld ret=%lld v=%d\n",qdst,ret,v);
	if(v==-1) return ret;
	int na=findge(v,a),nb=findle(v,b);
	//printf("na=%d nb=%d\n",na,nb);
	if(na>nb) return ret;
	ret-=cpdst[v][nb]-(na==0?0:cpdst[v][na-1])+(nb-na+1)*qdst;
	//printf("u=%d ret=%lld\n",u,ret);
	ret+=query(v,nxtidx[u][qidx],na,nb);
	//printf("u=%d ret=%lld\n",u,ret);
	return ret;
}

void swp(int u,int a,int b,ll dpdst=0) {
	FOR(i,a,b) cpdst[u][i]+=dpdst;
	swap(nodes[u][a],nodes[u][b]);
	swap(nxt[u][a],nxt[u][b]);
	swap(nxtidx[u][a],nxtidx[u][b]);
	ll adst=cdst[u][a]-(a==0?0:cdst[u][a-1]),bdst=cdst[u][b]-(b==0?0:cdst[u][b-1]); FOR(i,a,b) cdst[u][i]+=bdst-adst;
	if(nxt[u][a]!=-1) prvidx[nxt[u][a]][nxtidx[u][a]]=a; if(nxt[u][b]!=-1) prvidx[nxt[u][b]][nxtidx[u][b]]=b;
	if(nxt[u][a]!=nxt[u][b]) return;
	swap(nxtidx[u][a],nxtidx[u][b]); prvidx[nxt[u][a]][nxtidx[u][a]]=a; prvidx[nxt[u][b]][nxtidx[u][b]]=b;
	swp(nxt[u][a],nxtidx[u][a],nxtidx[u][b],bdst-adst);
}

void print(int u,int d=0) {
	REP(i,d) printf("  "); printf("nodes ="); REP(i,nnodes[u]) printf(" %d",nodes[u][i]); puts("");
	REP(i,d) printf("  "); printf("nxt ="); REP(i,nnodes[u]) printf(" %d",nxt[u][i]); puts("");
	REP(i,d) printf("  "); printf("nxtidx ="); REP(i,nnodes[u]) printf(" %d",nxtidx[u][i]); puts("");
	REP(i,d) printf("  "); printf("cdst ="); REP(i,nnodes[u]) printf(" %lld",cdst[u][i]); puts("");
	if(d!=0) {
		REP(i,d) printf("  "); printf("cpdst ="); REP(i,nnodes[u]) printf(" %lld",cpdst[u][i]); puts("");
		REP(i,d) printf("  "); printf("prvidx ="); REP(i,nnodes[u]) printf(" %d",prvidx[u][i]); puts("");
	}
	REP(i,nnodes[u]) if(nxtidx[u][i]==0) print(nxt[u][i],d+1);
}

int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],glen[MAXM]; bool done[MAXN];

int curch[MAXN]; ll curdst[MAXN]; int curcnt[MAXN]; int curoff[MAXN];
int dfs2(int at,int par,int ch,ll dst) {
	curch[at]=ch,curdst[at]=dst; int ret=1;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x];
		if(done[to]||to==par) continue;
		ret+=dfs2(to,at,ch,dst+glen[x>>1]);
	}
	return ret;
}
int sz[MAXN];
int dfs1(int at,int par,int n) {
	sz[at]=1; int ret=at;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x];
		if(done[to]||to==par) continue;
		int ret=dfs1(to,at,n);
		if(ret!=-1) return ret;
		sz[at]+=sz[to];
		if(2*sz[to]>=n) ret=-1;
	}
	if(2*(n-sz[at])>=n) ret=-1;
	return ret;
}

int init(int n,int *p,int *pidx,ll *pdst) {
	assert(n>=1); int u=dfs1(p[0],-1,n); assert(u!=-1);
	done[u]=true;
	nodes[u]=allnodes+nall,nxt[u]=allnxt+nall,nxtidx[u]=allnxtidx+nall,cdst[u]=allcdst+nall,cpdst[u]=allcpdst+nall,prvidx[u]=allprvidx+nall,nall+=n; assert(nall<=MAXNALL);
	nnodes[u]=n; REP(i,n) nodes[u][i]=p[i],prvidx[u][i]=pidx[i],cpdst[u][i]=pdst[i]+(i==0?0:cpdst[u][i-1]);
	int sumcnt=0;
	REP(i,n) curch[nodes[u][i]]=-1;
	for(int x=ghead[u];x!=-1;x=gnxt[x]) {
		int v=gto[x];
		if(done[v]) continue;
		curcnt[v]=0,curoff[v]=sumcnt;
		sumcnt+=dfs2(v,u,v,glen[x>>1]);
	}
	REP(i,n) {
		int w=nodes[u][i],v=curch[w];
		if(v==-1) { assert(w==u); nxt[u][i]=nxtidx[u][i]=-1; cdst[u][i]=(i==0?0:cdst[u][i-1]); continue; }
		nxtidx[u][i]=curcnt[v]++;
		cdst[u][i]=curdst[w]+(i==0?0:cdst[u][i-1]);
		p[curoff[v]+nxtidx[u][i]]=w;
		pidx[curoff[v]+nxtidx[u][i]]=i;
		pdst[curoff[v]+nxtidx[u][i]]=curdst[w];
	}
	for(int x=ghead[u];x!=-1;x=gnxt[x]) {
		int v=gto[x];
		if(done[v]) continue;
		int vv=init(curcnt[v],p+curoff[v],pidx+curoff[v],pdst+curoff[v]);
		REP(i,nnodes[vv]) nxt[u][prvidx[vv][i]]=vv;
	}
	return u;
}

int n,nq;
int p[MAXN];
int tp[MAXN],tpidx[MAXN]; ll tpdst[MAXN];
int pinv[MAXN];
int root;

void init() {
	nall=0;
	REP(i,n) done[i]=false,tp[i]=p[i],tpidx[i]=i,tpdst[i]=0;
	root=init(n,tp,tpidx,tpdst);
	REP(i,n) pinv[p[i]]=i;
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&p[i]),--p[i];
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d%d",&a,&b,&glen[i]); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	
	init();

	ll pret=0;
	REP(i,nq) {
		//print(root); puts("");
		int type; scanf("%d",&type);
		if(type==1) {
			int l,r,v; scanf("%d%d%d",&l,&r,&v); l^=(pret%(1<<30)); r^=(pret%(1<<30)); v^=(pret%(1<<30)); --l,--r,--v;
			ll ret=query(root,pinv[v],l,r);
			printf("%lld\n",ret);
			pret=ret;
		}
		if(type==2) {
			int x; scanf("%d",&x); x^=(pret%(1<<30)); --x;
			swp(root,x,x+1);
			swap(p[x],p[x+1]); swap(pinv[p[x]],pinv[p[x+1]]);
		}
	}
}

const int MAXBFN=1000;
ll d[MAXBFN][MAXBFN];
void initbf() {
	REP(i,n) REP(j,n) d[i][j]=i==j?0:LLONG_MAX;
	REP(i,n-1) { int a=gto[2*i+1],b=gto[2*i+0],c=glen[i]; if(c<d[a][b]) d[a][b]=c; if(c<d[b][a]) d[b][a]=c; }
	REP(k,n) REP(i,n) REP(j,n) if(d[i][k]!=LLONG_MAX&&d[k][j]!=LLONG_MAX&&d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];
}
ll bf(int v,int l,int r) { ll ret=0; FORE(i,l,r) ret+=d[v][p[i]]; return ret; }

void stress() {
	while(true) {
		n=100,nq=10000; assert(n<=MAXBFN);
		REP(i,n) p[i]=i; random_shuffle(p,p+n);
		REP(i,n) ghead[i]=-1;
		REP(i,n-1) {
			int a=rand()%(i+1),b=i+1; glen[i]=1000000*(rand()%1000)+1000*(rand()%1000)+(rand()%1000)+1;
			gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
			gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
		}
		init(); initbf();
		REP(i,nq) {
			int type=rand()%2+1;
			if(type==1) {
				int l=rand()%n,r=rand()%n,v=rand()%n; if(l>r) swap(l,r);
				ll ret=query(root,pinv[v],l,r);
				ll chk=bf(v,l,r);
				if(ret!=chk) printf("%lld vs %lld\n",ret,chk);
			}
			if(type==2) {
				int x=rand()%(n-1);
				swp(root,x,x+1);
				swap(p[x],p[x+1]); swap(pinv[p[x]],pinv[p[x+1]]);
			}
		}
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}