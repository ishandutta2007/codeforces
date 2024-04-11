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

const int MAXN=200000;
const int MAXQ=200000;
const int MAXS=4*MAXN;

int n;
int initval[MAXN];
int par[MAXN];
int nq;
int qkind[MAXQ],qa[MAXQ],qb[MAXQ],qans[MAXQ];

vector<int> ch[MAXN];
int sz[MAXN],heavy[MAXN];
int hroot[MAXN],hidx[MAXN],hlst[MAXN],hsz[MAXN],nh;

int curval[MAXN],pos[MAXN];
priority_queue<pair<int,int>> pathvals[MAXN]; // for each heavy path, keep node with lowest value
int pathmin[MAXN];
set<pair<int,int>> pathmins; // keep minimum values of paths in sorted set

void dfsinit(int at) {
	sz[at]=1,heavy[at]=-1;
	REPSZ(i,ch[at]) {
		int to=ch[at][i];
		dfsinit(to);
		sz[at]+=sz[to]; if(heavy[at]==-1||sz[to]>sz[heavy[at]]) heavy[at]=to;
	}
}

void updatepath(int idx) {
	while(!pathvals[idx].empty()&&curval[pathvals[idx].top().second]!=-pathvals[idx].top().first) pathvals[idx].pop();
	if(pathmin[idx]!=-pathvals[idx].top().first) { pathmins.erase(MP(pathmin[idx],idx)); pathmin[idx]=-pathvals[idx].top().first; pathmins.insert(MP(pathmin[idx],idx)); }
}

int sval[MAXS];
void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=curval[hlst[l]];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		sval[x]=min(sval[2*x+1],sval[2*x+2]);
	}
}
void supd(int x,int l,int r,int IDX) {
	if(l==r) {
		sval[x]=curval[hlst[IDX]];
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) supd(2*x+1,l,m,IDX); else supd(2*x+2,m+1,r,IDX);
		sval[x]=min(sval[2*x+1],sval[2*x+2]);
	}
}
int sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[x];
	} else {
		int m=l+(r-l)/2,ret=INT_MAX;
		if(L<=m) ret=min(ret,sget(2*x+1,l,m,L,R));
		if(m+1<=R) ret=min(ret,sget(2*x+2,m+1,r,L,R));
		return ret;
	}
}


bool used[MAXN]; int firstidx[MAXN],lastidx[MAXN]; bool firstfixed[MAXN],lastfixed[MAXN]; // for heavy paths, whether any part of it is in the current path and info about that subpath
bool anc[MAXN]; int desc[MAXN]; int anclst[MAXN],nanc;
int usedlst[MAXN],nused;

int getlim(int at) {
	int before=firstidx[hroot[at]]==hidx[hroot[at]]?n:sget(0,0,n-1,hidx[hroot[at]],firstidx[hroot[at]]-1);
	int after=lastidx[hroot[at]]==hidx[hroot[at]]+hsz[hroot[at]]-1?n:sget(0,0,n-1,lastidx[hroot[at]]+1,hidx[hroot[at]]+hsz[hroot[at]]-1);
	int ret=firstidx[hroot[at]]==lastidx[hroot[at]]&&firstfixed[hroot[at]]!=lastfixed[hroot[at]]?max(before,after):min(firstfixed[hroot[at]]?before:n,lastfixed[hroot[at]]?after:n);
	//printf("getlim(%d)=%d\n",at+1,ret);
	return ret;
}
 
