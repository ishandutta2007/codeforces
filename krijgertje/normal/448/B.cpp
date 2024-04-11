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

int slen,tlen;
char s[101],t[101];

int diff[26];

void run() {
	scanf("%s%s",s,t); slen=strlen(s); tlen=strlen(t);

	memset(diff,0,sizeof(diff));
	REP(i,slen) diff[s[i]-'a']++;
	REP(i,tlen) diff[t[i]-'a']--;

	bool can=true,onlyswap=true;
	REP(i,26) {
		if(diff[i]<0) can=false;
		if(diff[i]!=0) onlyswap=false;
	}
	if(!can) { printf("need tree\n"); return; }
	if(onlyswap) { printf("array\n"); return; }

	int a=0,b=0;
	while(a<slen&&b<tlen) {
		if(s[a]==t[b]) { ++a; ++b; continue; }
		++a;
	}
	bool onlyrem=b>=tlen;
	if(onlyrem) { printf("automaton\n"); return; }
	printf("both\n");
}

int main() {
	run();
	return 0;
}