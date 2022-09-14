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

const int MAXLEN=100000;

char s[MAXLEN+1],t[MAXLEN+1]; int len;

void run() {
	scanf("%s%s",s,t); len=strlen(s); assert(strlen(t)==len);
	int ndiff=0; REP(i,len) if(s[i]!=t[i]) ++ndiff;
	if(ndiff%2!=0) { printf("impossible\n"); return; }
	int left=ndiff/2;
	REP(i,len) { char now=t[i]; if(s[i]!=t[i]&&left>0) { now=s[i]; --left; } printf("%c",now); } puts("");
}


int main() {
	run();
	return 0;
}