int calcmex() {
	int lim=n;
	nused=nanc=0;
	for(auto it=pathmins.begin();it!=pathmins.end();++it) {
		int pid=it->second,at=pos[pathmin[pid]],oat=at;
		if(curval[at]>=lim) break;
		if(it==pathmins.begin()) {
			used[hroot[at]]=true,usedlst[nused++]=hroot[at],firstidx[hroot[at]]=lastidx[hroot[at]]=hidx[at],firstfixed[hroot[at]]=lastfixed[hroot[at]]=false;
			for(int prv=hroot[at],to=par[prv];to!=-1;prv=hroot[to],to=par[prv]) anc[hroot[to]]=true,anclst[nanc++]=hroot[to],desc[hroot[to]]=prv;
		} else {
			bool atfixed=false;
			while(!used[hroot[at]]&&!anc[hroot[at]]) {
				used[hroot[at]]=true,usedlst[nused++]=hroot[at],firstidx[hroot[at]]=hidx[hroot[at]],lastidx[hroot[at]]=hidx[at],firstfixed[hroot[at]]=true,lastfixed[hroot[at]]=atfixed;
				lim=min(lim,getlim(at));
				at=par[hroot[at]],atfixed=true;
			}
			while(!used[hroot[at]]) {
				used[hroot[at]]=true,usedlst[nused++]=hroot[at],firstidx[hroot[at]]=hidx[at],lastidx[hroot[at]]=hidx[par[desc[hroot[at]]]],firstfixed[hroot[at]]=atfixed,lastfixed[hroot[at]]=true;
				if(firstidx[hroot[at]]>lastidx[hroot[at]]) swap(firstidx[hroot[at]],lastidx[hroot[at]]),swap(firstfixed[hroot[at]],lastfixed[hroot[at]]);
				lim=min(lim,getlim(at));
				at=desc[hroot[at]],atfixed=true;
			}
			if(hidx[at]<=firstidx[hroot[at]]) {
				if(firstidx[hroot[at]]==lastidx[hroot[at]]&&firstfixed[hroot[at]]) swap(firstfixed[hroot[at]],lastfixed[hroot[at]]);
				if(firstfixed[hroot[at]]&&(atfixed||hidx[at]<firstidx[hroot[at]])) { lim=curval[oat]; break; }
				firstidx[hroot[at]]=hidx[at]; if(atfixed) firstfixed[hroot[at]]=true;
			} else if(hidx[at]>=lastidx[hroot[at]]) {
				if(firstidx[hroot[at]]==lastidx[hroot[at]]&&lastfixed[hroot[at]]) swap(firstfixed[hroot[at]],lastfixed[hroot[at]]);
				if(lastfixed[hroot[at]]&&(atfixed||hidx[at]>lastidx[hroot[at]])) { lim=curval[oat]; break; }
				lastidx[hroot[at]]=hidx[at]; if(atfixed) lastfixed[hroot[at]]=true;
			}
			if(atfixed&&firstidx[hroot[at]]<hidx[at]&&hidx[at]<lastidx[hroot[at]]) { lim=curval[oat]; break; }
			lim=min(lim,getlim(at));
			if(lim<=curval[oat]) { lim=curval[oat]; break; }
		}
		//printf("after %d at %d (lim=%d):",curval[oat],oat+1,lim); REP(i,n) if(used[i]) printf(" %d=%c%d..%d%c",i+1,firstfixed[i]?'[':'(',hlst[firstidx[i]]+1,hlst[lastidx[i]]+1,lastfixed[i]?']':')'); puts("");
	}
	REP(i,nused) used[usedlst[i]]=false;
	REP(i,nanc) anc[anclst[i]]=false;
	return lim;
}

void solve() {
	REP(i,n) ch[i].clear(); REP(i,n) if(par[i]!=-1) ch[par[i]].PB(i);
	dfsinit(0);
	nh=0; REP(i,n) if(par[i]==-1||i!=heavy[par[i]]) { hsz[i]=0; for(int at=i;at!=-1;at=heavy[at]) hroot[at]=i,hlst[nh]=at,hidx[at]=nh,++nh,++hsz[i]; }
	//REP(i,n) printf("%d: par=%d sz=%d heavy=%d hroot=%d hidx=%d\n",i+1,par[i]+1,sz[i],heavy[i]+1,hroot[i]+1,hidx[i]);
	//printf("hlst:"); REP(i,nh) printf(" %d",hlst[i]+1); puts("");

	REP(i,n) curval[i]=initval[i],pos[curval[i]]=i;
	REP(i,n) pathvals[i]=priority_queue<pair<int,int>>();
	REP(i,n) pathvals[hroot[i]].push(MP(-curval[i],i));
	pathmins.clear(); REP(i,n) if(i==hroot[i]) pathmin[i]=-pathvals[i].top().first,pathmins.insert(MP(pathmin[i],i));

	//printf("pathmins: "); for(auto it=pathmins.begin();it!=pathmins.end();++it) printf("(%d=%d)",it->second+1,it->first); puts("");
	REP(i,n) used[i]=anc[i]=false;
	sinit(0,0,n-1);
	REP(i,nq) {
		if(qkind[i]==1) {
			int a=qa[i],b=qb[i];
			swap(curval[a],curval[b]); swap(pos[curval[a]],pos[curval[b]]);
			pathvals[hroot[a]].push(MP(-curval[a],a));
			pathvals[hroot[b]].push(MP(-curval[b],b));
			updatepath(hroot[a]);
			updatepath(hroot[b]);
			supd(0,0,n-1,hidx[a]);
			supd(0,0,n-1,hidx[b]);
			//printf("pathmins: "); for(auto it=pathmins.begin();it!=pathmins.end();++it) printf("(%d=%d)",it->second+1,it->first); puts("");
		}
		if(qkind[i]==2) {
			qans[i]=calcmex();
		}
	}
	

}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&initval[i]);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	scanf("%d",&nq);
	REP(i,nq) { scanf("%d",&qkind[i]); if(qkind[i]==1) scanf("%d%d",&qa[i],&qb[i]),--qa[i],--qb[i]; }
	solve();
	REP(i,nq) if(qkind[i]==2) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}