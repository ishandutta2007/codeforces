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

const int MAXLEN=100;

char s[MAXLEN+1]; int n;

int calc() {
	int ret=0; REP(i,n-1) if(s[i]=='V'&&s[i+1]=='K') ++ret; return ret;
}

void run() {
	scanf("%s",s); n=strlen(s);
	int ret=calc();
	REP(i,n) { s[i]=s[i]=='V'?'K':'V'; int cur=calc(); s[i]=s[i]=='V'?'K':'V'; if(cur>ret) ret=cur; }
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}