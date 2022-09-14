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

int n;
char a[21],b[21];


int convert(char p,char q) { if(p=='8'&&q=='<') return 0; if(p=='['&&q==']') return 1; if(p=='('&&q==')') return 2; assert(false); return -1; }

void run() {
	scanf(" %s %s",a,b); n=strlen(a);
	int ret=0;
	REP(i,n/2) {
		int p=convert(a[2*i],a[2*i+1]),q=convert(b[2*i],b[2*i+1]);
		if(p==q) continue;
		if((p+1)%3==q) ++ret;
		if((p+2)%3==q) --ret;
	}
	if(ret<0) printf("TEAM 2 WINS\n"); else if(ret>0) printf("TEAM 1 WINS\n"); else printf("TIE\n");
}

int main() {
	run();
	return 0;
}