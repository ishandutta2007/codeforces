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

int n,want;
int ret[100000];

void run() {
	scanf("%d%d",&n,&want);
	int npair=n/2;
	if(want<npair||npair==0&&want!=0) { printf("-1\n"); return; }
	if(npair==0) { printf("1\n"); return; }
	int first=want-(npair-1);
	ret[0]=first; ret[1]=2*first;
	int at=1;
	FOR(i,1,npair) {
		while(at==ret[0]||at==ret[1]||at+1==ret[0]||at+1==ret[1]) ++at;
		ret[2*i]=at; ret[2*i+1]=at+1; at+=2;
	}
	FOR(i,2*npair,n) {
		while(at==ret[0]||at==ret[1]) ++at;
		ret[i]=at; ++at;
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}