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
#include <bitset>
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

const int MAXN=500;
const int MAXGN=4*MAXN+2;
const int MAXGM=5*MAXN;

typedef struct MCMF {
	int n,m;
	int ghead[MAXGN],gnxt[2*MAXGM],gto[2*MAXGM],gcap[2*MAXGM],gcost[2*MAXGM];
	int d[MAXGN]; int bck[MAXGN];
	int pot[MAXGN];

	void init(int _n) { n=_n,m=0; REP(i,n) ghead[i]=-1,pot[i]=0; }
	void addedge(int a,int b,int c,int d) {
		gnxt[m]=ghead[a],ghead[a]=m,gto[m]=b,gcap[m]=c,gcost[m]=d,++m; gnxt[m]=ghead[b],ghead[b]=m,gto[m]=a,gcap[m]=0,gcost[m]=-d,++m; 
		//printf("adding edge %d-%d with cap %d and cost %d\n",a,b,c,d);
	}
	pair<int,int> solve(int s,int t) {
		//REP(i,n) { printf("%d:",i); for(int x=ghead[i];x!=-1;x=gnxt[x]) printf(" %d",gto[x]); puts(""); }

		REP(i,n) d[i]=INT_MAX,bck[i]=-1; d[s]=0,bck[s]=-2;
		while(true) {
			bool change=false;
			REP(at,n) if(d[at]!=INT_MAX) for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gcap[x]>0) {
				int to=gto[x]; if(d[at]+gcost[x]>=d[to]) continue;
				d[to]=d[at]+gcost[x]; bck[to]=x^1; change=true;
			}
			if(!change) break;
		}
		if(d[t]==INT_MAX) return MP(0,0);
		REP(i,n) pot[i]=d[i];


		pair<int,int> ret=MP(0,0);
		while(true) {
			REP(i,n) d[i]=INT_MAX,bck[i]=-1; d[s]=0,bck[s]=-2;
			priority_queue<pair<int,int> > q; q.push(MP(-d[s],s));
			while(!q.empty()) {
				int cost=-q.top().first; int at=q.top().second; q.pop();
				if(cost>d[at]) continue;
				for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gcap[x]>0) {
					int to=gto[x]; int rcost=gcost[x]-pot[at]+pot[to]; if(d[at]+rcost>=d[to]) continue;
					d[to]=d[at]+rcost; bck[to]=x^1; q.push(MP(-d[to],to));
				}
			}
			if(d[t]==INT_MAX) break;
			//printf("%d\n",d[t]-pot[t]);
			++ret.first,ret.second+=d[t]-pot[t];
			REP(i,n) if(d[i]!=INT_MAX) pot[i]-=d[i];

			for(int at=t;at!=s;at=gto[bck[at]]) {
				//printf("%d ",at);
				++gcap[bck[at]]; --gcap[bck[at]^1];
			}
			//printf("%d ",s);
			//puts("");
		}
		return ret;
	}
} MCMF;
MCMF g;


int n,rx,ry;
int gain[MAXN];
vector<int> xadj[MAXN];
vector<int> yadj[MAXN];
int xcap[MAXN]; bool hasxcap[MAXN];
int ycap[MAXN]; bool hasycap[MAXN];

int stck[MAXN],nstck;

int nl,lcap[MAXN],lidx[MAXN];
int nr,rcap[MAXN],ridx[MAXN];

int sid,tid,lid[MAXN],mid[MAXN][2],rid[MAXN],nid;

void xdfs(int at,int par,int subidx) {
	if(hasxcap[at]&&subidx!=-1) xcap[subidx]-=xcap[at];
	if(hasxcap[at]) subidx=at;
	stck[nstck++]=at;
	REPSZ(i,xadj[at]) { int to=xadj[at][i]; if(to==par) continue; xdfs(to,at,subidx); }
	if(hasxcap[at]) { int id=nl++; lcap[id]=xcap[at]; while(lidx[at]==-1) lidx[stck[--nstck]]=id;	}
}
void ydfs(int at,int par,int subidx) {
	if(hasycap[at]&&subidx!=-1) ycap[subidx]-=ycap[at];
	if(hasycap[at]) subidx=at;
	stck[nstck++]=at;
	REPSZ(i,yadj[at]) { int to=yadj[at][i]; if(to==par) continue; ydfs(to,at,subidx); }
	if(hasycap[at]) { int id=nr++; rcap[id]=ycap[at]; while(ridx[at]==-1) ridx[stck[--nstck]]=id;	}
}

int solve() {
	if(xcap[rx]!=ycap[ry]) return -1;
	int want=xcap[rx];
	nstck=nl=0; REP(i,n) lidx[i]=-1; xdfs(rx,-1,-1);
	nstck=nr=0; REP(i,n) ridx[i]=-1; ydfs(ry,-1,-1);
	REP(i,nl) if(lcap[i]<0) return -1;
	REP(i,nr) if(rcap[i]<0) return -1;
	//REP(i,n) printf("%d: lidx=%d ridx=%d xcap=%d ycap=%d\n",i+1,lidx[i],ridx[i],xcap[i],ycap[i]);

	nid=0; sid=nid++; tid=nid++; REP(i,nl) lid[i]=nid++; REP(i,n) REP(j,2) mid[i][j]=nid++;  REP(i,nr) rid[i]=nid++;
	g.init(nid);
	REP(i,nl) g.addedge(sid,lid[i],lcap[i],0);
	REP(i,n) g.addedge(lid[lidx[i]],mid[i][0],1,0);
	REP(i,n) g.addedge(mid[i][0],mid[i][1],1,-gain[i]);
	REP(i,n) g.addedge(mid[i][1],rid[ridx[i]],1,0);
	REP(i,nr) g.addedge(rid[i],tid,rcap[i],0);

	pair<int,int> res=g.solve(sid,tid);
	//printf("res=(%d,%d)\n",res.first,res.second);
	if(res.first!=want) return -1;
	return -res.second;
}

void run() {
	scanf("%d%d%d",&n,&rx,&ry); --rx,--ry;
	REP(i,n) scanf("%d",&gain[i]);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; xadj[a].PB(b),xadj[b].PB(a); }
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; yadj[a].PB(b),yadj[b].PB(a); }
	{ REP(i,n) hasxcap[i]=false; int nx; scanf("%d",&nx); REP(i,nx) { int idx,val; scanf("%d%d",&idx,&val); --idx; hasxcap[idx]=true,xcap[idx]=val; } }
	{ REP(i,n) hasycap[i]=false; int ny; scanf("%d",&ny); REP(i,ny) { int idx,val; scanf("%d%d",&idx,&val); --idx; hasycap[idx]=true,ycap[idx]=val; } }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}