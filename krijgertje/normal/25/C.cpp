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
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

void run() {
	int n; scanf("%d",&n);
	VVI d(n,VI(n));
	REP(i,n) REP(j,n) scanf("%d",&d[i][j]);
	int k; scanf("%d",&k);
	vector<ll> ret;
	REP(q,k) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b;
		if(c<d[a][b]) {
			d[a][b]=d[b][a]=c;
			REP(x,2) {
				REP(i,n) FOR(j,i+1,n) if(d[i][a]+d[a][b]+d[b][j]<d[i][j]) d[i][j]=d[j][i]=d[i][a]+d[a][b]+d[b][j];
				swap(a,b);
			}
		}
		ll cur=0; REP(i,n) FOR(j,i+1,n) cur+=d[i][j]; ret.PB(cur);
	}
	REPSZ(i,ret) { if(i!=0) printf(" "); printf("%I64d",ret[i]); } puts("");
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}