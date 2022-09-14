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

char s[MAXLEN+1]; int slen;
char p[]="Bulbasaur"; int plen;

int have[52],need[52];
int conv(char c) { if(isupper(c)) return c-'A'; if(islower(c)) return 26+c-'a'; assert(false); return -1; }

void run() {
	scanf("%s",s); slen=strlen(s); plen=strlen(p);
	memset(have,0,sizeof(have)); REP(i,slen) ++have[conv(s[i])];
	memset(need,0,sizeof(need)); REP(i,plen) ++need[conv(p[i])];
	int ret=INT_MAX;
	REP(i,52) if(need[i]>0) ret=min(ret,have[i]/need[i]);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}