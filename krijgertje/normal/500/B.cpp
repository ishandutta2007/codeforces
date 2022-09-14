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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n;
int p[300];
char A[300][300];

int comp[300],ncomp;
int q[300],qhead,qtail;

int have[300];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&p[i]); REP(i,n) REP(j,n) scanf(" %c",&A[i][j]);
	REP(i,n) comp[i]=-1; ncomp=0;
	REP(i,n) if(comp[i]==-1) {
		comp[i]=ncomp++;
		qhead=qtail=0; q[qhead++]=i;
		while(qtail<qhead) {
			int at=q[qtail++];
			REP(to,n) if(A[at][to]=='1'&&comp[to]==-1) { comp[to]=comp[at]; q[qhead++]=to; }
		}
		int cnt=qhead;
		sort(q,q+cnt);
		REP(j,cnt) have[j]=p[q[j]];
		sort(have,have+cnt);
		REP(j,cnt) p[q[j]]=have[j];
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",p[i]); } puts("");
}

int main() {
	run();
	return 0;
}