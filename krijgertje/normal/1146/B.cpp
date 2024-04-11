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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXLEN=100000;

char t[MAXLEN+1]; int tlen;
char s[MAXLEN+1]; int slen;

char x[MAXLEN+1]; int xpos[MAXLEN+1]; int xlen;

bool solve() {
	xlen=0; REP(i,tlen) if(t[i]!='a') x[xlen]=t[i],xpos[xlen]=i,++xlen; xpos[xlen]=tlen;
	if(xlen%2!=0) return false;
	int ylen=xlen/2;
	REP(i,ylen) if(x[i]!=x[ylen+i]) return false;
	REP(i,tlen) if(t[i]=='a'&&i>=xpos[ylen]) return false;
	slen=0; REP(i,xpos[ylen]) s[slen++]=t[i]; s[slen]='\0'; return true;
}

void run() {
	scanf("%s",t); tlen=strlen(t);
	if(!solve()) { printf(":(\n"); return; }
	printf("%s\n",s);
}

int main() {
	run();
	return 0;
}