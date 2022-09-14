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

const int MAXSLEN=100000;
const int MAXN=100000;
const int MAXX=2*MAXSLEN+1;

int n,len;
char s[MAXSLEN+1];
int off[MAXN+1],val[MAXN];

int nx,root;
int nxt[MAXX][26];
int id[MAXN],rid[MAXN];
int phead[MAXX],pnxt[MAXN];
int qhead[MAXX],qnxt[MAXN];
int rhead[MAXX],rnxt[MAXN];
int addx() { assert(nx<MAXX); REP(i,26) nxt[nx][i]=-1; phead[nx]=qhead[nx]=rhead[nx]=-1; return nx++; }

int p[MAXN],np;
int q[MAXN],nq;
int r[MAXN],nr;

ll solve() {
	nx=0; root=addx();
	REP(i,n) {
		{ int at=root; REP(j,len) { int y=s[off[i]+j]-'a'; if(nxt[at][y]==-1) nxt[at][y]=addx(); at=nxt[at][y]; } id[i]=at; }
		{ int at=root; REP(j,len) { int y=s[off[i]+len-j-1]-'a'; if(nxt[at][y]==-1) nxt[at][y]=addx(); at=nxt[at][y]; } rid[i]=at; }
		if(id[i]==rid[i]) {
			int a=id[i];
			pnxt[i]=phead[a],phead[a]=i;
		} else {
			int a=min(id[i],rid[i]);
			if(id[i]==a) qnxt[i]=qhead[a],qhead[a]=i; else rnxt[i]=rhead[a],rhead[a]=i;
		}
	}

	ll ret=0; int mxcenter=0;
	REP(i,nx) if(phead[i]!=-1) {
		np=0; for(int a=phead[i];a!=-1;a=pnxt[a]) p[np++]=val[a]; sort(p,p+np); reverse(p,p+np);
		int at=0;
		while(at+1<np&&p[at]>=0&&p[at+1]>=0) { ret+=p[at]+p[at+1]; at+=2; }
		if(at+1<np) {
			int cur=p[at]+p[at+1];
			if(cur>=0) { ret+=cur; if(-p[at+1]>mxcenter) mxcenter=-p[at+1]; } else if(p[at]>mxcenter) mxcenter=p[at];
		} else if(at<np) {
			if(p[at]>mxcenter) mxcenter=p[at];
		}
	}
	ret+=mxcenter;
	REP(i,nx) if(qhead[i]!=-1||rhead[i]!=-1) {
		nq=0; for(int a=qhead[i];a!=-1;a=qnxt[a]) q[nq++]=val[a]; sort(q,q+nq); reverse(q,q+nq);
		nr=0; for(int a=rhead[i];a!=-1;a=rnxt[a]) r[nr++]=val[a]; sort(r,r+nr); reverse(r,r+nr);
		int mx=min(nq,nr);
		REP(j,mx) { int cur=q[j]+r[j]; if(cur>0) ret+=cur; }
	}
	return ret;

}

void run() {
	scanf("%d%d",&n,&len);
	off[0]=0; REP(i,n) { scanf("%s%d",s+off[i],&val[i]); off[i+1]=off[i]+len; }
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}