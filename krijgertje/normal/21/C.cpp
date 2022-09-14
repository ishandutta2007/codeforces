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
	vector<int> x(n); REP(i,n) scanf("%d",&x[i]);

	ll sum=0; REP(i,n) sum+=x[i];
	if(sum%3!=0) { printf("0\n"); return; }
	ll part=sum/3;
	
	ll two=0,ret=0,parsum=0;
	REP(i,n-1) {
		parsum+=x[i];
		if(parsum==2*part) ret+=two;
		if(parsum==part) two++;
	}
	cout<<ret<<endl;
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}