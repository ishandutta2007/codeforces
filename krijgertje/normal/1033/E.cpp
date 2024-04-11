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

const int MAXN=600;
const int MAXM=MAXN*(MAXN-1)/2;
struct Comp {
	vector<int> red;
	vector<int> blue;
	int ntotedges;
};

int n;

vector<int> adj[MAXN];
vector<int> ans;

bool local=false; int nq;
int locm;
int loce[MAXM][2];

map<vector<int>,int> mem;

int query(vector<int> &a) {
	sort(a.begin(),a.end());
	if(SZ(a)<=1) return 0;
	if(mem.count(a)) return mem[a];
	int ret;
	if(!local) {
		printf("? %d\n",SZ(a)); REPSZ(i,a) { if(i!=0) printf(" "); printf("%d",a[i]+1); } puts(""); fflush(stdout);
		scanf("%d",&ret);
	} else {
		++nq;
		vector<bool> have(n,false); REPSZ(i,a) have[a[i]]=true;
		ret=0; REP(i,locm) if(have[loce[i][0]]&&have[loce[i][1]]) ++ret;
		//printf("?"); REPSZ(i,a) printf(" %d",a[i]+1); printf(" -> %d\n",ret);
	}
	return mem[a]=ret;
}


int countedges(vector<int> &a) {
	return query(a);
}
int countedges(vector<int> &a,vector<int> &b) {
	vector<int> c=a; REPSZ(i,b) c.PB(b[i]); return query(c);
}
bool test(Comp &a,vector<Comp> &b,int l,int r) {
	vector<int> c; REPSZ(j,a.red) c.PB(a.red[j]); REPSZ(j,a.blue) c.PB(a.blue[j]); FORE(i,l,r) { REPSZ(j,b[i].red) c.PB(b[i].red[j]); REPSZ(j,b[i].blue) c.PB(b[i].blue[j]); }
	int have=query(c);
	int expect=a.ntotedges; FORE(i,l,r) expect+=b[i].ntotedges; return have>expect;
}

pair<int,int> findedge(vector<int> &a,vector<int> &b) {
	if(countedges(a,b)==0) return MP(-1,-1);
	int lo=-1,hi=SZ(a)-1;
	while(lo+1<hi) {
		int mi=lo+(hi-lo)/2;
		vector<int> c; REPE(i,mi) c.PB(a[i]); REPSZ(i,b) c.PB(b[i]);
		if(query(c)==0) lo=mi; else hi=mi;
	}
	int aidx=hi; lo=-1,hi=SZ(b)-1;
	while(lo+1<hi) {
		int mi=lo+(hi-lo)/2;
		vector<int> c; c.PB(a[aidx]); REPE(i,mi) c.PB(b[i]);
		if(query(c)==0) lo=mi; else hi=mi;
	}
	int bidx=hi;
	//printf("ab[%d,%d]\n",a[aidx],b[bidx]);
	return MP(a[aidx],b[bidx]);
}
pair<int,int> findedge(vector<int> &a) {
	//printf("findedge in"); REPSZ(i,a) printf(" %d",a[i]+1); puts("");
	int lo=-1,hi=SZ(a)-1;
	while(lo+1<hi) {
		int mi=lo+(hi-lo)/2;
		vector<int> c; REPE(i,mi) c.PB(a[i]);
		if(query(c)==0) lo=mi; else hi=mi;
	}
	int ridx=hi; lo=-1,hi=ridx-1;
	while(lo+1<hi) {
		int mi=lo+(hi-lo)/2;
		vector<int> c; REPE(i,mi) c.PB(a[i]); c.PB(a[ridx]);
		if(query(c)==0) lo=mi; else hi=mi;
	}
	int lidx=hi;
	//printf("a[%d,%d]\n",a[lidx],a[ridx]);
	return MP(a[lidx],a[ridx]);
}

bool dfs(int at,int par,int dst) {
	ans.PB(at);
	if(at==dst) return true;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par) continue;
		if(dfs(to,at,dst)) return true;
	}
	ans.pop_back();
	return false;
}

void makeerr(int s,int t) {
	assert(dfs(s,-1,t));
	assert(SZ(ans)>0);
}

