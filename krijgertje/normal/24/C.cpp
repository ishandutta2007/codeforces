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
	int n; scanf("%d",&n); ll ind; cin>>ind;
	ll x,y; cin>>x>>y;
	vector<int> px(n),py(n); REP(i,n) scanf("%d%d",&px[i],&py[i]);
	ind=ind%(2*n);
	REP(i,ind) {
		int j=i%n;
		x=2*px[j]-x; y=2*py[j]-y;
	}
	cout<<x<<" "<<y<<endl;
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}