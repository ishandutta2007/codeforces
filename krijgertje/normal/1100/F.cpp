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

const int MAXN=500000;
const int MAXQ=500000;
const int MAXBIT=19;

int n;
int a[MAXN];
int nq;
int ql[MAXQ],qr[MAXQ],qans[MAXQ];

int bval[MAXBIT+1]; int bidx[MAXBIT+1];
vector<int> byr[MAXN];

void badd(int val,int idx) {
	for(int i=MAXBIT;i>=0;--i) {
		if((val&(1<<i))==0) continue;
		if(bidx[i]==-1) { bval[i]=val; bidx[i]=idx; return; }
		if(idx>bidx[i]) swap(val,bval[i]),swap(idx,bidx[i]);
		val^=bval[i];
	}
}
int bget(int lidx) {
	int ret=0;
	for(int i=MAXBIT;i>=0;--i) if(bidx[i]!=-1&&bidx[i]>=lidx&&(ret^bval[i])>ret) ret^=bval[i];
	return ret;
}


void solve() {
	REPE(i,MAXBIT) bidx[i]=-1;
	REP(i,n) byr[i].clear(); REP(i,nq) byr[qr[i]].PB(i);
	REP(i,n) {
		badd(a[i],i);
		REPSZ(j,byr[i]) { int qi=byr[i][j]; qans[qi]=bget(ql[qi]); }
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i];
	solve();
	REP(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}