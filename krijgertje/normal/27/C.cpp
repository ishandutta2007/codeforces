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
	int a=0;
	while(a+1<n&&x[a]==x[a+1]) a=a+1;
	int b=a+1,c=b+1;
	while(b<n&&c<n) {
		if(x[a]>x[b]&&x[b]<x[c]) break;
		if(x[a]<x[b]&&x[b]>x[c]) break;
		++b,++c;
	}
	if(a<n&&b<n&&c<n) {
		printf("3\n%d %d %d\n",a+1,b+1,c+1);
	} else {
		printf("0\n");
	}
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}