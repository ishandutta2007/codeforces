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

const int MAXCOMP=100;
const int MAXPART=1000;

int ncomp,npart;
int me[MAXCOMP];

double p[2][MAXCOMP*MAXPART];

void run() {
	scanf("%d%d",&ncomp,&npart); REP(i,ncomp) scanf("%d",&me[i]),--me[i];
	if(npart==1) { printf("%.9lf\n",1.0); return; }
	
	int at=0; memset(p,0,sizeof(p)); p[at][0]=1;
	REP(i,ncomp) {
		double sum=0;
		REP(j,(i+1)*npart) {
			sum+=p[at][j];
			if(j>=npart) sum-=p[at][j-npart];
			p[1-at][j]=(sum-(j>=me[i]?p[at][j-me[i]]:0))/(npart-1);
		}
		at=1-at;
		//sum=0; REP(j,(i+1)*npart) printf("%.3lf ",p[at][j]),sum+=p[at][j]; printf(" = %.4lf\n",sum);
	}
	int mesum=0; REP(i,ncomp) mesum+=me[i];
	double ret=1; REP(i,mesum) ret+=(npart-1)*p[at][i]; printf("%.9lf\n",ret);
}


int main() {
	run();
	return 0;
}