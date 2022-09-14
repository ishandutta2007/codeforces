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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;
const int MAXM=MAXN-1;
const int MAXCOMP=MAXN;
const int MAXVAL=MAXN;

int n;
int fst[MAXN];
int nxt[2*MAXM];
int to[2*MAXM];
int len[MAXM];

int root;
int sz[MAXN];

void dfs1(int at,int par) {
	sz[at]=1;
	int maxsz=0;
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		if(to[x]==par) continue;
		dfs1(to[x],at);
		if(sz[to[x]]>maxsz) maxsz=sz[to[x]];
		sz[at]+=sz[to[x]];
	}
	if(n-sz[at]>maxsz) maxsz=n-sz[at];
	if(root==-1&&2*maxsz<=n) root=at;
}

int ncomp;
int comp[MAXN];
int compstart[MAXCOMP];
int compsz[MAXCOMP];
int compnodes[MAXN];
int compin[MAXCOMP];
int compout[MAXCOMP];
ll d[MAXN];

void dfs2(int at,int par) {
	comp[at]=ncomp; compnodes[compstart[ncomp]+compsz[ncomp]++]=at;
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		if(to[x]==par) continue;
		d[to[x]]=d[at]+len[x/2];
		dfs2(to[x],at);
	}
}

int out[MAXN],in[MAXN];
int cntcomp[MAXVAL+1];
int fstcomp[MAXVAL+1];
int nxtcomp[MAXCOMP];
int prvcomp[MAXCOMP];
int atcomp[MAXCOMP];
int at1,at2;

void insertcomp(int x) {
	int val=compin[x]+compout[x];
	cntcomp[val]++;
	prvcomp[x]=-1; nxtcomp[x]=fstcomp[val]; if(nxtcomp[x]!=-1) prvcomp[nxtcomp[x]]=x; fstcomp[val]=x;
}
void removecomp(int x) {
	int val=compin[x]+compout[x];
	cntcomp[val]--;
	if(prvcomp[x]!=-1) nxtcomp[prvcomp[x]]=nxtcomp[x]; else fstcomp[val]=nxtcomp[x];
	if(nxtcomp[x]!=-1) prvcomp[nxtcomp[x]]=prvcomp[x];
	prvcomp[x]=nxtcomp[x]=-1;
}
void printcomps() {
	REPE(i,n) if(cntcomp[i]!=0) { printf("%d (%d):",i,cntcomp[i]); for(int x=fstcomp[i];x!=-1;x=nxtcomp[x]) printf(" %d",x); puts(""); }
}


void run() {
	scanf("%d",&n);
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; len[i]=c;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}

	root=-1;
	dfs1(0,-1);
	assert(root!=-1);
	//printf("%d\n",root);

	ncomp=0; comp[root]=-1; d[root]=0;
	for(int x=fst[root];x!=-1;x=nxt[x]) { compstart[ncomp]=ncomp==0?0:compstart[ncomp-1]+compsz[ncomp-1]; compsz[ncomp]=0; d[to[x]]=len[x/2]; dfs2(to[x],root); ++ncomp; }
	REP(i,ncomp) sort(compnodes+compstart[i],compnodes+compstart[i]+compsz[i]);
	REP(i,ncomp) compin[i]=compout[i]=compsz[i];
	//REP(i,n) printf("%d: %d / %d\n",i,comp[i],d[i]);
	//REP(i,ncomp) { printf("%d:",i); REP(j,compsz[i]) printf(" %d",compnodes[compstart[i]+j]); puts(""); }

	REP(i,n) out[i]=in[i]=-1;
	REPE(i,n) cntcomp[i]=0,fstcomp[i]=-1;
	REP(i,ncomp) nxtcomp[i]=prvcomp[i]=-1;
	REP(i,ncomp) insertcomp(i);
	REP(i,ncomp) atcomp[i]=0; at1=at2=0;
	//printcomps();
	int rem=n;
	REP(i,n) {
		int fixcomp=-1; 
		for(int x=fstcomp[rem];x!=-1;x=nxtcomp[x]) {
			if(comp[i]==x) continue;
			assert(fixcomp==-1);
			fixcomp=x;
		}
		int j;
		if(fixcomp!=-1) {
			while(atcomp[fixcomp]<compsz[fixcomp]&&in[compnodes[compstart[fixcomp]+atcomp[fixcomp]]]!=-1) ++atcomp[fixcomp];
			assert(atcomp[fixcomp]<compsz[fixcomp]);
			j=compnodes[compstart[fixcomp]+atcomp[fixcomp]];
		} else {
			while(at1<n&&in[at1]!=-1) ++at1;
			while(at2<n&&(in[at2]!=-1||at1<n&&comp[at1]==comp[at2])) ++at2;
			assert(at1<n); assert(i==root||comp[at1]!=comp[i]||at2<n&&comp[at2]!=comp[i]);
			j=i==root||comp[at1]!=comp[i]?at1:at2;
		}
		//printf("%d: fixcomp=%d -> %d\n",i,fixcomp,j);
		out[i]=j; in[j]=i;
		if(comp[i]!=-1) { removecomp(comp[i]); --compout[comp[i]]; insertcomp(comp[i]); }
		if(comp[j]!=-1) { removecomp(comp[j]); --compin[comp[j]]; insertcomp(comp[j]); }
		//printcomps();
		--rem;
	}
	ll dsum=0; REP(i,n) dsum+=d[i]; cout<<2*dsum<<endl;
	REP(i,n) { if(i!=0) printf(" "); printf("%d",out[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}