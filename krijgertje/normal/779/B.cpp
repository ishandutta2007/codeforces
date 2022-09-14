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

const int MAXLEN=10;

char s[MAXLEN+1]; int k; int slen;

void run() {
	scanf("%s%d",s,&k); slen=strlen(s);
	int rem=k,ret=0;
	for(int i=slen-1;i>=0&&rem>0;--i) if(s[i]=='0') --rem; else s[i]='x',++ret;
	bool leadnonzero=false;
	for(int i=0;i<slen&&!leadnonzero;++i) if(s[i]=='0') s[i]='x',++ret; else if(s[i]!='x') leadnonzero=true;
	if(!leadnonzero&&ret>0) --ret;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}