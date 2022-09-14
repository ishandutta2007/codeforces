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

const int MAXBIT=29;
const int MAXQ=200000;
const int MAXZ=(MAXBIT+1)*MAXQ+1;


typedef struct Z { int c[2],tcnt; } Z;

Z z[MAXZ]; int nz;

int createz() { assert(nz<MAXZ); int ret=nz++; z[ret].c[0]=z[ret].c[1]=-1,z[ret].tcnt=0; return ret; }
void update(int at,int val,int bit,int by) {
	z[at].tcnt+=by;
	if(bit<0) return;
	int ci=(val>>bit)&1;
	if(z[at].c[ci]==-1) z[at].c[ci]=createz();
	update(z[at].c[ci],val,bit-1,by);
}
int find(int at,int val,int bit) {
	if(bit<0) return 0;
	int ci=1-((val>>bit)&1);
	if(z[at].c[ci]==-1||z[z[at].c[ci]].tcnt<=0) ci=1-ci;
	assert(z[at].c[ci]!=-1&&z[z[at].c[ci]].tcnt>0);
	//if(bit<=5) printf("\tfinding %d %d %d -> %d\n",at,val,bit,ci);
	return find(z[at].c[ci],val,bit-1)+(ci<<bit);
}

void run() {
	nz=0; createz();
	update(0,0,MAXBIT,+1);
	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		char c; int x; scanf(" %c%d",&c,&x);
		if(c=='+') update(0,x,MAXBIT,+1);
		if(c=='-') update(0,x,MAXBIT,-1);
		if(c=='?') { int y=find(0,x,MAXBIT); printf("%d\n",x^y); }
	}
}

int main() {
	run();
	return 0;
}