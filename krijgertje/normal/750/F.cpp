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

typedef vector<int> fnc(int x);



int solve(int h,fnc f) {
	int a=1; vector<int> xa=f(a);
	if(SZ(xa)==2) return a;
	int depth,below=a,par; vector<int> parpath; vector<vector<int> > xparpath;
	if(SZ(xa)==1) {
		depth=h-1; par=xa[0];
	} else {
		int pb=a,b=xa[0]; vector<int> xb=f(b); if(SZ(xb)==2) return b; vector<int> bpath; vector<vector<int> > xbpath; bpath.PB(b); xbpath.PB(xb);
		int pc=a,c=xa[1]; vector<int> xc=f(c); if(SZ(xc)==2) return c; vector<int> cpath; vector<vector<int> > xcpath; cpath.PB(c); xcpath.PB(xc);
		depth=h-2;
		while(SZ(xb)!=1&&SZ(xc)!=1) {
			int nb=xb[0]!=pb?xb[0]:xb[1]; pb=b,b=nb,xb=f(b); if(SZ(xb)==2) return b; bpath.PB(b); xbpath.PB(xb);
			int nc=xc[0]!=pc?xc[0]:xc[1]; pc=c,c=nc,xc=f(c); if(SZ(xc)==2) return c; cpath.PB(c); xcpath.PB(xc);
			--depth;
		}
		par=SZ(xb)==1&&SZ(xc)==1?xa[2]:SZ(xc)!=1?xa[1]:xa[0];
		if(SZ(xb)!=1) parpath=bpath,xparpath=xbpath;
		if(SZ(xc)!=1) parpath=cpath,xparpath=xcpath;
	}
	//printf("par=%d depth=%d\n",par,depth);
	assert(depth>=1);
	while(depth>=4) {
		if(SZ(parpath)==0) { vector<int> xpar=f(par); if(SZ(xpar)==2) return par; parpath.PB(par); xparpath.PB(xpar); }
		while(SZ(parpath)<h-depth+1) {
			int prv=SZ(parpath)==1?below:parpath[SZ(parpath)-2],cur=parpath.back(); vector<int> xcur=xparpath.back(); assert(SZ(xcur)==3);
			int nxt=xcur[0]!=prv?xcur[0]:xcur[1]; vector<int> xnxt=f(nxt); if(SZ(xnxt)==2) return nxt; parpath.PB(nxt); xparpath.PB(xnxt);
		}
		if(SZ(xparpath.back())==1) {
			par=-1; REPSZ(i,xparpath[0]) if(xparpath[0][i]!=below&&xparpath[0][i]!=parpath[1]) { par=xparpath[0][i]; break; } assert(par!=-1);
			--depth; below=parpath[0]; parpath.clear(); xparpath.clear();
		} else {
			--depth; below=par; par=parpath[1]; parpath.erase(parpath.begin()); xparpath.erase(xparpath.begin());
		}
	}
	//printf("-> par=%d,depth=%d\n",par,depth);
	vector<int> pos;
	if(depth==3) {
		vector<int> xpar; if(SZ(parpath)>=1) xpar=xparpath[0]; else { xpar=f(par); if(SZ(xpar)==2) return par; }
		REPSZ(i,xpar) if(xpar[i]!=below) {
			int d=xpar[i]; vector<int> xd; if(SZ(parpath)>=2&&parpath[1]==d) xd=xparpath[1]; else { xd=f(d); if(SZ(xd)==2) return d; }
			REPSZ(j,xd) if(xd[j]!=par) {
				int e=xd[j]; if(SZ(parpath)>=3&&parpath[1]==d&&parpath[2]==e) continue; else pos.PB(e);
			}
		}
	}
	if(depth==2) {
		vector<int> xpar; if(SZ(parpath)>=1) xpar=xparpath[0]; else { xpar=f(par); if(SZ(xpar)==2) return par; }
		REPSZ(i,xpar) if(xpar[i]!=below) {
			int d=xpar[i]; if(SZ(parpath)>=2&&parpath[1]==d) continue; else pos.PB(d);
		}
	}
	if(depth==1) {
		pos.PB(par);
	}
	REP(i,SZ(pos)-1) {
		int ret=pos[i]; vector<int> xret=f(ret); if(SZ(xret)==2) return ret;
	}
	return pos.back();
}

