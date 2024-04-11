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

int n,npart;
int x[30000];

// |s1-s2|+|s2-s3|+|s3-s4|+...

int f[2][201][2]; // f[at][i][op] == max value when finished i parts (using op with previous part)
int g[2][200][2][2]; // g[at][i][op1][op2] == max value when working it on part i (op1 with part before, op2 with part after) [0=-,1=+]
#define CHANGE(a,b) if((b)>=a) a=(b);

void run() {
	scanf("%d%d",&n,&npart); REP(i,n) scanf("%d",&x[i]);

	int at=0;
	REPE(i,npart) REP(op,2) f[at][i][op]=i==0?0:INT_MIN;
	REP(i,npart) REP(op1,2) REP(op2,2) g[at][i][op1][op2]=INT_MIN;
	REP(j,n) {
		int to=1-at;
		REPE(i,npart) REP(op,2) f[to][i][op]=INT_MIN;
		REP(i,npart) REP(op1,2) REP(op2,2) g[to][i][op1][op2]=INT_MIN;
		REPE(i,npart) REP(op,2) if(f[at][i][op]!=INT_MIN) {
			CHANGE(f[to][i][op],f[at][i][op]);
			if(i!=npart) REP(op2,2) CHANGE(g[to][i][1-op][op2],f[at][i][op]+(i==0?0:1-op==0?-x[j]:+x[j])+(i==npart-1?0:op2==0?-x[j]:+x[j]));
		}
		REP(i,npart) REP(op1,2) REP(op2,2) if(g[at][i][op1][op2]!=INT_MIN) {
			CHANGE(g[to][i][op1][op2],g[at][i][op1][op2]+(i==0?0:op1==0?-x[j]:+x[j])+(i==npart-1?0:op2==0?-x[j]:+x[j]));
		}
		REP(i,npart) REP(op1,2) REP(op2,2) if(g[to][i][op1][op2]!=INT_MIN) {
			CHANGE(f[to][i+1][op2],g[to][i][op1][op2]);
		}
		at=to;
	}
	int ret=INT_MIN; REP(op,2) CHANGE(ret,f[at][npart][op]); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}