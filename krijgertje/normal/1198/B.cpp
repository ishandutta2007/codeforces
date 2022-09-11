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

int n;
int initbal[MAXN];
int nq;
int qkind[MAXQ],qidx[MAXQ],qval[MAXQ];
int ans[MAXN];


void solve() {
	REP(i,n) ans[i]=-1;
	int mxpayout=0;
	for(int i=nq-1;i>=0;--i) {
		if(qkind[i]==1) {
			int who=qidx[i],val=qval[i];
			if(ans[who]!=-1) continue;
			ans[who]=max(mxpayout,val);
		}
		if(qkind[i]==2) {
			int val=qval[i];
			mxpayout=max(mxpayout,val);
		}
	}
	REP(who,n) if(ans[who]==-1) ans[who]=max(mxpayout,initbal[who]);
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&initbal[i]);
	scanf("%d",&nq);
	REP(i,nq) { scanf("%d",&qkind[i]); if(qkind[i]==1) scanf("%d%d",&qidx[i],&qval[i]),--qidx[i]; if(qkind[i]==2) scanf("%d",&qval[i]); }
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}