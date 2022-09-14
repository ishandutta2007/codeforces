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

const int MAXN=300000;
const int MAXM=300000;

int n,m,deg0;
int fhead[MAXN],fnxt[2*MAXM],fto[2*MAXM];

int q[MAXN],nq;
int r[MAXN],nr;
int mark[MAXN],curmark;
void markadj(int at) { ++curmark; for(int x=fhead[at];x!=-1;x=fnxt[x]) mark[fto[x]]=curmark; }

void run() {
	scanf("%d%d%d",&n,&m,&deg0);
	REP(i,n) fhead[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		fnxt[2*i+0]=fhead[a]; fhead[a]=2*i+0; fto[2*i+0]=b;
		fnxt[2*i+1]=fhead[b]; fhead[b]=2*i+1; fto[2*i+1]=a;
	}

	nq=0; FOR(i,1,n) q[nq++]=i;
	int mn=0,mx=0; curmark=-1; memset(mark,-1,sizeof(mark));
	while(nq>0) {
		nr=0; int cnt0=0;
		r[nr++]=q[--nq];
		REP(i,nr) {
			markadj(r[i]); int nnq=0; if(mark[0]!=curmark) ++cnt0;
			REP(j,nq) if(mark[q[j]]!=curmark) r[nr++]=q[j]; else q[nnq++]=q[j];
			nq=nnq;
		}
		//printf("%d:",cnt0); REP(i,nr) printf(" %d",r[i]); puts("");
		if(cnt0==0) { printf("impossible\n"); return; }
		mn++,mx+=cnt0;
	}
	//printf("%d %d\n",mn,mx);
	if(deg0<mn||deg0>mx) { printf("impossible\n"); return; }
	printf("possible\n");
}

int main() {
	run();
	return 0;
}