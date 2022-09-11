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

const int NCARDS=8;
const int NVALS=5;
const int NSTATE=495;

vector<vector<int> > states;
map<vector<int>,int> mp;
void genstates(vector<int> &v,int at,int rem) {
	if(at>=SZ(v)) { if(rem==0) { int id=SZ(states); states.PB(v); mp[v]=id; } return; }
	for(v[at]=0;v[at]<=rem;++v[at]) genstates(v,at+1,rem-v[at]);
}

int nxt[NSTATE][NVALS][NVALS];
vector<int> adj[NSTATE][NSTATE];
vector<int> radj[NSTATE][NSTATE];

int deg[NSTATE][NSTATE];
int dp[NSTATE][NSTATE];

int q[NSTATE*NSTATE],qhead,qtail;


void precalc() {
	states.clear(); mp.clear(); vector<int> state(NVALS,0); genstates(state,0,NCARDS); 
	//printf("%d\n",SZ(states));
	//REPSZ(i,states) { printf("%d:",i); REPSZ(j,states[i]) printf(" %d",states[i][j]); puts(""); }

	REPSZ(i,states) REP(a,NVALS) REP(b,NVALS) {
		if(states[i][a]==0) { nxt[i][a][b]=-1; continue; }
		vector<int> tmp=states[i]; tmp[a]--; tmp[b]++; assert(mp.count(tmp)); nxt[i][a][b]=mp[tmp];
	}

	REPSZ(i,states) REPSZ(j,states) {
		REP(a,NVALS) REP(b,NVALS) if(a*b!=0&&states[i][a]!=0&&states[j][b]!=0) {
			int c=(a+b)%NVALS; int ni=j,nj=nxt[i][a][c]; assert(nj!=-1); adj[i][j].PB(ni*NSTATE+nj);
			//printf("(%d,%d) -> (%d,%d)\n",i,j,ni,nj);
		}
		sort(adj[i][j].begin(),adj[i][j].end()); adj[i][j].erase(unique(adj[i][j].begin(),adj[i][j].end()),adj[i][j].end());
		REPSZ(k,adj[i][j]) { int ii=adj[i][j][k]/NSTATE,jj=adj[i][j][k]%NSTATE; radj[ii][jj].PB(i*NSTATE+j); }
	}

	int winid=SZ(states)-1;
	REPSZ(i,states) REPSZ(j,states) dp[i][j]=0,deg[i][j]=SZ(adj[i][j]);
	qhead=qtail=0;
	REPSZ(i,states) dp[i][winid]=-1,q[qhead++]=i*NSTATE+winid;
	while(qtail<qhead) {
		int i=q[qtail]/NSTATE,j=q[qtail]%NSTATE; ++qtail;
		//printf("at %d=",i); REP(x,NVALS) printf(" %d",states[i][x]); printf(" - %d=",j); REP(x,NVALS) printf(" %d",states[j][x]); printf(" = %d\n",dp[i][j]);
		REPSZ(k,radj[i][j]) {
			int ii=radj[i][j][k]/NSTATE,jj=radj[i][j][k]%NSTATE;
			//printf(" from %d=",ii); REP(x,NVALS) printf(" %d",states[ii][x]); printf(" - %d=",jj); REP(x,NVALS) printf(" %d",states[jj][x]); puts("");
			if(dp[ii][jj]!=0) continue;
			if(dp[i][j]==-1) { dp[ii][jj]=1; q[qhead++]=ii*NSTATE+jj; continue; }
			if(--deg[ii][jj]==0) { dp[ii][jj]=-1; q[qhead++]=ii*NSTATE+jj; continue; }
		}
	}
}

int fst;
int a[NCARDS],b[NCARDS];

void run() {
	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		scanf("%d",&fst); REP(i,NCARDS) scanf("%d",&a[i]); REP(i,NCARDS) scanf("%d",&b[i]);
		vector<int> acnt(NVALS,0),bcnt(NVALS,0); REP(i,NCARDS) acnt[a[i]]++,bcnt[b[i]]++;
		assert(mp.count(acnt)&&mp.count(bcnt)); int aid=mp[acnt],bid=mp[bcnt];
		int ans=fst==0?dp[aid][bid]:-dp[bid][aid];
		printf("%s\n",ans>0?"Alice":ans<0?"Bob":"Deal");
	}
}


int main() {
	precalc();
	run();
	return 0;
}