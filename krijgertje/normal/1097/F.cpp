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

const int MAXSETS=100000;
const int MAXVAL=7000;
const int MAXQ=1000000;

int nsets,nq;
int qkind[MAXQ],qx[MAXQ],qy[MAXQ],qz[MAXQ],qv[MAXQ],qans[MAXQ];


bitset<MAXVAL+1> vmult[MAXVAL+1];
bitset<MAXVAL+1> vcnt[MAXVAL+1];
bitset<MAXVAL+1> setmult[MAXSETS];

void init() {
	FORE(i,1,MAXVAL) { vmult[i].reset(); for(int j=1;j<=i;++j) if(i%j==0) vmult[i].set(j); }
	for(int i=MAXVAL;i>=1;--i) { vcnt[i].reset(); vcnt[i].set(i); for(int j=i+i;j<=MAXVAL;j+=i) vcnt[i]^=vcnt[j]; }
}

void solve() {
	REP(i,nsets) setmult[i].reset();
	REP(i,nq) {
		if(qkind[i]==1) setmult[qx[i]]=vmult[qv[i]];
		if(qkind[i]==2) setmult[qx[i]]=setmult[qy[i]]^setmult[qz[i]];
		if(qkind[i]==3) setmult[qx[i]]=setmult[qy[i]]&setmult[qz[i]];
		if(qkind[i]==4) qans[i]=(setmult[qx[i]]&vcnt[qv[i]]).count()%2;
		//printf("%d:",i+1); REP(j,nsets) { printf(" {"); bool any=false; FORE(k,1,MAXVAL) if(setmult[j][k]) { if(any) printf(","); else any=true; printf("%d",k); } printf("}"); } puts("");
	}
}

void run() {
	scanf("%d%d",&nsets,&nq);
	REP(i,nq) { scanf("%d",&qkind[i]); if(qkind[i]==1||qkind[i]==4) scanf("%d%d",&qx[i],&qv[i]),--qx[i]; if(qkind[i]==2||qkind[i]==3) scanf("%d%d%d",&qx[i],&qy[i],&qz[i]),--qx[i],--qy[i],--qz[i]; }
	solve();
	REP(i,nq) if(qkind[i]==4) printf("%d",qans[i]); puts("");
}

int bfans[MAXQ];

void bfsolve() {
	vector<multiset<int>> sets(nsets);
	REP(i,nq) {
		if(qkind[i]==1) { sets[qx[i]].clear(); sets[qx[i]].insert(qv[i]); }
		if(qkind[i]==2) { multiset<int> a=sets[qy[i]],b=sets[qz[i]]; sets[qx[i]].clear(); for(auto ait=a.begin();ait!=a.end();++ait) sets[qx[i]].insert(*ait); for(auto bit=b.begin();bit!=b.end();++bit) sets[qx[i]].insert(*bit); }
		if(qkind[i]==3) { multiset<int> a=sets[qy[i]],b=sets[qz[i]]; sets[qx[i]].clear(); for(auto ait=a.begin();ait!=a.end();++ait) for(auto bit=b.begin();bit!=b.end();++bit) sets[qx[i]].insert(gcd(*ait,*bit)); }
		if(qkind[i]==4) { bfans[i]=sets[qx[i]].count(qv[i])%2; }
	}

}

void stress() {
	REP(rep,1000) {
		nsets=4,nq=20;
		REP(i,nq) { qkind[i]=rand()%4+1; if(qkind[i]==1||qkind[i]==4) qx[i]=rand()%nsets,qv[i]=rand()%24+1; else qx[i]=rand()%nsets,qy[i]=rand()%nsets,qz[i]=rand()%nsets; }
		solve();
		bfsolve();
		bool ok=true; REP(i,nq) if(qkind[i]==4&&qans[i]!=bfans[i]) ok=false;
		if(ok) { printf("."); continue; }
		printf("err rep=%d\n",rep);
		printf("%d %d\n",nsets,nq);
		REP(i,nq) { printf("%d ",qkind[i]); if(qkind[i]==1||qkind[i]==4) printf("%d %d",qx[i]+1,qv[i]); if(qkind[i]==2||qkind[i]==3) printf("%d %d %d",qx[i]+1,qy[i]+1,qz[i]+1); puts(""); }
		printf("have: "); REP(i,nq) if(qkind[i]==4) printf("%d",qans[i]); puts("");
		printf("want: "); REP(i,nq) if(qkind[i]==4) printf("%d",bfans[i]); puts("");
		break;
	}
}

int main() {
	init();
	run();
	//stress();
	return 0;
}