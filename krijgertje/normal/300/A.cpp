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
	vector<int> a(n); REP(i,n) scanf("%d",&a[i]);
	vector<int> pos,neg,zero; REP(i,n) if(a[i]<0) neg.PB(a[i]); else if(a[i]>0) pos.PB(a[i]); else zero.PB(a[i]);
	vector<int> l1,l2,l3;
	assert(SZ(zero)>0); REPSZ(i,zero) l3.PB(zero[i]);
	REPSZ(i,pos) l2.PB(pos[i]);
	assert(SZ(neg)>=1); l1.PB(neg[0]);
	if(SZ(neg)%2==0) l3.PB(neg[1]); else if(SZ(neg)>=2) l2.PB(neg[1]);
	FORSZ(i,2,neg) l2.PB(neg[i]);
	assert(SZ(l2)>0);
	printf("%d",SZ(l1)); REPSZ(i,l1) printf(" %d",l1[i]); puts("");
	printf("%d",SZ(l2)); REPSZ(i,l2) printf(" %d",l2[i]); puts("");
	printf("%d",SZ(l3)); REPSZ(i,l3) printf(" %d",l3[i]); puts("");
}

int main() {
	run();
	return 0;
}