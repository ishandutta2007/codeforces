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

const int MAXN=100000;
const int MAXLEN=500000+MAXN;
const int MAXX=1+2*MAXLEN;
const int NALPH=27;

typedef struct X {
	int nxt[NALPH];
	int len,suff;
} X;

// a node represents a range of factors (abcd)efgh -> 
// for each factor s: calculate |s|*sum(ci*psi)
// for each factor s: calculate |s|*sum(ci*#(u | su=is a suffix of t[i]))
// for each factor s: calculate |s|*sum(ci*#(u | |su|<=|t[i]| and su leads to a suffix of t[0]t[1]..t[i] in the suffix automaton))

// sum(ci*#(u | su leads to a suffix of t[0]t[1]..t[i] in the suffix automaton))
// -sum(ci*#(u | and su leads to a suffix of t[0]t[1]..t[i-1] in the suffix automaton))
// -sum(ci*#(u | |u|<|t[i]| && |s|+|u|>|t[i]| and su leads to a suffix of t[0]t[1]..t[i] in the suffix automaton))


X x[MAXX]; int nx,root;
int getx(int len) { assert(nx<MAXX); memset(x[nx].nxt,-1,sizeof(x[nx].nxt)),x[nx].len=len,x[nx].suff=-1; return nx++; }
bool been[MAXX];
ll A[MAXX],B[MAXX]; int mxlen[MAXX];
int deg[MAXX];
int q[MAXX],qhead,qtail;

void build(char *s) {
	nx=0; root=getx(0);
	for(int last=root,cur=-1,at=-1;*s!='\0';++s,last=cur) {
		int c=*s-'a';
		cur=getx(x[last].len+1);
		for(at=last;at!=-1&&x[at].nxt[c]==-1;at=x[at].suff) x[at].nxt[c]=cur;
		if(at==-1) { x[cur].suff=root; continue; }
		int to=x[at].nxt[c];
		if(x[at].len+1==x[to].len) { x[cur].suff=to; continue; }
		int cp=getx(x[at].len+1); REP(i,NALPH) x[cp].nxt[i]=x[to].nxt[i]; x[cp].suff=x[to].suff;
		for(;at!=-1&&x[at].nxt[c]==to;at=x[at].suff) x[at].nxt[c]=cp;
		x[to].suff=cp; x[cur].suff=cp;
	}
}
void dfs(int at) {
	if(been[at]) return; else been[at]=true;
	B[at]=A[at];
	REP(i,26) if(x[at].nxt[i]!=-1) {
		dfs(x[at].nxt[i]);
		B[at]+=B[x[at].nxt[i]];
	}
}


int n;
char s[MAXLEN+1];
int idx[MAXN+1],val[MAXN];


void run() {
	scanf("%d",&n); idx[0]=0;
	REP(i,n) { scanf("%s",s+idx[i]); idx[i+1]=idx[i]+strlen(s+idx[i])+1; s[idx[i+1]-1]='{'; } s[idx[n]]='\0';
	REP(i,n) scanf("%d",&val[i]);

	//printf("%s\n",s);
	build(s);
	REP(i,nx) A[i]=B[i]=0,been[i]=false,deg[i]=0;
	{ int at=root; REP(i,n) { FOR(j,idx[i],idx[i+1]-1) at=x[at].nxt[s[j]-'a']; A[at]+=val[i]; at=x[at].nxt['{'-'a']; } }
	REP(i,nx) if(x[i].suff!=-1) ++deg[x[i].suff];
	qhead=qtail=0; REP(i,nx) if(deg[i]==0) q[qhead++]=i;
	while(qtail<qhead) {
		int at=q[qtail++];
		if(x[at].suff==-1) continue;
		A[x[at].suff]+=A[at];
		if(--deg[x[at].suff]==0) q[qhead++]=x[at].suff;
	}
	dfs(root);
	REP(i,nx) deg[i]=0,mxlen[i]=-1; REP(i,nx) REP(j,NALPH) if(x[i].nxt[j]!=-1) ++deg[x[i].nxt[j]];
	qhead=qtail=0; mxlen[root]=0; q[qhead++]=root;
	while(qtail<qhead) {
		int at=q[qtail++];
		REP(j,NALPH) if(x[at].nxt[j]!=-1) {
			if(mxlen[at]!=-1&&j<26&&mxlen[at]+1>mxlen[x[at].nxt[j]]) mxlen[x[at].nxt[j]]=mxlen[at]+1;
			if(--deg[x[at].nxt[j]]==0) q[qhead++]=x[at].nxt[j];
		}
	}
	//REP(i,nx) { printf("%d:",i); REP(j,NALPH) if(x[i].nxt[j]!=-1) printf(" %c->%d",'a'+j,x[i].nxt[j]); printf(" (len:%d..%d[%d],suff:%d,A:%lld,B:%lld)\n",x[i].suff==-1?0:x[x[i].suff].len+1,x[i].len,mxlen[i],x[i].suff,A[i],B[i]); }
	ll ret=0; REP(i,nx) if(mxlen[i]!=-1) { ll cur=mxlen[i]*B[i]; if(cur>ret) ret=cur; } printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}