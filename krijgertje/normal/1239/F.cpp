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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXN=500000;
const int MAXCOMP=MAXN;

int n,m;
vector<int> adj[MAXN];
vector<int> anssteal;

int col[MAXN];
bool keep[MAXN];

void buildans() { anssteal.clear(); REP(i,n) if(!keep[i]) anssteal.PB(i); }

int par[MAXN],dep[MAXN],comp[MAXN],ncomp;
vector<pair<int,int>> cycedges;

int lastseenby[MAXCOMP];
vector<int> compones[MAXCOMP];
vector<int> onlyones[MAXCOMP];

bool debug=false;


void dfscyc(int at) {
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(col[to]!=2||to==par[at]||par[to]!=-2&&dep[to]>dep[at]) continue;
		if(par[to]==-2) {
			par[to]=at; dep[to]=dep[at]+1; comp[to]=comp[at]; dfscyc(to);
		} else {
			cycedges.PB(MP(at,to));
		}
	}
}

bool aadj[MAXN];
bool badj[MAXN];

void makepath(int a,int b,int c) {
	if(debug) printf("makepath(%d,%d,%d)\n",a+1,b+1,c);
	int aa=-1; REPSZ(i,adj[a]) { int to=adj[a][i]; if(col[to]==2&&comp[to]==c&&(aa==-1||dep[to]<dep[aa])) aa=to; } assert(aa!=-1);
	int bb=-1; REPSZ(i,adj[b]) { int to=adj[b][i]; if((a!=b||to!=aa)&&col[to]==2&&comp[to]==c&&(bb==-1||dep[to]<dep[bb])) bb=to; } assert(bb!=-1);
	if(dep[aa]<dep[bb]) swap(aa,bb),swap(a,b);
	REP(i,n) aadj[i]=false; REPSZ(i,adj[a]) { int to=adj[a][i]; aadj[to]=true; }
	REP(i,n) badj[i]=false; REPSZ(i,adj[b]) { int to=adj[b][i]; badj[to]=true; }
	keep[a]=keep[b]=true;
	while(dep[aa]>dep[bb]) { keep[aa]=true; if(badj[aa]&&a!=b) return; aa=par[aa]; }
	if(aadj[bb]&&a!=b) { keep[bb]=true; return; }
	keep[aa]=keep[bb]=true;
	while(aa!=bb) aa=par[aa],bb=par[bb],keep[aa]=keep[bb]=true;
}


bool solve() {
	REP(i,n) col[i]=SZ(adj[i])%3;
	REP(i,n) keep[i]=false;
	REP(i,n) if(col[i]==0) { keep[i]=true; buildans(); return SZ(anssteal)>0; }
	REP(at,n) REPSZ(i,adj[at]) { int to=adj[at][i]; if(col[at]==1&&col[to]==1) { keep[at]=keep[to]=true; buildans(); return SZ(anssteal)>0; } }

	REP(i,n) par[i]=-2;
	ncomp=0;
	REP(i,n) if(col[i]==2&&par[i]==-2) { par[i]=-1; dep[i]=0; comp[i]=ncomp++; dfscyc(i); }
	if(debug) { REP(i,n) if(par[i]!=-2) printf("%d: par=%d dep=%d\n",i+1,par[i]+1,dep[i]); }
	if(debug) { printf("cycedges:"); REPSZ(i,cycedges) printf(" (%d,%d)",cycedges[i].first+1,cycedges[i].second+1); puts(""); }
	if(SZ(cycedges)>=1) {
		pair<int,int> highest=cycedges[0];
		FORSZ(i,1,cycedges) if(dep[cycedges[i].first]<dep[highest.first]||dep[cycedges[i].first]==dep[highest.first]&&dep[cycedges[i].second]>dep[highest.second]) highest=cycedges[i];
		if(debug) { printf("highest=(%d,%d)\n",highest.first+1,highest.second+1); }
		cycedges.clear();
		for(int x=highest.first;;x=par[x]) { keep[x]=true; if(x==highest.second) break; } buildans(); return SZ(anssteal)>0;
	}

	REP(i,ncomp) lastseenby[i]=-1;
	REP(at,n) if(col[at]==1) REPSZ(i,adj[at]) { int to=adj[at][i]; if(col[to]!=2||lastseenby[comp[to]]==at) continue; lastseenby[comp[to]]=at; compones[comp[to]].PB(at); }
	REP(i,ncomp) if(SZ(compones[i])>=2) {
		int a=compones[i][0],b=compones[i][1];
		REP(k,ncomp) compones[k].clear();
		makepath(a,b,i); buildans(); return SZ(anssteal)>0;
	}
	REP(k,ncomp) compones[k].clear();

	int onlyone=-1; REP(i,n) if(col[i]==1) { assert(onlyone==-1); onlyone=i; } if(onlyone==-1) return false;
	REPSZ(i,adj[onlyone]) { int to=adj[onlyone][i]; if(col[to]==2) onlyones[comp[to]].PB(to); }
	int c1=-1,c2=-1;
	REP(i,ncomp) if(SZ(onlyones[i])>=2) { if(c1==-1) c1=i; else if(c2==-1) c2=i; }
	REP(k,ncomp) onlyones[k].clear();
	if(c1==-1||c2==-1) return false;
	makepath(onlyone,onlyone,c1);
	makepath(onlyone,onlyone,c2);
	buildans();
	return SZ(anssteal)>0;
}

int ncase;

void run(int casenr) {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	bool ans=solve();
	REP(i,n) adj[i].clear();
	printf("%s\n",ans?"Yes":"No");
	if(ans) { printf("%d\n",SZ(anssteal)); REPSZ(i,anssteal) { if(i!=0) printf(" "); printf("%d",anssteal[i]+1); } puts(""); }
}

int main() {
	scanf("%d",&ncase); FORE(i,1,ncase) run(i);
	return 0;
}