vector<Comp> solve(int l,int r) {
	if(l==r) { vector<Comp> ret; Comp comp; comp.red.clear(); comp.blue.clear(); comp.ntotedges=0; comp.red.PB(l); ret.PB(comp); return ret; }
	int m=l+(r-l)/2;
	vector<Comp> cl=solve(l,m);
	if(SZ(ans)>0) return vector<Comp>();
	vector<Comp> cr=solve(m+1,r);
	if(SZ(ans)>0) return vector<Comp>();
	vector<Comp> ret;
	REPSZ(i,cl) {
		int last=-1;
		//printf("solve(%d,%d): testing connections from cl[%d]\n",l+1,r+1,i);
		vector<pair<int,bool>> conn;
		while(true) {
			bool any=test(cl[i],cr,last+1,SZ(cr)-1); if(!any) break;
			int lo=last,hi=SZ(cr)-1; // (lo,hi]
			while(lo+1<hi) {
				int mi=lo+(hi-lo)/2;
				if(!test(cl[i],cr,last+1,mi)) lo=mi; else hi=mi;
			}
			int j=hi;
			last=j;
			//printf("here:"); REPSZ(k,cl[i].red) printf(" %d",cl[i].red[k]+1); printf(" -"); REPSZ(k,cr[j].red) printf(" %d",cr[j].red[k]+1); puts("");
			pair<int,int> rr=findedge(cl[i].red,cr[j].red); if(rr.first!=-1&&rr.second!=-1) { adj[rr.first].PB(rr.second); adj[rr.second].PB(rr.first); conn.PB(MP(j,true)); continue; }
			//printf("here:"); REPSZ(k,cl[i].blue) printf(" %d",cl[i].blue[k]+1); printf(" -"); REPSZ(k,cr[j].blue) printf(" %d",cr[j].blue[k]+1); puts("");
			pair<int,int> bb=findedge(cl[i].blue,cr[j].blue); if(bb.first!=-1&&bb.second!=-1) { adj[bb.first].PB(bb.second); adj[bb.second].PB(bb.first); conn.PB(MP(j,true)); continue; }
			//printf("here:"); REPSZ(k,cl[i].red) printf(" %d",cl[i].red[k]+1); printf(" -"); REPSZ(k,cr[j].blue) printf(" %d",cr[j].blue[k]+1); puts("");
			pair<int,int> rb=findedge(cl[i].red,cr[j].blue); if(rb.first!=-1&&rb.second!=-1) { adj[rb.first].PB(rb.second); adj[rb.second].PB(rb.first); conn.PB(MP(j,false)); continue; }
			//printf("here:"); REPSZ(k,cl[i].blue) printf(" %d",cl[i].blue[k]+1); printf(" -"); REPSZ(k,cr[j].red) printf(" %d",cr[j].red[k]+1); puts("");
			pair<int,int> br=findedge(cl[i].blue,cr[j].red); if(br.first!=-1&&br.second!=-1) { adj[br.first].PB(br.second); adj[br.second].PB(br.first); conn.PB(MP(j,false)); continue; }
			assert(false);
		}
		if(SZ(conn)==0) { ret.PB(cl[i]); continue; }
		//REPSZ(j,conn) printf("connecting with %d%s\n",conn[j].first,conn[j].second?" (flipping)":"");
		Comp comp=cl[i];
		vector<bool> keep(SZ(cr),true);
		REPSZ(jj,conn) {
			int j=conn[jj].first; bool flip=conn[jj].second; keep[j]=false;
			REPSZ(k,cr[j].red) if(!flip) comp.red.PB(cr[j].red[k]); else comp.blue.PB(cr[j].red[k]);
			REPSZ(k,cr[j].blue) if(!flip) comp.blue.PB(cr[j].blue[k]); else comp.red.PB(cr[j].blue[k]);
		}
		//printf("recalculating\n");
		comp.ntotedges=countedges(comp.red,comp.blue);
		if(countedges(comp.red)>0) {
			pair<int,int> rr=findedge(comp.red);
			makeerr(rr.first,rr.second);
			return vector<Comp>();
		}
		if(countedges(comp.blue)>0) {
			pair<int,int> bb=findedge(comp.blue);
			makeerr(bb.first,bb.second);
			return vector<Comp>();
		}
		vector<Comp> ncr; REPSZ(j,cr) if(keep[j]) ncr.PB(cr[j]); ncr.PB(comp); cr=ncr;
		//printf("->ncr=%d\n",SZ(cr));
	}
	REPSZ(j,cr) ret.PB(cr[j]);
	return ret;
}

bool solve() {
	mem.clear();
	REP(i,n) adj[i].clear();
	ans.clear();
	vector<Comp> comps=solve(0,n-1);
	if(SZ(ans)>0) return false;
	REPSZ(i,comps) REPSZ(j,comps[i].red) ans.PB(comps[i].red[j]);
	return true;
}

void run() {
	scanf("%d",&n);
	bool res=solve();
	printf("%c %d\n",res?'Y':'N',SZ(ans)); REPSZ(i,ans) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

bool runloc() {
	local=true; nq=0;
	bool res=solve();
	//printf("%c %d\n",res?'Y':'N',SZ(ans)); REPSZ(i,ans) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
	if(res) {
		vector<bool> have(n,false); REPSZ(i,ans) have[ans[i]]=true;
		REP(i,locm) { int cnt=(have[loce[i][0]]?1:0)+(have[loce[i][1]]?1:0); if(cnt!=1) return false; }
	} else {
		if(SZ(ans)%2!=1) return false;
		set<pair<int,int>> have; REP(i,locm) have.insert(MP(loce[i][0],loce[i][1])),have.insert(MP(loce[i][1],loce[i][0]));
		REPSZ(i,ans) { int a=ans[i],b=ans[(i+1)%SZ(ans)]; if(!have.count(MP(a,b))) return false; }
	}
}

void test() {
	scanf("%d",&n); scanf("%d",&locm);
	REP(i,locm) { int a,b; scanf("%d%d",&a,&b); --a,--b; loce[i][0]=a,loce[i][1]=b; }
	runloc();
}

void stress() {
	int mxq=0;
	REP(rep,1000) {
		n=MAXN; locm=rand()%(2*n); if(locm>n*(n-1)/2) continue;
		set<pair<int,int>> seen; REP(i,locm) while(true) { int a=rand()%n,b=rand()%n; if(a==b||seen.count(MP(a,b))||seen.count(MP(b,a))) continue; seen.insert(MP(a,b)); loce[i][0]=a,loce[i][1]=b; break; }
		if(runloc()) { printf("."); if(nq>mxq) mxq=nq,printf("%d\n",nq); continue; }
		printf("%d: err\n",rep);
		printf("%d %d\n",n,locm); REP(i,locm) printf("%d %d\n",loce[i][0]+1,loce[i][1]+1); return;
	}
}

int main() {
	run();
	//test();
	//stress();
	return 0;
}