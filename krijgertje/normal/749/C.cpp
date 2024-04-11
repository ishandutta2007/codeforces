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

const int MAXN=200000;

int n;
char s[2*MAXN+1];

void run() {
	scanf("%d%s",&n,s);
	int nd=0,nr=0; int dleft=0,rleft=0; REP(i,n) if(s[i]=='D') ++dleft; else if(s[i]=='R') ++rleft; int at=0;
	while(dleft>0&&rleft>0) {
		if(s[at]=='D'&&nd>0) { --nd; ++at; continue; }
		if(s[at]=='R'&&nr>0) { --nr; ++at; continue; }
		if(s[at]=='D') ++nr,--rleft; if(s[at]=='R') ++nd,--dleft; s[n++]=s[at++];
	}
	printf("%c\n",dleft>0?'D':rleft>0?'R':'?');
}

int main() {
	run();
	return 0;
}