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
#include <list> 
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

void run() {
	int n; scanf("%d",&n);
	vector<vector<double> > a(n,vector<double>(n));
	REP(i,n) REP(j,n) scanf("%lf",&a[i][j]);
//	printf("%d\n",n); REP(i,n) { REP(j,n) printf("%4lf ",a[i][j]); puts(""); }
	vector<double> p((1<<n),0);
	p[(1<<n)-1]=1;
	for(int i=(1<<n)-1;i>=0;--i) {
		int cnt=0; REP(j,n) if(i&(1<<j)) ++cnt;
		REP(j,n) if(i&(1<<j)) FOR(k,j+1,n) if(i&(1<<k)) {
			p[i-(1<<j)]+=a[k][j]*p[i]/(cnt*(cnt-1)/2);
			p[i-(1<<k)]+=a[j][k]*p[i]/(cnt*(cnt-1)/2);
		}
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%.6lf",p[1<<i]); } printf("\n");
}

int main() {
	run();
	return 0;
}