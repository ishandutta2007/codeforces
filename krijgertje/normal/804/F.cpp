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

const int MAXN=5000;
const int MAXS=2000000;
const int MOD=1000000007;

int n,A,B;
char g[MAXN][MAXN+1];
int off[MAXN+1],cnt[MAXN];
char s[MAXS+1];

vector<int> compnodes[MAXN];
int comp[MAXN],ncomp;
int id[MAXN],lid[MAXN],nid;
int stck[MAXN],nstck;
bool done[MAXN];
int top[MAXN],ntop;

bool have[MAXS];
int gcomp[MAXN];
int mn[MAXN],mx[MAXN];
pair<int,int> o[MAXN];
priority_queue<int> q;

int C[MAXN+1][MAXN+1];

void tarjan(int at) {
	id[at]=lid[at]=nid++; stck[nstck++]=at;
	REP(to,n) if(g[at][to]=='1') {
		if(id[to]==-1) {
			tarjan(to);
			if(lid[to]<lid[at]) lid[at]=lid[to];
		} else if(comp[to]==-1) {
			if(id[to]<lid[at]) lid[at]=id[to];
		}
	}
	//printf("%d: lid=%d id=%d\n",at,lid[at],id[at]); 
	if(lid[at]>=id[at]) {
		//REP(i,nstck) printf(" %d",stck[i]); puts("");
		compnodes[ncomp].clear();
		while(comp[at]==-1) comp[stck[--nstck]]=ncomp,compnodes[ncomp].PB(stck[nstck]); ++ncomp;
	}
}
void dfstop(int c) {
	done[c]=true;
	REPSZ(i,compnodes[c]) {
		int at=compnodes[c][i];
		REP(to,n) if(g[at][to]=='1'&&!done[comp[to]]) dfstop(comp[to]);
	}
	top[ntop++]=c;
}


void run() {
	scanf("%d%d%d",&n,&A,&B);
	REP(i,n) scanf("%s",g[i]);
	off[0]=0; REP(i,n) { scanf("%d%s",&cnt[i],s+off[i]); off[i+1]=off[i]+cnt[i]; }

	REP(i,n) comp[i]=id[i]=-1; nid=nstck=ncomp=0;
	REP(i,n) if(comp[i]==-1) tarjan(i);
	ntop=0; REP(i,ncomp) done[i]=false; REP(i,ncomp) if(!done[i]) dfstop(i); assert(ntop==ncomp); reverse(top,top+ntop);
	//REP(i,ncomp) { int c=top[i]; printf("%d:",c); REPSZ(j,compnodes[c]) printf(" %d",compnodes[c][j]+1); puts(""); }

	REP(i,ncomp) { int c=top[i]; int g=0; REPSZ(j,compnodes[c]) { int at=compnodes[c][j]; g=gcd(g,cnt[at]); } gcomp[c]=g; }
	REP(i,ncomp) {
		int c=top[i];
		{
			int g=gcomp[c];
			REP(i,g) have[i]=false; REPSZ(j,compnodes[c]) { int at=compnodes[c][j]; REP(k,cnt[at]) if(s[off[at]+k]!='0') have[k%g]=true; }
			REPSZ(j,compnodes[c]) { int at=compnodes[c][j]; REP(k,cnt[at]) if(s[off[at]+k]=='0'&&have[k%g]) s[off[at]+k]='F'; }
		}
		if(i+1<ncomp) {
			int nc=top[i+1];
			int g=gcd(gcomp[c],gcomp[nc]);
			REP(i,g) have[i]=false; REPSZ(j,compnodes[c]) { int at=compnodes[c][j]; REP(k,cnt[at]) if(s[off[at]+k]!='0') have[k%g]=true; }
			REPSZ(j,compnodes[nc]) { int at=compnodes[nc][j]; REP(k,cnt[at]) if(s[off[at]+k]=='0'&&have[k%g]) s[off[at]+k]='F'; }			
		}
	}
	//REP(i,n) { if(i!=0) printf("|"); REP(j,cnt[i]) printf("%c",s[off[i]+j]); } puts("");

	REPE(i,n) { C[i][0]=C[i][i]=1; FOR(j,1,i) if((C[i][j]=C[i-1][j-1]+C[i-1][j])>=MOD) C[i][j]-=MOD; }
	REP(i,n) { mn[i]=mx[i]=0; REP(j,cnt[i]) if(s[off[i]+j]=='1') ++mn[i],++mx[i]; else if(s[off[i]+j]=='F') ++mx[i]; }
	REP(i,n) o[i]=MP(-mx[i],i); sort(o,o+n); REP(i,n) o[i].first=-o[i].first;
	q=priority_queue<int>(); int nopt=0,nalways=0;
	int ret=0;
	REP(i,n) {
		int at=o[i].second;
		while(SZ(q)>0&&q.top()>mx[at]) --nopt,++nalways,q.pop();
		if(nalways<A&&nalways+nopt>=B-1) {
			FORE(j,max(0,B-1-nalways),min(min(B-1,nopt),A-1-nalways)) ret=(ret+(ll)C[nopt][j]*C[nalways][B-1-j])%MOD;
		}
		++nopt; q.push(mn[at]);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}