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
	int n,d,m,l; scanf("%d%d%d%d",&n,&d,&m,&l);
	int da=d%m,db=d/m;
	
	int offset=0,nr=0;
	vector<bool> been(m,false);
	while(!been[offset]) {
		been[offset]=true;
		offset+=da; nr+=db; if(offset>=m) offset-=m,++nr;
		if(offset>l||nr>=n) { cout<<(ll)nr*m+offset<<endl; return; }
	}
	cout<<((ll)m*n+d-1)/d*d<<endl;
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}