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

int len; char s[MAXLEN+1];

int ret[MAXLEN],nret;

void run() {
	scanf("%d%s",&len,&s);

	nret=0; int cur=0;
	REPE(i,len) if(i<len&&s[i]=='B') ++cur; else if(cur!=0) ret[nret++]=cur,cur=0;
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}


int main() {
	run();
	return 0;
}