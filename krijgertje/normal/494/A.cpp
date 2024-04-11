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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

char s[100001]; int slen;
bool ok(int lastdash,int lastval) {
	if(lastval<1) return false;
	int cur=0;
	REP(i,slen) {
		if(s[i]=='(') ++cur;
		if(s[i]==')'||s[i]=='#'&&i!=lastdash) --cur;
		if(i==lastdash) cur-=lastval;
		if(cur<0) return false;
	}
	return cur==0;
}

void run() {
	scanf("%s",s); slen=strlen(s);
	int nopen=0,nclose=0,ndash=0,lastdash=-1;
	REP(i,slen) if(s[i]=='(') ++nopen; else if(s[i]==')') ++nclose; else ++ndash,lastdash=i;
	int lastval=nopen-nclose-(ndash-1);
	if(ok(lastdash,lastval)) {
		REP(i,ndash) printf("%d\n",i!=ndash-1?1:lastval);
	} else {
		printf("-1\n");
	}
}

int main() {
	run();
	return 0;
}