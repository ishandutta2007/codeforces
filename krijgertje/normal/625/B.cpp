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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXSLEN=100000;
const int MAXPLEN=30;

char s[MAXSLEN+1]; int slen;
char p[MAXPLEN+1]; int plen;

void run() {
	scanf("%s%s",s,p); slen=strlen(s); plen=strlen(p);
	int ret=0;
	for(int at=0;at+plen<=slen;++at) {
		bool match=true; REP(i,plen) if(s[at+i]!=p[i]) { match=false; break; } if(!match) continue;
		s[at+plen-1]='#'; ++ret;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}