vector<int> iofnc(int x) {
	printf("? %d\n",x); fflush(stdout);
	int k; scanf("%d",&k); if(k==0) exit(0);
	vector<int> ret(k); REP(i,k) scanf("%d",&ret[i]); return ret;
}
void run() {
	int h; scanf("%d",&h); if(h==0) exit(0);
	int ret=solve(h,iofnc);
	printf("! %d\n",ret); fflush(stdout);
}


bool dbg=false;
int h,n,s,nq;
vector<int> pos,id; bool fst; int nxtid;
vector<int> c; int cidx; bool done;
vector<int> adj;
int getid(int at,int to) { if(id[at]!=-1) return id[at]; while(nxtid<=n&&pos[nxtid]!=-1||adj[nxtid]!=-1) ++nxtid; assert(nxtid<=n); adj[nxtid]=to; return nxtid++; }
vector<int> dbgfnc(int x) {
	if(dbg) printf("\t\tq(%d)\n",x);
	if(fst) {
		id[s]=x; pos[x]=s; fst=false; //printf("id[%d]=%d\n",s,x);
	} else {
		int at=adj[x]; assert(at!=-1); //printf("\t\tat=%d\n",at);
		vector<int> opt;
		if(at!=-1&&id[at/2]==-1) opt.PB(at/2);
		if(2*at<=n&&id[2*at]==-1) opt.PB(2*at);
		if(2*at+1<=n&&id[2*at+1]==-1) opt.PB(2*at+1);
		assert(SZ(opt)>0);
		if(cidx>=SZ(c)) c.PB(SZ(opt)-1);
		int to=opt[c[cidx++]];
		id[to]=x; pos[x]=to; adj[x]=-1; //printf("id[%d]=%d\n",to,x);
	}
	if(dbg) printf("\t\tpos=%d\n",pos[x]);
	vector<int> ret;
	if(pos[x]!=1) ret.PB(getid(pos[x]/2,pos[x]));
	if(2*pos[x]<=n) ret.PB(getid(2*pos[x],pos[x]));
	if(2*pos[x]+1<=n) ret.PB(getid(2*pos[x]+1,pos[x]));
	random_shuffle(ret.begin(),ret.end());
	if(dbg) { printf("\t\tret="); REPSZ(i,ret) printf(" %d",ret[i]); puts(""); }
	++nq; return ret;
}
void test() {
	pos=id=adj=vector<int>(n+1,-1); fst=true; nxtid=1; cidx=0; nq=0;
	if(dbg) printf("start\n");
	int res=solve(h,dbgfnc);
	bool correct=id[1]==res;
	int cnt=-1; if(adj[res]!=-1&&(adj[res]==2||adj[res]==3)) { cnt=0; FORE(i,1,n) if(adj[i]==adj[res]) ++cnt; if(cnt==1) correct=true; }
	if(!correct||nq>16) printf("error: %d in %d moves [%d,%d]\n",res,nq,adj[res],cnt);
	while(SZ(c)>0&&c[SZ(c)-1]==0) c.pop_back();
	if(SZ(c)==0) done=true; else c[SZ(c)-1]--;
}
void stress() {
	srand(time(NULL));
	for(h=2;h<=7;++h) {
		printf("processing %d\n",h);
		n=(1<<h)-1;
		for(s=1;s<=n;++s) {
			//dbg=h==6&&s==32;
			c.clear(); done=false;
			while(true) {
				printf("."); test();
				if(done) break;
			}
			printf("%d ok\n",s);
		}
	}
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	//stress();
	return 0;
}