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

int n,m;
int a[200000];

void run(int casenr) {
	scanf("%d%d",&n,&m); REP(i,n) scanf("%d",&a[i]);
	int cntpos=0,cntneg=0; REP(i,n) if(a[i]<0) ++cntneg; else ++cntpos;
	REP(i,m) {
		int l,r; scanf("%d%d",&l,&r); int cnt=r-l+1;
		printf("%d\n",cnt%2==0&&cntpos>=cnt/2&&cntneg>=cnt/2?1:0);
	}
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}