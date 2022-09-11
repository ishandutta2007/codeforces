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

const int MAXQ=1000;

int scnt,sidx,limcnt,nq;
int qkind[MAXQ],qx[MAXQ];
int qcnt[MAXQ],qidx[MAXQ];

void solve() {
	int cnt=scnt,idx=sidx;
	REP(i,nq) {
		int x=qx[i];
		if(qkind[i]==0) {
			if(idx<=x) cnt=x; else idx-=x,cnt-=x;
		}
		if(qkind[i]==1) {
			if(x<=idx) ++idx,++cnt; else ++cnt;
		}
		qcnt[i]=cnt,qidx[i]=idx;
	}
}

void run() {
	scanf("%d%d%d%d",&scnt,&sidx,&limcnt,&nq);
	REP(i,nq) scanf("%d%d",&qkind[i],&qx[i]);
	solve();
	REP(i,nq) printf("%d %d\n",qcnt[i],qidx[i]);
}

int main() {
	run();
	return 0;
}